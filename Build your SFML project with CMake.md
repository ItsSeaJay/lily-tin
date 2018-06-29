Building your SFML project using the pre-made binaries is all well and good,
but what happens if you need to work with someone who doesn't compile C++
applications the same way you do?

CMake is a 'meta build system' that aims to solve this problem.
Unlike a complier that turns source code into executable binary data,
CMake instead takes source code and turns it into a build chain that can be
compiled into an executable. A 'build chain' in this context can be anything
from a Visual Studio solution to a series of makefiles.

Setting up your build chain through CMake instead of doing it yourself allows
people to build and contribute to your project regardless of what platform or
IDE they use.

In this tutorial, we'll write a simple CMake configuration file with centralized
version numbering, and see how to integrate SFML in it. This example is not for
compiling SFML using CMake but for creating an example project that uses the
SFML library.

# The Source Files
First, you'll need to create a folder for your project with the following
structure:

```
project-name/
	- bin/
	- src/
```

Next, create a file called `Main.cpp` inside the `src` folder, and fill it with
some test code:

```cpp
#include <SFML/Window.hpp>

int main()
{
    sf::Window window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}
```

This show a window to the end user, which they can close using their operating
system. We'll also add a `config.h` in the `src` folder to hold our project's
version number:

```cpp
#define PROJECT_NAME_VERSION_MAJOR @PROJECT_NAME_VERSION_MAJOR@
#define PROJECT_NAME_VERSION_MINOR @PROJECT_NAME_VERSION_MINOR@
```

# Installing SFML
Now that we have a program that uses SFML, we need to install the library itself.
Go to https://www.sfml-dev.org/download.php and obtain the latest stable version
for your desired compiler. Unzip it to a suitable location on your computer
outside the project directory, and copy the `lib` and `include` folders into the
root directory of your project.

# Configuring CMake
Let's describe our project configuration in the `CMakeLists.txt` file:

```cmake
cmake_minimum_required(VERSION 3.1)

# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

# Set version information in a config.h file
set(myproject_VERSION_MAJOR 1)
set(myproject_VERSION_MINOR 0)
configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
include_directories("${PROJECT_BINARY_DIR}")

# Set the name of the project
project(SFMLTest)

# This tutorial is configured to use static libraries,
# but you can remove this line if you want to use dynamic ones
set(SFML_STATIC_LIBRARIES TRUE)

# Find the SFML package and install the necessary components
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
# Configure each of the source files to be compiled as an executable
# You don't need to include header files this way
add_executable(SFMLTest src/Main.cpp)
# Link all of the libraries to the executable
target_link_libraries(SFMLTest sfml-graphics sfml-audio)
```

# Additional libraries

Here are a few examples of commonly used C/C++ libraries:

```cmake
# OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
if (OPENGL_FOUND)
  target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_LIBRARIES})
  # or: target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_gl_LIBRARY})
  target_link_libraries(${EXECUTABLE_NAME} m)  # if you use maths.h
endif()
```
```cmake
# boost::filesystem
#set(Boost_ADDITIONAL_VERSIONS "1.78" "1.78.0" "1.79" "1.79.0")
find_package(Boost 1.34.0 REQUIRED system filesystem)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  target_link_libraries(${EXECUTABLE_NAME} ${Boost_LIBRARIES})
endif()
```
```cmake
# pkg-config-based library
include(FindPkgConfig)
pkg_check_modules(yaml-cpp REQUIRED yaml-cpp>=0.2.5)
if(yaml-cpp_FOUND)
  include_directories(${yaml-cpp_INCLUDE_DIRS})
  link_directories(${yaml-cpp_LIBRARY_DIRS})
endif()
add_executable(${EXECUTABLE_NAME} ${SOURCES})
target_link_libraries(${EXECUTABLE_NAME} ${yaml-cpp_LIBRARIES})
...
```
Note: because `link_directories` needs to be called before a target is created, if you use the pkg-config snippet, you need to move your `add_executable` and `target_link_libraries` calls _after_ the call to `link_directories`.

# Configuration

To configure a CMake project, execute `cmake ..` (where `..` is the relative path to your CMakeLists.txt created above).

At this point you may also specify a specific Generator by adding the `-G` flag to the cmake command, e.g. `cmake .. -G"Xcode"`. For a full list of generators run `cmake --help`

At this point your project may complain that SFML is not found. If you have installed SFML to a non-standard place, then you will need to set the SFML_ROOT variable so it can be found, e.g. `cmake .. -G"Xcode" -DSFML_ROOT=/path/to/sfml`
 
# Compilation

At this point you should have generated project files in the folder you executed cmake from. You can use these directly as you normally would, or you can use cmake's build command: `cmake --build .`
 
# Installation

To install your project, build the install target. If you're using the cmake build command, you can add `--target install`

You can also define `CMAKE_INSTALL_PREFIX` when invoking `cmake` to change the default install path (`/usr/local` under Unix).  
```bash
cmake -D CMAKE_INSTALL_PREFIX=/usr ..
```

If you want to check a variable's value, open `CMakeCache.txt`, they are all there!

# Packaging

To package your project into an archive/installer, just build the package target

```bash
cmake --build . --target package
```

By default this usually just creates a compressed archive with your installed files, but it is highly configurable. See CMake/CPack documentation for more info

# Further information

* CMake has built-in help, for instance:
```bash
$ cmake --help-variable CMAKE_SOURCE_DIR
cmake version 2.8.5
  CMAKE_SOURCE_DIR
       The path to the top level of the source tree.

       This is the full path to the top level of the current CMake source
       tree.  For an in-source build, this would be the same as
       CMAKE_BINARY_DIR.
```

* [CMake reference for version 2.8](http://www.cmake.org/cmake/help/cmake-2-8-docs.html)
* [CMake Tutorial](http://www.cmake.org/cmake/help/cmake_tutorial.html)
* [CMake tutorial en français](http://geenux.wordpress.com/2009/12/27/utilisation-de-cmake/)

-- [Beuc](http://www.beuc.net/) & the other members of the SFML community