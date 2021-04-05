#include <stdio.h>
int main(int argc, char **argv){
    int ch;
    FILE *fp;
    fp = fopen("test.txt", "r");
    while((ch = getc(fp)) != EOF){
        putc(ch,stdout);
    }
    return 0;
}
