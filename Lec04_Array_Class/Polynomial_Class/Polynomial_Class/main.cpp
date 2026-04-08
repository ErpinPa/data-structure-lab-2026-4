#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
    Polynomial a, b, c;

    // ÀÔ·Â
    a.read();
    b.read();

    // µ¡¼À
    c = a.add(b);

    // Ãâ·Â
    cout << "A: ";
    a.print();

    cout << "B: ";
    b.print();

    cout << "C = A + B: ";
    c.print();

    return 0;
}