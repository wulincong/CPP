#include "LinkList.cpp"

LinkList LinkList_comban(LinkList &La,LinkList &Lb);

int main(){
    LinkList La,Lb,Lc;
    int m,n;
    m = 5;n = 4;
    printf("La:");
    LinkList_Init(La,m);
    LinkList_View(La);
    printf("\n");
    printf("Lb:");
    LinkList_Init(Lb,n);
    LinkList_View(Lb);
    printf("\n");
    Lc = LinkList_comban(La,Lb);
    LinkList_View(Lc);
    return 0;
}

LinkList LinkList_comban(LinkList &La,LinkList &Lb){
    int m=1,n=1;
    LinkList pa,pb;
    pa = La->next;
    pb = Lb->next;
    while (pa->next)
    {
        pa = pa->next;
        m++;
    }
    while (pb->next)
    {
        pb = pb->next;
        n++;
    }
    if(m<=n){
        pa->next = Lb->next;
        return La;
    }
    pb->next = La->next;
    return Lb;
}
