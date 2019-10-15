#include "stdio.h"
#include "stdlib.h"

typedef int Status;
#define OK 1
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

Status LinkList_Data_Init(ListLink L){
	LinkList p;
	int j;
	p = L->next;
	j = 1;
	p->
	
}

int main(){
    LNode L;
    LinkList p;
   	//printf("hello!");
   	p = &L;
   	LinkList_Data_Init(p);
   	//printf("%d:%d\n",&L,sizeof(L));
	//printf("%d:%d\n",&p,sizeof(p));	
}

