#ifndef ENEMY_H
#define ENEMY_H
#include<SFML/Graphics.hpp>
#include<iostream>
//มีเรื่องรูปร่างของศัตรู HP และ Damageของแต่ละตัว
class Enemy
{
private:
  sf::Sprite enemysprite;
  sf::Texture enemytexture;
  sf::Sprite enemyWsprite;
  sf::Texture enemyWtexture;
  float movementSpeed;
    int type;
    int speed;
    int hp;
    int hpMax;
    int damage;
    int points;
    void initTexture();
    void initEnemySprite();
    void initVariables();
public:
    Enemy(float dirX,float dirY);
    virtual ~Enemy();
    //Acesssor
    const sf::FloatRect getBounds() const;
    const int& getPoints() const;
    const int& getDamage() const;
    void update();
    void render(sf::RenderTarget*target);
};

#endif
