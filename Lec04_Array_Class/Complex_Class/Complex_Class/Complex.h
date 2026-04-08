#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
    double real;
    double imag;
public:
    void set(double r, double i);
    void print(const char* msg = "º¹¼Ò¼ö = ");
    void add(Complex a, Complex b);
};
#endif
