#include "car.h"
#include <sstream>

Car::Car(const string& brand, int year, double price, const string& configuration,
    const string& country, const string& saleDate, const string& buyer)
    : brand(brand), year(year), price(price), configuration(configuration),
    country(country), saleDate(saleDate), buyer(buyer) {}

string Car::getInfo() const {
    stringstream ss;
    ss << "Brand: " << brand << ", Year: " << year
        << ", Price: " << price << ", Configuration: " << configuration
        << ", Country: " << country << ", Sale Date: " << saleDate
        << ", Buyer: " << buyer;
    return ss.str();
}

double Car::getPrice() const {
    return price;
}

UsedCar::UsedCar(const string& brand, int year, double price, const string& configuration,
    const string& country, const string& saleDate, const string& buyer,
    int condition, const string& previousOwner, int mileage)
    : Car(brand, year, price, configuration, country, saleDate, buyer),
    condition(condition), previousOwner(previousOwner), mileage(mileage) {}

string UsedCar::getInfo() const {
    stringstream ss;
    ss << Car::getInfo()
        << ", Condition: " << condition
        << ", Previous Owner: " << previousOwner
        << ", Mileage: " << mileage;
    return ss.str();
}

SportsCar::SportsCar(const string& brand, int year, double price, const string& configuration,
    const string& country, const string& saleDate, const string& buyer,
    double acceleration, double engineVolume, int horsepower)
    : Car(brand, year, price, configuration, country, saleDate, buyer),
    acceleration(acceleration), engineVolume(engineVolume), horsepower(horsepower) {}

string SportsCar::getInfo() const {
    stringstream ss;
    ss << Car::getInfo()
        << ", Acceleration: " << acceleration
        << " sec, Engine Volume: " << engineVolume
        << " L, Horsepower: " << horsepower;
    return ss.str();
}

SpecialCar::SpecialCar(const string& brand, int year, double price, const string& configuration,
    const string& country, const string& saleDate, const string& buyer,
    const string& type, double weight, const string& dimensions)
    : Car(brand, year, price, configuration, country, saleDate, buyer),
    type(type), weight(weight), dimensions(dimensions) {}

string SpecialCar::getInfo() const {
    stringstream ss;
    ss << Car::getInfo()
        << ", Type: " << type
        << ", Weight: " << weight
        << " kg, Dimensions: " << dimensions;
    return ss.str();
}