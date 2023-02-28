#include <iostream>
#include <math.h>
#include "eq2.h"

eq2::eq2(){
	a = 0;
	b = 0;
	c = 0;
}

eq2::eq2(double a1, double b1, double c1){
	a = a1;
	b = b1;
	c = c1;
	D = b*b - 4*a*c;
}

void eq2::set(double a1, double b1, double c1){
	a = a1;
	b = b1;
	c = c1;
	D = b*b - 4*a*c;
}



double eq2::find_x() {
	if (D < 0) {
		std::cout << "No Rational roots" << '\n';
		return 0;
	}
	else {
		if (D == 0) {
			double x1 = (-b - sqrt(D)) / (2 * a);
			std::cout << "One root, x = " << x1 << '\n';
			return x1;
		} else {
			double x1 = (-b - sqrt(D)) / (2 * a);
			double x2 = (-b + sqrt(D)) / (2 * a);
			std::cout << "Two roots, \nx1 = " << x1 << "\nx2 = " << x2 << '\n';
			return fmax(x1, x2);
		}
	}
}

double eq2::find_y(double _x){
	return a * _x *_x + b * _x + c;
}