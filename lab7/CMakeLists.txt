cmake_minimum_required(VERSION 3.5)

project(lab7)

file(GLOB CPPS "src/*.cpp")

add_executable(${PROJECT_NAME} ${CPPS})
target_include_directories(${PROJECT_NAME} PUBLIC "include")
