cmake_minimum_required(VERSION 3.16)
project(testServer)

set(CMAKE_CXX_STANDARD 20)

add_executable(testServer Server.cpp Cliente.cpp)