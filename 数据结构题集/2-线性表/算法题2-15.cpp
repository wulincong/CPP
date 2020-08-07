#include "LinkList.cpp" 
Status bond(LinkList &ha,LinkList &hb,LinkList &hc,int a,int b);
main(){
	LinkList ha,hb,hc;
	int a = 5,b = 4;
	printf("ha\n");
	LinkList_Init(ha,a);

	printf("\nhb\n");
	LinkList_Init(hb,b);

	bond(ha,hb,hc,a,b);
	LinkList_View(hc);
}

Status bond(LinkList &ha,LinkList &hb,LinkList &hc,int a,int b){
	LinkList pa,pb,p;
	pa = ha->next;
	pb = hb->next;
	if(a <= b){
		p = pa;
		while(p->next)p = p->next;
		p->next = pb;
		hc = ha;
	}
	else{
		p = pb;
		while(p->next)p = p->next;
		p->next = pa;
		hc = hb;
	}
	return OK;
}
