#include "Sea.h"

class Bay : public Sea {
private:
    int depth;
    int area;
    point location;
    std::string name;

    std::string get_parent();


public:
    Bay();
    Bay(std::string _ocean, std::string _sea, std::string _name);
    Bay(std::string _ocean, std::string _sea, std::string _name, point _loc, int _depth, int _square);

    friend std::ostream &operator << (std::ostream &stream, Bay object); 
    friend std::istream &operator >> (std::istream &stream, Bay &object); 

};



