#include <stdio.h>

enum spectrum{red, orange, yello, green, blue, violet, indigo, ultrviolet};


int main(){
	spectrum band;
	band = blue;
	//band = 2000;  invalid
	int color = blue;//blue 强转为 int
	band = spectrum(3); //若int值有效，则可以通过强转赋值给枚举变量
	return 0;

}
