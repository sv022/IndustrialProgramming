#include <iostream>
#include <math.h>
#include "triangle.h"

int main() {
	Triangle tr[3];
	int i = 0;
	while (i < 3){
		double a, b, c;
		std::cin >> a >> b >> c;
		Triangle temp(a, b, c);
		if (!temp.exst_tr()){
			std::cout << "Triangle doesn't exist." << '\n';
		} else {tr[i] = temp; i++;}
	}
	for (int i = 0; i < 3; i++) std::cout << tr[i].perimeter() << ' ' << tr[i].square();
}
