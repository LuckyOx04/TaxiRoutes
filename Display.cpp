//
// Created by ivaylo on 6/5/25.
//
#include <iostream>
#include <iomanip>
#include <cmath>
#include <format>
#include "Display.h"
#define WELCOME_MESSAGE_WIDTH 31

namespace view {
    int Display::menuWidth = 85;

    void Display::setMenuWidth(int numberOfChars) {
        Display::menuWidth = numberOfChars;
    }

    void Display::printUpperBorder() {
        std::cout << std::right << "╔";
        for (int i = 0; i < Display::menuWidth - 2; i++) {
            std::cout << "═";
        }
        std::cout << "╗\n";
    }

    void Display::printWelcomeMessage() {
        int leftPadding = (int)ceil((Display::menuWidth - WELCOME_MESSAGE_WIDTH) / 2.0);
        int rightPadding = Display::menuWidth - leftPadding - 1; // -1 because the end of border character is not included
        std::cout << std::left << std::setfill(' ') << std::setw(leftPadding + 2) << "║"; // +2 because apparently std::left and std::setfill each also take a space;
        std::cout << std::setw(rightPadding) << "Welcome to taxi routes manager!";
        std::cout << "║\n";
    }

    void Display::printBreakLine() {
        std::cout << "╟";
        for (int i = 0; i < Display::menuWidth - 2; i++) {
            std::cout << "═";
        }
        std::cout << "╢\n";
    }

    void Display::printLineWithinBorders(const std::string& text) {
        std::cout << std::left << "║ " << std::setw(Display::menuWidth - 3) << text;
        std::cout << "║\n";
    }

    void Display::printLowerBorder() {
        std::cout << std::right << "╚";
        for (int i = 0; i < Display::menuWidth - 2; i++) {
            std::cout << "═";
        }
        std::cout << "╝\n";
    }

    void Display::printRoute(model::Route route) {
        printLineWithinBorders(std::format("route length: {} km; number of laps {}",
                                           route.getRouteLength(),
                                           route.getNumberOfLaps()));
        printLineWithinBorders("With nodes: ");
        std::vector<model::Route::RouteNode> routeNodes = route.getRouteNodes();
        for (const auto& routeNode : routeNodes) {
            printLineWithinBorders(std::format(
                    "location name: {}; longitude: {}; latitude: {}",
                    routeNode.getPlaceName(), routeNode.getLongitude(), routeNode.getLatitude()));
        }
    }

    void Display::showMainMenu() {
        printUpperBorder();
        printWelcomeMessage();
        printBreakLine();
        printLineWithinBorders("Enter a number of choice form this menu:");
        printBreakLine();
        printLineWithinBorders("1. View taxis");
        printLineWithinBorders("2. View routes");
        printLineWithinBorders("3. Add route");
        printLineWithinBorders("4. Add taxi");
        printLineWithinBorders("5. Assign route to taxi and calculate fuel consumption");
        printLineWithinBorders("6. Show this menu again (in case you forget the choices).");
        printLineWithinBorders("7. Exit this app");
        printLowerBorder();
    }

    void Display::showRoutesList(std::vector<model::Route> routesList) {
        printUpperBorder();
        if (routesList.empty()) {
            printLineWithinBorders("There are currently no routes.");
        } else {
            for (int i = 0; i < routesList.size(); i++) {
                printLineWithinBorders(std::format("{}. This route has:", i + 1));
                printRoute(routesList[i]);
                if (i < routesList.size() - 1) {
                    printBreakLine();
                }
            }
        }
        printLowerBorder();
    }

    void Display::showTaxisList(std::vector<model::Taxi> taxisList) {
        printUpperBorder();
        if (taxisList.empty()) {
            printLineWithinBorders("There are currently no taxis.");
        } else {
            for (int i = 0; i < taxisList.size(); i++) {
                printLineWithinBorders(std::format("{}. This taxi has:", i + 1));
                printLineWithinBorders(std::format("brand: {}; model: {}",
                                                   taxisList[i].getBrand(), taxisList[i].getModel()));
                printLineWithinBorders(std::format(
                        "number of passenger seats: {}; load capacity: {} kg; fuel economy: {} l/100km",
                        taxisList[i].getNumberOfPassengerSeats(),
                        taxisList[i].getLoadCapacity(),
                        taxisList[i].getFuelEconomy()));

                if (i < taxisList.size() - 1) {
                    printBreakLine();
                }
            }
        }
        printLowerBorder();
    }

    void Display::showSingleLine(const std::string &text) {
        printUpperBorder();
        printLineWithinBorders(text);
        printLowerBorder();
    }

    void Display::showSuccessMessage(const std::string& text) {
        std::cout << "\033[92m";
        showSingleLine(text);
        std::cout << "\033[0m\n";
    }

    void Display::showErrorMessage(const std::string &text) {
        std::cout << "\033[91m";
        showSingleLine(text);
        std::cout << "\033[0m\n";
    }

    void Display::showFuelEconomyMessage(double value, int taxiNum, int routeNum) {
        std::cout << "\033[93m";
        showSingleLine(std::format("The fuel consumption for taxi {} with route {} is {} liters",
                                   taxiNum, routeNum, value));
        std::cout << "\033[0m\n";
    }

    void Display::showGoodbyeMessage() {
        std::cout << "\033[94m";
        showSingleLine("Goodbye!");
        std::cout << "\033[0m\n";
    }
}
