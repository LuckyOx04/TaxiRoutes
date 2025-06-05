//
// Created by ivaylo on 12/8/24.
//

#ifndef TAXIROUTES_TAXI_H
#define TAXIROUTES_TAXI_H

#include <iostream>
#include "Route.h"

namespace model {

    class Taxi {
    private:
        std::string brand;
        std::string model;
        int numberOfPassengerSeats;
        int loadCapacity; // in kg
        double fuelEconomy; // liters per 100km
    public:
        Taxi();
        Taxi(const std::string& brand, const std::string& model, int numberOfPassengerSeats, int loadCapacity,
             double fuelEconomy);

        [[nodiscard]] const std::string& getBrand() const;
        void setBrand(const std::string& b);

        [[nodiscard]] const std::string& getModel() const;
        void setModel(const std::string& m);

        [[nodiscard]] int getNumberOfPassengerSeats() const;
        void setNumberOfPassengerSeats(int nops);

        [[nodiscard]] int getLoadCapacity() const;
        void setLoadCapacity(int lc);

        [[nodiscard]] double getFuelEconomy() const;
        void setFuelEconomy(double fe);

        friend std::ostream& operator<<(std::ostream& os, const Taxi& taxi);
        friend std::istream& operator>>(std::istream& is, Taxi& taxi);
    };

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

} // model

#endif //TAXIROUTES_TAXI_H
