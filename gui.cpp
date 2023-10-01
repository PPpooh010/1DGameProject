#include "gui.h"

gui::gui() {

}

void gui::Init()
{
	// HP BAR
	player1HpBarBG.setOrigin(0, 0);
	player1HpBarBG.setSize(sf::Vector2f(300, 20));
	player1HpBarBG.setFillColor(sf::Color::Black);
	player1HpBarBG.setPosition(20, 20);

	player1HpBar.setOrigin(0, 0);
	player1HpBar.setFillColor(sf::Color::Red);
	player1HpBar.setPosition(20, 20);

	player2HpBarBG.setSize(sf::Vector2f(300, 20));
	player2HpBarBG.setFillColor(sf::Color::Black);
	player2HpBarBG.setPosition(1117, 20);

	player2HpBar.setFillColor(sf::Color::Red);
	player2HpBar.setPosition(1117, 20);


	//Stamina BAR
	player1StaminaBarBG.setSize(sf::Vector2f(250, 20));
	player1StaminaBarBG.setFillColor(sf::Color::White);
	player1StaminaBarBG.setPosition(20, 60);

	player1StaminaBar.setOrigin(0, 0);
	player1StaminaBar.setFillColor(sf::Color::Blue);
	player1StaminaBar.setPosition(20, 60);

	player2StaminaBarBG.setSize(sf::Vector2f(250, 20));
	player2StaminaBarBG.setFillColor(sf::Color::White);
	player2StaminaBarBG.setPosition(1168, 60);

	player2StaminaBar.setOrigin(0, 0);
	player2StaminaBar.setFillColor(sf::Color::Blue);
	player2StaminaBar.setPosition(1168, 60);

}

void gui::Update(int player1HP, int player2HP , float Stamina_player1, float Stamina_player2)
{
	player1HpBar.setSize(sf::Vector2f((float)player1HP / 3000 * 300, 20));
	player2HpBar.setSize(sf::Vector2f((float)player2HP / 3000 * 300, 20));
	player1StaminaBar.setSize(sf::Vector2f((float)Stamina_player1 / 100.f * 250, 20));
	player2StaminaBar.setSize(sf::Vector2f((float)Stamina_player2 / 100.f * 250, 20));
}

void gui::Draw(sf::RenderWindow& window)
{
	//HP BAR
	window.draw(player1HpBarBG);
	window.draw(player1HpBar);
	
	window.draw(player2HpBarBG);
	window.draw(player2HpBar);

	//Stamina BAR 
	window.draw(player1StaminaBarBG);
	window.draw(player1StaminaBar);

	window.draw(player2StaminaBarBG);
	window.draw(player2StaminaBar);

}
