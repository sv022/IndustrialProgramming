#pragma once

class Circle{
private:
	float radius;
	float x;
	float y; 
public:
	Circle();
	Circle(float r);
	Circle(float r, float x_c, float y_c);
	void set_circle(float r, float x_c, float y_c);
	float square();
	bool triangle_around(float a, float b, float c);
	bool triangle_in(float a, float b, float c);
	bool check_circle(float _r, float _x, float _y);
};