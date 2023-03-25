#include"Ocean.h"

class Sea : public Ocean {
protected:
    int area;
    int depth;
    int coastline;
    std::string name;

private:
    std::string get_parent();

public:
    Sea();
    Sea(std::string _ocean, std::string _name);
    Sea(std::string _ocean, std::string _name, int _depth, int _square, int _cl);

    friend std::ostream &operator << (std::ostream &stream, Sea object); 
    friend std::istream &operator >> (std::istream &stream, Sea &object); 
};
