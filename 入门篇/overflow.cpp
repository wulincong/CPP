#include <stdio.h>

int main(){
    char a = (char)1;
    int size = sizeof(a);
    printf("%d\n",sizeof(char)*8);
    printf("%d\n",sizeof(int)*8);
    
    return 0;
}

