#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include "Vector_.h"

// Vector<int> v;
using namespace std;
template class Vector<int>;

int RandInt(){
    return rand()>>29;
}


void VisitInt(int i){
    printf("%d ", i);
}



int main(int argc, char *argv[]){

    // if(argc == 2){
    //     int capacity = atoi(argv[1]);
    //     Vector<int> v = Vector<int>(capacity);
    //     int (*Rand)() = RandInt;
    //     v.Random(Rand);
    //     void (*visit)(int) = VisitInt;
    //     v.traverse(visit);
    //     v.sort();
    //     printf("\n第二遍\n");
    //     v.traverse(visit);
    // }

    int (*Rand)() = RandInt;
    void (*visit)(int) = VisitInt;   
    if(argc > 1){
        int size = atoi(argv[1]);
        Vector<int> v = Vector<int>(size);
        v.Random(Rand);
        v.traverse(visit);
        v.sort();
        printf("\n");
        v.traverse(visit);
        printf("\n");
    }
}
