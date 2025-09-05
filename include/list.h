#ifndef LIST_H
#define LIST_H


#include <stdint.h>

struct users{
    
    char name[60];
    uint_least8_t age;
    struct users *next_node;

};
typedef struct users users;
typedef users* PTR_users;


struct filter{

    uint_fast8_t cont;
    uint_least8_t age_low;
    uint_least8_t age_high;
    char name[60];
    char filter[15];
};
typedef struct filter filter ;

    extern PTR_users START_ptr;


int new_user(const char *name, const uint_least8_t year);

int rm_user(const char *name, const uint_least8_t year);

int pass_user(PTR_users* list, filter *type);


void testrm(void);

void testnw(void);

void testps(void);


#endif
