#include"mainMenu.h"

mainMenu::mainMenu(float w, float h)
{if(!this->font.loadFromFile("Font/ZF#2ndPixelus.ttf")){


   std::cout<< "ERROR"<<"\n";
}
menu[0].setFont(font);
menu[0].setFillColor(sf::Color::Red);
menu[0].setString("PLAY");
menu[0].setPosition(sf::Vector2f(w/2,h/(MAX_FUNCT+1)*1));

menu[1].setFont(font);
menu[1].setFillColor(sf::Color::White);
menu[1].setString("LEADERBOARD");
menu[1].setPosition(sf::Vector2f(w/2,h/(MAX_FUNCT+1)*1));

menu[2].setFont(font);
menu[2].setFillColor(sf::Color::White);
menu[2].setString("EXIT");
menu[2].setPosition(sf::Vector2f(w/2,h/(MAX_FUNCT+1)*1));
}

mainMenu::~mainMenu()
{
}
void mainMenu::draw(sf::RenderWindow*& window){

   for(int i=0; i<MAX_FUNCT;i++)
   {
      window->draw(menu[i]);
   }
}
