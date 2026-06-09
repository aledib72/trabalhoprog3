/**
 * Title: basic graphic function for a game
 * Author: Alexandre Dib
 */


#pragma once

#include "raylib.h"
#include <cstdlib>
#include <string>

#include "personagens.hpp"

#define WIDTH 1920
#define HEIGHT 1200
#define FLOOR_Y 853.0f


#define BACKGROUND_SPEED 0.2f
#define PLAYER_SPEED 0.2f
#define MOB_SPEED 0.1f
#define BOSS_SPEED 0.05f
#define PLAYER_JUMP_HEIGHT -15.0f
#define GRAVITY 0.5f

/*
terminar função spawnboss (setar probabilidade para 1%)
*/

/**
 * @brief stores the position of an entity.
 */
struct Position{
    int x;
    int y;
};

/**
 * @brief Draw the function where the player can use the setnamefunction;
 * @param texture the namescreen texture
 * @param name name of the player
 * @param confirmation confirmation of the name
 */
void drawNamescreen(Texture2D texture, std::string &name, bool &confirmation);

//criar função de transição entre eles.


/**
 * @brief Draw the initial screen
 * @param texture The initial screen texture
 */
void drawInitialScreen(Texture2D texture);

/**
 * @brief Transiction from Initial screen to Background
 * @param initial Initial Screen
 * @param background Background Screen
 * @param offset horizonal displacement of the texture
 */
void transictionInitialScreenToBackground(Texture2D initial, Texture2D background, float offset);

/**
 * @brief Draws the background with a scrolling effect
 * @param texture The background texture
 * @param offset Horizontal displacement of the texture
 */
void drawBackground(Texture2D texture, float offset);

/**
 * @brief Draw the floor where the entities can walk
 */
void drawFloor();

/**
 * @brief Draw the player
 */
void drawPlayer(Texture2D texture, Position &pos);

/**
 * @brief Uptade the background position
 * @param offset Horizontal displacement of the texture
 */
void uptadeBackground(float &offset);

/**
 * @brief Uptade the player position
 * @param pos Reference to the player position
 */
void uptadePlayer(Position &pos);


/**
 * @brief Spawn mob with a 20% chance
 * @param pos Get the position to the mob to spawn
 * @param active Check to see the situation of Mob
 */
void spawnMob(Position &pos, bool &active);

/**
 * @brief Simple movement system
 * @param pos Get the mob's position
 * @param active Check to see the situation of the Mob
 * @param mobDirection the direction mob is walking
 * @param moveTimer Set a timer to the mobs movement
 */

void updateMob(Position &pos, bool &active, float &mobDirection, int &moveTimer);


/**
 * @brief Spawn boss with 2-% chance
 * @param pos Get the boss position
 * @param active Check the situation of the mob
 */
void spawnBoss(Position &pos, bool &active);