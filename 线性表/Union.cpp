#include "Union.h"

Status 
Union(SqList *La,SqList *Lb){
    int La_len = ListLength_Sq(La);    
    int Lb_len = ListLength_Sq(Lb);
    LElemType_Sq e;
    for (size_t i = 0; i < Lb_len; i++)
    {
        GetElem_Sq(Lb,i+1,&e);
        if(!LocateElem_Sq(La,e))
            List_Insert(La,++La_len,e);
    }
    return OK;
}

int main(){
    SqList La,Lb;
    LElemType_Sq a[5] = {5,2,1,3,9};
    LElemType_Sq b[7] = {7,2,6,9,11,3,10};
    List_Init(&La);
    for (size_t i = 0; i < 5; i++) List_Insert(&La,i+1,a[i]);
    List_Init(&Lb);
    for (size_t i = 0; i < 7; i++) List_Insert(&Lb,i+1,b[i]);
    printf("La = ");
    ListTraverse_Sq(&La);
    printf("\n");
    printf("Lb = ");
    ListTraverse_Sq(&Lb);
    printf("\n\n");

    printf("La = La U Lb = ");
    Union(&La,&Lb);
    ListTraverse_Sq(&La);
    printf("\n");
    return 0;
}
