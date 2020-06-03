cmake_minimum_required(VERSION 2.4)

project(dpks2)

include_directories(include/)

file(GLOB SOURCES source/*.cpp)

add_executable(main ${SOURCES})






