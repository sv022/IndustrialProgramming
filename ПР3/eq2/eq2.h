class eq2{
    private:
    double a;
    double b;
    double c;
    double D;
    public:
    eq2 (double a1, double b1, double c1);
    eq2 ();
    void set(double a1, double b1, double c1);
    double find_x();
    double find_y (double x1);
    eq2 operator + (eq2 other){
        return eq2(this->a + other.a, this->b + other.b, this->c + other.c);
    };
};
