//
// Created by ivaylo on 6/5/25.
//
#include "Taxi.h"

namespace model {
    Taxi::Taxi() {
        Taxi::brand = "";
        Taxi::model = "";
        Taxi::numberOfPassengerSeats = 0;
        Taxi::loadCapacity = 0;
        Taxi::fuelEconomy = 0;
    }

    Taxi::Taxi(const std::string& brand, const std::string& model, int numberOfPassengerSeats, int loadCapacity,
               double fuelEconomy) {
        Taxi::brand = brand;
        Taxi::model = model;
        Taxi::numberOfPassengerSeats = numberOfPassengerSeats;
        Taxi::loadCapacity = loadCapacity;
        Taxi::fuelEconomy = fuelEconomy;
    }

    const std::string& Taxi::getBrand() const {
        return Taxi::brand;
    }

    void Taxi::setBrand(const std::string& b) {
        Taxi::brand = b;
    }

    const std::string& Taxi::getModel() const {
        return Taxi::model;
    }

    void Taxi::setModel(const std::string& m) {
        Taxi::model = m;
    }

    int Taxi::getNumberOfPassengerSeats() const {
        return Taxi::numberOfPassengerSeats;
    }

    void Taxi::setNumberOfPassengerSeats(int nops) {
        Taxi::numberOfPassengerSeats = nops;
    }

    int Taxi::getLoadCapacity() const {
        return Taxi::loadCapacity;
    }

    void Taxi::setLoadCapacity(int lc) {
        Taxi::loadCapacity = lc;
    }

    double Taxi::getFuelEconomy() const {
        return Taxi::fuelEconomy;
    }

    void Taxi::setFuelEconomy(double fe) {
        Taxi::fuelEconomy = fe;
    }

    std::ostream& operator<<(std::ostream& os, const Taxi& taxi) {
        os << " " << taxi.brand << " " << taxi.model << " " << taxi.numberOfPassengerSeats <<
           " " << taxi.loadCapacity << " " << taxi.fuelEconomy;

        return os;
    }

    std::istream& operator>>(std::istream& is, Taxi& taxi) {
        is >> taxi.brand >> taxi.model >> taxi.numberOfPassengerSeats >>
           taxi.loadCapacity >> taxi.fuelEconomy;

        return is;
    }
}