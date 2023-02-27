#pragma once

struct vec {
	float x1;
	float y1;
	float x2;
	float y2;
	vec(float _x1, float _y1, float _x2, float _y2);
	vec();
	float len();
};

class figure {
private:
	float x1;
	float x2;
	float x3;
	float x4;
	float y1; 
	float y2; 
	float y3;
	float y4; 
	float S;
	float P;
public:
	figure();
	figure(float _x1, float _x2, float _x3, float _x4, float _y1, float _y2, float _y3, float _y4);
	void set(float _x1, float _x2, float _x3, float _x4, float _y1, float _y2, float _y3, float _y4);
	void show();
	bool is_prug();
	bool is_square();
	bool is_romb();
	bool is_in_circle();
	bool is_out_circle();
};

float angle(vec v1, vec v2);