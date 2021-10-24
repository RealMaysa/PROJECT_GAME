#include"Game.h"

void Game::initWindow(){
//ปรับความกว้างความยาวของวินโดว์
this->videoMode.height=1200;
this->videoMode.width=1600;

this->window=new sf::RenderWindow(this->videoMode, "RED RIDING SHOOT",sf::Style::Titlebar | sf::Style::Close);
this->window->setFramerateLimit(144);
this->window->setVerticalSyncEnabled(false);
}
void Game::initTextures(){
//Add 
 this->textures["BULLET"]= new sf::Texture();
 this->textures["BULLET"]->loadFromFile("texture/bullet.png");
}

void Game::initGUI(){

 //Load Font
if(!this->font.loadFromFile("Font/ZF#2ndPixelus.ttf")){


   std::cout<< "ERROR"<<"\n";
}

//Init pointText
this->pointText.setFont(this->font);
this->pointText.setCharacterSize(100);
this->pointText.setFillColor(sf::Color::White);
this->pointText.setPosition(20.f,25.f);
//GameOver
this->gameOverText.setFont(this->font);
this->gameOverText.setCharacterSize(300);
this->gameOverText.setFillColor(sf::Color::White);
this->gameOverText.setPosition(1600/2.f-550.f,1200/2.f+this->gameOverText.getLocalBounds().height/2.f-300.f);
this->gameOverText.setString("GAME OVER");
//init player GUI
this->PlayerHpBar.setSize(sf::Vector2f(300.f,30.f));
this->PlayerHpBar.setFillColor(sf::Color::Black);
this->PlayerHpBar.setPosition(sf::Vector2f(20.f,20.f));
this->PlayerHpBarBack=this->PlayerHpBar;//ให้ขนาดมันเท่ากัน
this->PlayerHpBar.setFillColor(sf::Color::Green);

}
void Game::initPlayer(){

	this->player=new Player();
 
}
void Game::initEnemies(){

this->spawnTimerMax=50.f;//จะให้spawnศัตรูเร็วแค่ไหน
this->spawnTimer=this->spawnTimerMax;

}
void Game::initWorld(){
this->worldbackgroundTex.loadFromFile("texture/Forest.jpg");
this->worldbackground.setTexture(this->worldbackgroundTex);

}
void Game::initSystems(){

this->point=0;


}
//ตัวที่สร้างและทำลาย
Game::Game()
{
this->initWindow();
this->initPlayer();
this->initTextures();
this->initGUI();
this->initSystems();
this->initWorld();
this->initEnemies();

}

Game::~Game()
{
delete this->window;
delete this->player;

//Delete textures
for(auto&i:this->textures)
{
  delete i.second;

}
//Delete Bullets
for(auto *i : this-> bullets){

	delete i;
}
//Delete enemies
for(auto *i : this-> enemies){

	delete i;
}

}

//ฟังก์ชัน
void Game::run(){
    while(this->window->isOpen())
    {  this->pollEvents();
      if(this->player->getHp()>0)
        this->update();
        this->render();
    }
    

}
void Game::pollEvents(){         //ตอนนี้เราสร้างตัวแปรevของตัวเองแล้ว ที่จะติดตามทุกๆอย่าง
while(this->window->pollEvent(this->ev)){ //ตราบใดที่มีการทำงานของเกมอยู่จะถูกเก็บไว้ในตัวแปรvev polling=ยังทำงานไม่จบ
               switch (this->ev.type) //ในแต่ละevที่เกิดขึ้น จะมีการtypeเกิดขึ้น เป็นตัวแปรนึงในstructที่เช็คว่าผู้เล่นพิมอะไร
			   {
			   case sf::Event::Closed:
			      this->window->close();
				   break;
			   
			   case sf::Event::KeyPressed:
			     if(this->ev.key.code==sf::Keyboard::Escape)
				 this->window->close();
				   break;
			   }


		 }
}


void Game::updateInput(){
 //Move Player	
if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
 this->player->move(-2.f,0.f);
if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
 this->player->move(2.f,0.f);
if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
 this->player->move(0.f,-2.f);
if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
 this->player->move(0.f,2.f);

//&& this->player->canAttack()
if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)&&this->player->canAttack()){
                                                                                                              //x //y //speed
this->bullets.push_back(new Bullet(this->textures["BULLET"],this->player->getPos().x,this->player->getPos().y,1.f,0.f,5.f));//สร้างกระสุนตำแหน่งเดียวกับผู้เล่น
}
 
 }


