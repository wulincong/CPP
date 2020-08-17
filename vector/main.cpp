#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

int RandInt(void ){
    return rand();
}


int (*Rand)(void) = RandInt;

void visitInt(int i){
    printf("%d", i);
}

void (*visit)(int) = visitInt;

int main(int argc, char *argv[]){
    
    Vector<int> v ;
    
    v.Random(Rand);
    v.traverse(visit);
}
