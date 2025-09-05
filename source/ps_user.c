#include "list.h"
#include <stdlib.h>     
#include <stdio.h>
#include <string.h>


static void find_name(PTR_users *list, filter *type);
static void find_all(PTR_users *list, filter *type);
static void find_age(PTR_users *list, filter *type );


int pass_user(PTR_users* list, filter *type){

    if(type->age_low > type->age_high){

        return -3;

        }

    if (list != NULL){
    
        free(*list);
    }

    type->cont = 0;
    *list = NULL;

    if (strcmp(type->filter, "all") == 0) {
        
        find_all(list, type);
        return 1; 
    }


    if (strcmp(type->filter, "filter_name") == 0){

        find_name(list, type);
        return 2;
    }

    if (strcmp(type->filter, "filter_age") == 0) {

        find_age(list, type);
        return 3;
    }

    if(type->cont == 0){
        return -1;
    }

    if(strcmp(type->filter, "filter_name") && strcmp(type->filter, "all") && strcmp(type->filter, "filter_age")){

        return -2;
    }

    return -2;
    
}


static void find_name(PTR_users *list, filter *type){

    PTR_users cont_node = START_ptr;

    while(cont_node != 0){
    
        if (strcmp(cont_node->name,type->name) == 0){
        
            (*list) = realloc((*list),(type->cont + 1) * sizeof(users));
            
            (*list)[type->cont].age = cont_node->age;
            strcpy((*list)[type->cont].name, cont_node->name);
            
            type->cont++;
        };


    cont_node = cont_node->next_node;
    }

}


static void find_all(PTR_users *list, filter *type){

    PTR_users cont_node = START_ptr;

    while(cont_node != NULL){

       (*list) = realloc((*list), ((type->cont) + 1) * sizeof(users));

        strcpy((*list)[type->cont].name, cont_node->name);
        (*list)[type->cont].age = cont_node->age;

        cont_node = cont_node->next_node;
        
            type->cont++;
        };

    return ;
}


static void find_age(PTR_users *list, filter *type){

    PTR_users cont_node = START_ptr;
    

    while(cont_node != NULL){
    
        if (cont_node->age >= type->age_low && cont_node->age <= type->age_high) {
       
            (*list) = realloc((*list), ((type->cont) + 1) * sizeof(users));

            strcpy((*list)[type->cont].name, cont_node->name);
            (*list)[type->cont].age = cont_node->age;
            type->cont++;
        }
    
        cont_node = cont_node->next_node;
    }
    
    return ;
}

