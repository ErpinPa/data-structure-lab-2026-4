#pragma once

class Rectangle {
private:
    double width;
    double height;  // length °Ê height∑Œ ≈Î¿œ

public:
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    double getArea() {
        return width * height;
    }

    double getPerimeter() {
        return 2 * (width + height);
    }

    bool isSquare() {
        return width == height;
    }
};