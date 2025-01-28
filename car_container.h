#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include "car.h"
using namespace std;
// Класс для хранения и управления списком машин
class CarContainer {
private:
    vector<Car*> cars; // Вектор указателей на машины

public:
    void addCar(Car* car); // Добавить машину в контейнер
    void removeCar(Car* car); // Удалить машину из контейнера
    vector<Car*> searchCars(function<bool(Car*)> criteria) const; // Поиск машин по критерию
    void printAllCars() const;// Вывести информацию обо всех машинах
};
