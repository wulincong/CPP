#include <stdio.h>
#include <stdlib.h> 
#include "../xulun/Status.h"

typedef struct BTNode{
	char *data;
	struct BTNode *lchild;
	struct BTNode *rchild;
} BTNode,*BTree;


Status InitBiTree(BTree &T){ 
	//Init empty Binary Tree
	if(! (T = (BTNode *)malloc(sizeof(BTNode)))) exit(OVERFLOW);
	T->data = "";
	T->lchild = NULL;
	T->rchild = NULL;
	return OK;
}

Status CreateBiTree(BTree &T,FILE &fp){
	char *ch;
	
	scanf("%s",&ch);
	printf("%s",&ch);
	if(!ch) T = NULL;
	else{
		if(! (T = (BTNode *)malloc(sizeof(BTNode)))) exit(OVERFLOW);
		T->data = ch;
		CreateBiTree(T->lchild,fp);
		CreateBiTree(T->rchild,fp);
	}
	return OK;
}

Status Visit(BTree & p){
	printf("%c",& p->data);	
} 

void preorder(BTree &T){
	if(T != NULL){
		Visit(T);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

int main(){
	BTree T;
	FILE *fp;
	fp = fopen("Tree.txt","r");
	InitBiTree(T);	
	CreateBiTree(T,fp);
	preorder(T);
	return 0;
}
