#include "stdio.h"
#include "stdlib.h"
#define DATATYPE int

typedef int Status;
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef struct LNode{
    DATATYPE data;
    struct LNode *next;
}LNode,*LinkList;
#include "SqList.h"

