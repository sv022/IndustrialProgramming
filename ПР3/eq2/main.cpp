#include <iostream>
#include <math.h>
#include "eq2.h"

using namespace std;

int main() {
	eq2 P(1, 2, -3);
	eq2 Q(1, 2, 1);
	eq2 L = P + Q;
	L.find_x();
	L.find_y(0);
}
