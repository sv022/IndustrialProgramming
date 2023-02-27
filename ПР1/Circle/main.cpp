#include <iostream>
#include <math.h>
#include "circle.h"

int main() {
	Circle cr[3];
	int i = 0;
	while (i < 3){
		double r = 3 + i, x = 1, y = 1;
		//std::cin >> a >> b >> c;
		Circle temp(r, x, y);
		cr[i] = temp; 
		i++;
	}
	for (int i = 0; i < 3; i++) std::cout << cr[i].square() << ' ' << cr[i].triangle_around(3, 4, 5) << ' ' << cr[i].triangle_in(6, 8, 10) << '\n';
}
