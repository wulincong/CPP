#include "Stack.h"

SqStack * SqStack_Create(int max_size){
    SqStack *st;
    if ((st = (SqStack *)malloc(sizeof(SqStack))) == NULL){
        printf("malloc failed\n");
        return NULL;
    };
    datatype *d;
    if ((d = (datatype*) malloc(sizeof(datatype)*max_size)) == NULL){
        printf("malloc failed\n");
        return NULL;
    }
    st->MaxSize = max_size;
    st->data = d;
    st->top = -1;
    return st;
}

Status SqStack_Empty(SqStack *st){
    return st->top == -1 ? 1:0;
}

Status SqStack_Full(SqStack *st){
    return st->top == st->MaxSize -1 ? 1:0;
}

Status SqStack_Push(SqStack *st){

}

Status SqStack_Pop(SqStack *st){

}


