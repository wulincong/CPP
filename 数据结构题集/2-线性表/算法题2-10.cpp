#include "SqList.cpp"

Status DeleteK(SqList &a,int i,int k);

main(){
	int i = 1;
//	printf("hello\n");
	SqList L;
	printf("初始化线性表..\n");
	SqList_Init(L);
	printf("数据写入..\n");
//	SqList_Append(L,1);
//	printf("%d\n",L.elem[0]);]
	for(i;i<=1000;i++){
		SqList_Append(L,i);
	}
	SqList_View(L);
	DeleteK(L,1,10);
	SqList_View(L);
}

Status DeleteK(SqList &a,int i,int k){
	//从线性表a中删除第i个元素起的k个元素
	int n = a.length-i-k+1;
	if(not (0<i<=a.length && 0<k<=a.length-i+1)) return ERROE;  //没有第0个元素，而且
	while(n>0){
		a.elem[i-1] = a.elem[i+k-1];
		i++;
		n--;
	}
	a.length = a.length-k;
	return OK;
} 
