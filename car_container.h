#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include "car.h"

using namespace std;

class CarContainer {
private:
    vector<Car*> cars;

public:
    void addCar(Car* car);
    void removeCar(Car* car);
    vector<Car*> searchCars(function<bool(Car*)> criteria) const;
    void printAllCars() const;
};
