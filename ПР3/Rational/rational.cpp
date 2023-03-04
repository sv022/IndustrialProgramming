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

// operators

Rational Rational::operator + (Rational other) {
        return Rational((this->n * other.m + other.n * this->m), this->m * other.m);
}
Rational Rational::operator + (int other) {
    return Rational(this->n + other * this->m, this->m);
}

Rational Rational::operator * (Rational other){
	return Rational(this->n * other.n, this->m * other.m);
}
Rational Rational::operator * (int other){
	return Rational(this->n * other, this->m);
}
Rational Rational::operator / (Rational other){
	return Rational(this->n * other.m, this->m * other.n);
}
Rational Rational::operator / (int other){
	return Rational(this->n, this->m * other);
}

// operators comparison

bool Rational::operator > (Rational other){
    return this->n * other.m > other.n * this->m;
}
bool Rational::operator < (Rational other){
    return this->n * other.m < other.n * this->m;
}
bool Rational::operator == (Rational other){
    return (this->n == other.n) && (this->m == other.m);
}
bool Rational::operator != (Rational other){
    return (this->n != other.n) || (this->m != other.m);
}

// operators = , -=, +=

Rational& Rational::operator = (Rational other){
    this->n = other.n;
    this->m = other.m;
    return *this;
}
Rational& Rational::operator += (Rational other){
    this->n = this->n * other.m + other.n * this->m;
    this->m = this->m * other.m;
    int d = gcd(this->n, this->m);
    this->n /= d;
    this->m /= d;
    return *this;
}
Rational& Rational::operator -= (Rational other){
    this->n = this->n * other.m - other.n * this->m;
    this->m = this->m * other.m;
    int d = gcd(this->n, this->m);
    this->n /= d;
    this->m /= d;
    return *this;
}

//operator ++

Rational& Rational::operator ++(){
        n += 1;
        int d = gcd(n, m);
        n = n / d;
        m = m / d;
        return *this;
}
