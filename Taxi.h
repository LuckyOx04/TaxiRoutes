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
} // model

#endif //TAXIROUTES_TAXI_H
