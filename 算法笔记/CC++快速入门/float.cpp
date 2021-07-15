#include <stdio.h>
int main(int argc, char *argv[]){
    float f;
    f = 0b0|127|0b10000000000000000000000;     //float`s frac is 23 bits
    printf("%f\n", f);
    f = 0b0|0b00000001|0b10000000000000000000000;     //float`s exp is 8 bits
    printf("%f\n", f);
    f = 0b1|0b00000001|0b10000000000000000000000;     //float`s sign is the first one bit
    printf("%f\n", f);
    return 0;
}
