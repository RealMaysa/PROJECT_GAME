#ifndef GAME_H
#define GAME_H 
#include<map>
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
//Bullets
std::vector<Bullet*>bullets;

//Player
Player*player;

//Enemies

float spawnTimer;
float spawnTimerMax;
Enemy*enemy;
std::vector<Enemy*> enemies;//เก็บค่าจาก class Enemy มาไว้ในvector

//privarte function
   void initWindow();
   void initBulletSprite();
   void initTextures();
   void initPlayer();
   void initEnemies();
   void initWorld();

public:


//constructor/destructor
    Game();
    virtual~Game();

//Accessor



    //ฟังก์ชัน
void run();
void pollEvents();
void updateInput();
void updateBullets();
void updateEnemies();
void update();
void render();
void renderWorld();
};

#endif