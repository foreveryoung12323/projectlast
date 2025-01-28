#pragma once
#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string brand; // Марка автомобиля.
    int year; // Год выпуска.
    double price; // Цена автомобиля.
    string configuration; // Конфигурация (например, модель, уровень оснащения).
    string country; // Страна производства или продажи.
    string saleDate; // Дата продажи.
    string buyer; // Информация о покупателе.

public:
    Car(const string& brand, int year, double price, const string& configuration,
        const string& country, const string& saleDate, const string& buyer);
    virtual ~Car() = default;

    virtual string getInfo() const; // Метод для получения информации о машине
    double getPrice() const; // Метод для получения цены машины
};
// наследник класса выше 
class UsedCar : public Car {
private:
    int condition; // Состояние (например, от 1 до 10)
    string previousOwner; // Предыдущий владелец
    int mileage; // Пробег

public:
    UsedCar(const string& brand, int year, double price, const string& configuration,
        const string& country, const string& saleDate, const string& buyer,
        int condition, const string& previousOwner, int mileage);

    string getInfo() const override;
};

class SportsCar : public Car {
private:
    double acceleration;// Разгон до 100 км/ч (в секундах)
    double engineVolume; // Объём двигателя (в литрах)
    int horsepower; // Мощность (в лошадиных силах)

public:
    SportsCar(const string& brand, int year, double price, const string& configuration,
        const string& country, const string& saleDate, const string& buyer,
        double acceleration, double engineVolume, int horsepower);

    string getInfo() const override;
};
// наследник класса car
class SpecialCar : public Car {
private:
    string type;
    double weight;
    string dimensions;

public:
    SpecialCar(const string& brand, int year, double price, const string& configuration,
        const string& country, const string& saleDate, const string& buyer,
        const string& type, double weight, const string& dimensions);

    string getInfo() const override;
};

