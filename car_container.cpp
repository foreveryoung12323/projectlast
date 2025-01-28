#include "car_container.h"
#include <iostream>

void CarContainer::addCar(Car* car) {
    cars.push_back(car);
}

void CarContainer::removeCar(Car* car) {
    cars.erase(remove(cars.begin(), cars.end(), car), cars.end());
}
// Поиск машин по заданному критерию (например, по цене или бренду)
vector<Car*> CarContainer::searchCars(function<bool(Car*)> criteria) const {
    vector<Car*> result;
    for (const auto& car : cars) {
        if (criteria(car)) {  // Если машина соответствует критерию
            result.push_back(car);
        }
    }
    return result;
}
// Вывод информации обо всех машинах
void CarContainer::printAllCars() const {
    for (const auto& car : cars) {
        cout << car->getInfo() << endl;
    }
}