#include <iostream>

float F(float x);

int main(){
	float dx = 0.001;  //΢�� 
	float x = 3;   //�������� 
	float i = 0;  //�������� 
	float res = 0;  //��� 
	for(i;i<=x;i+=dx){
		res += F(i)*dx;
	}
	std::cout<<res<<std::endl;	
} 


float F(float x){
	return x*x;
}
