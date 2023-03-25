#include "DissectedCone.h"

using namespace std;

int main(){
	Cone A(3, 4);
	cout << A << ' ' << A.area() << ' ' << A.volume() << '\n';
	DissectedCone B(3, 1, 1);
	cout << B << ' ' << B.area() << ' ' << B.volume() << '\n';
	DissectedCone C(3, 1, 1);
	cout << (B == C);
}
