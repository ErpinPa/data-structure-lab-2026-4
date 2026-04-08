#include "CarSports.h"

using namespace std;

// ===================== Car 구현 =====================
Car::Car() : speed(0), name("NoName"), gear(0) {}

Car::Car(int s, const string& n, int g)
    : speed(s), name(n), gear(g) {}

Car::~Car() {}

void Car::changeGear(int g) {
    gear = g;
}

void Car::speedUp() {
    speed += 5;
}

void Car::display() const {
    cout << "[" << name << "] : 기어="
        << gear << "단 속도="
        << speed << "kmph\n";
}

void Car::whereAmI() const {
    cout << "객체 주소 = " << this << endl;
}

// ===================== SportsCar 구현 =====================
SportsCar::SportsCar() : Car(), bTurbo(false) {}

SportsCar::SportsCar(int s, const string& n, int g, bool turbo)
    : Car(s, n, g), bTurbo(turbo) {}

void SportsCar::setTurbo(bool bTur) {
    bTurbo = bTur;
}

void SportsCar::speedUp() {
    if (bTurbo)
        speed += 20;
    else
        Car::speedUp();
}

void SportsCar::display() const {
    cout << "[" << name << "] : 기어="
        << gear << "단 속도="
        << speed << "kmph "
        << "(Turbo: " << (bTurbo ? "ON" : "OFF") << ")\n";
}

// ===================== main =====================
int main() {
    SportsCar car(0, "Ferrari", 1, false);

    car.display();

    car.speedUp();
    car.display();

    car.setTurbo(true);
    car.speedUp();
    car.display();

    return 0;
}