#include <stdio.h>

int main(){
    int num;
    int i;
    scanf("%d",&num);
    i = 0;
    while (num != 1)
    {
        if (num%2 == 0) num = num / 2;
        else num = (3 * num + 1) / 2;
        i++;
    }
    printf("%d\n",i);

    return 0;
}
