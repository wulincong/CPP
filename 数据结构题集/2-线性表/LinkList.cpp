#include <stdio.h>
#include <stdlib.h>

typedef int Status;
#define ERROE 0
#define INFEASIBLE -4
#define OK 1
#define OVERFLOW -2

typedef struct LNode{
	int data;
	struct LNode *next;
} LNode,*LinkList;

Status LinkList_Init(LinkList &L,int n){
	LinkList p;
	int i,a;
	L = (LinkList)malloc(sizeof(LNode));
	p = L;
	for(i = 1;i <= n;i++){
		p->next = (LinkList)malloc(sizeof(LNode));
		p = p->next;
		printf(">>>");
		scanf("%d",&a);
		p->data = a;
	}
	p->next = NULL;
	return OK;
}

Status LinkList_View(LinkList &L){
	LinkList p;
	p = L;
	while(p->next){
		p = p->next;
		printf("%d,",p->data);
	}
	return OK;
}
