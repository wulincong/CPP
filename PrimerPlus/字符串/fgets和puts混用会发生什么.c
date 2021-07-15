#include <stdio.h>

int main(int argc, char **argv){
    char line[1024];
    while (fgets(line,1024,stdin))
        puts(line);
    printf("end input\n");

}
