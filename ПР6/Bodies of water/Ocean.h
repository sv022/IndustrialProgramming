#include<iostream>
#include<string>

struct point {
    double latitude;
    double longtitud;

    point(){
        latitude = 0;
        longtitud = 0;
    }

    point(double _lat, double _lon){
        latitude = _lat;
        longtitud = _lon;
    }
};

class Ocean {
protected:
    int depth;
    int area;
    std::string name;

public:
    Ocean();
    Ocean(std::string _name);
    Ocean(std::string _name, int _depth, int _square);

    friend std::ostream &operator << (std::ostream &stream, Ocean object); 
    friend std::istream &operator >> (std::istream &stream, Ocean &object); 

};


