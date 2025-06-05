//
// Created by ivaylo on 12/8/24.
//

#ifndef TAXIROUTES_DISPLAY_H
#define TAXIROUTES_DISPLAY_H

#include <vector>
#include "Taxi.h"
#include "Route.h"

namespace view {

    class Display {
    private:
        static int menuWidth; // in number of characters
        static void printUpperBorder();
        static void printWelcomeMessage();
        static void printBreakLine();
        static void printLineWithinBorders(const std::string& text);
        static void printLowerBorder();
        static void printRoute(model::Route route);
    public:
        static void setMenuWidth(int numberOfChars);
        static void showMainMenu();
        static void showRoutesList(std::vector<model::Route> routesList);
        static void showTaxisList(std::vector<model::Taxi> taxisList);
        static void showSingleLine(const std::string& text);
        static void showSuccessMessage(const std::string& text);
        static void showErrorMessage(const std::string& text);
        static void showFuelEconomyMessage(double value, int taxiNum, int routeNum);
        static void showGoodbyeMessage();
    };
} // view

#endif //TAXIROUTES_DISPLAY_H
