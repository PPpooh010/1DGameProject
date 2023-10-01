#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <vector>

class PlayerMovement
{
public:
    PlayerMovement(sf::Sprite& sprite, sf::Texture& texture , float scale);

    void moveLeft();
    void moveRight();
    void update();

   

private:
    sf::Sprite& playerSprite;
    sf::Texture& playerTexture;
    int currentFrame;
    sf::Clock frameClock;
    sf::Time frameTime;
    
    bool isDPressed;
    bool isAPressed;

};

