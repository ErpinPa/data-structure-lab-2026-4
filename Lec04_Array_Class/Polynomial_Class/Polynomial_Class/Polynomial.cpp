#include <iostream>
#include "Polynomial.h"

using namespace std;

Polynomial::Polynomial() {
    degree = 0;
    for (int i = 0; i < MAX_DEGREE; i++)
        coef[i] = 0.0;
}

// ÀÔ·Â
void Polynomial::read() {
    cin >> degree;
    for (int i = degree; i >= 0; i--) {
        cin >> coef[i];
    }
}

// Ãâ·Â
void Polynomial::print() const {
    for (int i = degree; i >= 0; i--) {
        if (coef[i] != 0) {
            cout << coef[i];
            if (i > 0) cout << "x^" << i << " + ";
        }
    }
    cout << endl;
}

// µ¡¼À
Polynomial Polynomial::add(const Polynomial& p) const {
    Polynomial result;
    result.degree = (degree > p.degree) ? degree : p.degree;

    for (int i = 0; i <= result.degree; i++) {
        result.coef[i] = coef[i] + p.coef[i];
    }

    return result;
}