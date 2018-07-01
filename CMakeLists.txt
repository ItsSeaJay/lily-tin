cmake_minimum_required(VERSION 3.1)

project(LilyTin)

set(SFML_STATIC_LIBRARIES TRUE)

# Define all of the files that this project will use
set(SOURCES
	src/Main.cpp
	src/Game.cpp
	src/GameObject.cpp
	src/Paddle.cpp)
set(INCLUDES
	src/Game.h
	src/GameObject.h
	src/Paddle.h)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)
add_executable(LilyTin ${SOURCES} ${INCLUDES})
target_link_libraries(LilyTin sfml-graphics sfml-audio)