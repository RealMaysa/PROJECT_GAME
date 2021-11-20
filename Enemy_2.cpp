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
this->enemyWsprite.scale(2.f,2.f);

}
void Enemy_2::initVariables(){
this->speed=-1.4f;
this->hpMax=50;
this->hp=this->hpMax;
this->points=300;
this->damage=20;


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


void Enemy_2::loseHp(int value){
    this->hp-=value;//set ทุกอย่างที่เข้ามาในนี้ให้ลบHp
   if(this->hp<0){
    this->hp=0;
        }
}
const sf::FloatRect Enemy_2::getBounds() const
{

    return this->enemyWsprite.getGlobalBounds();
}
const int &Enemy_2::getHp() const{
    return this->hp;
}
const int &Enemy_2::getHpMax() const{

    return this->hpMax;
}
void Enemy_2::setHp(int hp){


this->hp=hp;

}
const int &Enemy_2::getPoints() const{

    return this->points;
}
const int &Enemy_2::getDamage() const{

return this->damage;

}
const bool Enemy_2::canAttack(){

if(this->attackCooldown>=this->attackCooldownMax){
    this->attackCooldown=0.f;//ให้มันเริ่มนับใหม่
    return true;
}

    return false;
}
void Enemy_2::updateAttack(){
if(this->attackCooldown < this->attackCooldownMax){
    this->attackCooldown+=0.5f;//เพิ่มคูลดาวน์ทีละ0.5
    }

}
void Enemy_2::update(){

this->enemyWsprite.move(this->speed,0.f);
}

void Enemy_2::render(sf::RenderTarget *target){
    target->draw(this->enemyWsprite);


}