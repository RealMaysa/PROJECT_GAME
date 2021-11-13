#include"Flower_2.h"
Flower_2::Flower_2(float x,float y){
   
    this->Fltexture.loadFromFile("texture/Flower_2.png");
    this->Flsprite.setTexture(this->Fltexture);
    //ปรับขนาดของSprite
    this->Flsprite.scale(1.f,1.f);
    this->points=1.f;
    this->Flsprite.setPosition(x,y);


}
Flower_2::~Flower_2(){



}
const int &Flower_2::getPoints() const{

    return this->points;
}
const sf::FloatRect Flower_2::getBounds() const{

 return this->Flsprite.getGlobalBounds();

}
void Flower_2::render(sf::RenderTarget *target){

    target->draw(this->Flsprite);
}