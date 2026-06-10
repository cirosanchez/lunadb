cmake_minimum_required(VERSION 3.20)

project(lunadb)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE ALL_SOURCES src/*.cpp include/*.hpp)

add_executable(lunadb ${ALL_SOURCES})