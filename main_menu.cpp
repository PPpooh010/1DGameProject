#include "main_menu.h"
#include "Game.h"

main_menu::main_menu(sf::RenderWindow& window)
{

	font.loadFromFile("Fontgame.ttf");
	credit.setFont(font);
	credit.setString("HOW TO PALY");
	credit.setFillColor(sf::Color:: Black);
	credit.setCharacterSize(48);
	credit.setPosition(1037, 358);
	
	creadit_up.setFont(font);
	creadit_up.setString("PLAY");
	creadit_up.setFillColor(sf::Color::Black);
	creadit_up.setCharacterSize(48);
	creadit_up.setPosition(1105, 170);

	credit_down.setFont(font);
	credit_down.setString("SCORE BOARD");
	credit_down.setFillColor(sf::Color::Black);
	credit_down.setCharacterSize(46);
	credit_down.setPosition(1040, 545);

	Exit.setFont(font);
	Exit.setString("Exit");
	Exit.setFillColor(sf::Color::Black);
	Exit.setCharacterSize(48);
	Exit.setPosition(79, 698);

	//background
	BG_menu_tx.loadFromFile("menugame_warofghost.png");
	BG_menu_sp.setTexture(BG_menu_tx);
	BG_menu_sp.setPosition(0.f, 0.f);
	

	Loop(window);
}

void main_menu::Update(sf::RenderWindow& window, sf::Event& event)
{
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (event.type == sf::Event::KeyReleased ) {
			if (event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
			if (event.key.code == sf::Keyboard::Return) {
				Game game(window);
			}
		}
	}
}

void main_menu::Draw(sf::RenderWindow& window)
{
	window.draw(BG_menu_sp);
	window.draw(credit); //draw something
	window.draw(creadit_up);
	window.draw(credit_down);
	window.draw(Exit);
}

void main_menu::Loop(sf::RenderWindow& window)
{
	while (window.isOpen()) {
		sf::Event event;
		window.clear();
		Update(window , event);
		Draw(window);
		window.display();
	}
}
