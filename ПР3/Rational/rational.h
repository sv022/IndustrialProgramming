int gcd(int a , int b) {
	if (b == 0) return a;
	a %= b;
	return gcd(b, a);
}

class Rational {
    private:
    int n; // числитель
    int m; // знаменатель

    public:

    Rational();
    Rational(int _n, int _m);
    void set(int _n, int _m);
    void show();

    // operator +

    Rational operator + (Rational other) {
        return Rational((this->n * other.m + other.n * this->m), this->m * other.m);
    }
    Rational operator + (int other) {
        return Rational(this->n + other * this->m, this->m);
    }

    // operator -

    friend Rational operator - (Rational &ths, Rational &other){
        return Rational((ths.n * other.m - other.n * ths.m), (ths.m * other.m));
    }
    friend Rational operator - (Rational &ths, int &other){
        return Rational((ths.n - other * ths.m), (ths.m));
    }

    // operators compare

    bool operator > (Rational other){
        return this->n * other.m > other.n * this->m;
    }

    bool operator < (Rational other){
        return this->n * other.m < other.n * this->m;
    }

    bool operator == (Rational other){
        return (this->n == other.n) && (this->m == other.m);
    }

    bool operator != (Rational other){
        return (this->n != other.n) || (this->m != other.m);
    }

    // operator =
    
    Rational& operator = (Rational other){
        this->n = other.n;
        this->m = other.m;
        return *this;
    }

    Rational& operator += (Rational other){
        this->n = this->n * other.m + other.n * this->m;
        this->m = this->m * other.m;
        int d = gcd(this->n, this->m);
        this->n /= d;
        this->m /= d;
        return *this;
    }

    Rational& operator -= (Rational other){
        this->n = this->n * other.m - other.n * this->m;
        this->m = this->m * other.m;
        int d = gcd(this->n, this->m);
        this->n /= d;
        this->m /= d;
        return *this;
    }


    //operator ++

    Rational& operator ++(){
        n += 1;
        int d = gcd(n, m);
        n = n / d;
        m = m / d;
        return *this;
    }


    // Rational operator - (Rational other){
    //     return Rational((this->n * other.m - other.n * this->m), (this->m * other.m));
    // }
    // Rational operator - (int other){
    //     return Rational((this->n - other * this->m), (this->m));
    // }
};
