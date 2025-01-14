#include "car_container.h"
#include <iostream>

void CarContainer::addCar(Car* car) {
    cars.push_back(car);
}

void CarContainer::removeCar(Car* car) {
    cars.erase(remove(cars.begin(), cars.end(), car), cars.end());
}

vector<Car*> CarContainer::searchCars(function<bool(Car*)> criteria) const {
    vector<Car*> result;
    for (const auto& car : cars) {
        if (criteria(car)) {
            result.push_back(car);
        }
    }
    return result;
}

void CarContainer::printAllCars() const {
    for (const auto& car : cars) {
        cout << car->getInfo() << endl;
    }
}