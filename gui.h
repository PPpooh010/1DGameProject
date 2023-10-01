#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class gui
{
public:
	sf::RectangleShape player1HpBarBG;
	sf::RectangleShape player1HpBar;

	sf::RectangleShape player2HpBarBG;
	sf::RectangleShape player2HpBar;

	sf::RectangleShape player1StaminaBarBG;
	sf::RectangleShape player1StaminaBar;

	sf::RectangleShape player2StaminaBarBG;
	sf::RectangleShape player2StaminaBar;


	gui();

	void Init();
	void Update(int player1HP, int player2HP , float Stamina_player1 , float Stamina_player2);
	void Draw(sf::RenderWindow& window);
};

