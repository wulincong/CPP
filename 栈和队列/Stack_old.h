#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "../绪论/Status.h"

#define datatype int

//SqStack 
typedef struct {
	datatype *data;
	int MaxSize;
	int top;
} SqStack;

//LNode 
typedef struct LNode{ 
	int data;
	struct LNode *next;
} LNode;

#endif
