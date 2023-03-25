#include<iostream>

const double pi = 3.1416;



class Cone {
    protected:
    point center;
    double r;
    double h;
    double l;
    
    public:
    Cone();
    Cone(double _r, double _h);
    Cone(point _p, double _r, double _h);
    void setpos(point _p);
    void setrad(double _r);
    void setheight(double _h);

    double area();
    double volume();

    bool operator < (Cone other) {
        return this->volume() > other.volume();
    }
    bool operator > (Cone other){
        return this->volume() < other.volume();
    }
    bool operator == (Cone other){
        return this->volume() == other.volume();
    }
    bool operator != (Cone other){
        return this->volume() != other.volume();
    }

    friend std::ostream &operator << (std::ostream &stream, Cone object); 

};
