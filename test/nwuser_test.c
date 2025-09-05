#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void testnw(void){

    PTR_users view;

    if(new_user("primeiro", 1) == 0){
        fprintf(stderr, "\nnó linkado\n");
        fprintf(stderr, "estrutura de dados\n");
        view = START_ptr;
        while (view != NULL){
            fprintf(stderr, "%s || %d", view->name, view->age);
            view =  view->next_node;
        }
        fprintf(stderr, "\n__________________________________________");
    }else{
        fprintf(stderr, "o no não foi alocado, ou memória insufciente");


    }
    if(new_user("segundo", 2) == 0){
        fprintf(stderr, "\nnó linkado\n");
        fprintf(stderr, "estrutura de dados\n");
        view = START_ptr;
        while (view != NULL){
            fprintf(stderr, "%s || %d\n", view->name, view->age);
            view = view->next_node;
        }  
        fprintf(stderr, "\n__________________________________________");
    }
    if(new_user("terceiro", 3) == 0){
        fprintf(stderr, "\nnó linkado\n");
        fprintf(stderr, "estrutura de dados\n");
        view = START_ptr;
        while (view != NULL){
            fprintf(stderr, "%s || %d\n", view->name, view->age);
            view = view->next_node;
        }  
        fprintf(stderr, "\n__________________________________________");
    }
    if(new_user("quarto", 4) == 0){
        fprintf(stderr, "\nnó linkado\n");
        view = START_ptr;
        fprintf(stderr, "estrutura de dados\n");
        while (view != NULL){
            fprintf(stderr, "%s || %d\n", view->name, view->age);
            view = view->next_node;
        }  
        fprintf(stderr, "\n__________________________________________");
    }
    if(new_user("quinto", 5) == 0){
        fprintf(stderr, "\nnó linkado\n");
        view = START_ptr;
        fprintf(stderr, "estrutura de dados\n");
        while (view != NULL){
            fprintf(stderr, "%s || %d\n", view->name, view->age);
            view = view->next_node;
        }
        fprintf(stderr, "\n__________________________________________");
    }
     
}
