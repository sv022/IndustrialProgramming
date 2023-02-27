#include "triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle(double _a, double _b, double _c) {
	a = _a;
	b = _b;
	c = _c;
}

Triangle::Triangle() {
	a = 0;
	b = 0;
	c = 0;
}

bool Triangle::exst_tr() {
	return ((a + b > c) && (b + c > a) && (a + c > b));
}

void Triangle::set(double _a, double _b, double _c) {
	a = _a;
	b = _b;
	c = _c;
}

void Triangle::show() {
	std::cout << a << ' ' << b << ' ' << c << '\n';
}

double Triangle::perimeter() {
	return a + b + c;
}

double Triangle::square() {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}


