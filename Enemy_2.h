#ifndef ENEMY_2_H
#define ENEMY_2_H
#include<SFML/Graphics.hpp>
#include<iostream>

//มีเรื่องรูปร่างของศัตรู HP และ Damageของแต่ละตัว
class Enemy_2
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
    float attackCooldown;
    float attackCooldownMax;
    void initTexture();
    void initEnemySprite();
    void initVariables();
public:
    Enemy_2(float dirX,float dirY);
    virtual ~Enemy_2();
    //Acesssor
    const sf::FloatRect getBounds() const;
    const int& getPoints() const;
    const int& getDamage() const;
    void loseHp(const int value);
    void setHp(const int hp);
    const int&getHp() const;
    const int&getHpMax() const;
    const bool canAttack();
    void updateAttack();
    inline const bool isDead()const{return this->hp==0;}
    void update();
    void render(sf::RenderTarget*target);
};

#endif