#include <iostream>
#include <math.h>
#include <numeric>
#include "rational.h"

// operator -

Rational operator - (Rational &ths, Rational &other){
        return Rational((ths.n * other.m - other.n * ths.m), (ths.m * other.m));
}
Rational operator - (Rational &ths, int &other){
    return Rational((ths.n - other * ths.m), (ths.m));
}


using namespace std;

void demo(Rational a, int i){
	Rational b(2, 7);
	Rational c1 = a + b * std::pow(-1, i);
	Rational c2 = a + b * std::pow(-1, i + 1);
	cout << "c1 ";
	c1.show();
	cout << "c2 ";
	c2.show();
	++c1;
	cout << "c1++ ";
	c1.show();
	cout << "c1 == c2 " << (c1 == c2) << '\n';
	cout << "c1 > c2 " << (c1 > c2) << '\n';
	c1 += c2;
	cout << "c1 += c2 ";
	c1.show();
	c1.set(9, 13);
	cout << "\n";
}

int main() {
	//demo();
	int n = 5, a, b;
	//cin >> n;
	Rational* arr = new Rational[n];
	for (int i = 0; i < n; i++){
		//cin >> a >> b;
		a = (i + (i % 2));
		b = (i + 3 + (i % 2));
		arr[i] = Rational(a, b);
		cout << "Fraction " << i + 1 << '\n';
		demo(arr[i], i);
	}
}
