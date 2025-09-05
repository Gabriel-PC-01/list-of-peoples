#include "list.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


static PTR_users AFTER_user;
static PTR_users BEFORE_user;


static int find(const char name[], const uint_least8_t year);
static int delete_one(const char name[], const uint_least8_t year);
static int delete_all(void);


static int find(const char name[], const uint_least8_t year){

    AFTER_user = START_ptr;
    BEFORE_user = NULL;

    while(AFTER_user != NULL){
        
        if(strcmp(AFTER_user->name, name) == 0 && AFTER_user->age == year )
            break;

        BEFORE_user = AFTER_user;
        AFTER_user = AFTER_user->next_node;
    }

       if(AFTER_user == NULL){ 

            return 1; 
       }

    return 0;
    }


    static int delete_one(const char name[], const uint_least8_t year){

        if(find(name, year) == 1){

            return 1;
        }

        PTR_users DEL_user;

        if (BEFORE_user == NULL){
            
            START_ptr = AFTER_user->next_node;
        }else{

            BEFORE_user->next_node = AFTER_user->next_node;
        }

        DEL_user = AFTER_user;
        free(DEL_user);


           
        return 0;
    }


    static int delete_all(void){

        PTR_users delete = NULL;
        PTR_users *node = &START_ptr;

        if(*node == NULL){

            return 1;
        }

        while ((*node) != NULL){
            
            delete = (*node);
            (*node) = (*node)->next_node;
            free(delete);
       }

        return 0;
    }

    int rm_user(const char *name, const uint_least8_t year){

    if(strcmp(name, "delete_all") == 0){

        if(delete_all() == 1){

            return 1;
        }else{

            return 0;
        }
    }
    else if(delete_one(name, year) == 1){

        return 2;
    }

    return 0;
}
