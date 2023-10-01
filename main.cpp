#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Game.h"
#include "main_menu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1440, 810), "WAR OF GHOST" );
    window.setFramerateLimit(60);

    std::cout << "Hello World\n";

    main_menu menu(window);
    //Game game(window);
}
