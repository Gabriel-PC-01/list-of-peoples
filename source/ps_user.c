#include "list.h"
#include <stdio.h>
#include <string.h>


PTR_users pass_user(){

    int cont;
    PTR_users reset = START_ptr;

    while (START_ptr != NULL){

        START_ptr = START_ptr->next_node;
        
        cont++;
    }

    if(cont == 0){

        return NULL;
    }

    START_ptr  = reset;
    users list[cont];
    
    for (int i = 0; i < cont; i++){
    
        strcpy(list[i].name, START_ptr->name);
        list[i].age = START_ptr->age;
        
        START_ptr = START_ptr->next_node;
    }
    

    return &list;

}