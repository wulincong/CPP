#ifndef SEQUENCEARRAY
#define SEQUENCEARRAY
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "Status.h"

#define MAX_ARRAY 8  

typedef int AElemType;
typedef struct {
    AElemType *base;
    int dim;
    int *bounds; // array dim number 维度基地址
    int *constants;//数组映像函数常量地址
}Array;

Status InitArray(Array *A, int dim, ...);
#endif 