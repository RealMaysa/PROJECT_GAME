#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<iostream>
class Player
{
private:
  sf::Sprite sprite;
  sf::Texture texture;
  float movementSpeed;
  float attackCooldown;
  float attackCooldownMax;//เมื่อค่าถึงmaxแล้วค่อยจะยิงได้
  //Private Functions
  void initVariables();
  void initTexture();
  void initSprite();
 
public:
    Player();
    virtual~Player();
     //Accessor

  const sf::Vector2f&getPos()const;

    //Functions
    void move(const float dirX,const float dirY);
    const bool canAttack();//ถ้า attack แล้วจะreset
    void updateAttack();
    void update();
    void render(sf::RenderTarget& target);
};


