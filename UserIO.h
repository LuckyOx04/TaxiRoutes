//
// Created by ivaylo on 12/8/24.
//

#ifndef TAXIROUTES_USERIO_H
#define TAXIROUTES_USERIO_H

#include <iostream>
#include <regex>
#include "Display.h"
#include "FileIO.h"

namespace controller {

    class UserIO {
    private:
        int choice;
        std::vector<model::Taxi> taxis;
        std::vector<model::Route> routes;

        void resetPromptAfterChoice();
        double getInputIfCorrect(const std::string& regEx, double lowerBound, double upperBound,
                                 const std::string& prompt);
    public:
        UserIO();
        UserIO(int ch, const std::vector<model::Taxi>& taxis, const std::vector<model::Route>& routes);

        [[nodiscard]] int getChoice() const;
        void setChoice(int ch);

        [[nodiscard]] const std::vector<model::Taxi> &getTaxis() const;
        void setTaxis(const std::vector<model::Taxi> &tx);

        [[nodiscard]] const std::vector<model::Route> &getRoutes() const;
        void setRoutes(const std::vector<model::Route> &rt);

        void programInnit();
        void showTaxis();
        void showRoutes();
        void addRoute();
        void addTaxi();
        void assignRouteToTaxi();
    };

    UserIO::UserIO() {
        UserIO::choice = 0;
    }

    UserIO::UserIO(int ch, const std::vector<model::Taxi>& taxis, const std::vector<model::Route>& routes) {
        UserIO::choice = ch;
        UserIO::taxis = taxis;
        UserIO::routes = routes;
    }

    void UserIO::resetPromptAfterChoice() {
        choice = (int)getInputIfCorrect("^[0-9]$", 1.0, 7.0,
                                        "Your choice (6 for menu)? => ");
    }

    double UserIO::getInputIfCorrect(const std::string &regEx, double lowerBound, double upperBound,
                                     const std::string& prompt) {
        std::regex r(regEx);
        std::string input;
        double result;
        while(true) {
            std::cin.clear();
            std::cout << prompt;
            std::getline(std::cin, input);
            if (std::regex_match(input, r)) {
                result = std::stod(input);
                if (result >= lowerBound && result <= upperBound) {
                    return result;
                }
            }
            view::Display::showErrorMessage("Invalid input!");
        }
    }

    void UserIO::programInnit() {
        view::Display::showMainMenu();
        UserIO::resetPromptAfterChoice();

        while (true) {
            if (choice == 1) {
                showTaxis();
            }
            else if (choice == 2) {
                showRoutes();
            }
            else if (choice == 3) {
                addRoute();
            }
            else if (choice == 4) {
                addTaxi();
            }
            else if (choice == 5) {
                assignRouteToTaxi();
            }
            else if (choice == 6) {
                view::Display::showMainMenu();
            }
            else if (choice == 7) {
                view::Display::showGoodbyeMessage();
                break;
            }
            UserIO::resetPromptAfterChoice();
        }
    }

    void UserIO::showTaxis() {
        UserIO::taxis = FileIO::readTaxisFromFile();
        view::Display::showTaxisList(UserIO::taxis);
    }

    void UserIO::showRoutes() {
        UserIO::routes = FileIO::readRoutesFromFile();
        view::Display::showRoutesList(UserIO::routes);
    }

    void UserIO::addRoute() {
        int numberOfNodes;
        numberOfNodes = (int)getInputIfCorrect("^[0-9]+$", 2.0, 10000.0,
                                               "Enter number of route nodes (2 to 10000) => ");
        std::vector<model::Route::RouteNode> nodes;
        std::string placeName;
        double longitude, latitude;
        for (int i = 0; i < numberOfNodes; i++) {
            std::cout << "This is node number " << i + 1 << ":\n";
            std::cout << "Enter place name => ";
            std::getline(std::cin, placeName);
            longitude = getInputIfCorrect(R"(^-?[0-9]\d*(\.\d+)?$)", -1000.0, 1000.0,
                                          "Enter longitude (-1000 to 1000 floating number) => ");
            latitude = getInputIfCorrect(R"(^-?[0-9]\d*(\.\d+)?$)", -1000.0, 1000.0,
                                         "Enter latitude (-1000 to 1000 floating number) => ");
            model::Route::RouteNode node(placeName, longitude, latitude);
            nodes.push_back(node);
        }
        int numberOfLaps;
        numberOfLaps = (int)getInputIfCorrect("^[0-9]+$", 1.0, 100,
                                              "Enter number of laps (1 to 100) => ");
        model::Route route(nodes, numberOfLaps);
        if (FileIO::writeRouteToFile(route)) {
            view::Display::showSuccessMessage("File \"routes-data.txt\" written successfully.");
        } else {
            view::Display::showErrorMessage("Error writing in file \"routes-data.txt\"!");
        }
    }

    void UserIO::addTaxi() {
        std::string brand;
        std::string mo;
        int numberOfPassengers;
        int loadCapacity;
        double fuelEconomy;
        std::cout << "Enter brand => ";
        std::getline(std::cin, brand);
        std::cout << "Enter model => ";
        std::getline(std::cin, mo);
        numberOfPassengers = (int)getInputIfCorrect("^[0-9]+$", 1.0, 7.0,
                                                    "Enter number of passengers (1 to 7) => ");
        loadCapacity = (int)getInputIfCorrect("^[0-9]+$", 10.0, 3500.0,
                                              "Enter load capacity in kg (10 to 3500) => ");
        fuelEconomy = getInputIfCorrect(R"(^-?[0-9]\d*(\.\d+)?$)", 1.0, 100.0,
            "Enter fuel economy in l/100km (1 to 100 floating number) => ");
        model::Taxi taxi(brand, mo, numberOfPassengers,
                         loadCapacity, fuelEconomy);
        if (FileIO::writeTaxiToFile(taxi)) {
            view::Display::showSuccessMessage("File \"taxis-data.txt\" written successfully.");
        } else {
            view::Display::showErrorMessage("Error writing in file \"taxis-data.txt\"!");
        }
    }

    void UserIO::assignRouteToTaxi() {
        int taxiNumber, routeNumber;
        UserIO::routes = FileIO::readRoutesFromFile();
        UserIO::taxis = FileIO::readTaxisFromFile();
        if (taxis.empty() || routes.empty()) {
            view::Display::showErrorMessage("Taxis list or routes list is empty!");
            return;
        }
        taxiNumber = (int)getInputIfCorrect("^[0-9]$", 1.0, (double)taxis.size(),
                                            "Enter taxi number => ");
        routeNumber = (int)getInputIfCorrect("^[0-9]$", 1.0, (double)routes.size(),
                                             "Enter route number => ");
        double result = taxis[taxiNumber - 1].getFuelEconomy() * routes[routeNumber - 1].getRouteLength()
                * routes[routeNumber - 1].getNumberOfLaps();
        result /= 100;
        view::Display::showFuelEconomyMessage(result, taxiNumber, routeNumber);
    }

    int UserIO::getChoice() const {
        return choice;
    }

    void UserIO::setChoice(int ch) {
        UserIO::choice = ch;
    }

    const std::vector<model::Taxi> &UserIO::getTaxis() const {
        return taxis;
    }

    void UserIO::setTaxis(const std::vector<model::Taxi> &tx) {
        UserIO::taxis = tx;
    }

    const std::vector<model::Route> &UserIO::getRoutes() const {
        return routes;
    }

    void UserIO::setRoutes(const std::vector<model::Route> &rt) {
        UserIO::routes = rt;
    }

} // controller

#endif //TAXIROUTES_USERIO_H
