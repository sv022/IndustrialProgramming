#include <iostream>
#include <math.h>
#include "DissectedCone.h"

struct point {
    double x;
    double y;
    double z;

    point(){
        x = 0;
        y = 0;
        z = 0;
    }

    point(double _x, double _y, double _z){
        x = _x;
        y = _y;
        z = _z;
    }
};

Cone::Cone(){
	center = point(0, 0, 0);
	r = 0;
	h = 0;
	l = 0;
}

Cone::Cone(double _r, double _h){
	center = point(0, 0, 0);
	r = _r;
	h = _h;
	l = sqrt(r * r + h * h);
}

Cone::Cone(point _p, double _r, double _h){
	center = _p;
	r = _r;
	h = _h;
	l = sqrt(r * r + h * h);
}

void Cone::setpos(point _p){
	center = _p;
}

void Cone::setrad(double _r){
	r = _r;
	l = sqrt(r * r + h * h);
}

void Cone::setheight(double _h){
	h = _h;
	l = sqrt(r * r + h * h);
}

double Cone::area(){
	return pi * r * l + pi * r * r;
}

double Cone::volume(){
	return pi * r * r * h / 3;
}



std::ostream &operator << (std::ostream &stream, Cone object){
	stream << "{center: (" << object.center.x << ", " << object.center.y << ", " << object.center.z << "), r : " << object.r << ", h : " << object.h << "}\n";
	return stream;
}

DissectedCone::DissectedCone(){
	h_cut = 0;
	r_cut = 0;
}

DissectedCone::DissectedCone(double _r, double _rc, double _hc) : Cone(_r, _hc * _r / _rc){
	h_cut = _hc;
	r_cut = Cone::r * (_hc / Cone::h);
	l_cut = sqrt(h_cut * h_cut + (r - r_cut) * (r - r_cut));
}

double DissectedCone::area(){
	return pi * (r + r_cut) * l_cut + pi * r * r + pi * r_cut * r_cut;
}

double DissectedCone::volume(){
	return (pi * h_cut * (r_cut * r_cut + r * r_cut + r * r)) / 3;
}

std::ostream &operator << (std::ostream &stream, DissectedCone object){
	stream << "{center: (" << object.center.x << ", " << object.center.y << ", " << object.center.z << "), r : " << object.r << ", h_cut : " << object.h_cut << ", r_cut : " << object.r_cut << "}\n";
	return stream;
}

std::istream &operator >> (std::istream &stream, DissectedCone& object){
	stream >> object.r >> object.r_cut >> object.h_cut;
	return stream;
}