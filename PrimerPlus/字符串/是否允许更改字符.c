#include <stdio.h>
int main(int argc, char **argv){
    char * p1 = "Klingon";
    *p1 = 'F'; 
    printf("Klingon");
    printf(":Beware the %ss!\n","Klingon");
}
