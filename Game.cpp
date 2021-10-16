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
//ตัวที่สร้างและทำลาย
Game::Game()
{
this->initWindow();
this->initPlayer();
this->initTextures();
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
    {
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
 this->player->move(-1.f,0.f);
if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
 this->player->move(1.f,0.f);
if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
 this->player->move(0.f,-1.f);
if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
 this->player->move(0.f,1.f);

//&& this->player->canAttack()
if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)&&this->player->canAttack()){
                                                                                                              //x //y //speed
this->bullets.push_back(new Bullet(this->textures["BULLET"],this->player->getPos().x,this->player->getPos().y,1.f,0.f,5.f));//สร้างกระสุนตำแหน่งเดียวกับผู้เล่น
}
 
 }

void Game::updateBullets(){
unsigned counter=0;
for(auto*bullet : this->bullets)
{
  bullet->update();
  //checkว่าชนขอบมั้ย
  if(bullet->getBounds().width+bullet->getBounds().top<0.f){
//Delete Bullet
delete this->bullets.at(counter);
this->bullets.erase(this->bullets.begin()+counter);
--counter;
  }
  ++counter;
}

}
void Game::updateEnemies(){
   this->spawnTimer+=0.5f;
 if(this->spawnTimer>=this->spawnTimerMax){
      this->enemies.push_back(new Enemy(1200+rand()%1400,rand()%1000));//บริเวณนี้จะมีการspawnเกิดขึ้น
      this->spawnTimer=0.f;

 }
 for(auto *enemy : this->enemies)
{
   enemy->update();

}


}
void Game::update(){
//update game logic การmove keyboard inputต่างๆ
this->pollEvents();
this->updateInput();
this->player->update();
this->updateBullets();
this->updateEnemies();


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
//Draw game objects//ให้ทุกอย่างrenderไปยังหน้าจอ
this->player->render(*this->window);

for(auto *bullet : this->bullets)
{
  bullet->render(this->window);

}

for(auto *enemy : this->enemies)
{
enemy->render(this->window);

}




this->window->display();


}
void Game::renderWorld(){

this->window->draw(this->worldbackground);



}