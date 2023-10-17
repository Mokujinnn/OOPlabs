cmake_minimum_required(VERSION 3.5)

project(lab6)

# устанавливаем путь до корневого каталога SFML
set(SFML_ROOT_DIR "../SFMLbuild")

# # Генерируем SFML_DIR на основании SFML_ROOT_DIR
set(SFML_DIR "${SFML_ROOT_DIR}")

# set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.6.0 REQUIRED COMPONENTS system window graphics main)
set(SFML_STATIC_LIBRARIES TRUE)
# set(BUILD_SHARED_LIBS OFF)

set(SFML_LIBRARIES 
    "sfml-system sfml-window sfml-graphics")

#Выводим список библиотек
message(STATUS "SFML libraries: ${SFML_LIBRARIES}")

file(GLOB CPPS "src/*.cpp")

add_executable(${PROJECT_NAME} ${CPPS})
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-main)
target_include_directories(${PROJECT_NAME} PUBLIC "include")
# set(SFML_STATIC_LIBRARIES TRUE)