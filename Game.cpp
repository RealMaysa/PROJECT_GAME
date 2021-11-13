#include"Game.h"
#include"mainMenu.h"
#include"TextBox.h"
using namespace std;
void Game::initWindow(){
//ปรับความกว้างความยาวของวินโดว์
this->videoMode.height=1200;
this->videoMode.width=1600;

this->window=new sf::RenderWindow(this->videoMode, "RED RIDING SHOOT",sf::Style::Titlebar | sf::Style::Close);
this->window->setFramerateLimit(144);
this->window->setVerticalSyncEnabled(false);
 
}
/*void Game::initState(){

this->states.push(new GameState(this->window));
}*/
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
this->pointText.setPosition(20.f,20.f);
//Init FlowerText
this->FlexpText.setFont(this->font);
this->FlexpText.setCharacterSize(100);
this->FlexpText.setFillColor(sf::Color::White);
this->FlexpText.setPosition(20.f,70.f);
//Level
this->LevelText.setFont(this->font);
this->LevelText.setCharacterSize(70);
this->LevelText.setFillColor(sf::Color::White);
this->LevelText.setPosition(20.f,150.f);
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
void Game::initMainMenuText(){
//Main menu 
this->StartText.setFont(this->font);
this->StartText.setCharacterSize(150);
this->StartText.setFillColor(sf::Color::White);
this->StartText.setPosition(1000,500);
this->StartText.setString("START");
this->ExitText.setFont(this->font);
this->ExitText.setCharacterSize(150);
this->ExitText.setFillColor(sf::Color::White);
this->ExitText.setPosition(1000,600);
this->ExitText.setString("EXIT");

this->LeaderBoardText.setFont(this->font);
this->LeaderBoardText.setCharacterSize(150);
this->LeaderBoardText.setFillColor(sf::Color::White);
this->LeaderBoardText.setPosition(800,700);
this->LeaderBoardText.setString("LEADERBOARD");


}
void Game::initTextBox(){

  /*TextBox TextboxText(15,sf::Color::White,false);
  this->TextboxText.setFont(this->font);
  this->TextboxText.setPosition(200,200);*/
  this->nameplayer.setFont(this->font);
  this->nameplayer.setPosition(800.f,200.f);
  this->nameplayer.setFillColor(sf::Color::White);
  this->nameplayer.setCharacterSize(100);
  this->CooldownMax=15.f;
  this->Cooldown=this->CooldownMax;
  }
void Game::initPlayer(){

	this->player=new Player();
 
}
void Game::initEnemies(){

this->spawnTimerMax=50.f;//จะให้spawnศัตรูเร็วแค่ไหน
this->spawnTimer=this->spawnTimerMax;
}
void Game::initEnemies_2(){

this->spawnTimerMax_2=50.f;//จะให้spawnศัตรูเร็วแค่ไหน
this->spawnTimer_2=this->spawnTimerMax_2;
}
void Game::initFlower(){
this->dropTimerMax_1=50.f;//จะให้หน่วงspawnศัตรูเร็วแค่ไหน
this->dropTimer_1=this->dropTimerMax_1;
this->countFlMax=10.f;//จำนวนสิ้นสุด
this->countFl=0;//จำนวนเริ่มต้น
  }

void Game::initFlower_2(){
this->dropTimerMax_2=50.f;//จะให้หน่วงspawnศัตรูเร็วแค่ไหน
this->dropTimer_2=this->dropTimerMax_2;
this->countFlMax_2=10.f;//จำนวนสิ้นสุด
this->countFl_2=0;//จำนวนเริ่มต้น
  }
