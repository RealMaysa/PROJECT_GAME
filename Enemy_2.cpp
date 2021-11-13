#include"Enemy_2.h"
void Enemy_2::initTexture(){

//โหลด texture จากไฟล์ไม่ได้และเซตtexture
if(!this->enemyWtexture.loadFromFile("texture/WOLF.png")){

    std::cout<<"ERROR"<<"\n";
}
}

void Enemy_2::initEnemySprite(){
// Set texture to the sprite
this->enemyWsprite.setTexture(this->enemyWtexture);
//ปรับขนาดของSprite
this->enemyWsprite.scale(3.f,3.f);

}
void Enemy_2::initVariables(){
this->speed=-1.7f;
this->hp=0;
this->hpMax=10;
this->points=100;
this->damage=10;


}
Enemy_2::Enemy_2(float dirX,float dirY)
{   this->initTexture();
    this->initEnemySprite();
    this->initVariables();   
    this->enemyWsprite.setPosition(dirX,dirY);
       

}
Enemy_2::~Enemy_2()
{
   

}



const sf::FloatRect Enemy_2::getBounds() const
{

    return this->enemyWsprite.getGlobalBounds();
}
const int &Enemy_2::getPoints() const{

    return this->points;
}
const int &Enemy_2::getDamage() const{

return this->damage;

}
void Enemy_2::update(){

this->enemyWsprite.move(this->speed,0.f);

}

void Enemy_2::render(sf::RenderTarget *target){
    target->draw(this->enemyWsprite);


}