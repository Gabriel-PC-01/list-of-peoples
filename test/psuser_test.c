#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print(const users list[], const int size);


void testps(void){

new_user("Alice", 25);
new_user("Bruno", 34);
new_user("Carla", 19);
new_user("Diego", 42);
new_user("Eduarda", 28);
new_user("Felipe", 37);
new_user("Gabriela", 22);
new_user("Henrique", 60);
new_user("Isabela", 31);
new_user("João", 18);
new_user("Karen", 45);
new_user("Lucas", 52);
new_user("Mariana", 27);
new_user("Nicolas", 39);
new_user("Olívia", 55);
new_user("Paulo", 41);
new_user("Queila", 20);
new_user("Ricardo", 36);
new_user("Sofia", 24);
new_user("Thiago", 33);
new_user("Ursula", 48);
new_user("Vinicius", 29);
new_user("William", 58);
new_user("Xavier", 26);
new_user("Yara", 44);
new_user("Zeca", 32);
new_user("Alice", 30);  
new_user("Alice", 55);   
new_user("Alice", 42);   
new_user("Bruno", 21);  
new_user("Bruno", 47);   
new_user("Bruno", 59);  


    fprintf(stderr, "***********************************************************\n");
    fprintf(stderr, "***********************************************************\n\n");


    filter set_test;
    PTR_users list = NULL;

    strcpy(set_test.filter, "all");
    strcpy(set_test.name, "Bruno");
    set_test.age_low = 30;
    set_test.age_high = 40;

    switch (pass_user(&list, &set_test)) {
        
        case 1:
            
            fprintf(stderr, "todos os usuários foram passados\n");

            print(list, set_test.cont);
        break;

        case -1:

            fprintf(stderr, "nada foi passado");
        break;

        case -2:

            fprintf(stderr, "nehuma filtro valido foi escolhido");
        break;


        default:

        
        break;
    }


    strcpy(set_test.filter, "filter_name");

    switch (pass_user(&list, &set_test)) {
        
        case 2:
            
            fprintf(stderr, "\n\ntodos os usuários foram passados\n");

            print(list, set_test.cont);
        break;

        case -1:

            fprintf(stderr, "nada foi passado");
        break;

        case -2:

            fprintf(stderr, "\nnehuma filtro valido foi escolhido\n");
        break;


        default:

        
        break;
    }

    strcpy(set_test.filter, "filter_age");

    switch (pass_user(&list, &set_test)) {
        
        case 3:
            
            fprintf(stderr, "\ntodos os usuários foram passados\n");

            print(list, set_test.cont);
        break;

        case -1:

            fprintf(stderr, "nada foi passado");
        break;

        case -2:

            fprintf(stderr, "nehuma filtro valido foi escolhido");
        break;

        case -3:

            fprintf(stderr, "erro: a idade minima e maior que a maxima");
        break;

        default:

        break;
    }       

    free(list);
}


void print(const users list[], const int size){

    for (int i = 0; i < size; i++){
   
        fprintf(stderr, "\n%s | %d", list[i].name, list[i].age);
    }

}

