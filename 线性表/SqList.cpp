#include "SqList.h"

Status List_Init(SqList *L){
	L->elem = (int *)(malloc(LIST_INIT_SIZE*sizeof(int)));
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

Status List_Insert(SqList *L,int i,int e){
	int *p,*q,*newbase;
	if(i<0||i>L->length+1) return ERROR;
	if(L->length >= L->listsize){
		newbase = (int *)(realloc(L->elem,(L->listsize + LISTINCREMENT)*sizeof(int)));
		//if(!newbase)exit OVERFLOW;
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}
	p = &L->elem[i-1];
	for(q = &L->elem[L->length-1];q<=p;q++){
		*(q+1) = *q;
	}
	*p = e;
	L->length++;
	return OK;
}

Status List_View(SqList *L){
	int *p;
	int i = 0;
	p = &L->elem[0];
	printf("L->elem = %d id = %d\n",L->elem,&L->elem);
	printf("L->length = %d id = %d\n",L->length,&L->length);
	printf("L->listsize = %d id = %d\n",L->listsize,&L->listsize);
	for(i;i<L->length;i++){
		printf("%d   ",*p);
		printf("id = %d\n",p);
		p++;
	};
	return OK;
}

Status SqList_test(){
	SqList MyList;
	int m = 0,n,i,e;
	char a;
	Status S;
	List_Init(&MyList);
	printf("Insert the Data\n");
	printf("Please chose the number of data");
	scanf("%d",&n);
	while(m < n){
		m++;
		printf("Use\",\" to split id and data >>>");
		scanf("%d,%d",&i,&e);
		S = List_Insert(&MyList,i,e);
		if (S != OK){
			printf("ERROR\n");
			m--;
		}
	};
	List_View(&MyList);
	return OK;
}

void Swap(int *List,int a,int b){
	int i;
	i = List[a];
	List[a] = List[b];
	List[b] = i;
}

//设计一个算法，讲L中所有小于表头元素的整数放在前半部分，大于表头元素的整数放在后半部分
Status HeadReverse(){
	SqList L;
	int l[] = {5,1,2,3,4,6,7,1,2};
	L.elem = l;
	L.length = 9;
	L.listsize = 9;
	int i = 0;
	for (size_t j = 1; j < 9; j++)
	{
		if (L.elem[i] > L.elem[j] )
		{
			Swap(L.elem,i+1,j);
			Swap(L.elem,i,i+1);
			i = i+1;
		}
	}
	List_View(&L);
	return OK;
}

main(){
	SqList_test();
	HeadReverse();
	return 0;
}