void Game::updateGUI(){
std::stringstream ss;
ss<<"Score: "<<this->point;
this->pointText.setString(ss.str());
//Update Player GUI

float hpPercent=static_cast<float>(this->player->getHp())/this->player->getHpMax();
this->PlayerHpBar.setSize(sf::Vector2f(300.f*hpPercent,this->PlayerHpBar.getSize().y));

}
void Game::updateBullets(){
unsigned counter=0;
for(auto*bullet : this->bullets)
{
  bullet->update();
  //checkว่าชนขอบมั้ย
  if(bullet->getBounds().width+bullet->getBounds().left>=this->window->getSize().x){
//Delete Bullet
delete this->bullets.at(counter);
this->bullets.erase(this->bullets.begin()+counter);
  }
  ++counter;
}

}

void Game::updateWorld(){



}
void Game::updateCollision(){
  //เช็คชนกรอบ
   //Left 
  if(this->player->getBounds().left<0.f){

    this->player->setPosition(0.f,this->player->getBounds().top);
  }
  //Right
   if(this->player->getBounds().left+this->player->getBounds().width>=this->window->getSize().x){

    this->player->setPosition(this->window->getSize().x-this->player->getBounds().width,this->player->getBounds().top);
  }
  //Top
  if(this->player->getBounds().top<0.f){

    this->player->setPosition(this->player->getBounds().left,0.f);
  }
  //Bottom
  if(this->player->getBounds().top+this->player->getBounds().width>=this->window->getSize().y){

    this->player->setPosition(this->player->getBounds().left,this->window->getSize().y-this->player->getBounds().height);
  }
}
void Game::updateEnemies(){
  //spawning
   this->spawnTimer+=0.2f;
 if(this->spawnTimer>=this->spawnTimerMax){                //x             //y
      this->enemies.push_back(new Enemy(1200+rand()%1400,rand()%1000));//บริเวณนี้จะมีการspawnเกิดขึ้น
      this->spawnTimer=0.f;

 }  
 //update
 unsigned counter=0;
for(auto*enemy : this->enemies)
{
  enemy->update();
  //checkenemyว่าชนขอบมั้ย
  if(enemy->getBounds().left<0.f){ 
  //Delete enemy
 delete this->enemies.at(counter);
 this->enemies.erase(this->enemies.begin()+counter);
--counter;
  }
  //Player Enemy Collision
else if(enemy->getBounds().intersects(this->player->getBounds())){
this->player->loseHp(this->enemies.at(counter)->getDamage());
delete this->enemies.at(counter);
 this->enemies.erase(this->enemies.begin()+counter);
--counter;

  }
  ++counter;
      
 
}
  }
void Game::updateCombat(){
for(int i=0;i<this->enemies.size();++i)
{  bool enemy_deleted=false;
for (size_t k= 0; k < this->bullets.size()&& enemy_deleted==false; k++)
{
  if(this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds())){

    this->point+=this->enemies[i]->getPoints();
     delete this->enemies[i];
    this->enemies.erase(this->enemies.begin()+i);
    delete this->bullets[k];
    this->bullets.erase(this->bullets.begin()+k);
    enemy_deleted=true;
  }
}



}
}
void Game::update(){
//update game logic การmove keyboard inputต่างๆ
this->updateInput();
this->player->update();
this->updateCollision();
this->updateBullets();
this->updateEnemies();
this->updateCombat();
this->updateGUI();
this->updateWorld();


}
void Game::renderGUI(){


this->window->draw(this->pointText);
this->window->draw(this->PlayerHpBarBack);
this->window->draw(this->PlayerHpBar);

}
void Game::render(){
//แสดงตำแหน่ง คะแนน แสดงภาพให้เห็น
/* @return void
การRenderวัตถุ ขั้นตอนคือ
-เคลียเฟรมเก่าก่อน
-เรนเดอร์object
-display บน window

*/
//draw World

this->window->clear();//clearก่อนเสมอ
this->renderWorld();
//Draw game objects//ให้ทุกอย่างrenderไปยังหน้าจอ โดยจะเรนเดอร์เป็นลำดับจากบนไปล่างทับกันไปเรื่อยๆ ล่างสุดจะอยู่ด้านหน้าสุด
this->player->render(*this->window);


for(auto *enemy : this->enemies)
{
enemy->render(this->window);

}
for(auto *bullet : this->bullets)
{
  bullet->render(this->window);

}


this->renderGUI();
//Game over Screen
if(this->player->getHp()<=0){
 this->window->draw(this->gameOverText);

}
this->window->display();


}
void Game::renderWorld(){

this->window->draw(this->worldbackground);



}