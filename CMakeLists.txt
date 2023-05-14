cmake_minimum_required(VERSION 3.24)
project(a6_NorbyInfoGod_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(a6_NorbyInfoGod_1
        main.cpp
        repository.h
        service.h
        tutorial.h
        ui.h watchlist.h)
