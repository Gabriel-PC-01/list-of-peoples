#include "list.h"
#include <stdio.h>
#include <stdlib.h>


int main(void){

    #if defined TESTNW

    testnw();
    #endif
    
    #if defined TESTRM
    
    testrm();
    #endif

    #if defined TESTPS

    testps();
    #endif
    
    #if defined TEST

    testnw();
    testrm();
    testps();
    #endif

    return 0;
}
