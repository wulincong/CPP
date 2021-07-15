#include "SequenceStack.h"

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