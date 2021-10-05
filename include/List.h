#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct Node{ 
    char *Bin; 
    int value; 
    struct Node *next;  
}Node_t; 
typedef Node_t List; 

/** 
 * \brief Aloca uma nova lista
 */   
void    Allocate_List(List **L); 
/** 
 * \brief Insere um novo elemento na lista
 */   
int     Insert_List(List **L, char *Bin);  
/** 
 * \brief Converte uma string de binário para um decimal em int
 */    
int     Bin_to_int(char *Bin);      
/** 
 * \brief Exibe o conteúdo da lista
 */   
void    show_List(List **DL);   
