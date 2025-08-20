#include "list.h"
#include <stdio.h>
#include <unistd.h>


void testrm(void){

    
    new_user("primeiro", 1);
    new_user("segundo", 2);
    new_user("terceiro", 3);
    
    switch(rm_user("primeiro", 1)){

        case 0:
        fprintf(stderr,"\nexclusão 1 bem sucediada\n");
        break;

        case 2:

        fprintf(stderr,"\nhouve problema na exclusão de um único usuário\n");
        break;

        default:

        fprintf(stderr, "Um problema ocorreu nos teste de exclusão");

    }


     switch(rm_user("segundo", 2)){

        case 0:
        fprintf(stderr,"\nexclusão 2 bem sucediada\n");
        break;

        case 2:

        fprintf(stderr,"\nhouve problema na exclusão de um único usuário\n");
        break;

        default:

        fprintf(stderr, "Um problema ocorreu nos teste de exclusão");

    }   

    
    switch(rm_user("terceiro", 3)){

        case 0:
        fprintf(stderr,"\nexclusão 3 bem sucediada\n");
        break;

        case 2:

        fprintf(stderr,"\nhouve problema na exclusão de um único usuário\n");
        break;

        default:

        fprintf(stderr, "\nUm problema ocorreu nos teste de exclusão");

    }   


   
    new_user("primeiro", 1);
    new_user("segundo", 2);
    new_user("terceiro", 3);

    switch(rm_user("delete_all", 0)){

        case 0:
            
            fprintf(stderr, "\ntodos os usuários deletados com sucesso\n");
        break;

        case 1:

            fprintf(stderr, "remoção invalida: a lista está vazia");
        break;
    }

    sleep(1);   
}
