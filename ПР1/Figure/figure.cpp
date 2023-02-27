#include "figure.h"
#include <cmath>
#include <iostream>

using namespace std;

vec::vec() {
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
}

vec::vec(float _x1, float _y1, float _x2, float _y2) {
	x1 = _x1;
	y1 = _y1;
	x2 = _x2;
	y2 = _y2;
}

float vec::len() {
	return sqrt(pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2));
}

float angle(vec v1, vec v2) {
	return acos(((v1.x1 - v1.x2) * (v2.x1 - v2.x2) + (v1.y1 - v1.y2) * (v2.y1 - v2.y2)) / (v1.len() * v2.len()));
}

figure::figure() {
	x1 = x2 = x3 = x4 = y1 = y2 = y2 = y3 = y4 = S = P = 0;
}

figure::figure(float _x1, float _x2, float _x3, float _x4, float _y1, float _y2, float _y3, float _y4) {
	x1 = _x1;
	x2 = _x2;
	x3 = _x3;
	x4 = _x4;
	y1 = _y1;
	y2 = _y2;
	y3 = _y3;
	y4 = _y4;
	vec a(_x1, _y1, _x2, _y2);
	vec b(_x2, _y2, _x3, _y3);
	vec c(_x3, _y3, _x4, _y4);
	vec d(_x4, _y4, _x1, _y1);
	vec d1(_x1, _y1, _x3, _y3);
	vec d2(_x2, _y2, _x4, _y4);
	P = a.len() + b.len() + c.len() + d.len();
	S = d1.len() * d2.len() * sin(angle(d1, d2)) / 2;
}

void figure::set(float _x1, float _x2, float _x3, float _x4, float _y1, float _y2, float _y3, float _y4) {
	x1 = _x1;
	x2 = _x2;
	x3 = _x3;
	x4 = _x4;
	y1 = _y1;
	y2 = _y2;
	y3 = _y3;
	y4 = _y4;
	vec a(_x1, _y1, _x2, _y2);
	vec b(_x2, _y2, _x3, _y3);
	vec c(_x3, _y3, _x4, _y4);
	vec d(_x4, _y4, _x1, _y1);
	vec d1(_x1, _y1, _x3, _y3);
	vec d2(_x2, _y2, _x4, _y4);
	P = a.len() + b.len() + c.len() + d.len();
	S = d1.len() * d2.len() * sin(angle(d1, d2)) / 2;
}

void figure::show() {
	cout << "1 point coords: " << x1 << " " << y1 << '\n' \
		<< "2 point coords: " << x2 << " " << y2 << '\n' \
		<< "3 point coords: " << x3 << " " << y3 << '\n' \
		<< "4 point coords: " << x4 << " " << y4 << '\n' \
		<< "Square of figure: " << S << '\n' \
		<< "Perimeter of figure: " << P << '\n' \
		<< "If square is prug: " << is_prug() << '\n' \
		<< "If square is square: " << is_square() << '\n' \
		<< "If square is romb: " << is_romb() << '\n' \
		<< "If square in a circle: " << is_in_circle() << '\n' \
		<< "If square out a circle: " << is_out_circle() << '\n';
}

bool figure::is_romb() {
	vec d1(x1, y1, x3, y3);
	vec d2(x2, y2, x4, y4);
	return (d1.x1 - d1.x2) * (d2.x1 - d2.x2) + (d1.y1 - d1.y2) * (d2.y1 - d2.y2) == 0;
}

bool figure::is_square() {
	vec a(x1, y1, x2, y2);
	vec b(x2, y2, x3, y3);
	vec c(x3, y3, x4, y4);
	vec d(x4, y4, x1, y1);
	return (a.len() == b.len() && b.len() == c.len() && c.len() == d.len() && d.len() == a.len());
}

bool figure::is_prug() {
	vec a(x1, y1, x2, y2);
	vec b(x2, y2, x3, y3);
	vec c(x3, y3, x4, y4);
	vec d(x4, y4, x1, y1);
	vec d1(x1, y1, x3, y3);
	vec d2(x2, y2, x4, y4);
	if ((a.len() == c.len() && b.len() == d.len()) && (d1.len() == d2.len())) {
		return true;
	};
	return false;
}

bool figure::is_in_circle() {
	vec a(x1, y1, x2, y2);
	vec b(x2, y2, x3, y3);
	vec c(x3, y3, x4, y4);
	vec d(x4, y4, x1, y1);
	return (angle(a, b) == angle(c, d) && angle(a, c) == angle(b, d));
}

bool figure::is_out_circle() {
	vec a(x1, y1, x2, y2);
	vec b(x2, y2, x3, y3);
	vec c(x3, y3, x4, y4);
	vec d(x4, y4, x1, y1);
	return (a.len() + c.len()) == (b.len() + d.len());
}
