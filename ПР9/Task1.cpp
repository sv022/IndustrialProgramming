#include <iostream>
using namespace std;

template <class T>
void Swap(T& x, T& y) {
    T z = x;
    x = y;
    y = z;
}

template <class T>
void OutXY(T& x, T& y) {
    cout << x << " " << y << "\n";
}

class My_class {
    int a;
    float b;
public:
    My_class(int a, float b) {
        this->a = a;
        this->b = b;
    }
    void Out() {
        cout << a << " " << b << "\n";
    }
    My_class operator = (My_class& T) {
        a = T.a;
        b = T.b;
        return *this;
    }
};

int main() {
    int x = 1;
    int y = 2;
    cout << "before (int)\n";
    OutXY(x, y);
    Swap(x, y);
    cout << "after\n";
    OutXY(x, y);
    float x1 = 1.5;
    float y1 = 5.9;
    cout << "before (float)\n";
    OutXY(x1, y1);
    Swap(x1, y1);
    cout << "after\n";
    OutXY(x1, y1);
    My_class t1(1, 1.5), t2(2, 9.9);
    cout << "before (classes)\n";
    t1.Out();
    t2.Out();
    Swap(t1, t2);
    cout << "after\n";
    t1.Out();
    t2.Out();
    return 0;
}
