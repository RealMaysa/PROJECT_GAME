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
  int hp;
  int hpMax;
  

  //Private Functions
  void initVariables();
  void initTexture();
  void initSprite();
 
public:
    Player();
    virtual~Player();
     //Accessor
  const sf::FloatRect getBounds() const;
  const sf::Vector2f&getPos()const;
  const int&getHp() const;
  const int&getHpMax() const;
   //Modifier
   void setPosition(const sf::Vector2f pos);
   void setPosition(const float x,const float y);
   void setHp(const int hp);
   void loseHp(const int value);
    //Functions
    void move(const float dirX,const float dirY);
    const bool canAttack();//ถ้า attack แล้วจะreset
    void updateAttack();
    void update();
    void render(sf::RenderTarget& target);
};


