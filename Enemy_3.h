#ifndef ENEMY_3_H
#define ENEMY_3_H
#include<SFML/Graphics.hpp>
#include<iostream>

//มีเรื่องรูปร่างของศัตรู HP และ Damageของแต่ละตัว
class Enemy_3
{
private:
  sf::Sprite enemyWsprite;
  sf::Texture enemyWtexture;
  float movementSpeed;
    int hp;
    int hpMax;
    float speed;
    int damage;
    int points;
    void initTexture();
    void initEnemySprite();
    void initVariables();
public:
    Enemy_3(float dirX,float dirY);
    virtual ~Enemy_3();
    //Acesssor
    const sf::FloatRect getBounds() const;
    const int& getPoints() const;
    const int& getDamage() const;
    void loseHp(const int value);
    void setHp(const int hp);
    const int&getHp() const;
    const int&getHpMax() const;
    inline const bool isDead()const{return this->hp==0;}
    void update();
    void render(sf::RenderTarget*target);
};

#endif