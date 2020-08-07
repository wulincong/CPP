#include <stdio.h>
#include "psum.c"

int main(){
    float a[] = {1,2,3,4,5,6,7,8,9};
    float p[9];
    psum2(a,p,9);
    for (size_t i = 0; i < 9; i++) printf("%f ",p[i]);

}