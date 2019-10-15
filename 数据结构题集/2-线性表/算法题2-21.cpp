#include "SqList.cpp"
Status SqList_Reverse(SqList &L);
int main(){
	SqList L;
	SqList_Init(L);
	int i;
	int e;
	for(i = 0;i<6;i++){
		printf(">>>");
		scanf("%d",&e);
		SqList_Append(L,e);
	}
	SqList_View(L);
	SqList_Reverse(L);
	SqList_View(L);
	return 0;
}

Status SqList_Reverse(SqList &L){
	int e = 0;
	int a = 0;
	int b = L.length-1;
	while(a<=b){
		e = L.elem[a];
		L.elem[a] = L.elem[b];
		a++;
		L.elem[b] = e;
		b--;
	}
	return OK;
}







