#include <stdio.h>
#include <stdlib.h>
#include "Vector_.h"

Vector<int> v;

template class Vector<int>;

int RandInt( ){
    return rand()>>25;
}


void visitInt(int i){
    printf("%d  ", i);
}


int main(int argc, char *argv[]){
    int (*Rand)() = RandInt;
    void (*visit)(int) = visitInt;   
//    printf("OK");
    int a[] = {1,2,3,4,5,6,7,8};
    v = Vector<int>(10);
    
    printf("生成向量大小%d，空间10\n",v.size());
    
    printf("随机生成未知数填满空间\n");
    v.Random(Rand);
    v.traverse(visit);
    printf("\n排序\n");
    v.sort();

    v.traverse(visit);
    printf("\n");


}
