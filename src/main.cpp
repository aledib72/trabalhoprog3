#include "raylib.h"
#include "graphs.hpp"
#include "menu.hpp"
#include "pokedex.hpp"
#include <cstdlib>
#include <ctime>

// ─── Estados do jogo ─────────────────────────────────────────────────────────
enum GameState {
    INITIAL_SCREEN,
    NAME_SCREEN,
    CHOOSE_STARTER,
    OVERWORLD,
    BATTLE,
    GAME_OVER,
    GAME_WIN
};


Personagem* spawnRandomMob(int &outType) {
    outType = GetRandomValue(0, 2);
    switch (outType) {
        case 0: return new Capivara();
        case 1: return new LoboGuara();
        case 2: return new Tamandua();
        default: return new Capivara();
    }
}

Personagem* spawnRandomBoss(int &outType) {
    outType = GetRandomValue(0, 1);
    return (outType == 0) ? (Personagem*)new Onca() : (Personagem*)new Sucuri();
}

int main() {
    InitWindow(WIDTH, HEIGHT, "Brasilmon");
    SetTargetFPS(60);
    srand(time(0));

    Texture2D playerTex = LoadTexture("build/assets/player.png");
    Texture2D texBackground = LoadTexture("build/assets/background.png");
    Texture2D texInitial    = LoadTexture("build/assets/background.png");

    Texture2D texStarters[3] = {
        LoadTexture("build/assets/capivara.png"),
        LoadTexture("build/assets/capivara.png"),
        LoadTexture("build/assets/capivara.png")
    };

    Texture2D texMobs[3] = {
        LoadTexture("build/assets/capivara.png"),
        LoadTexture("build/assets/capivara.png"),
        LoadTexture("build/assets/capivara.png")
    };

    Texture2D texBosses[2] = {
        LoadTexture("build/assets/capivara.png"),
        LoadTexture("build/assets/capivara.png")
    };

    GameState   gameState   = INITIAL_SCREEN;
    BattleState battleState = PLAYER_TURN;

    std::string playerName     = "";
    bool        nameConfirmed  = false;
    int         starterChoice  = 0;  

    Personagem* player     = nullptr;
    Personagem* currentMob = nullptr;
    int         mobType    = 0;   
    bool        isBoss     = false;
    int         shield     = 0;

    Position playerPos    = { 100.0f, (float)FLOOR_Y };
    Position mobPos       = { 0.0f,   0.0f };
    Position bossPos      = { 0.0f,   0.0f };
    bool     mobActive    = false;
    bool     bossActive   = false;
    float    bgOffset     = 0.0f;
    float    mobDir       = 1.0f;
    int      moveTimer    = 0;

    while (!WindowShouldClose()) {
        BeginDrawing();

        switch (gameState) {

            case INITIAL_SCREEN:
                drawInitialScreen(texInitial);
                if (GetKeyPressed() != 0)
                    gameState = NAME_SCREEN;
                break;

            case NAME_SCREEN:
                drawNamescreen(texInitial, playerName, nameConfirmed);
                if (nameConfirmed)
                    gameState = CHOOSE_STARTER;
                break;

            case CHOOSE_STARTER:
                ClearBackground(BLACK);
                DrawText("Escolha seu parceiro:",  WIDTH/2 - 250, HEIGHT/2 - 150, 40, WHITE);
                DrawText("[1] Arara",               WIDTH/2 - 250, HEIGHT/2 - 60,  36, YELLOW);
                DrawText("[2] Tucano",              WIDTH/2 - 250, HEIGHT/2,        36, YELLOW);
                DrawText("[3] Preguica",            WIDTH/2 - 250, HEIGHT/2 + 60,   36, YELLOW);

                if (IsKeyPressed(KEY_ONE))   { starterChoice = 0; gameState = OVERWORLD; }
                if (IsKeyPressed(KEY_TWO))   { starterChoice = 1; gameState = OVERWORLD; }
                if (IsKeyPressed(KEY_THREE)) { starterChoice = 2; gameState = OVERWORLD; }

                if (gameState == OVERWORLD) {
                    switch (starterChoice) {
                        case 0: player = new Arara();    break;
                        case 1: player = new Tucano();   break;
                        case 2: player = new Preguica(); break;
                    }
                    player->setHitbox((int)playerPos.x, (int)playerPos.y, 80, 120);
                }
                break;

            case OVERWORLD:
                ClearBackground(BLACK);

                updateBackground(bgOffset);
                updatePlayer(playerPos);
                player->setHitbox((int)playerPos.x, (int)playerPos.y, 80, 120);

                if (!mobActive && !bossActive) {
                    spawnBoss(bossPos, bossActive);
                    if (!bossActive)
                        spawnMob(mobPos, mobActive);
                }

                if (mobActive) {
                    updateMob(mobPos, mobActive, mobDir, moveTimer, bgOffset);

                    if (currentMob == nullptr) {
                        isBoss     = false;
                        currentMob = spawnRandomMob(mobType);
                        currentMob->setHitbox((int)mobPos.x, (int)mobPos.y, 80, 120);
                    } else {
                        currentMob->setHitbox((int)mobPos.x, (int)mobPos.y, 80, 120);
                    }
                }

                if (bossActive && currentMob == nullptr) {
                    isBoss     = true;
                    currentMob = spawnRandomBoss(mobType);
                    currentMob->setHitbox((int)bossPos.x, (int)bossPos.y, 100, 140);
                } else if (bossActive && currentMob != nullptr) {
                    currentMob->setHitbox((int)bossPos.x, (int)bossPos.y, 100, 140);
                }

                
                drawBackground(texBackground, bgOffset);
                drawFloor();
                drawPlayer(playerTex, playerPos);
                if (mobActive && !isBoss)
                    drawMob(texMobs[mobType], mobPos);
                if (bossActive && isBoss)
                    drawMob(texBosses[mobType], bossPos);

                if (currentMob != nullptr && setContact(player, currentMob)) {
                    battleState = PLAYER_TURN;
                    shield      = 0;
                    gameState   = BATTLE;
                }
                break;

            case BATTLE:
                drawBattle(player, currentMob);

                if (battleState == PLAYER_TURN)
                    battleState = playerAction(player, currentMob, battleState, shield);
                else if (battleState == MOB_TURN)
                    battleState = mobAction(player, currentMob, shield);

                if (battleState == BATTLE_WIN) {
                    delete currentMob;
                    currentMob = nullptr;
                    mobActive  = false;
                    bossActive = false;
                    gameState  = OVERWORLD;
                    battleState = PLAYER_TURN;
                }
                if (battleState == BATTLE_LOSE) {
                    gameState = GAME_OVER;
                }
                break;

            case GAME_OVER:
                ClearBackground(BLACK);
                DrawText("GAME OVER",            WIDTH/2 - 160, HEIGHT/2 - 60, 64, RED);
                DrawText("Pressione R para reiniciar", WIDTH/2 - 220, HEIGHT/2 + 20, 32, WHITE);
                if (IsKeyPressed(KEY_R)) {
                    delete player;
                    if (currentMob) { delete currentMob; currentMob = nullptr; }
                    player        = nullptr;
                    playerName    = "";
                    nameConfirmed = false;
                    playerPos     = { 100.0f, (float)FLOOR_Y };
                    mobActive     = false;
                    bossActive    = false;
                    bgOffset      = 0.0f;
                    gameState     = INITIAL_SCREEN;
                }
                break;

            case GAME_WIN:
                ClearBackground(BLACK);
                DrawText("VOCE VENCEU!",  WIDTH/2 - 160, HEIGHT/2, 64, GREEN);
                break;
        }

        EndDrawing();
    }

    if (player)     delete player;
    if (currentMob) delete currentMob;

    UnloadTexture(texBackground);
    UnloadTexture(texInitial);
    for (int i = 0; i < 3; i++) UnloadTexture(texStarters[i]);
    for (int i = 0; i < 3; i++) UnloadTexture(texMobs[i]);
    for (int i = 0; i < 2; i++) UnloadTexture(texBosses[i]);

    CloseWindow();
    return 0;
}