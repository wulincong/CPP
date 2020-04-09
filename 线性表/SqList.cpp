#include "SqList.h"

Status 
List_Init(SqList *L){
	L->elem = (int *)(malloc(LIST_INIT_SIZE*sizeof(LElemType_Sq)));
	if(!L->elem) exit(OVERFLOW);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

void 
Clear_Sq(SqList *L){
	L->length = 0;
}

void 
DestroyList_Sq(SqList *L){
	free(L->elem);
	L->elem = NULL;
	L->length = 0;
	L->listsize = 0;
}

Status 
ListEmpty_Sq(SqList *L){
	return L->length == 0 ? YES : NO; 
}

int 
ListLength_Sq(SqList *L){
	return L->length;
}

Status 
GetElem_Sq(SqList *L,int i,LElemType_Sq *e){
	if (i<1 || i>L->length) return ERROR;
	else *e = L->elem[i-1];
	return OK;
}

int 
LocateElem_Sq(SqList *L,LElemType_Sq *e){
	int i = 1;
	while (i<L->length && ! (L->elem[i-1] == *e)) ++i;
	if (i<=L->length) return i;
	else return 0;
}

Status 
PriorElem_Sq(SqList *L,LElemType_Sq cur_elem,LElemType_Sq *pre_elem){
	int i = 1;
	if(L->elem[0] != cur_elem){
		while (i<L->length && L->elem[i] != cur_elem) ++i;
		if (i<L->length) {
			*pre_elem = L->elem[i-1];
			return OK;
		}
	}
	return ERROR;
}

Status 
NextElem_Sq(SqList *L,LElemType_Sq cur_elem,LElemType_Sq *next_elem){
	int i = 1;
	while (i < L->length && cur_elem != L->elem[i]) ++i;
	if (i<L->length-1) {
		*next_elem = L->elem[i+1];
		return OK;
	}
	return ERROR;
}



Status 
List_Insert(SqList *L,int i,int e){
	int *p,*q,*newbase;
	if(i<0||i>L->length+1) return ERROR;
	if(L->length >= L->listsize){
		newbase = (int *)(realloc(L->elem,(L->listsize + LISTINCREMENT)*sizeof(LElemType_Sq)));
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

Status 
List_View(SqList *L){
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

Status 
SqList_test(){
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

void 
Swap(int *List,int a,int b){
	int i;
	i = List[a];
	List[a] = List[b];
	List[b] = i;
}

//设计一个算法，讲L中所有小于表头元素的整数放在前半部分，大于表头元素的整数放在后半部分
Status 
HeadReverse(){
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



/*
answer Max_Min(SqList *L){
	int l[L->length];
	answer ans;
	int len = 0;
	for (size_t i = 0; i < L->length/2; i++)
	{
		if(L->elem[i]-L->elem[i+1]>0){
			l[i] = L->elem[i];
			l[i+1] = L->elem[i+1];
			len++;
		}
		else{
			l[i] = L->elem[i+1];
			l[i+1] = L->elem[i];
			len++;
		}
	}
	while (len!=2){
		for(size_t i = 0; i < len/4;i++){
			i*=4;
			if (l[i]-l[i+2]>0) l[i] = l[i+2];
			if (l[i+1]-l[i+3]<0) l[i+1] = l[i+3];
			len /= 2;
		}
	}
	if(L->length % 2 == 1){
		if(L->elem[L->length] < l[0]) l[0] = L->elem[L->length];
		if(L->elem[L->length] > l[1]) l[1] = L->elem[L->length];
	}
	ans.min = l[0];
	ans.max = l[1];
	return ans;
}
*/

answer 
Max_Min(SqList *L){
	answer ans;
	ans.min = ans.max = L->elem[0];
	for (size_t i = 0; i < L->length; i++)
	{
		if (L->elem[i] < ans.min) ans.min = L->elem[i];
		else if (L->elem[i] > ans.max) ans.max = L->elem[i];
	}
	return ans;
}

void 
test_Max_Min(){
	SqList L;
	int l[] = {5,1,2,3,4,6,7,1,2};
	L.elem = l;
	L.length = 9;
	L.listsize = 9;
	answer ans = Max_Min(&L);
	printf("the min number of L is %d\n",ans.min);
	printf("the max number of L is %d\n",ans.max);
}

Status 
answer_42_4(SqList *A,SqList *B){
	int n = A->length < B->length ? A->length : B->length;
	int flag = 0; // A == B flag = 0 A>B flag = 1 A<B flag = 2
	for(int i = 0; i < n;i++){
		if(A->elem[i] == B->elem[i]) continue;
		else if(A->elem[i]>B->elem[i]) {
			flag = 1;
			printf("A>B\n");
			break;}
		else {
			flag = 2;
			printf("A<B\n");
			break;
		}
	}
	if (flag == 0 & A->length == B->length) printf("A = B\n");
	else if (flag == 0 & A->length > B->length) printf("A>B\n");
	else if (flag == 0 & A->length < B->length) printf("A<B\n");
	return flag;
}

void 
test_answer_42_4(){
	SqList A;
	int l[] = {5,1,2,3,4,6,7,1,2};
	A.elem = l;
	A.length = 9;
	A.listsize = 9;
	SqList B;
	int l2[] = {6,1,2,3,4,6,7,1,};
	B.elem = l2;
	B.length = 8;
	B.listsize = 9;
	answer_42_4(&A, &B);
}


int main(){
	// SqList_test();
	// HeadReverse();
	// test_Max_Min();
	test_answer_42_4();
	return 0;
}
