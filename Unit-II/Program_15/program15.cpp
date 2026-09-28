#include <iostream>
#include <string>
#include <utility>

class Vehicle {
protected:
    std::string registrationNumber;
    double ratePerDay;

public:
    Vehicle(std::string registration, double rate)
        : registrationNumber(std::move(registration)), ratePerDay(rate) {}

    virtual double calculateRent(int days) const {
        return ratePerDay * days;
    }

    virtual void display() const {
        std::cout << "Registration: " << registrationNumber << '\n';
        std::cout << "Rate per day: " << ratePerDay << '\n';
    }

    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
private:
    double insuranceFee;

public:
    Car(std::string registration, double rate, double insurance)
        : Vehicle(std::move(registration), rate), insuranceFee(insurance) {}

    double calculateRent(int days) const override {
        return (ratePerDay * days) + insuranceFee;
    }

    void display() const override {
        Vehicle::display();
        std::cout << "Insurance fee: " << insuranceFee << '\n';
    }
};

class Bike : public Vehicle {
private:
    double helmetFee;

public:
    Bike(std::string registration, double rate, double helmet)
        : Vehicle(std::move(registration), rate), helmetFee(helmet) {}

    double calculateRent(int days) const override {
        return (ratePerDay * days) + helmetFee;
    }

    void display() const override {
        Vehicle::display();
        std::cout << "Helmet fee: " << helmetFee << '\n';
    }
};

int main() {
    Car car("MH12AB1234", 1500.0, 200.0);
    Bike bike("MH12CD5678", 500.0, 50.0);

    car.display();
    std::cout << "Car rent for 3 days: "
              << car.calculateRent(3) << '\n';

    std::cout << '\n';

    bike.display();
    std::cout << "Bike rent for 3 days: "
              << bike.calculateRent(3) << '\n';

    return 0;
}
