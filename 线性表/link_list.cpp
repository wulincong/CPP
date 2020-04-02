#include "LinkList.h"

Status LinkList_Data_Init(LinkList L,int n,DATATYPE *DataList){
	LinkList p = L;
	int j = 0;
	for(j = 0;j<n;j++){
		LinkList Node = (LinkList)malloc(sizeof(LNode));
		p->next = Node;
		Node->data = DataList[j];
		p = p->next;
	}
	p->next = NULL;
	return OK;
}

Status LinkList_View(LinkList &L){
	LinkList p = L->next;
	while(p){
		printf("%d,",p->data);
		p = p->next;
	}
	return OK;
}



int main(){
    LNode L;
    LinkList p;
   	//printf("hello!");
   	p = &L;
	DATATYPE DataList[5] = {1,2,3,4,5};
   	LinkList_Data_Init(p,5,DataList);
	LinkList_View(p);

	return 0;
}

