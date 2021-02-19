#include "Scanf.h"

int main(int argc, char *argv[]){
    char ch;
    FILE *fp = fopen("Test.txt","r");
    Scanf(fp, "%c",&ch);
    printf("%c",ch);
    return 0;
}

