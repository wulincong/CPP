#include <iostream>
#include <stdio.h>
#include "Vector.h"




int RandInt(){
    return rand()>>29;
}

void VisitInt(int i){
    printf("%d ", i);
}


int main(int argc, char* argv[]){
    //Vector<int> v;
    if(argc == 2){
        int capacity = atoi(argv[1]);
        Vector<int> v = Vector<int>(capacity);
        int (*Rand)() = RandInt;
        v.Random(Rand);
        void (*visit)(int) = VisitInt;
        v.traverse(visit);
        v.sort();
        printf("\n第二遍\n");
        v.traverse(visit);
    }
    return 0;
}
