#include"Player.h"
void Player::initVariables(){
this->movementSpeed=1.f;
this->attackCooldownMax=10.f;
this->attackCooldown=this->attackCooldownMax;

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

const sf::Vector2f &Player::getPos() const{

return this->sprite.getPosition(); //สร้างกระสุนในตำแหน่งผู้เล่น

}
void Player::move(float dirX, float dirY){

    this->sprite.move(this->movementSpeed*dirX,this->movementSpeed*dirY);
}
//Functions
const bool Player::canAttack(){

if(this->attackCooldown>=this->attackCooldownMax){
    this->attackCooldown=0.f;
    return true;
}

    return false;
}
void Player::updateAttack(){
if(this->attackCooldown < this->attackCooldownMax){
    this->attackCooldown+=0.5f;
    }

}
void Player::update(){
this->updateAttack();
}
void Player::render(sf::RenderTarget& target){
 target.draw(this->sprite);
}





