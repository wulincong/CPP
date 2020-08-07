#include <iostream>

double F(double x);

int main(){
	double dt = 0.1;
	double x = 2.0;
	double res;
	res = (F(x+dt)-F(x))/dt;
	std::cout << res<<dt << std::endl;
	return 0;
}


double F(double x){
	return 1/2 * x * x;
}
