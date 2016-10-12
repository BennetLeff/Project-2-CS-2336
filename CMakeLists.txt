cmake_minimum_required(VERSION 3.5)
project(project_2_CS_2336)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    drinkitem.cpp
    drinkitem.h
    drinkmachine.h
    project2.cpp
    receipt.h drinkmachine.cpp receipt.cpp)

add_executable(project_2_CS_2336 ${SOURCE_FILES})