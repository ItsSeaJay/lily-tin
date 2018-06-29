cmake_minimum_required(VERSION 3.1)

project(LilyTin)

set(SFML_STATIC_LIBRARIES TRUE)

# Define all of the files that this project will use
set(SOURCES
	src/Main.cpp
	src/Game.cpp
	src/GameObject.cpp)
set(INCLUDES
	include/Game.h
	include/GameObject.h)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(LilyTin ${SOURCES} ${INCLUDES})
target_link_libraries(LilyTin sfml-graphics sfml-audio)