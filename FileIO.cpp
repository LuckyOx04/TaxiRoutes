//
// Created by ivaylo on 6/5/25.
//
#include <fstream>
#include "FileIO.h"
#define TAXI_FILE_NAME "taxis-data.txt"
#define ROUTE_FILE_NAME "routes-data.txt"

namespace controller {
    void FileIO::trimWhitespaces(const std::string& filename) {
        // Open file for reading
        std::ifstream inFile(filename, std::ifstream::binary);
        if (!inFile) {
            return;
        }

        // Read the entire content of the file
        std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
        inFile.close();

        // Check and remove the trailing newline character
        if (!content.empty() && content.back() == ' ') {
            content.pop_back();
        }
        // Check and remove beginning newline character
        if (!content.empty() && content[0] == ' ') {
            content.erase(0, 1);
        }

        // Open file for writing (truncate mode)
        std::ofstream outFile(filename, std::ofstream::binary | std::ofstream::trunc);
        if (!outFile) {
            return;
        }

        // Write the modified content back to the file
        outFile << content;
        outFile.close();
    }

    bool FileIO::writeRouteToFile(const model::Route& route) {
        std::ofstream outputFileStream;
        outputFileStream.open(ROUTE_FILE_NAME, std::ofstream::app);

        if (!outputFileStream) {
            return false;
        }

        outputFileStream << route;

        outputFileStream.close();
        FileIO::trimWhitespaces(ROUTE_FILE_NAME);
        return true;
    }

    std::vector<model::Route> FileIO::readRoutesFromFile() {
        std::vector<model::Route> routes;
        std::ifstream inputFileStream;
        inputFileStream.open(ROUTE_FILE_NAME);

        if (!inputFileStream) {
            return routes;
        }

        while (!inputFileStream.eof()) {
            model::Route route;
            inputFileStream >> route;
            routes.push_back(route);
        }

        inputFileStream.close();

        return routes;
    }

    bool FileIO::writeTaxiToFile(const model::Taxi& taxi) {
        std::ofstream outputFileStream;
        outputFileStream.open(TAXI_FILE_NAME, std::ifstream::app);

        if (!outputFileStream) {
            return false;
        }

        outputFileStream << taxi;

        outputFileStream.close();
        FileIO::trimWhitespaces(TAXI_FILE_NAME);
        return true;
    }

    std::vector<model::Taxi> FileIO::readTaxisFromFile() {
        std::ifstream inputFileStream;
        std::vector<model::Taxi> taxis;
        inputFileStream.open(TAXI_FILE_NAME);

        if (!inputFileStream) {
            return taxis;
        }

        while (!inputFileStream.eof()) {
            model::Taxi taxi;
            inputFileStream >> taxi;
            taxis.push_back(taxi);
        }

        inputFileStream.close();

        return taxis;
    }
}
