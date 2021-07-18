#include "KMP.h"

void prefix_table(char pattern[],int prefix[],int n){
    prefix[0] = 0;
    int len = 0;
    int i = 1;
    while(i < n){
        if(pattern[i] == pattern[len]){
            len++;
            prefix[i] = len;
            i++;
        }
        else{
            if(len > 0){
            len = prefix[len - 1];
            }
            else{
                prefix[i] = len;
                i++;
            }
        }
    }
}

void move_prefix_table(int prefix[],int n){
    for(int i = n-1; i > 0; i--){
        prefix[i] = prefix[i-1];
    }
    prefix[0] = -1;
}

void kmp_search(Str &text,char pattern[]){
    int n = strlen(pattern);
    int prefix[n];
    int i = 0;
    int j = 0;
    int m = text.length;
    prefix_table(pattern,prefix,n);
    move_prefix_table(prefix,n);
    // text[i]    ,len(text)    = m 
    // pattern[i] ,len(pattern) = n
    while(i<m){
        if(j == n-1 && text.ch[i] == pattern[j]){
            printf("Found pattern at %d",i-j);
            j = prefix[j];
        }
        if(text.ch[i] == pattern[j]){
            i++;
            j++;
        }
        else
        {
            j = prefix[j];
            if(j == -1){
                i++;
                j++;
            }
        }
        
    }
}

int *prefix(Str &P){
    int m = P.length;
    int *pi = (int *)malloc(sizeof(int)*(m+1));
    pi[1] = 0;
    int k = 0;
    for(size_t q = 2; q <= m;q++){
        while(k > 0 && P.ch[q] != P.ch[k+1]){
            k = pi[k];
        }
        if(P.ch[k+1] == P.ch[q]){
            ++k;
        }
        pi[q] = k;
    }
    return pi;
}

void KMP_Matcher(Str T,Str P){
    int n = T.length;
    int m = P.length;
    int *pi = prefix(P);
    int q = 0;
    for(size_t i = 1; i <= n; ++i){
        while(q> 0 && P.ch[q+1]!= T.ch[i]) q = pi[q];
        if(P.ch[q+1]==T.ch[i]) q = q + 1;
        if(q == m)printf("Pattern occurs with shift %d\n",i-m);
        q= pi[q];
    }
}

void getnext(Str substr,int next[]){

}