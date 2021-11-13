#ifndef GAME_H
#define GAME_H 
#include<map>
#include<string>
#include<sstream>
#include<fstream>
#include<iostream>
#include<string>
#include<utility>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<string.h>
#include"Player.h"
#include"Bullet.h"
#include"Enemy.h"
#include"Enemy_2.h"
#include"Flower.h"
#include"Flower_2.h"
#include"Flower_3.h"
#include"Clover.h"
#include"TextBox.h"

//#include"State.h"
//#include"GameState.h"
//#include"mainMenu.h"
/* ทำตัวเหมือนแก่นทำงานหลักของเกม game engine
    รวมคลาสไว้เข้าด้วยกัน */

class Game
{
private:

//MainMenu
sf::Texture MainmenubackgroundTex;
sf::Sprite Mainmenubackground;
sf::Texture LDBbackgroundTex;
sf::Sprite LDBbackground;
sf::Texture TBbackgroundTex;
sf::Sprite TBbackground;
sf::Sprite buttonRsprite;
sf::Texture buttonRtexture;
sf::Sprite buttonExitsprite;
sf::Texture buttonExittexture;
//UserName

bool StartGame=false;
bool ExitGame=false;
bool LDBGame=false;
bool NameState=false;
//Window
sf::RenderWindow* window;
sf::Event ev;
sf::VideoMode videoMode ;
//std::stack<State*> states;//ในstateสร้างobjectไม่ได้เลยต้องสร้างได้แค่pointerชี้ไปยังมันและสร้างstackเพื่อเพิ่มstateใหม่ขึ้น

//Resource  //คอนเทนเนอร์class
std::map<std::string,sf:: Texture*>textures; //ในแต่ละstringจะกลายเป็นแต่ละtexture
/*ดังนั้นเมื่อมีการใส่บางอย่างเข้าไปในarray stringนี้ ในจุดเดียวกันก็จะมีtextureด้วย*/

//World
sf::Texture worldbackgroundTex;
sf::Sprite worldbackground;
//GUI แสดงผลให้ผู้เล่นรู้
sf::Font font;
sf::Text pointText;
sf::Text gameOverText;
sf::Text FlexpText;
sf::Text LevelText;
sf::Text StartText;
sf::Text ExitText;
sf::Text LeaderBoardText;
//sf::Text TextboxText;
//Systems
unsigned point;
unsigned high_score;
//Bullets
std::vector<Bullet*>bullets;

//Player
Player*player;

//PlayerGUI
sf::RectangleShape PlayerHpBar;//ส่วนที่เปลี่ยนตามHp
sf::RectangleShape PlayerHpBarBack;
//Enemies

float spawnTimer;
float spawnTimerMax;
float spawnTimer_2;
float spawnTimerMax_2;

Enemy*enemy;
Enemy_2* enemy_2;
std::vector<Enemy*> enemies;//เก็บค่าจาก class Enemy มาไว้ในvector
std::vector<Enemy_2*> enemies_2;
//Item
  
float dropTimer;
float dropTimerMax;
float dropTimer_1;
float dropTimerMax_1;
float dropTimer_2;
float dropTimerMax_2;
float dropTimer_3;
float dropTimerMax_3;
float countFlMax;
float countFl;
float countFlMax_2;
float countFl_2;
float countFlMax_3;
float countFl_3;
float countClMax;
float countCl;
float CooldownMax;
float Cooldown;
float Cooldown_2;
float CooldownMax_2;
Flower*flower;
std::vector<Flower*> flowers;
Flower_2*flower_2;
std::vector<Flower_2*> flowers_2;
Flower_3*flower_3;
std::vector<Flower_3*> flowers_3;
Clover*clover;
std::vector<Clover*> clovers;
//NAmeBOx
sf::String yourname;
sf::Text nameplayer;
sf::String name;
/*std::vector<std::pair<int,std::string>> name_score;
std::string nameJa;
int j=0,e,g;
std::ifstream myfile;
std::ofstream myfile2;*/
FILE*fp;
char temp[218];
int num=0;
int savscore[6];
std::string name_one[6];
std::vector<std::pair<int,std::string>> user_score;
//privarte function
   void initWindow();
   void initMainmenu();
   void initBulletSprite();
   void initTextures();
   void initGUI();
   void initPlayer();
   void initEnemies();
   void initEnemies_2();
   void initFlower();
   void initFlower_2();
   void initFlower_3();
   void initClover();
   void initWorld();
   void initSystems();
   void initMainMenuText();
   void initLDB();
   void initButtonR();
   void initButtonEX();
   void initTextBox();
   void initTextBoxBG();
   void initHighScore(float x,float y,std::string word);

public:

//constructor/destructor
    Game();
    virtual~Game();

//Mainmenu 
void Mainmenu();

    //ฟังก์ชัน
void run();
void pollEvents();
void updateInput();
void updateGUI();
void updateEnemies();
void updateEnemies_2();
void updateCollision();
void updateCombat();
void updateBullets();
void updateFlower();
void updateFlower_2();
void updateFlower_3();
void updateClover();
void updateText();
void updateText_2();
const bool canText();
const bool canText_2();
void update(); 
void renderGUI();
void render();
void renderWorld();
void renderMainmenu();
void renderMainmenuBG();
void renderFunctionMain();
void renderLeader();
void renderTextBox();
void renderHighscore();
};

#endif