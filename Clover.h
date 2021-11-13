#ifndef CLOVER_H
#define CLOVER_H
#include<SFML/Graphics.hpp>
#include<iostream>
class Clover
{
private:
   //Clover
   sf::Sprite Closprite;
   sf::Texture Clotexture;
   int heal;
public:
    Clover(float x,float y);
    
    ~Clover();
    const sf::FloatRect getBounds() const;
    const int& getHP() const;
    void render(sf::RenderTarget*target);
};


#endif