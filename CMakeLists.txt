cmake_minimum_required(VERSION 3.27)
project(TaxiRoutes)

set(CMAKE_CXX_STANDARD 23)

add_executable(TaxiRoutes main.cpp
        Taxi.h
        Route.h
        UserIO.h
        Display.h
        FileIO.h
)
