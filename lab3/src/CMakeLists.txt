cmake_minimum_required(VERSION 3.5)

project(lab1)

# устанавливаем путь до корневого каталога SFML
set(SFML_ROOT_DIR "../buildsfmlwin")

# # Генерируем SFML_DIR на основании SFML_ROOT_DIR
set(SFML_DIR "${SFML_ROOT_DIR}")

option(SFML_USE_STATIC_STD_LIBS ON)
option(BUILD_SHARED_LIBS ON)


find_package(SFML 2.6.0 REQUIRED COMPONENTS system window graphics main)
# set(SFML_STATIC_LIBRARIES TRUE)


set(SFML_LIBRARIES 
    "sfml-system sfml-window sfml-graphics")

#Выводим список библиотек
message(STATUS "SFML libraries: ${SFML_LIBRARIES}")

# file(GLOB CPPS "*.cpp")

add_executable(lab3-1 main.cpp tPoint.cpp)
target_link_libraries(lab3-1 sfml-system sfml-window sfml-graphics sfml-main)
target_include_directories(lab3-1 PUBLIC "..\\SFML-2.6.0\\include")
set(SFML_STATIC_LIBRARIES TRUE)

add_executable(lab3-2 main2.cpp tPoint.cpp)
target_link_libraries(lab3-2 sfml-system sfml-window sfml-graphics sfml-main)
target_include_directories(lab3-2 PUBLIC "..\\SFML-2.6.0\\include")
set(SFML_STATIC_LIBRARIES TRUE)
