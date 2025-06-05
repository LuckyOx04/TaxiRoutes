//
// Created by ivaylo on 12/8/24.
//

#ifndef TAXIROUTES_USERIO_H
#define TAXIROUTES_USERIO_H

#include <iostream>
#include <vector>
#include "Taxi.h"
#include "Route.h"

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

        void programInnit(int menuWidth = 85);
        void showTaxis();
        void showRoutes();
        void addRoute();
        void addTaxi();
        void assignRouteToTaxi();
    };
} // controller

#endif //TAXIROUTES_USERIO_H
