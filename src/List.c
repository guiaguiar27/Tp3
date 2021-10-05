#include "../include/List.h" 


/** 
 * Aloca uma nova lista;  
 * ajustando os campos para receberem informações da árvore
 */ 
void Allocate_List(List **L){ 
    
    *L = (List*)malloc(sizeof(List)); 
    (*L)->next = NULL;  
    (*L)->value = 0; 
    (*L)->Bin = NULL;   
    if(*L == NULL){ 
        printf("ERROR (list allocation)\n"); 
        exit(1);
    } 
} 
/** 
 * Insere um novo item na lista  
 * São inseridos tanto os valores em binario quanto em decimal depois de convertidos  
 */ 
int Insert_List(List **L, char *Bin){   
    List *New =  (List*)malloc(sizeof(List));  
    int success = New != NULL;  
    if (success)
    {  
        New->Bin = (char*)malloc(sizeof(char));  
        New->Bin = Bin; 
        New->value = Bin_to_int(Bin);  
        New->next = NULL; 
        while(*L !=NULL) L = &(*L)->next; 
        *L = New;   
        
     
    } 
    return Bin_to_int(Bin); 

}    
/**
 * Converte um valor em binario no tipo string, para um valor em decimal do tipo int  
 * Realiza módulos e divisões consecutivas da string  
 */ 
int  Bin_to_int(char *Bin){ 

    int total = 0;    
    int base =1; 
    int a = atoi(Bin); 
    while (a) { 

        int last_digit = a % 10;
        a = a / 10;
 
        total += last_digit * base;
 
        base = base * 2;
    }
 
    return total;
} 
/** 
 * Exibe o conteudo da lista em decimal (Já convertido) 
 *  Usada para testes do comportamento do algoritmo. 
 */ 
void show_List(List **DL){ 
    List *current = *DL;
    while (current != NULL) { 
        printf("DECIMAL: %d \n",current->value);
        current = current->next;
    
} 
}

