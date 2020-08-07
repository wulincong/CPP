#include <stdio.h>
#include "bits.c"

int main(){
    
    printf("%d\n",bitXor(1,1));
    printf("%d\n",bitXor(0,1));
    printf("%d\n",bitXor(1,0));
    printf("%d\n",bitXor(0,0));

    printf("%d\n",isTmax(0xFFFFFFFF));
    return 0;
}
