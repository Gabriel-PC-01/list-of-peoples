#pragma once

#include <stdio.h>

struct users{
    
    char name[200];
    int age;
    struct users *next_node;

};
typedef struct users users;
typedef users* PTR_users;


    extern PTR_users START_ptr;


int new_user(const char *name, const int year);

int rm_user(const char *name, const int year);

//PTR_users pass_user();

int testrm();

int testnw();


