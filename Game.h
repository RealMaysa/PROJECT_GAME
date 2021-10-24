#ifndef GAME_H
#define GAME_H 
#include<map>
#include<string>
#include<sstream>
#include"Player.h"
#include"Bullet.h"
#include"Enemy.h"
/* ทำตัวเหมือนแก่นทำงานหลักของเกม game engine
    รวมคลาสไว้เข้าด้วยกัน */

class Game
{
private:


//Window
sf::RenderWindow* window;
sf::Event ev;
sf::VideoMode videoMode ;

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
//Systems
unsigned point;
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
Enemy*enemy;
std::vector<Enemy*> enemies;//เก็บค่าจาก class Enemy มาไว้ในvector



//privarte function
   void initWindow();
   void initBulletSprite();
   void initTextures();
   void initGUI();
   void initPlayer();
   void initEnemies();
   void initWorld();
   void initSystems();

public:


//constructor/destructor
    Game();
    virtual~Game();



    //ฟังก์ชัน
void run();
void pollEvents();
void updateInput();
void updateGUI();
void updateEnemies();
void updateWorld();
void updateCollision();
void updateCombat();
void updateBullets();
void update(); 
void renderGUI();
void render();
void renderWorld();
};

#endif