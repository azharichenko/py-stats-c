cmake_minimum_required(VERSION 3.12)
project(stats)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


find_package(Python3 COMPONENTS Interpreter Development)
find_package(Boost 1.71.0 REQUIRED COMPONENTS python)

message(STATUS "PYTHON_LIBRARIES = ${Python3_LIBRARY}")
message(STATUS "PYTHON_EXECUTABLE = ${Python3_EXECUTABLE}")
message(STATUS "PYTHON_INCLUDE_DIRS = ${Python3_INCLUDE_DIRS}")
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS} ${Python3_INCLUDE_DIRS})
#LINK_DIRECTORIES(${Boost_LIBRARIES} ${Python3_LIBRARY})

Python3_add_library(stats MODULE statistics.cpp)

FILE(COPY test.py DESTINATION .)