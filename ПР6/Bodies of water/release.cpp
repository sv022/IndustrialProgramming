#include "Bay.h"

Ocean::Ocean(){
    name = "";
    area = 0;
    depth = 0;
}

Ocean::Ocean(std::string _name, int _depth, int _square){
    name = _name;
    area = _square;
    depth = _depth;
}

Ocean::Ocean(std::string _name){
    name = _name;
    area = -1;
    depth = -1;
}


std::ostream &operator << (std::ostream &stream, Ocean object){
	stream << "{name: " << object.name << ", depth : " << object.depth << ", square : " << object.area << "}\n";
	return stream;
}

std::istream &operator >> (std::istream &stream, Ocean& object){
	stream >> object.name >> object.depth >> object.area;
	return stream;
}

// --------------

Sea::Sea(){
    area = 0;
    depth = 0;
    coastline = 0;
}

Sea::Sea(std::string _ocean, std::string _name) : Ocean(_ocean){
    name = _name;
    area = -1;
    depth = -1;
    coastline = -1;
}

Sea::Sea(std::string _ocean, std::string _name, int _depth, int _square, int _cl) : Ocean(_ocean) {
    name = _name;
    depth = _depth;
    area = _square;
    coastline = _cl;
}

std::string Sea::get_parent(){
    return Ocean::name;
}

std::ostream &operator << (std::ostream &stream, Sea object){
	stream << "{name: " << object.name << ", Ocean : " << object.get_parent() << ", depth : "  << object.depth << ", coastline : "  << object.coastline << ", square : " << object.area << "}\n";
	return stream;
}

std::istream &operator >> (std::istream &stream, Sea& object){
	stream >> object.name >> object.depth >> object.area;
	return stream;
}

// --------------

Bay::Bay() {
    name = "";
    area = 0;
    depth = 0;
}

Bay::Bay(std::string _ocean, std::string _sea, std::string _name) : Sea(_ocean, _sea) {
    name = _name;
    area = 0;
    depth = 0;
}

Bay::Bay(std::string _ocean, std::string _sea, std::string _name, point _loc, int _depth, int _square) : Sea(_ocean, _sea) {
    name = _name;
    location = _loc;
    depth = _depth;
    area = _square;
}

std::string Bay::get_parent(){
    return Ocean::name + "; " + Sea::name;
}

std::ostream &operator << (std::ostream &stream, Bay object){
	stream << "{name: " << object.name << ", Ocean & Sea : " << object.get_parent() << ", depth : "  << object.depth  << ", square : " << object.area << "}\n";
	return stream;
}

std::istream &operator >> (std::istream &stream, Bay& object){
	stream >> object.name >> object.depth >> object.area;
	return stream;
}

// --------------
