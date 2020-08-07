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

void test_for_LinkList_View(){
	LNode L;
    LinkList p;
   	//printf("hello!");
   	p = &L;
	DATATYPE DataList[5] = {1,2,3,4,5};
   	LinkList_Data_Init(p,5,DataList);
	LinkList_View(p);
}

Status answer_42_1(LinkList &L, int k){
	int d = 0;
	LinkList p1 = L->next;
	LinkList p2 = L->next;
	while(p1){
		if (d<k)
		{
			p1 = p1->next;
			d++;
		}
		else if(d == k){
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	if(d == k){
		printf("%d,",p2->data);
		return OK;	
	}
	return 0;	
}

void test_answer_p42_1(){
	LNode L;
    LinkList p;
   	//printf("hello!");
   	p = &L;
	DATATYPE DataList[5] = {1,2,3,4,5};
   	LinkList_Data_Init(p,5,DataList);
	answer_42_1(p,3);
}


int main(){
	// test_for_LinkList_View();
	test_answer_p42_1();
	return 0;
}

