cmake_minimum_required(VERSION 3.3)
project(ex01)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ConvexHull.cpp Point.h PointSet.h Point.cpp PointSet.cpp)
add_executable(ex01 ${SOURCE_FILES})