#ifndef TRIPLESPARSEMATRIX_H
#define TRIPLESPARSEMATRIX_H

#include <stdio.h>
#include <stdarg.h>
#include "Status.h"
#include "Scanf.c"

#define MAXSIZE 400 

typedef int MElemType;

typedef struct {
    int i,j;
    MElemType e;
} Triple;

typedef struct {
    Triple data[MAXSIZE+1]; // data[0] not used
    int mu,nu,tu;
} TSMatrix;

Status CreateSMatrix_T(FILE *fp,int n,...);






#endif 