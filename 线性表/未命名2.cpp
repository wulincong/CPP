#include "stdlib.h" 
#include "stdio.h"

#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define INFEASIBLE -1
typedef int Status;
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef	 struct{
	int *elem;
	int length;
	int listsize;
} SqList;

Status List_Init(SqList *L){
	L->elem = (int *)(malloc(LIST_INIT_SIZE*sizeof(int)));
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

Status List_Insert(SqList *L,int i,int e){
	int *p,*q,*newbase;
	if(i<0||i>L->length+1) return ERROR;
	if(L->length >= L->listsize){
		newbase = (int *)(realloc(L->elem,(L->listsize + LISTINCREMENT)*sizeof(int)));
		//if(!newbase)exit OVERFLOW;
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}
	p = &L->elem[i-1];
	for(q = &L->elem[L->length-1];q<=p;q++){
		*(q+1) = *q;
	}
	*p = e;
	L->length++;
	return OK;
}

Status List_View(SqList *L){
	int *p;
	int i = 0;
	p = &L->elem[0];
	printf("L->elem = %d id = %d\n",L->elem,&L->elem);
	printf("L->length = %d id = %d\n",L->length,&L->length);
	printf("L->listsize = %d id = %d\n",L->listsize,&L->listsize);
	for(i;i<L->length;i++){
		printf("%d",*p);
		printf("id = %d\n",p);
		p++;
	};
}

main(){
	SqList MyList;
	int m = 0,n,i,e;
	char a;
	Status S;
	List_Init(&MyList);
	printf("插入数据\n");
	printf("请输入插入数据数量");
	scanf("%d",&n);
	while(m < n){
		m++;
		printf("请输入位置和数值并用,隔开>>>");
		scanf("%d,%d",&i,&e);
		S = List_Insert(&MyList,i,e);
		if (S != OK){
			printf("您输入的数据有误，请重新输入\n");
			m--;
		}
	};
	List_View(&MyList);
}
