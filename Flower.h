#ifndef FLOWER_H
#define FLOWER_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Player.h"
class Flower
{
private:
  
   sf::Sprite Flsprite;
   sf::Texture Fltexture;
   int points;
  
public: 
    Player* players;
    Flower(float x,float y);
    ~Flower();
    const int& getPoints() const;
    const sf::FloatRect getBounds() const;
    void render(sf::RenderTarget*target);
};


#endif