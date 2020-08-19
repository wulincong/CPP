#include <stdio.h>
#include <stdlib.h>

int RandInt(){
    return rand();
}


void put_rand_number(int (*get)()){
    printf("%d   ",get());
}



int main(){
    int (* Rand)() = RandInt;
    put_rand_number(Rand);


}


