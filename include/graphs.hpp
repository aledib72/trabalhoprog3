#pragma once
#include "raylib.h"
#include <cstdlib>
#include <string>
#include "menu.hpp"
#include "personagens.hpp"

#define WIDTH             1920
#define HEIGHT            1200
#define FLOOR_Y           675
#define BACKGROUND_SPEED  5.0f
#define PLAYER_SPEED      5.0f
#define MOB_SPEED         5.0f
#define BOSS_SPEED        0.05f
#define PLAYER_JUMP_HEIGHT 100.0f  
#define GRAVITY           5.0f

/**
 * @brief Stores the position of an entity.
 */
struct Position {
    float x;
    float y;
};

void drawNamescreen(Texture2D texture, std::string &name, bool &confirmation);
void drawInitialScreen(Texture2D texture);
void drawBackground(Texture2D texture, float offset);
void drawFloor();
void drawPlayer(Texture2D texture, Position &pos);
void drawMob(Texture2D texture, Position &pos);
void drawPlayerBattle(Texture2D texture, Position &pos);
void drawMobBattle(Texture2D texture, Position &pos);


void updateBackground(float &offset);
void updatePlayer(Position &pos, float floorY);

void spawnMob(Position &pos, bool &active);
void updateMob(Position &pos, bool &active, float &mobDirection, int &moveTimer, float offset);
void spawnBoss(Position &pos, bool &active);  

bool setContact(Personagem* p, Personagem* m);

void drawBattle(Personagem* player, Personagem* mob);
BattleState playerAction(Personagem* player, Personagem* mob, BattleState state, int &shield);

BattleState mobAction(Personagem* player, Personagem* mob, int shield);