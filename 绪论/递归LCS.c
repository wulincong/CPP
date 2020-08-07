#include <stdio.h>

// 对于字符串A[0,m] B[0,n],有三种情形
//
//1. m == -1 || n == -1 即A、B其中一个为空字符串，此为递归基
//
//2. A[m] == B[n] 字符串的最后一个字符相同，问题缩减
//    LCS(A,B) = LCS(A[0,m),B[0,n)) + 1
//
//3. A[m] != B[n] 即最后一个字符不相同，此时需要分为两种情况，考察去掉A[m]
//   或去掉B[n]哪个更长，因此
//    LCS(A,B) = Max{ LCS(A[0,m],B[0,n)) , LCS(A[0,m),B[0,n])}

int LCS(char *A,char *B,int m, int n){
    if(m == -1 || n == -1 ) return 0;
    if(A[m] == B[n]) return LCS(A,B,m-1,n-1) + 1;
    int a = LCS(A,B,m,n-1),b =  LCS(A,B,m-1,n);
    return a > b ? a : b;
}



int main(){
    int m = 7,n = 8;
    char *A = "aaaabaaa";
    char *B = "aaaaaaaaa";

    int LCS_result = LCS(A,B,m,n);
    printf("%d\n",LCS_result);

    return 0;

}
