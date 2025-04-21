cmake_minimum_required(VERSION 3.30)
project(PrototypePattern)

set(CMAKE_CXX_STANDARD 20)

add_executable(PrototypePattern main.cpp
        PrototypeRegistry.hpp
        AsciiImage.hpp)
