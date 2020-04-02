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

