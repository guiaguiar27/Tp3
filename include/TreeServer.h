/** 
 * DUBBUGTREE exibe o comportamento da árvore 
 * DUBBUGTREE exibe o comportamento da Lista operada pela árvore   
 */
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include "List.h" 
#define DEBUGTREE 0 
#define DEBUGLIST 0
   
/* 
    -> Estrutura usada apenas para a transferencia do arquivo para a list 
    -> no interior de um nó epecifico da arvore
*/  
typedef struct datatype_t
{   char *data; 
    char *name;
} datatype_t;
/* 
    -> Estruturas especificas da árvore binária
    -> Campo Data é uma lista das consciências binárias  
    -> Value é correspondente ao valor em decimal total de todas as consciências presentes na lista  
    -> campo name é usado como parâmetro para percorrer a árvore sendo o identificador de cada nó 
*/
typedef struct BST_node* Pointer; 
typedef struct BST_node
{
    List *Data;   
    char *name;  
    int value;
    Pointer left;
    Pointer right;
}BST_node;
/** 
 * \brief Inserção de elementos datatype na bst
 */
void Insert(Pointer *rootptr, datatype_t *d); 
/** 
 * \brief Printa a bst em ordem
 */  
void BST_print_inorder(Pointer *node); 
/** 
 * \brief Pesquisa na BST
 */ 
void search(char  *B, Pointer *P);
/** 
 * \brief Encontra o maior nó a esquerda para a remoção
 */   
void Father(Pointer q, Pointer *r); 
/** 
 * \brief Realiza a remoção do nó desejado
 */   
void Remove(char *x, Pointer *P);

