#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#define MAX_DEGREE 80

class Polynomial {
private:
    int degree;
    double coef[MAX_DEGREE];

public:
    Polynomial();

    void read();                 // ÀÔ·Â
    void print() const;          // Ãâ·Â
    Polynomial add(const Polynomial& p) const; // µ¡¼À
};

#endif