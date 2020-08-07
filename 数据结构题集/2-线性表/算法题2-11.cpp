#include "SqList.cpp"

Status Insert(SqList &va,int x);

main(){
	//printf("hello\n");
	SqList L;
	int i;
	SqList_Init(L);
	SqList_Append(L,1);
	SqList_Append(L,2);
	SqList_Append(L,3);
	SqList_Append(L,5);
	SqList_Append(L,6);
	SqList_Append(L,7);
	SqList_Append(L,8);
	SqList_View(L);
	Insert(L,4);
	Insert(L,4);
	Insert(L,9);
	Insert(L,1);
	Insert(L,0);
	SqList_View(L);
	for(i = 0;i<200;i++){
		Insert(L,i);
	}
	SqList_View(L);
} 

Status Insert(SqList &va,int x){
	int i;
	int j;
	int *newbase;
	if(va.length == va.listsize){
		newbase = (int *)realloc(va.elem,sizeof(int) * (va.listsize + LISTINCREAMENT));
		if(!newbase) exit(OVERFLOW);
		va.elem = newbase;
		va.listsize += LISTINCREAMENT;
	}
	i = 0;
	j = va.length;
	while(x>=va.elem[i] && i<va.length)i++;
	while(i < j){
		va.elem[j] = va.elem[j-1];
		j--;
	}
	va.elem[i] = x;
	va.length++;
	return OK;
}
