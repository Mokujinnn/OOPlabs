cmake_minimum_required(VERSION 3.5)

project(lab1)

# set(SFML_STATIC_LIBRARIES TRUE)

# set(BUILD_SHARED_LIBS OFF)
# set(SFML_USE_STATIC_STD_LIBS TRUE)

add_subdirectory(SFML-2.6.0)
add_subdirectory(src)
# устанавливаем путь до корневого каталога SFML
# set(SFML_ROOT_DIR "SFML-2.6.0")

# # Генерируем SFML_DIR на основании SFML_ROOT_DIR
# set(SFML_DIR "${SFML_ROOT_DIR}/cmake")

# # find_package(SFML 2.6.0 REQUIRED 
# #     COMPONENTS audio graphics window system)

# set(SFML_LIBRARIES 
#     "-lsfml-system-s -lsfml-window-s -lsfml-audio-s -lsfml-graphics-s")

# #Выводим список библиотек
# message(STATUS "SFML libraries: ${SFML_LIBRARIES}")

# file(GLOB CPPS "*.cpp")

# add_executable(${PROJECT_NAME} ${CPPS})
# target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

