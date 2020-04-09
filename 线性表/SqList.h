#include "stdlib.h" 
#include "stdio.h"

#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define INFEASIBLE -1
#define YES 1
#define NO 1
typedef int Status;
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

