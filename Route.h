//
// Created by ivaylo on 12/8/24.
//

#ifndef TAXIROUTES_ROUTE_H
#define TAXIROUTES_ROUTE_H

#include <vector>
#include <iostream>
#include <string>
#include <cmath>

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

    Route::RouteNode::RouteNode() {
        Route::RouteNode::placeName = "";
        Route::RouteNode::longitude = 0;
        Route::RouteNode::latitude = 0;
    }

    Route::RouteNode::RouteNode(const std::string& placeName, double longitude, double latitude) {
        Route::RouteNode::placeName = placeName;
        Route::RouteNode::longitude = longitude;
        Route::RouteNode::latitude = latitude;
    }

    [[nodiscard]] const std::string& Route::RouteNode::getPlaceName() const {
        return Route::RouteNode::placeName;
    }

    void Route::RouteNode::setPlaceName(const std::string &pn) {
        Route::RouteNode::placeName = pn;
    }

    [[nodiscard]] double Route::RouteNode::getLongitude() const {
        return Route::RouteNode::longitude;
    }

    void Route::RouteNode::setLongitude(double lo) {
        Route::RouteNode::longitude = lo;
    }

    [[nodiscard]] double Route::RouteNode::getLatitude() const {
        return Route::RouteNode::latitude;
    }

    void Route::RouteNode::setLatitude(double la) {
        Route::RouteNode::latitude = la;
    }

    Route::Route() {
        Route::routeLength = 0;
        Route::numberOfLaps = 0;
    }

    Route::Route(const std::vector<RouteNode>& routeNodes, int numberOfLaps) {
        Route::routeNodes = routeNodes;
        Route::numberOfLaps = numberOfLaps;
        Route::routeLength = calculateRouteLength();
    }

    const std::vector<Route::RouteNode>& Route::getRouteNodes() const {
        return Route::routeNodes;
    }

    void Route::setRouteNodes(const std::vector<RouteNode> &rN) {
        Route::routeNodes = rN;
    }

    double Route::getRouteLength() {
        Route::routeLength = Route::calculateRouteLength();
        return Route::routeLength;
    }

    int Route::getNumberOfLaps() const {
        return Route::numberOfLaps;
    }

    void Route::setNumberOfLaps(int nol) {
        Route::numberOfLaps = nol;
    }

    double Route::calculateRouteLength() const {
        double totalDistance = 0;
        for (int i = 0; i < Route::routeNodes.size() - 1; i++) {
            totalDistance += std::sqrt(std::pow((
                Route::routeNodes[i].getLongitude() - Route::routeNodes[i + 1].getLongitude()), 2)
                + std::pow((Route::routeNodes[i].getLatitude() - Route::routeNodes[i + 1].getLatitude()), 2));
        }
        return totalDistance;
    }

    std::ostream& operator<<(std::ostream& os, const Route& route) {
        os << " " << route.routeNodes.size() << " ";
        for (const auto & routeNode : route.routeNodes) {
            os << routeNode.getPlaceName() << " "
               << routeNode.getLongitude() << " "
               << routeNode.getLatitude() << " ";
        }
        os << route.routeLength << " " << route.numberOfLaps;
        return os;
    }

    std::istream& operator>>(std::istream& is, Route& route) {
        int size;
        is >> size;
        double lo, la;
        std::string name;
        std::vector<Route::RouteNode> rns;
        for (int i = 0; i < size; i++) {
            is >> name >> lo >> la;
            Route::RouteNode routeNode(name, lo, la);
            rns.push_back(routeNode);
        }
        route.routeNodes = rns;
        is >> route.routeLength >> route.numberOfLaps;

        return is;
    }

} // model

#endif //TAXIROUTES_ROUTE_H
