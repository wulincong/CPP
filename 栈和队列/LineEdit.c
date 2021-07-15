#include "SequenceStack.h"

void Print(SElemType_Sq e){
    printf("%c", e);
}

void LineEdit(char buffer[]){
    SqStack S;
    SElemType_Sq e;
    int i;
    char *ch;
    InitStack_Sq(&S);
    i = 0;
    ch = buffer;
    while(*ch != '\0'){
        while(*ch != '\0' && *ch != '\n'){
            switch(*ch){
                case '#':Pop_Sq(&S, &e);
                    break;
                case '@':ClearStack_Sq(&S);
                    break;
                default: Push_Sq(&S, *ch);
            }
            ch++;
            // printf("%c", *ch);
        }
        if(*ch == '\n'){
            Push_Sq(&S, *ch);
            StackTraverse_Sq(S, Print);
            ClearStack_Sq(&S);
            ch++;
        }
    }
    if(*ch == '\0'){
        StackTraverse_Sq(S,Print);
        DestroyStack_Sq(&S);
    }
}

int main(int argc, char **argv){
    char *buffer = "whil##ilr#e(s#*s)\noutchar@  putchar(*s=#++);";
    LineEdit(buffer);
    return 0;
}