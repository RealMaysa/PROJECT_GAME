#ifndef FLOWER_3_H
#define FLOWER_3_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Player.h"
class Flower_3
{
private:
  
   sf::Sprite Flsprite;
   sf::Texture Fltexture;
   int points;
  
public: 
    Player* players;
    Flower_3(float x,float y);
    ~Flower_3();
    const int& getPoints() const;
    const sf::FloatRect getBounds() const;
    void render(sf::RenderTarget*target);
};


#endif