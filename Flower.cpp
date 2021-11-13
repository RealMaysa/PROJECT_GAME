#include"Flower.h"
Flower::Flower(float x,float y){
   
    this->Fltexture.loadFromFile("texture/Flower.png");
    this->Flsprite.setTexture(this->Fltexture);
    //ปรับขนาดของSprite
    this->Flsprite.scale(0.4f,0.4f);
    this->points=1.f;
    this->Flsprite.setPosition(x,y);


}
Flower::~Flower(){



}
const int &Flower::getPoints() const{

    return this->points;
}
const sf::FloatRect Flower::getBounds() const{

 return this->Flsprite.getGlobalBounds();

}
void Flower::render(sf::RenderTarget *target){

    target->draw(this->Flsprite);
}