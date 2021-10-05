#include "../include/TreeServer.h" 

/** 
 * Função de inserção recebe um tipo de dados datatype contendo o nome e os arquivos binarios 
 * Percorre a arvore binaria para nós internos indo tanto para a direita quanto para a esquerda  
 * Caso o nó seja folha insere as informações contidas no datatype nessa folha 
 * Cada nova inserção uma lista é criada  
 * Caso o elemento a ser inserido já esteja presente  na árvore apenas acrescenta o char de binario em sua lista 
 */ 
void Insert(Pointer *rootptr, datatype_t *d)
{   
    #if DEBUGTREE 
        puts("INSERCAO"); 
    #endif
    if ((*rootptr) == NULL)
    {   
        Pointer N = NULL;  
        N = (Pointer)malloc(sizeof(struct BST_node)); 
        N->left = N->right = NULL;  
        List *Dl;  
        Allocate_List(&Dl); 
        N->Data = Dl; 
        N->name = malloc(sizeof(strlen(d->name))); 
        strcpy(N->name,d->name);      
        N->value += Insert_List(&(N->Data),d->data);  
        
        *rootptr = N;     
         
        #if DEBUGLIST
            puts(N->name);
            show_List(&(*rootptr)->Data); 
            printf("Value: %d\n",(*rootptr)->value); 
        #endif  
        #if DEBUGTREE  
             puts("Inserido");
        #endif
        
        return; 
    }
    else{ 
        
        #if DEBUGTREE
            printf("A: %s\n",(*rootptr)->name); 
            printf("I: %s\n",d->name);
        #endif 
        if (strcmp((*rootptr)->name, d->name) > 0)
        {   
            #if DEBUGTREE
                printf("LEFT\n"); 
            #endif
            Insert(&(*rootptr)->left, d);
        }
        else if (strcmp((*rootptr)->name, d->name) < 0)
        {   
            #if DEBUGTREE
                printf("RIGHT \n"); 
            #endif
            Insert(&(*rootptr)->right, d);
        }
        else if(strcmp((*rootptr)->name, d->name) == 0)
        {   

            (*rootptr)->value += Insert_List(&(*rootptr)->Data,d->data);   
            #if DEBUGTREE
                printf("DUPLICATE - %s\n",d->name);  
            #endif  

            #if DEBUGLIST
                puts((*rootptr)->name);        
                show_List(&(*rootptr)->Data); 
            #endif
        }  
    }
    return;
} 
/**  
 *  Printa as informações da arvore em ordem 
 *  Percorre-se o filho a esquerda o nó interno e o filho a direita 
 *  É exibido na tela apenas o campo nome contido no nó
 */
 void BST_print_inorder(Pointer *node)
{   
   if (*node == NULL){ 
   
        printf(" "); 
          
    } 
    else
    {
        BST_print_inorder(&(*node)->left);
        printf("%s",(*node)->name);
        BST_print_inorder(&(*node)->right);
    }
}   
/** 
 * Realiza a busca de um elemento na árvore  
 * Como parâmetro de busca usa-se uma string de nome.  
 * Caso a string seja compatível invoca-se a função de remoção    
 */
void search(char *B, Pointer *P) 
{   
   
    if (*P== NULL){  
        printf("\nErro: Na pesquisa\n");
        return;
    } 
    if (strcmp((*P)->name,B)== 0){ 
        //puts((*P)->name);
        Remove(B,P);   
        return; 
    }
    else if(strcmp((*P)->name, B) > 0){   
        search(B, &(*P)->left);
        return;
    }
    else if (strcmp((*P)->name, B) < 0){ 
        search(B, &(*P)->right); 
        return;  
    }
}  
/**  
*   Função auxiliar da remoção 
*   Utilizada quando o nó a ser removido possui dois filhos  
*   Percorre-se á direita do filho a esquerda do nó que será removido 
*   Realiza a conexão dos ponteiros e libera a memória alocada do ponteiro do nó que será removido
*/ 

void Father(Pointer q, Pointer *r)
{ if ((*r)->right != NULL) 
  {  
    Father(q, &(*r)->right);
    return;
  }
  q->Data = (*r)->Data; 
  q->name = (*r)->name; 
  q->value = (*r)->value; 
  q = *r; 
  *r = (*r)->left; 
  printf(" %s %d\n", q->name, q->value);
  free(q); 

}   
/** 
 *  Função usada para remover um elemento da árvore 
 *  Percorre-se a árvore até o nó que se deseja remover  
 *  Caso não encontre retorna com mensagem de erro   
 *  Verifica-se, então, o estado dos filhos. 
 *  Caso não haja filhos à direita substitui o mesmo pelo filho à esquerda.  
 *  Caso não haja filhos à esqueda substitui pelo mais á direita de seus descendentes. 
 *  Nos demais casos substitui pelo filho à esquerda.  
 *  (Algoritmo do Prof. Ziviani com adaptações)
 */ 
void Remove(char*x,Pointer *p) 
{  
    Pointer Aux;
    if (*p == NULL) 
    { printf("Erro REMOCAO\n");
        return;
    }
    if (strcmp((*p)->name, x) > 0) {  
        Remove(x, &(*p)->left);  
        return;  
    }
    if (strcmp((*p)->name, x) < 0) {  
        Remove(x, &(*p)->right);  
        return;  
    } 

    if ((*p)->right == NULL) 
    { Aux = *p;  *p = (*p)->left;
        free(Aux);  
        if(Aux)
            printf(" %s %d\n",Aux->name, Aux->value);
        return;
    }
    if ((*p)->left != NULL) 
    { Father(*p, &(*p)->left);
        return;
    }
    Aux = *p;  *p = (*p)->left; 
    printf(" %s %d\n",Aux->name, Aux->value);
    free(Aux);
}   

