#include"Bullet_2.h"

//ทุกอย่างของการแสดงbullet
 Bullet_2:: Bullet_2(sf::Texture*texture,float pos_x,float pos_y,float dir_x,float dir_y,float movement_speed){

this->shape.setTexture(*texture);
this->shape.setPosition(pos_x,pos_y);
this->direction.x= dir_x;
this->direction.y= dir_y;
this->movementSpeed = movement_speed;
this->shape.scale(4.f,4.f);

}


 Bullet_2::~ Bullet_2()
{
}

const sf::FloatRect  Bullet_2::getBounds() const
{

    return this->shape.getGlobalBounds();
}
void  Bullet_2::update(){
//MOVEMENT
this->shape.move(this->movementSpeed * this->direction);


}
void  Bullet_2::render(sf::RenderTarget * target){


target->draw(this->shape);

}