void Game::initFlower_3(){


this->dropTimerMax_3=50.f;//จะให้หน่วงspawnศัตรูเร็วแค่ไหน
this->dropTimer_3=this->dropTimerMax_3;
this->countFlMax_3=10.f;//จำนวนสิ้นสุด
this->countFl_3=0;//จำนวนเริ่มต้น
}
void Game::initClover(){

this->dropTimerMax=1000.f;//จะให้spawnศัตรูเร็วแค่ไหน
this->dropTimer=this->dropTimerMax;
this->countClMax=rand()%10;
this->countCl=0;
}
void Game::initWorld(){
this->worldbackgroundTex.loadFromFile("texture/Forest.jpg");
this->worldbackground.setTexture(this->worldbackgroundTex);

}
void Game::initMainmenu(){
this->MainmenubackgroundTex.loadFromFile("texture/MainMenuBG.png");
this->Mainmenubackground.setTexture(this->MainmenubackgroundTex);

}
void Game::initLDB(){
this->LDBbackgroundTex.loadFromFile("texture/LDB.png");
this->LDBbackground.setTexture(this->LDBbackgroundTex);

}
void Game::initTextBoxBG(){
this->TBbackgroundTex.loadFromFile("texture/NameBox.png");
this->TBbackground.setTexture(this->TBbackgroundTex);

}
void Game::initButtonR(){
this->buttonRtexture.loadFromFile("texture/return.png");
this->buttonRsprite.setTexture(this->buttonRtexture);
this->buttonRsprite.setPosition(1100,1000);
this->buttonRsprite.scale(1.f,1.f);
}
void Game::initButtonEX(){
this->buttonExittexture.loadFromFile("texture/Newgame.png");
this->buttonExitsprite.setTexture(this->buttonExittexture);
this->buttonExitsprite.setPosition(1100,1000);
this->buttonExitsprite.scale(1.f,1.f);
}
void Game::initSystems(){

this->point=0;


}
void Game::initHighScore(float x,float y,string word)
{  sf::Text text;
   text.setFont(this->font);
   text.setCharacterSize(32);
   text.setFillColor(sf::Color::White);
   text.setPosition(x,y);
   text.setString(word);
   this->window->draw(text);
}
const bool Game::canText(){

if(this->Cooldown>=this->CooldownMax){
    this->Cooldown=0.f;//ให้มันเริ่มนับใหม่
    return true;
}

    return false;
}
const bool Game::canText_2(){
  if(this->Cooldown_2>=this->CooldownMax_2){
   this->CooldownMax_2=0.f;
   return true;
}
return false;
}
//ตัวที่สร้างและทำลาย
Game::Game()
{
this->initWindow();
this->initMainmenu();
this->initPlayer();
this->initTextures();
this->initGUI();
this->initSystems();
this->initWorld();
this->initEnemies();
this->initEnemies_2();
this->initClover();
this->initFlower();
this->initFlower_2();
this->initFlower_3();
this->initMainMenuText();
this->initLDB();
this->initButtonR();
this->initButtonEX();
this->initTextBox();
this->initTextBoxBG();
this->canText();
this->canText_2();
}

Game::~Game()
{
/*delete this->window;
while(!this->states.empty()){
  delete this->states.top();
  this->states.pop();
}*/
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
for(auto *i : this-> enemies_2){

	delete i;
}

}

