#include"Player.h"
void Player::initVariables(){
this->movementSpeed=2.f;
this->attackCooldownMax=10.f;
this->attackCooldown=this->attackCooldownMax;
this->hpMax=100;
this->hp=this->hpMax;
this->level=1;
this->FlexpNext=10;
this->Flexp=0;
}
void Player::initTexture(){

//โหลด texture จากไฟล์ไม่ได้
if(!this->texture.loadFromFile("texture/RedV.2.png")){

    std::cout<< "ERROR::Player::initTexture::Could not load texture file"<<"\n";
}
}
void Player::initSprite(){

// Set texture to the sprite
this->sprite.setTexture(this->texture);
//ปรับขนาดของSprite
this->sprite.scale(1.5f,1.5f);
}
Player::Player()
{

this->initVariables();
 this->initTexture();
 this->initSprite();


}

Player::~Player()
{
}
//Acesssor
const sf::FloatRect Player::getBounds() const{

     return this->sprite.getGlobalBounds();
}

const sf::Vector2f &Player::getPos() const{

return this->sprite.getPosition(); //สร้างกระสุนในตำแหน่งผู้เล่น

}
void Player::move(float dirX, float dirY){

    this->sprite.move(this->movementSpeed*dirX,this->movementSpeed*dirY);
}

const int &Player::getHp() const{

return this->hp;

}
const int &Player::getHpMax() const{

return this->hpMax;

}

const int &Player::getFlexp() const{

   return this->Flexp;
}
const int &Player::getFlexpMax() const{

    return this->FlexpNext;
}
const int &Player::getLevel() const{

return this->level;

}
//MOdifier
void Player::setPosition(sf::Vector2f pos){

this->sprite.setPosition(pos);

}
void Player::setPosition(float x, float y){

this->sprite.setPosition(x,y);

}
void Player::setHp(int hp){


this->hp=hp;//set ทุกอย่างที่เข้ามาในนี้เป็นHP

}
void Player::loseHp(int value){

this->hp-=value;//set ทุกอย่างที่เข้ามาในนี้ให้ลบHp
if(this->hp<0){
    this->hp=0;
}

}
void Player::gainHp(int value){

this->hp+=value;//set ทุกอย่างที่เข้ามาในนี้ให้เพิ่มHp


}
void Player::gainFlexp(int exp){

this->Flexp+=exp;//set ทุกอย่างที่เข้ามาในนี้ให้ลบHp
this->UpdateLeveling();
 
    if(this->Flexp>=10){
    this->Flexp=0;
             }
}

//Functions
void Player::UpdateLeveling(){
 if(this->Flexp>=this->FlexpNext)
 {
     this->level++;
     this->Flexp-=this->FlexpNext;
     
 }



}
const bool Player::canAttack(){

if(this->attackCooldown>=this->attackCooldownMax){
    this->attackCooldown=0.f;//ให้มันเริ่มนับใหม่
    return true;
}

    return false;
}
void Player::updateAttack(){
if(this->attackCooldown < this->attackCooldownMax){
    this->attackCooldown+=0.5f;//เพิ่มคูลดาวน์ทีละ0.5
    }

}
void Player::update(){
this->updateAttack();
}
void Player::render(sf::RenderTarget& target){
 target.draw(this->sprite);
}





