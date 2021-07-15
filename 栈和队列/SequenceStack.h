/*
顺序栈相关操作列表
*/

#ifndef SEQUENCESTACK_H
#define SEQUENCESTACK_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10 

#ifndef SElemType_Sq

#define SElemType_Sq int

#endif

typedef struct {
    SElemType_Sq *base;
    SElemType_Sq *top;
    int stackSize;
}SqStack;

Status InitStack_Sq(SqStack *S);
Status DestroyStack_Sq(SqStack *S);
Status ClearStack_Sq(SqStack *S);
Status StackEmpty_Sq(SqStack S);
int StackLength_Sq(SqStack S);
Status GetTop_Sq(SqStack S, SElemType_Sq *e);
Status Push_Sq(SqStack *S, SElemType_Sq e);
Status Pop_Sq(SqStack *S, SElemType_Sq *e);

Status StackTraverse_Sq(SqStack S, void(Visit)(SElemType_Sq));
//访问栈


#endif