#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void testps(void){

    new_user("primeiro", 1);
    new_user("segundo", 2);
    new_user("terceiro", 3);


    PTR_users list = NULL;
    int size = 0; 

        size = pass_user(&list);

    switch (size){
        
        case -1:

            fprintf(stderr, "\nA estrutura da dados está vazia\n");
            
        default:

            fprintf(stderr, "________________________________________________\n");
            fprintf(stderr, "\nestrutura de dados passada com sucesso\n");

            for (int i = 0; i < size; i++) {

                fprintf(stderr, "nome: %s", list[i].name);
                fprintf(stderr, "||idade:%d\n\n", list[i].age);
            }
            
        break;
        }

    free(list);
}
