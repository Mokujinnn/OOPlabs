cmake_minimum_required(VERSION 3.5)

project(lab2)

file(GLOB CPPS "*.cpp")

add_executable(${PROJECT_NAME} ${CPPS})