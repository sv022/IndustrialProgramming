#pragma once

class Triangle {
private:
	double a, b, c;

public:
	Triangle(double _a, double _b, double _c);
	Triangle();
	bool exst_tr();
	void set(double _a, double _b, double _c);
	void show();
	double perimeter();
	double square();
};
