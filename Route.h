//
// Created by ivaylo on 12/8/24.
//

#ifndef TAXIROUTES_ROUTE_H
#define TAXIROUTES_ROUTE_H

#include <vector>
#include <iostream>
#include <string>

namespace model {

    class Route {
    public:
        class RouteNode {
        private:
            std::string placeName;
            double longitude;
            double latitude;
        public:
            RouteNode();
            RouteNode(const std::string& placeName, double longitude, double latitude);

            [[nodiscard]] const std::string& getPlaceName() const;
            void setPlaceName(const std::string& pn);

            [[nodiscard]] double getLongitude() const;
            void setLongitude(double lo);

            [[nodiscard]] double getLatitude() const;
            void setLatitude(double la);
        };

    private:
        std::vector<RouteNode> routeNodes;
        double routeLength;
        int numberOfLaps;

        [[nodiscard]] double calculateRouteLength() const;

    public:
        Route();
        Route(const std::vector<Route::RouteNode>& routeNodes, int numberOfLaps);

        [[nodiscard]] const std::vector<Route::RouteNode>& getRouteNodes() const;
        void setRouteNodes(const std::vector<Route::RouteNode>& rN);

        [[nodiscard]] double getRouteLength();

        [[nodiscard]] int getNumberOfLaps() const;
        void setNumberOfLaps(int nol);


        friend std::ostream& operator<<(std::ostream& os, const Route& route);
        friend std::istream& operator>>(std::istream& is, Route& route);
    };
} // model

#endif //TAXIROUTES_ROUTE_H
