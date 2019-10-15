#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100
#define LISTINCREAMENT 10

typedef int Status;
#define ERROE 0
#define INFEASIBLE -4
#define OK 1
#define OVERFLOW -2

typedef struct{
	int *elem;
	int length;
	int listsize;
} SqList;

Status SqList_Init(SqList &L){
	L.elem = (int *)malloc(sizeof(int) * LIST_INIT_SIZE);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}

Status SqList_Append(SqList &L,int i){
	if(L.length == L.listsize) {
		L.elem = (int *)realloc(L.elem,sizeof(int) * (L.listsize + LISTINCREAMENT));
		L.listsize += LISTINCREAMENT;
	};
	L.elem[L.length] = i;
	L.length++;
}

Status SqList_View(SqList &L){
	int i = 0;
	for(i;i<L.length;i++)printf("%d,",L.elem[i]);
	printf("\n");
}

Status SqList_ListSize_Increament(SqList &L){
	L.elem = (int *)realloc(L.elem,sizeof(int) * (L.listsize + LISTINCREAMENT));
	L.listsize += LISTINCREAMENT;
	return OK;
}

