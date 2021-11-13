#include"Clover.h"


Clover::Clover(float x,float y)
{   this->Clotexture.loadFromFile("texture/Clover.png");
    this->Closprite.setTexture(this->Clotexture);
    //ปรับขนาดของSprite
    this->Closprite.scale(1.3f,1.3f);
    this->heal=20.f;
    this->Closprite.setPosition(x,y);

}
Clover::~Clover(){



}
const int &Clover::getHP() const{

    return this->heal;
}
const sf::FloatRect Clover::getBounds() const{
   
  return this->Closprite.getGlobalBounds();

}

void Clover::render(sf::RenderTarget *target){

    target->draw(this->Closprite);
}