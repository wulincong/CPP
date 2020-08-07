#include <stdio.h>

void max2(int A[],int lo,int hi,int & x1,int & x2){
    if(lo + 1 == hi){//共二个元素
        A[lo] > A[hi] ? x1 = lo,x2 = hi : x1 = hi,x2 = lo;
        return;
    }
    if(lo + 2 == hi){//共三个元素
        A[lo] > A[hi] ? x1 = lo,x2 = hi : x1 = hi,x2 = lo;
        if(A[x2] > A[lo+1]) return;
        A[x1] > A[lo+1] ? x2 = lo+1:x2 = x1,x1 = lo+1;
        return;
    }
    int mi = (lo + hi) / 2;
    int x1L,x2L;
    max2(A,lo,mi,x1L,x2L);
    int x1R,x2R;
    max2(A,mi,hi,x1R,x2R);
    if(A[x1L] > A[x1R]){
        x1 = x1L; x2 = (A[x2L] > A[x1R]) ? x2L:x1R;
    }else{
        x1 = x1R; x2 = (A[x1L] > A[x2R]) ? x1L:x2R;
    }
}


int main(){
    int A[] = {0,1,2,3,4,5,6,7,8};
    int lo = 0,hi = 8;
    int x1,x2;
    max2(A,lo,hi,x1,x2);
    printf("%d,%d\n",x1,x2);
    return 0;


}




