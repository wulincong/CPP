#include "SequenceStack.h"


void conversion(int i){
    SqStack S;
    SElemType_Sq e;
    InitStack_Sq(&S);
    while (i){
        Push_Sq(&S, i % 8);
        i = i / 8;
    }
    //printf("十进制%d转换为八进制之后为：", i);
    while(!StackEmpty_Sq(S)){
        Pop_Sq(&S, &e);
        printf("%d", e);
    }
}


int main(int argc, char **argv){
    int N;
    N = atoi(argv[1]);
    conversion(N);
    return 0;
}