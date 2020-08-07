#include <iostream>

float F(float x);

int main(){
	float dx = 0.001;  //微分 
	float x = 3;   //积分上限 
	float i = 0;  //积分下限 
	float res = 0;  //结果 
	for(i;i<=x;i+=dx){
		res += F(i)*dx;
	}
	std::cout<<res<<std::endl;	
} 


float F(float x){
	return x*x;
}
