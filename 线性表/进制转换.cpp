#include "stdio.h" 
#include "stdlib.h"

typedef int Status;
#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define STACKINITSIZE 100
#define INCREMENT 10

typedef struct{
	int *top;
	int *base;
	int StackSize;
} Stack;

Status StackInit(Stack &S){
	S.base = (int *)malloc(sizeof(int)*STACKINITSIZE);
	if (!S.base) return OVERFLOW;
	S.top = S.base;
	S.StackSize = 100;
}

Status Push(Stack &S,int e){
	*S.top = e;
	S.top++;
}

int Pop(Stack &S){
	if(S.top > S.base) return *--S.top; 	
	return ERROR; 
}

main(){
	int num,e,i = 0; 
	Stack S;
	StackInit(S);
	printf("请输入一个数>>>");
	scanf("%d",&num);
	while(num){
		printf("push(%d)\n",num%8);
		Push(S,num % 8);
		num = num/8;
		i++;
	}
	while(i){
		printf("%d",Pop(S));
		i--;
	}
}
