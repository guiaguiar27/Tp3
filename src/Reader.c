#define _GNU_SOURCE  
#include "../include/Reader.h"
#include <stdio.h> 
#include <stdlib.h> 

/**  
 * Recebe como parametro o nome de um arquivo 
 * Modifica o nome para que o arquivo em seu diretório seja aberto de forma adequada  
 * Lê a primeira linha do árquivo e armazena o numero de inserções 
 * Realiza as N inserções particionando a string em duas  
 * Percorre a árvore em ordem  
 * Realiza o envio das consciencias fazendo do buscas e remoções na árvore 
 * Exibe o último elemento  
 *  
*/
void reader(char *FileName){ 
    char pre_path[] =  "./src/";    
    char *path = malloc(strlen(pre_path) + strlen(FileName) + 1);    
    char *buff = (char*)malloc(sizeof(char));   
    char *tokenSpace =  " "; 
    char *slot = (char*)malloc(sizeof(char));   
    char *data = (char*)malloc(sizeof(char));   

    int lines = 0; 

    size_t len = 0; 
    size_t read = 0;  
    strcat(path,pre_path);  
    strcat(path,FileName);   

    FILE *file = NULL;    
    file = fopen(path,"r");  
   
    struct BST_node *root = NULL; 
    
    lines = atoi(fgets(buff,MAX_CHAR_COMMAND,file));   
    for(int i = 0; i <lines; i++){ 
      if(fgets(buff,MAX_CHAR_COMMAND,file) != NULL){ 
      

        slot = strtok (buff," "); 
        data = strtok (NULL," "); 
        
        datatype_t *earth = (datatype_t*)malloc(sizeof(datatype_t));   
        earth->name = malloc(sizeof(strlen(slot+1)));  
        earth->data = malloc(sizeof(strlen(buff+1))); 

        slot[strcspn(slot, "\n")] = 0;
        strcpy(earth->name,slot);   
        strcpy(earth->data,data);
         
        Insert(&root, earth); 
        
        free(earth);
        
      }
        
    }  
    BST_print_inorder(&root); 
    printf("\n");

    while(fgets(buff,MAX_CHAR_COMMAND,file)){ 
      
      if(buff){
        buff[strcspn(buff, "\n")] = 0; 
        search(buff,&root); 
      }
    } 
    printf(" %s\n",root->name);
    
    fclose(file);    
    
    
    

    
}