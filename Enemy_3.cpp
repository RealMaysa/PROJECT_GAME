#include"Enemy_3.h"
void Enemy_3::initTexture(){

//โหลด texture จากไฟล์ไม่ได้และเซตtexture
if(!this->enemyWtexture.loadFromFile("texture/BigBoss.png")){

    std::cout<<"ERROR"<<"\n";
}
}

void Enemy_3::initEnemySprite(){
// Set texture to the sprite
this->enemyWsprite.setTexture(this->enemyWtexture);
//ปรับขนาดของSprite
this->enemyWsprite.scale(2.f,2.f);

}
void Enemy_3::initVariables(){
this->speed=-0.f;
this->hpMax=1000;
this->hp=this->hpMax;
this->points=5000;
this->damage=10;


}
Enemy_3::Enemy_3(float dirX,float dirY)
{   this->initTexture();
    this->initEnemySprite();
    this->initVariables();   
    this->enemyWsprite.setPosition(dirX,dirY);
       

}
Enemy_3::~Enemy_3()
{
   

}


void Enemy_3::loseHp(int value){
    this->hp-=value;//set ทุกอย่างที่เข้ามาในนี้ให้ลบHp
   if(this->hp<0){
    this->hp=0;
        }
}
const sf::FloatRect Enemy_3::getBounds() const
{

    return this->enemyWsprite.getGlobalBounds();
}
const int &Enemy_3::getHp() const{
    return this->hp;
}
const int &Enemy_3::getHpMax() const{

    return this->hpMax;
}
void Enemy_3::setHp(int hp){


this->hp=hp;

}
const int &Enemy_3::getPoints() const{

    return this->points;
}
const int &Enemy_3::getDamage() const{

return this->damage;

}
void Enemy_3::update(){

this->enemyWsprite.move(this->speed,0.f);
}

void Enemy_3::render(sf::RenderTarget *target){
    target->draw(this->enemyWsprite);


}