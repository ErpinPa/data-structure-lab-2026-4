#include "Complex.h"
#include <cstdio>
#include <cstdlib>

void Complex::set(double r, double i) { real = r; imag = i; }

void Complex::print(const char* msg) {
    printf("%s %4.2f + %4.2fi\n", msg, real, imag);
}

void Complex::add(Complex a, Complex b) {
    real = a.real + b.real;
    imag = a.imag + b.imag;
}

int main() {
    Complex a, b, sum;
    // 랜덤 값 설정 (0.0 ~ 10.0 사이)
    a.set((rand() % 100) / 10.0, (rand() % 100) / 10.0);
    b.set((rand() % 100) / 10.0, (rand() % 100) / 10.0);

    sum.add(a, b); // [6]
    a.print("A = ");
    b.print("B = ");
    sum.print("A + B = ");
    return 0;
}