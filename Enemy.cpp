#include"Enemy.h"
void Enemy::initTexture(){

//โหลด texture จากไฟล์ไม่ได้
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
//Functions
void Enemy::update(){



}
void Enemy::render(sf::RenderTarget *target){
    target->draw(this->enemysprite);


}