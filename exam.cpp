#include <iostream>
#include "car.h"
#include "car_container.h"

using namespace std;

void printMenu() {
    cout << "Menu: \n";
    cout << "1. Add a Used Car\n";
    cout << "2. Add a Sports Car\n";
    cout << "3. Add a Special Car\n";
    cout << "4. View All Cars\n";
    cout << "5. Search Cars by Price\n";
    cout << "6. Remove a Car\n";
    cout << "7. Exit\n";
}

int main() {
    try {
        CarContainer container; // Контейнер для хранения машин
        int choice; // Выбор пользователя

        while (true) {
            printMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                string brand, configuration, country, saleDate, buyer, previousOwner;
                int year, condition, mileage;
                double price;

                cout << "Enter brand: ";
                cin >> brand;
                cout << "Enter year: ";
                cin >> year;
                cout << "Enter price: ";
                cin >> price;
                cout << "Enter configuration: ";
                cin >> configuration;
                cout << "Enter country: ";
                cin >> country;
                cout << "Enter sale date: ";
                cin >> saleDate;
                cout << "Enter buyer: ";
                cin >> buyer;
                cout << "Enter condition: ";
                cin >> condition;
                cout << "Enter previous owner: ";
                cin >> previousOwner;
                cout << "Enter mileage: ";
                cin >> mileage;

                cin.ignore(); 

                UsedCar* usedCar = new UsedCar(brand, year, price, configuration, country, saleDate, buyer, condition, previousOwner, mileage);
                container.addCar(usedCar);   // Добавляем машину в контейнер
            }
            else if (choice == 2) {
                string brand, configuration, country, saleDate, buyer;
                int year, horsepower;
                double price, acceleration, engineVolume;

                cout << "Enter brand: ";
                cin >> brand;
                cout << "Enter year: ";
                cin >> year;
                cout << "Enter price: ";
                cin >> price;
                cout << "Enter configuration: ";
                cin >> configuration;
                cout << "Enter country: ";
                cin >> country;
                cout << "Enter sale date: ";
                cin >> saleDate;
                cout << "Enter buyer: ";
                cin >> buyer;
                cout << "Enter acceleration (sec): ";
                cin >> acceleration;
                cout << "Enter engine volume (L): ";
                cin >> engineVolume;
                cout << "Enter horsepower: ";
                cin >> horsepower;

                cin.ignore(); 

                SportsCar* sportsCar = new SportsCar(brand, year, price, configuration, country, saleDate, buyer, acceleration, engineVolume, horsepower);
                container.addCar(sportsCar);  
            }
            else if (choice == 3) {
                string brand, configuration, country, saleDate, buyer, type, dimensions;
                int year;
                double price, weight;

                cout << "Enter brand: ";
                cin >> brand;
                cout << "Enter year: ";
                cin >> year;
                cout << "Enter price: ";
                cin >> price;
                cout << "Enter configuration: ";
                cin >> configuration;
                cout << "Enter country: ";
                cin >> country;
                cout << "Enter sale date: ";
                cin >> saleDate;
                cout << "Enter buyer: ";
                cin >> buyer;
                cout << "Enter type: ";
                cin >> type;
                cout << "Enter weight (kg): ";
                cin >> weight;
                cout << "Enter dimensions (LxWxH): ";
                cin >> dimensions;

                cin.ignore(); 

                SpecialCar* specialCar = new SpecialCar(brand, year, price, configuration, country, saleDate, buyer, type, weight, dimensions);
                container.addCar(specialCar);  
            }
            else if (choice == 4) {
                cout << "\nAll cars:\n";
                container.printAllCars();  
            }
            else if (choice == 5) {
                double targetPrice, tolerance;
                cout << "Enter target price: ";
                cin >> targetPrice;

                cout << "Enter tolerance percentage (e.g., 10 for ±10%): ";
                cin >> tolerance;

                cin.ignore();

                double lowerBound = targetPrice * (1 - tolerance / 100);
                double upperBound = targetPrice * (1 + tolerance / 100);

                cout << "\nCars within " << tolerance << "% of " << targetPrice << ":\n";
                vector<Car*> closePriceCars = container.searchCars([lowerBound, upperBound](Car* car) {
                    double price = car->getPrice();
                    return price >= lowerBound && price <= upperBound;  
                    });

                if (closePriceCars.empty()) {
                    cout << "No cars found within the specified price range.\n";
                }
                else {
                    for (const auto& car : closePriceCars) {
                        cout << car->getInfo() << endl;
                    }
                }
            }
            else if (choice == 6) {
                string brand;
                cout << "Enter brand of car to remove: ";
                cin >> brand;

                cin.ignore(); 

                Car* carToRemove = nullptr;
                for (auto& car : container.searchCars([&brand](Car* car) {
                    return car->getInfo().find(brand) != string::npos;
                    })) {
                    carToRemove = car;
                    break;
                }

                if (carToRemove) {
                    container.removeCar(carToRemove);  
                    cout << "Car removed.\n";
                }
                else {
                    cout << "Car not found.\n";
                }
            }
            else if (choice == 7) {
                break;  
            }
            else {
                cout << "Invalid choice. Try again.\n";
            }
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
