#include "config.h"
#include <iostream>
#include <Graphics.hpp>
using namespace std;

int main(int argc, char* argv[]) {

	sf::Window App(sf::VideoMode(800, 600), "myproject");

	while (App.isOpen()) {
		sf::Event Event;
		while (App.pollEvent(Event)) {
			if (Event.type == sf::Event::Closed)
				App.close();
		}
		App.display();
	}
}