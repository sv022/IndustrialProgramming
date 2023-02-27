#include "figure.h"
#include <iostream>

using namespace std;

int main()
{
	float x1 = 0, x2 = 1, x3 = 1, x4 = 0, y1 = 0, y2 = 0, y3 = 1, y4 = 1;
	figure fig[3];
	for (int i = 0; i < 3; i++) {
		//cout << "x, y coords " << i + 1 << "th figure" << '\n';
		//cin >> x1 >> x2 >> x3 >> x4 >> y1 >> y2 >> y3 >> y4;
		fig[i].set(x1 + (i % 3), x2 + (i % 2), x3 + i, x4 + i, y1 + (i % 3), y2 + (i % 2), y3 + i, y4 + i);
		fig[i].show();
	}
}