//ฟังก์ชัน
void Game::run(){
    while(this->window->isOpen())
    {  this->pollEvents();
       if(StartGame==false||ExitGame==false||LDBGame==false){
          this->renderMainmenu();
          if(this->StartText.getGlobalBounds().contains(sf::Mouse::getPosition(*this->window).x,sf::Mouse::getPosition(*this->window).y)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
          {      
                while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))){
                  this->window->clear(); 
                  this->pollEvents();
                  if(this->ev.type==sf::Event::TextEntered&&this->canText()){
                    if(this->ev.text.unicode=='\b'){
                       if(yourname.getSize()>=1){
                        this->yourname.erase(this->yourname.getSize()-1,1);
                        this->nameplayer.setString(this->yourname);
                        num--;
                          
                       }  
                     
                    }
                    else{
                      if(this->yourname.getSize()<15){
                        
                        this->yourname+=static_cast<char>(this->ev.text.unicode);
                        this->name+=static_cast<char>(this->ev.text.unicode);
                        num++;
                      }
                      if(this->ev.text.unicode<128){
                        
                        this->nameplayer.setString(this->yourname); 
                       
                      }
                    
                      }
                      this->nameplayer.setCharacterSize(90);
                      this->nameplayer.setPosition(600.f,300.f);
                      this->nameplayer.setFillColor(sf::Color::White);
                      }
                  else if(ev.type==sf::Event::KeyPressed){
                   if(ev.key.code==sf::Keyboard::Return){
                     this->nameplayer.setString(this->yourname);
                   }

                  }
                  this->renderTextBox();   
                  this->window->draw(this->nameplayer);
                  this->updateText(); 
                  this->window->display();
                  
                   
                        
                  }
              if((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))){
                    //this->nameJa=this->yourname;
                    NameState=true;
                  
              }   
                while(this->player->getHp()>0&&NameState==true){
                  
                  this->update();
                  this->render();
                 
                }
                while(this->player->getHp()<=0){
                this->pollEvents();
                this->window->clear();
                this->window->draw(this->worldbackground);
                this->window->draw(this->gameOverText);
                this->window->draw(this->buttonExitsprite);
                
                
                //std::
                /*this->myfile.open("rescource/Highscore.txt");
                if(this->myfile.is_open()){
                  while(!this->myfile.eof()){
                     this->myfile>>this->high_score;
                  }
                }
                this->myfile.close();
                this->myfile2.open("rescource/Highscore.txt");
                if(this->myfile2.is_open()){
                  if(this->point>this->high_score){
                     this->high_score=this->point;
                  }
                  this->myfile2<<this->high_score;
                  //<<"\n"<<this->nameJa
                }
                this->myfile2.close();*/
                if(this->buttonExitsprite.getGlobalBounds().contains(sf::Mouse::getPosition(*this->window).x,sf::Mouse::getPosition(*this->window).y)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {  this->fp = fopen("rescource/Highscore.txt", "r");
	                 for (int i = 0; i < 5; i++)
	                {
		                    fscanf(fp, "%s", &temp);
		                    name_one[i] = temp;
		                    fscanf(fp,"%d",&savscore[i]);
		                    user_score.push_back(make_pair(savscore[i], name_one[i]));
		                    //cout << temp << " " << score;
	                 }
	                  name_one[5] = "MMAED";
	                  savscore[5] = 8900;
	                  user_score.push_back(make_pair(savscore[5], name_one[5]));
	                  sort(user_score.begin(),user_score.end());
	                fclose(fp);
	                fopen("rescource/Highscore.txt", "w");
	                for (int i = 5; i >= 1; i--)
	                  {
		                  strcpy(temp, user_score[i].second.c_str());//แปลงstringให้กลายเป็นchar
		                  fprintf(fp,"%s %d\n",temp,user_score[i].first);
	                    
                    }
	                    fclose(fp);
                      
                    this->window->close();
                    
                }
                this->window->display();
          
                 }
                 StartGame=true;
                 }
                
                
          
    
                
             
           
          else if(this->ExitText.getGlobalBounds().contains(sf::Mouse::getPosition(*this->window).x,sf::Mouse::getPosition(*this->window).y)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
          {      ExitGame=true;
                 this->window->close();
               
          }
          else if(this->LeaderBoardText.getGlobalBounds().contains(sf::Mouse::getPosition(*this->window).x,sf::Mouse::getPosition(*this->window).y)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
          {       
                   while(!(this->buttonRsprite.getGlobalBounds().contains(sf::Mouse::getPosition(*this->window).x,sf::Mouse::getPosition(*this->window).y)&&sf::Mouse::isButtonPressed(sf::Mouse::Left)))
                   {this->pollEvents();
                    this->window->clear();
                    this->renderLeader();
                    this->fp = fopen("rescource/Highscore.txt", "r");
	                 for (int i = 0; i < 5; i++)
	                {
		                    fscanf(fp, "%s", &temp);
		                    name_one[i] = temp;
		                    fscanf(fp,"%d",&savscore[i]);
		                    user_score.push_back(make_pair(savscore[i], name_one[i]));
		                    //cout << temp << "              " << savscore[i]<<endl;
	                 }
                   fclose(fp);
                   this->initHighScore(600.f,200.f,user_score[0].second);
		               this->initHighScore(600.f, 230.f, to_string(user_score[0].first));
                    this->window->display();
                   }                
                    LDBGame=true;
                    
          }
            }

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
std::stringstream exp;
exp<<"Flower :"<<this->player->getFlexp();
this->FlexpText.setString(exp.str());
std::stringstream lv;
lv<<"Level :"<<this->player->getLevel();
this->LevelText.setString(lv.str());
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
/*---------------------------------------------------ENEMIES---------------------------------------------------------------*/
void Game::updateEnemies(){
  //spawning

 this->spawnTimer+=0.6f;
 if(this->player->getLevel()==2){
   this->spawnTimer=0.f;
 }
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
 this->player->loseHp(this->enemies.at(counter)->getDamage());
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

void Game::updateEnemies_2(){
    if(this->player->getLevel()==2){
    this->spawnTimer_2+=0.6f;
 if(this->spawnTimer_2>=this->spawnTimerMax_2){                //x             //y
      this->enemies_2.push_back(new Enemy_2(1200,1000));//บริเวณนี้จะมีการspawnเกิดขึ้น
      this->spawnTimer_2=0.f;
      
 }  
 //update
 unsigned counter_2=0;
 for(auto*enemy_2 : this->enemies_2)
{
  enemy_2->update();
  //checkenemyว่าชนขอบมั้ย
  if(enemy_2->getBounds().left<0.f){ 
  //Delete enemy
 this->player->loseHp(this->enemies_2.at(counter_2)->getDamage());
 this->enemies_2.erase(this->enemies_2.begin()+counter_2);
--counter_2;
  }
  //Player Enemy Collision
else if( enemy_2->getBounds().intersects(this->player->getBounds())){
this->player->loseHp(this->enemies_2.at(counter_2)->getDamage());
 this->enemies_2.erase(this->enemies_2.begin()+counter_2);
--counter_2;

  }
  ++counter_2;   
 





   }

    }
       }
/*---------------------------------------------------COMBAT---------------------------------------------------------------*/
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
/*---------------------------------------------------FLOWER---------------------------------------------------------------*/
void Game::updateFlower(){

    this->dropTimer_1+=1.f;
 if(this->dropTimer_1>=this->dropTimerMax_1 && this->countFl<this->countFlMax){                //x             //y
      this->flowers.push_back(new Flower(rand()%1400,rand()%1000));//บริเวณนี้จะมีการspawnเกิดขึ้น
      this->dropTimer_1=0.f;
      this->countFl+=1.f;
 }  
 
unsigned counter=0;
for(auto*flower : this->flowers)
{
if(this->player->getBounds().intersects(flower->getBounds())){
this->player->gainFlexp(this->flowers.at(counter)->getPoints());
delete this->flowers.at(counter);
 this->flowers.erase(this->flowers.begin()+counter);
 --counter;
}
++counter;



}
  }
void Game::updateFlower_2(){
   if(this->player->getLevel()==2){
    this->dropTimer_2+=1.f;
 if(this->dropTimer_2>=this->dropTimerMax_2 && this->countFl_2<this->countFlMax_2){                //x             //y
      this->flowers_2.push_back(new Flower_2(rand()%1400,rand()%1000));//บริเวณนี้จะมีการspawnเกิดขึ้น
      this->dropTimer_2=0.f;
      this->countFl_2+=1.f;
 }  
 
unsigned counter_2=0;
for(auto*flower_2 : this->flowers_2)
{
if(this->player->getBounds().intersects(flower_2->getBounds())){
this->player->gainFlexp(this->flowers_2.at(counter_2)->getPoints());
delete this->flowers_2.at(counter_2);
 this->flowers_2.erase(this->flowers_2.begin()+counter_2);
 --counter_2;
}
++counter_2;



}
   }
  }
void Game::updateFlower_3(){
  if(this->player->getLevel()==3){
    this->dropTimer_3+=1.f;
 if(this->dropTimer_3>=this->dropTimerMax_3 && this->countFl_3<this->countFlMax_3){                //x             //y
      this->flowers_3.push_back(new Flower_3(rand()%1400,rand()%1000));//บริเวณนี้จะมีการspawnเกิดขึ้น
      this->dropTimer_3=0.f;
      this->countFl_3+=1.f;
 }  
 
unsigned counter_3=0;
for(auto*flower_3 : this->flowers_3)
{
if(this->player->getBounds().intersects(flower_3->getBounds())){
this->player->gainFlexp(this->flowers_3.at(counter_3)->getPoints());
delete this->flowers_3.at(counter_3);
 this->flowers_3.erase(this->flowers_3.begin()+counter_3);
 --counter_3;
}
++counter_3;



}
  }
  }
/*--------------------------------------------------Clover-----------------------------------------------------------------------*/
void Game::updateClover(){
 this->dropTimer+=1.f;
 if(this->dropTimer>=this->dropTimerMax && this->countCl<this->countClMax){                //x             //y
      this->clovers.push_back(new Clover(rand()%1400,rand()%1000));//บริเวณนี้จะมีการspawnเกิดขึ้น
      this->dropTimer=0.f;
       this->countCl+=1.f;
 }  
 unsigned counter=0;
for(auto*clover : this->clovers)
{
if(this->player->getBounds().intersects(clover->getBounds())){
this->player->gainHp(this->clovers.at(counter)->getHP());
delete this->clovers.at(counter);
 this->clovers.erase(this->clovers.begin()+counter);
 --counter;
}
++counter;
}
}
void Game::updateText(){
if(this->Cooldown < this->CooldownMax){
    this->Cooldown+=0.5f;//เพิ่มคูลดาวน์ทีละ0.5
    }

}
void Game::updateText_2(){
if(this->Cooldown_2 < this->CooldownMax_2){
    this->Cooldown_2+=0.5f;//เพิ่มคูลดาวน์ทีละ0.5
    }

}
/*---------------------------------------------------UPDATE---------------------------------------------------------------*/
void Game::update(){
//update game logic การmove keyboard inputต่างๆ
this->pollEvents();
this->updateInput();
this->player->update();
this->updateCollision();
this->updateBullets();
this->updateEnemies();
this->updateEnemies_2();
this->updateCombat();
this->updateFlower();
this->updateFlower_2();
this->updateFlower_3();
this->updateClover();
this->updateGUI();


}
/*---------------------------------------------------RENDER---------------------------------------------------------------*/
void Game::renderGUI(){


this->window->draw(this->pointText);
this->window->draw(this->PlayerHpBarBack);
this->window->draw(this->PlayerHpBar);
this->window->draw(this->FlexpText);
this->window->draw(this->LevelText);

}
void Game::renderFunctionMain(){

if(this->StartText.getGlobalBounds().contains(sf::Mouse::getPosition(*this->window).x,sf::Mouse::getPosition(*this->window).y))
{
      this->StartText.setFillColor(sf::Color::Red);
       this->window->draw(this->StartText);
       
}
else if(this->ExitText.getGlobalBounds().contains(sf::Mouse::getPosition(*this->window).x,sf::Mouse::getPosition(*this->window).y))
{
      this->ExitText.setFillColor(sf::Color::Red);
       this->window->draw(this->ExitText);

}
else if(this->LeaderBoardText.getGlobalBounds().contains(sf::Mouse::getPosition(*this->window).x,sf::Mouse::getPosition(*this->window).y))
{
      this->LeaderBoardText.setFillColor(sf::Color::Red);
       this->window->draw(this->LeaderBoardText);

}
else{
this->StartText.setFillColor(sf::Color::White);
this->ExitText.setFillColor(sf::Color::White);
this->LeaderBoardText.setFillColor(sf::Color::White);
this->window->draw(this->StartText);
this->window->draw(this->ExitText);
this->window->draw(this->LeaderBoardText);
}
}
void Game::renderMainmenu(){
this->window->clear();
this->renderMainmenuBG();
this->renderFunctionMain();
this->window->display();

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
this->window->clear();
this->renderWorld();
//this->menu->draw(window);
/*if(!this->states.empty()){

  this->states.top()->render(this->window);
}*/
//Draw game objects//ให้ทุกอย่างrenderไปยังหน้าจอ โดยจะเรนเดอร์เป็นลำดับจากบนไปล่างทับกันไปเรื่อยๆ ล่างสุดจะอยู่ด้านหน้าสุด
this->player->render(*this->window);

for(auto *flower : this->flowers)
{
flower->render(this->window);

}
for(auto *flower_2 : this->flowers_2)
{
flower_2->render(this->window);

}
for(auto *flower_3 : this->flowers_3)
{
flower_3->render(this->window);

}
for(auto *clover : this->clovers)
{
clover->render(this->window);

}
for(auto *enemy : this->enemies)
{
enemy->render(this->window);

}
for(auto *enemy_2 : this->enemies_2)
{
enemy_2->render(this->window);

}
for(auto *bullet : this->bullets)
{
  bullet->render(this->window);

}

 this->renderGUI();
this->window->display();

}







void Game::renderWorld(){

this->window->draw(this->worldbackground);



}
void Game::renderMainmenuBG(){

this->window->draw(this->Mainmenubackground);



}
void Game::renderLeader(){
this->window->draw(this->LDBbackground);
this->window->draw(this->buttonRsprite);


}
void Game::renderTextBox(){

this->window->draw(this->TBbackground);


}
void::Game::renderHighscore(){
//this->window->draw(this->text);

}

/*void Game::rendername(){
                 
                  this->window->clear(); 
                  this->pollEvents();
                  if(this->ev.type==sf::Event::TextEntered){
                    if(this->ev.text.unicode=='\b'){
                       if(yourname.getSize()>=1){
                        this->yourname.erase(this->yourname.getSize()-1,1);
                        this->nameplayer.setString(this->yourname);
                        num--;
                         
                       }

                    }
                    else{
                      sf::String name;
                      if(this->yourname.getSize()<15){
                        this->yourname+=static_cast<char>(this->ev.text.unicode);
                        name+=static_cast<char>(this->ev.text.unicode);
                        num++;
                      }
                      else if(this->ev.text.unicode<128){
                        this->nameplayer.setString(this->yourname);

                      }
                      
                      }
                      this->nameplayer.setCharacterSize(90);
                      this->nameplayer.setPosition(600.f,300.f);
                  }
                  else if(this->ev.type==sf::Event::KeyPressed){
                    if(this->ev.key.code==sf::Keyboard::Return){
                      this->nameplayer.setString(this->yourname);
                    }
                  }
                  this->renderTextBox();
                  this->window->draw(this->nameplayer);
                  this->window->display();
                 
}*/