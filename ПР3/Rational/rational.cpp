#include <iostream>
#include <math.h>
#include <numeric>
#include "rational.h"

Rational::Rational(){
	n = 1;
	m = 1;
}

Rational::Rational(int _n, int _m){
	if (_m == 0) throw std::exception();
	int d = gcd(_n, _m);
	n = _n / d;
	m = _m / d;
}

void Rational::set(int _n, int _m){
	if (_m == 0) throw std::exception();
	int d = gcd(_n, _m);
	n = _n / d;
	m = _m / d;
}
void Rational::show(){
	std::cout << n << '/' << m << '\n';
}