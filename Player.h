#ifndef PLAYER_H
#define PLAYER_H 
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include<math.h>
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
  int level;
  int Flexp;
  int FlexpNext;
  

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
  const int&getFlexp() const ;
  const int&getFlexpMax() const;
  const int&getLevel() const;
   //Modifier
   void setPosition(const sf::Vector2f pos);
   void setPosition(const float x,const float y);
   void setHp(const int hp);
   void loseHp(const int value);
   void gainHp(const int hp);
  
   void gainFlexp(const int exp);
    //Functions
    void UpdateLeveling();
    void move(const float dirX,const float dirY);
    const bool canAttack();//ถ้า attack แล้วจะreset
    void updateAttack();
    void update();
    void render(sf::RenderTarget& target);
};
#endif


