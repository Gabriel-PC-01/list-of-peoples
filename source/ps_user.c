#include "list.h"
#include <stdlib.h>     
#include <stdio.h>
#include <string.h>


int pass_user(PTR_users* list){

    int cont = 0;
    PTR_users cont_node = START_ptr;
    *list = NULL;


    while(cont_node != NULL){

       (*list) = realloc((*list), (cont + 1) * sizeof(users));

        strcpy((*list)[cont].name,cont_node->name);
        (*list)[cont].age = cont_node->age;

        cont_node = cont_node->next_node;
        
        cont++;
    }

    if(cont == 0){

        return -1;
    }

    
    return cont;
}
