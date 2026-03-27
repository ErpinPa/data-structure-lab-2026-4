#pragma once
#pragma once
#include <cstdio>
class Complex
{
	double Re;
	double Im;
public:
	void set(double r, double i) {
		Re = r;
		Im = i;
	}
	void read(const char* msg = "복소수=") {
		printf("%s", msg);
		scanf_s("%lf%lf", &Re, &Im);
	}
	void print(const char* msg = "복소수=") {
		printf("%4.2f+%4.2i\n", msg, Re, Im);
	}
	void add(Complex a, Complex b) {
		Re = a.Re + b.Re;
		Im = a.Im + b.Im;
	}
};


