#include "list.h"


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

   rm_user("delete_all", 0); 

    return 0;
}
