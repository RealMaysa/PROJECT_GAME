#ifndef FLOWER_2_H
#define FLOWER_2_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Player.h"
class Flower_2
{
private:
  
   sf::Sprite Flsprite;
   sf::Texture Fltexture;
   int points;
  
public: 
    Player* players;
    Flower_2(float x,float y);
    ~Flower_2();
    const int& getPoints() const;
    const sf::FloatRect getBounds() const;
    void render(sf::RenderTarget*target);
};


#endif