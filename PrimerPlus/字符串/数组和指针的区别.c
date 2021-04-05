#include <stdio.h>
int main(int argc, char **argv){
    char heart[] = "I love Tillie!";
    char *head = "I love Millie!";
    putchar(heart[0]);
    putchar(head[0]);
    putchar(*(heart+2));
    putchar(*(head+2));
    heart++;
    head++;
}
