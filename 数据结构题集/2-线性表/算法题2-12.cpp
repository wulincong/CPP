#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char *elem;
	int length;
	int listsize;
} SqList;

int SqList_Init(SqList &L);
int SqList_Increment(SqList &L);
int SqList_Add(SqList &L,char a);
int SqList_View(SqList &L);
int	 compare(SqList &LA,SqList &LB);

main(){
	char a[] = "abcdef";
	int i,res;
	int len;
	SqList LA,LB;
	SqList_Init(LA);
	SqList_Init(LB);
	//if('b'>'a')printf("b\n");
	len = sizeof(a)/sizeof(a[0])-1;
	for(i = 0;i<len;i++){
		SqList_Add(LA,a[i]);
	}
	for(i = 0;i<len;i++){
		SqList_Add(LB,a[i]);
	}
	res = compare(LA,LB);
	printf("%d\n",res);
	SqList_View(LA);
	SqList_View(LB);
} 

int SqList_Init(SqList &L){
	char *database;
	database = (char *)malloc(sizeof(char)*100);
	if(!database) exit(0);
	L.elem = database;
	L.length = 0;
	L.listsize = 100;
	return 1;
}

int SqList_Increment(SqList &L){
	char *newbase;
	newbase = (char *)realloc(L.elem,sizeof(char)*(L.listsize + 10));
	if(!newbase) exit(0);
	L.elem = newbase;
	L.listsize +=10;
	return 1;
}

int SqList_Add(SqList &L,char a){
	if(L.length == L.listsize) SqList_Increment(L);
	L.elem[L.length] = a;
	L.length+=1;
	return 1;
}

int SqList_View(SqList &L){
	int i;
	for(i = 0;i<L.length;i++){
		printf("%c,",L.elem[i]);
	}
	printf("\n");
	return 1;
}

int	 compare(SqList &LA,SqList &LB){
	int lenA = LA.length;
	int lenB = LB.length;
	int i = 0; 
	while(lenA & lenB){
		if(LA.elem[i] == LB.elem[i]){
			i++;
			lenA--;
			lenB--;
		}
		else if(LA.elem[i]>LB.elem[i]) return 1;
	 	else return 2;
	}
	if(lenA == lenB)return 0;
	if(lenA == 0)return 2;
	if(lenB == 0)return 1;
}
