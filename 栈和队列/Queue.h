#ifndef _QUEUE_H
#define _QUEUE_H
#include "../绪论/Status.h"
typedef int datatype;

typedef struct {
    datatype *data;
    int front;
    int rear;
} SqQueue;

typedef struct QNode{
    datatype data;
    struct QNode *next;
}QNode;

typedef struct{
    QNode *front;
    QNode *rear;
}LiQueue;

#endif