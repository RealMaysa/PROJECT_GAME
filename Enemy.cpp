#include"Enemy.h"
void Enemy::initTexture(){

//โหลด texture จากไฟล์ไม่ได้และเซตtexture
if(!this->enemytexture.loadFromFile("texture/BABYWOLF.png")){

    std::cout<< "ERROR"<<"\n";
}
}
void Enemy::initEnemySprite(){
// Set texture to the sprite
this->enemysprite.setTexture(this->enemytexture);
//ปรับขนาดของSprite
this->enemysprite.scale(2.f,2.f);

}

void Enemy::initVariables(){
this->damage =0;
this->speed=-1.f;
this->hp=0;
this->hpMax=10;
this->points=100;
this->damage=10;


}
Enemy::Enemy(float dirX,float dirY)
{   this->initTexture();
    this->initEnemySprite();
    this->initVariables();   
    this->enemysprite.setPosition(dirX,dirY);
       

}

Enemy::~Enemy()
{
   

}

//Acesssors
const sf::FloatRect Enemy::getBounds() const
{

    return this->enemysprite.getGlobalBounds();
}
const int &Enemy::getPoints() const{

    return this->points;
}
const int &Enemy::getDamage() const{

return this->damage;

}
//Functions
void Enemy::update(){

this->enemysprite.move(this->speed,0.f);

}
void Enemy::render(sf::RenderTarget *target){
    target->draw(this->enemysprite);


}