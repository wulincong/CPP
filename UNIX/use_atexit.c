#include <stdio.h>
#include <stdlib.h>
void my_exit1(void);
void my_exit2(void);

int 
main(void){
    atexit(my_exit1);    
    atexit(my_exit2);    
    return 0;
}

void my_exit1(void){
    printf("exit1\n");
}
void my_exit2(void){
    printf("exit2\n");
}


