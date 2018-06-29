Building your SFML project using the pre-made binaries is all well and good,
but what happens if you need to work with someone who doesn't compile C++
applications the same way you do?

CMake is a 'meta build system' that aims to solve this problem.
Unlike a complier that turns source code into executable binary data,
CMake instead takes source code and turns it into a build chain that can be
compiled into an executable.

This allows people to build and contribute to your project
regardless of what platform or IDE they use. A 'build chain' can be anything
from a Visual Studio solution to a series of makefiles.

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
#define PROJECT_NAME_VERSION_MAJOR @myproject_VERSION_MAJOR@
#define PROJECT_NAME_VERSION_MINOR @myproject_VERSION_MINOR@
```

# Installing SFML
Now that we have a program that uses SFML, we need to install the library itself.
Go to https://www.sfml-dev.org/download.php and obtain the latest stable version.
Unzip it to a suitable location on your computer, and copy the `lib` and `include`
folders into the root directory of your project.

# Configuring CMake
In order for CMake