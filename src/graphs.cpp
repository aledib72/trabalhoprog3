#include "graphs.hpp"


    void drawNamescreen(Texture2D texture, std::string &name, bool &confirmation){
        //primeiro pegar um nome, passar ele como sendo 
        int key = GetKeyPressed();
        if (key > 0){
            if((key >= 32) && (key <= 125) && (name.length() < 20)){
                name += (char)key; //pasassar como char para não cadastrar nick de algueem como int
            }
            key = GetCharPressed(); 
        }   
            //apagar um nome caracter
            if (IsKeyPressed(KEY_BACKSPACE) && name.length() > 0)  {
                name.pop_back();
            }

            if(IsKeyPressed((KEY_ENTER))) { 
                confirmation = true;
            }

        DrawTexture(texture, 0, 0, WHITE);

        DrawRectangle(WIDTH/2, HEIGHT/2, 400, 200, BROWN);

        DrawText("Insert Name", WIDTH/2, HEIGHT/2, 32, LIGHTGRAY);
    }


void drawInitialScreen(Texture2D texture){
DrawTexture(texture, 0, 0, WHITE);
DrawRectangle(WIDTH / 2, HEIGHT / 2, 400, 200, BROWN);
DrawText("Press Any key to start the game", WIDTH/2, HEIGHT/2, 32, LIGHTGRAY);
}

void transictionInitialScreenToBackground(Texture2D initial, Texture2D background, float offset){
    if (GetKeyPressed() != 0){
        UnloadTexture(initial);
        drawBackground(background,offset);
    }
}

void drawBackground(Texture2D texture, float offset) {
    DrawTexture(texture, (int)offset, 0, WHITE);
    DrawTexture(texture, (int)offset + texture.width, 0, WHITE);
}

void drawFloor() {
    DrawRectangle(0, 903, 1920, 200, BROWN);
}

void drawPlayer(Texture2D texture, Position &pos){
    DrawTexture(texture, pos.x, pos.y, WHITE); 
}


void uptadeBackground(float &offset){
if (IsKeyDown(KEY_D)) offset -= BACKGROUND_SPEED;
if (IsKeyDown(KEY_A)) offset += BACKGROUND_SPEED;

if (offset <= -1920) offset = 0;
if (offset >= 1920) offset = 0;
}

void uptadePlayer(Position &pos){
if (IsKeyDown(KEY_D)) pos.x += PLAYER_SPEED;
if (IsKeyDown(KEY_A)) pos.x -= PLAYER_SPEED;

if (IsKeyPressed(KEY_W) && pos.y >= FLOOR_Y){
    pos.y -= PLAYER_JUMP_HEIGHT;
    }

if (pos.y < FLOOR_Y){
    pos.y += GRAVITY;
    }

if (pos.y >= FLOOR_Y){
    pos.y = FLOOR_Y;
    }
}

void spawnMob(Position &pos, bool &active){
    static size_t count = 0;

    while (count < 10){
        if (!active && GetRandomValue(100,800) <= 20){
            pos.x = GetRandomValue(100,1800);
            pos.y = FLOOR_Y;
            active = true;
            count++;
        }
    }
}

void updateMob(Position &pos, bool &active, float &mobDirection, int &moveTimer){
if (!active) return;

moveTimer++;
if (moveTimer >= 60){
    mobDirection = (GetRandomValue(0,1) == 0) ? -MOB_SPEED : MOB_SPEED;
    moveTimer = 0;
    }
    pos.x += mobDirection * MOB_SPEED;

    if (pos.x < 0) pos.x = 0;
    if (pos.x > 1870) pos.x = 1870;
}