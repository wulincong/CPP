#ifndef BINARYTREE
#define BINARYTREE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Status.h"
#include "Scanf.h"
typedef char TElemType;
typedef struct BiTNode{
    TElemType data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode;

typedef BiTNode* BiTree;
typedef BiTNode SElemType_Sq;
#include "SequenceStack.h"



#endif