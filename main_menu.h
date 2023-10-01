#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class main_menu
{
public:
	main_menu(sf::RenderWindow &window );
	void Update(sf::RenderWindow &window , sf::Event &event) ;
	void Draw(sf::RenderWindow &window );
	void Loop(sf::RenderWindow &window );

	sf::Font font;
	sf::Text credit;
	sf::Text creadit_up; 
	sf::Text credit_down;
	sf::Text Exit;

	//background 
	sf::Sprite BG_menu_sp;
	sf::Texture BG_menu_tx;
};

