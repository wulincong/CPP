#include <stdio.h>

int sum(int A[],int lo, int hi){
    if(lo == hi) return A[lo];
    int mi = (lo+hi)>>1;
    return sum(A,lo,mi) + sum(A,mi+1,hi);

}

int main(){
    int A[] = {1,2,3,4,5,6,7,8};
    int S = sum(A,0,7);
    printf("%d\n",S);
    return 0;
}

