#include "SqList.cpp"

Status DeleteK(SqList &a,int i,int k);

main(){
	int i = 1;
//	printf("hello\n");
	SqList L;
	printf("��ʼ�����Ա�..\n");
	SqList_Init(L);
	printf("����д��..\n");
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
	//�����Ա�a��ɾ����i��Ԫ�����k��Ԫ��
	int n = a.length-i-k+1;
	if(not (0<i<=a.length && 0<k<=a.length-i+1)) return ERROE;  //û�е�0��Ԫ�أ�����
	while(n>0){
		a.elem[i-1] = a.elem[i+k-1];
		i++;
		n--;
	}
	a.length = a.length-k;
	return OK;
} 
