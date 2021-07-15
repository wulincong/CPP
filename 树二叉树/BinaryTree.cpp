#include <stdio.h>
#include <stdlib.h> 
#include "../xulun/Status.h"

typedef struct BTNode{
	char data;
	struct BTNode *lchild;
	struct BTNode *rchild;
} BTNode,*BTree;


Status InitBiTree(BTree &T){ 
	//Init empty Binary Tree
	if(! (T = (BTNode *)malloc(sizeof(BTNode)))) exit(OVERFLOW);
	T->data = ' ';
	T->lchild = NULL;
	T->rchild = NULL;
	return OK;
}

Status CreateBiTree(BTree &T){
	char ch;
	ch = getchar();
	if(ch == '^') T = NULL;
	else{
		if(! (T = (BTNode *)malloc(sizeof(BTNode)))) exit(OVERFLOW);
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}

Status Visit(BTree & p){
	putchar(p->data);	
	return OK;
} 

void preorder(BTree &T){
	if(T != NULL){
		Visit(T);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

int GetDepth(BTree &T){
	if(T){
		int LTreeDepth = GetDepth(T->lchild);
		int RTreeDepth = GetDepth(T->rchild);
		return (LTreeDepth > RTreeDepth ? LTreeDepth:RTreeDepth)+1;
	}
	return 0;
}

Status Search(BTree &T,BTree &N,char e){
	if(T && T->data == e) {
		N = T;
		return OK;
	}
	else {
		if(Search(T->lchild,N,e)) return OK;
		if(Search(T->rchild,N,e)) return OK;
	}
	return ERROR;
}

void level(BTree &T){
	int front,rear;
	front = rear = 0;
	BTNode *que[100];
	BTree q;
	if(T != NULL){
		rear = (rear+1)%100; que[rear] = T;  //Init the first node 
		while(front != rear){
			front = (front + 1) % 100; q = que[front]; 
			Visit(q);
			if(q->lchild){
				rear = (rear + 1) % 100;que[rear] = q->lchild;
			}
			
			if(q->rchild){
				rear = (rear + 1) % 100;que[rear] = q->rchild;
			}
		}
	}
}

int main(){
	BTree T;
	FILE *fp;
	fp = fopen("Tree.txt","r");
	InitBiTree(T);	
	CreateBiTree(T);
	preorder(T);
	level(T);
	int Depth = GetDepth(T);
	printf("\nThe depth of the BinaryTree is %d\n",Depth);

	char e = 'G';
	BTree N = NULL;
	//if(Search(T,N,e)) printf("Find it!\n");

	return 0;
}
