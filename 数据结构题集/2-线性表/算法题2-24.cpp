#include "LinkList.cpp"

LinkList LinkList_combine(LinkList &La,LinkList &Lb);


int main(){
    LinkList La,Lb,Lc;
    printf("La\n");
    LinkList_Init(La,5);
    printf("Lb\n");
    LinkList_Init(Lb,4);
    printf("\n");
    Lc = LinkList_combine(La,Lb);
    LinkList_View(Lc);
}

LinkList LinkList_combine(LinkList &m,LinkList &n){
    LinkList La,Lb,Lc;
    LinkList i,j,k,p,q,r;
    if (m->next->data <= n->next->data){
        La = m;Lb = n;
    }
    else{
        La = n;Lb = m;
    }
    
    i = La->next;
    j = La->next->next;
    k = La->next->next->next;
    p = Lb->next;
    q = Lb->next->next;

    while (1) 
    {
        while(i->data <= p->data && p->data <= j->data ){
            p->next = i;
            i = p;
            j->next = p;
            p = q;
            if (! p)break;
            q = q->next;
        }
        if(!p  && !i->next) break;
        i = j;j = k;k = k->next;
    }
//###############$####################$############
    La->next->next = NULL;
    if (k->next){
        while (k->next){
            j->next = i;
            i = j;j = k;k = k->next;
        }
        printf("OVER!\n");
        k->next = j;
        Lc->next = k;
        return Lc;
    }
    else if (q->next)
    {
        r = q->next;
        while (r->next)
        {
            q->next = p;
            p = q;q = r;r = r->next;
        }
        printf("OVER!\n");
        r->next = q;
        Lc->next = r;
        return r;
    }
    printf("OVER!\n");
    j->next = i;
    k->next = j;
    Lc->next = k;
    return Lc;
}

