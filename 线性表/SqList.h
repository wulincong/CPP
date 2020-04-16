#include "stdlib.h" 
#include "stdio.h"
#include "Status.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define LElemType_Sq int

typedef	 struct{
	LElemType_Sq *elem;
	int length;
	int listsize;
} SqList;

typedef struct answer{
	int max, min;
} answer;

answer Max_Min(SqList *L);
Status List_Init(SqList *L);
Status ListEmpty_Sq(SqList *L);
Status GetElem_Sq(SqList *L,int i,LElemType_Sq *e);
Status PriorElem_Sq(SqList *L,LElemType_Sq cur_elem,LElemType_Sq *pre_elem);
Status NextElem_Sq(SqList *L,LElemType_Sq cur_elem,LElemType_Sq *next_elem);
Status List_Insert(SqList *L,int i,int e);
Status List_Delete_Sq(SqList *L,int i,LElemType_Sq *e);
Status ListTraverse_Sq(SqList *L);
Status List_View(SqList *L);
Status SqList_test();
Status HeadReverse();
extern Status answer_42_4(SqList *A,SqList *B);
int ListLength_Sq(SqList *L);
void Clear_Sq(SqList *L);
void DestroyList_Sq(SqList *L);
int LocateElem_Sq(SqList *L,LElemType_Sq e);
void Swap(int *List,int a,int b);
//设计一个算法，讲L中所有小于表头元素的整数放在前半部分，大于表头元素的整数放在后半部分
void test_Max_Min();
Status test_answer_42_4();
