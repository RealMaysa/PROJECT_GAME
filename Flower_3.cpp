#include"Flower_3.h"
Flower_3::Flower_3(float x,float y){
   
    this->Fltexture.loadFromFile("texture/Flower_3.png");
    this->Flsprite.setTexture(this->Fltexture);
    //ปรับขนาดของSprite
    this->Flsprite.scale(1.5f,1.5f);
    this->points=1.f;
    this->Flsprite.setPosition(x,y);


}
Flower_3::~Flower_3(){



}
const int &Flower_3::getPoints() const{

    return this->points;
}
const sf::FloatRect Flower_3::getBounds() const{

 return this->Flsprite.getGlobalBounds();

}
void Flower_3::render(sf::RenderTarget *target){

    target->draw(this->Flsprite);
}