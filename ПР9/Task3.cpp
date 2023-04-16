#include <iostream>

using namespace std;

template <typename T>
class set {
private:
	T* a;
	int size;
public:
	set() {
		size = 0;
		a = nullptr;
	}
	set(T* val, int len) {
		a = new T[len];
		for (int i = 0; i < len; i++) a[i] = val[i];
		size = len;
	}

	~set() {
		delete[] a;
	}

	bool empty() {
		return (size == 0);
	}
	void add(T val) {
		for (int i = 0; i < size; i++) { if (a[i] == val) return; }

		T* ac = new T[size + 1];
		for (int i = 0; i < size; i++) ac[i] = a[i];
		ac[size] = val;
		if (a != nullptr) delete[] a;
		a = ac;
		size++;
	}

	bool inset(T val) {
		for (int i = 0; i < size; i++) { if (a[i] == val) return true; }
		return false;
	}

	void remove(T val) {
		if (!inset(val)) return;
		T* ac = new T[size - 1];
		int j = 0;
		for (int i = 0; i < size; i++, j++) { 
			if (a[i] != val) {
				ac[j] = a[i];
			} else {
				j--;
			}
		}
		delete[] a;
		a = ac;
		size--;
	}

	void show() {
		for (int i = 0; i < size; i++) cout << a[i] << ' ';
		cout << '\n';
	}
};


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
	set<int> a;
	a.add(1);
	a.add(2);
	a.add(3);

	a.show();
	a.remove(1);
	a.show();
	cout << a.empty() << a.inset(5) << '\n';

	set<char> b;
	b.add('a');
	b.add('b');
	b.add('c');

	b.show();
	b.remove('a');
	b.show();
	cout << b.empty() << b.inset('c') << '\n';
}
