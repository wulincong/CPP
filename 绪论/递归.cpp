#include <stdio.h>

int sum(int A[],int n);

int main(){
    int A[] = {1,2,3,4,5,6,7,8};
    int S;
    S = sum(A,8);
    printf("%d\n",S);
}
//线性递归
int sum(int A[],int n){
    return 
        (n<1)?
        0:sum(A,n-1)+A[n-1];    
}

