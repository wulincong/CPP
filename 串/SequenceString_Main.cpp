#include "SequenceString.h"
#include "KMP.h"
int main(int argc, char *argv[]){
    Str str;
    char s[] = "abc";

    printf("str = abc\n");
    StrAssign(str, s);
    StrPrint_Sq(str);

    printf("Union str and str:");
    Str T;
    Concat_Sq(T, str,str);
    StrPrint_Sq(T);

    printf("substr of T:");
    Str substr;
    SubString_Sq(substr,T,2,2);
    StrPrint_Sq(substr);

    printf("index \"ca\" in T:");
    printf("%d\n",Index_Sq(T,substr));

    char pattern[] = "ababcab";
    char kmp_s[] = "gdasdababcabadhua";
    Str text;
    StrAssign(text, kmp_s);
    kmp_search(text,pattern);
    // printf("test of KMP:\n");
    // Str P;
    // char s_P[] = "0aba";
    // StrAssign(P, s_P);
    // Str T;
    // char s_T[] = "0fffaba";
    // StrAssign(T, s_T);
    // StrPrint_Sq(P);
    // StrPrint_Sq(T);
    // int *pi = prefix(P);
    // for (size_t i = 1; i < P.length;i++){
    //     printf("%d ",pi[i]);
    // }
    // printf("\n");
    // KMP_Matcher(T,P);
    return 0;
}

