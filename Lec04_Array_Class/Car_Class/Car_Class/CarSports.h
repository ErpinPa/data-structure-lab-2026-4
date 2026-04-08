#ifndef CARSPORTS_H
#define CARSPORTS_H

#include <iostream>
#include <string>

// ===================== Car =====================
class Car {
protected:
    int speed;
    std::string name;

public:
    int gear;

    Car();
    Car(int s, const std::string& n, int g);
    virtual ~Car();

    void changeGear(int g = 4);
    virtual void speedUp();
    virtual void display() const;
    void whereAmI() const;
};

// ===================== SportsCar =====================
class SportsCar : public Car {
private:
    bool bTurbo;

public:
    SportsCar();
    SportsCar(int s, const std::string& n, int g, bool turbo);

    void setTurbo(bool bTur);
    void speedUp() override;
    void display() const override;
};

#endif