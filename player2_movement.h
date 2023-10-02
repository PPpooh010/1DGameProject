#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <vector>

class Player2Movement
{
public:
    Player2Movement(sf::Sprite& sprite, sf::Texture& texture, float scale);

    void moveLeft2();
    void moveRight2();
    void update2();

    float scale_player;
private:
    sf::Sprite& playerSprite;
    sf::Texture& playerTexture;
    int currentFrame;
    float scale;
    sf::Clock frameClock;
    sf::Time frameTime;

    sf::Clock set_scale; 
    bool isRight_Pressed;
    bool isLeft_Pressed;

};

