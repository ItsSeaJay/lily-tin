cmake_minimum_required(VERSION 3.1)

project(LilyTin)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(LilyTin src/Main.cpp)
target_link_libraries(LilyTin sfml-graphics sfml-audio)