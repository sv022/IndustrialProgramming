#include <iostream>

using namespace std;

template <class T>
void Swap(T& x, T& y) {
	T z = x;
	x = y;
	y = z;
}


template <class T>
void sort(T* a, int n) {
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		while (j >= 0 && a[j] > a[j + 1]) {
			swap(a[j], a[j + 1]);
			j--;
		}
	}
}



int main() {
	int a[5] = { 3, 1, 2, 5, 4 };
	char b[5] = { 'c', 'a', 'n', 'k', 'b' };
	sort(a, 5);
	sort(b, 5);
	for (int i = 0; i < 5; i++) cout << a[i] << ' ';
	cout << '\n';
	for (int i = 0; i < 5; i++) cout << b[i] << ' ';
}
