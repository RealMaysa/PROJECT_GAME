#ifndef BULLET_2_H
#define BULLET_2_H
#include<SFML/Graphics.hpp>
#include<iostream>
class Bullet_2
{
    sf::Sprite shape;
    sf::Vector2f direction;
    float movementSpeed;
private:
  
public:
     Bullet_2();
     Bullet_2(sf::Texture*texture,float pos_x,float pos_y,float dir_x,float dir_y,float movement_speed);
    virtual ~ Bullet_2();
//Accessor
const sf::FloatRect getBounds() const;//ระบุตำแหน่งของกระสุน

    void update();
    void render(sf::RenderTarget*target);
};
#endif