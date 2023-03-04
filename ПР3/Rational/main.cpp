#include <iostream>
#include <math.h>
#include <numeric>
#include "rational.h"

using namespace std;

void demo(Rational a){
	Rational b(2, 7);
	Rational c1 = a + b;
	Rational c2 = a - b;
	c1.show();
	c2.show();
	++c1;
	c1.show();
	cout << (c1 == c2)<< '\n';
	cout << (c1 > c2) << '\n';
	c1 += c2;
	c1.show();
	c1 = Rational(9, 13);
	c1.show();
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
		demo(arr[i]);
	}
}
