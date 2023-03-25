#include "Cone.h"

class DissectedCone : public Cone {
private:
    double h_cut;
    double r_cut;
    double l_cut;
public:
    DissectedCone();
    DissectedCone(double _r, double _rc, double _hc);

    double area();
    double volume();

    friend std::ostream &operator << (std::ostream &stream, DissectedCone object);
    friend std::istream &operator >> (std::istream &stream, DissectedCone &object); 
};


