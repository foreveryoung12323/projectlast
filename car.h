#pragma once
#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string brand;
    int year;
    double price;
    string configuration;
    string country;
    string saleDate;
    string buyer;

public:
    Car(const string& brand, int year, double price, const string& configuration,
        const string& country, const string& saleDate, const string& buyer);
    virtual ~Car() = default;

    virtual string getInfo() const;
    double getPrice() const;
};

class UsedCar : public Car {
private:
    int condition;
    string previousOwner;
    int mileage;

public:
    UsedCar(const string& brand, int year, double price, const string& configuration,
        const string& country, const string& saleDate, const string& buyer,
        int condition, const string& previousOwner, int mileage);

    string getInfo() const override;
};

class SportsCar : public Car {
private:
    double acceleration;
    double engineVolume;
    int horsepower;

public:
    SportsCar(const string& brand, int year, double price, const string& configuration,
        const string& country, const string& saleDate, const string& buyer,
        double acceleration, double engineVolume, int horsepower);

    string getInfo() const override;
};

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

