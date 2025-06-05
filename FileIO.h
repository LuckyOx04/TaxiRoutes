//
// Created by ivaylo on 12/8/24.
//

#ifndef TAXIROUTES_FILEIO_H
#define TAXIROUTES_FILEIO_H

#include <vector>
#include "Route.h"
#include "Taxi.h"

namespace controller {

    class FileIO {
    private:
        static void trimWhitespaces(const std::string& filename);

    public:
        static bool writeRouteToFile(const model::Route& route);
        static std::vector<model::Route> readRoutesFromFile();
        static bool writeTaxiToFile(const model::Taxi& taxi);
        static std::vector<model::Taxi> readTaxisFromFile();
    };
} // controller

#endif //TAXIROUTES_FILEIO_H
