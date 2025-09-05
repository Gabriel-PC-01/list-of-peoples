#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


PTR_users START_ptr = NULL;


static int create_user(PTR_users *INIT_ptr, const char *name, const uint_least8_t year){

    
 PTR_users NEW_node = NULL;


    NEW_node = malloc(sizeof(users)); 

    if(NEW_node == NULL){

        fprintf(stderr, "Voce não tem memoria para criar usuarios:");
        return 1;
    }

    if(NEW_node != NULL){

        strcpy(NEW_node->name, name);
        NEW_node->age = year;

        NEW_node->next_node = *INIT_ptr;
        *INIT_ptr = NEW_node;
    }
    
    return 0;
}


int new_user(const char *name, const uint_least8_t year){

    switch (create_user(&START_ptr ,name, year)){
        case 0:
       
            return 0;
        break;
    
        case 1:

            return 1;
        break;

        case 2:

            return 2;
        break;

        default:

            return 0;
        break;
    }

    return 0;
}


