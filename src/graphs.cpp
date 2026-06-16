#include "graphs.hpp"


void drawNamescreen(Texture2D texture, std::string &name, bool &confirmation) {
 
    int key = GetCharPressed();
    while (key > 0) {
        if ((key >= 32) && (key <= 125) && (name.length() < 20)) {
            name += (char)key;
        }
        key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE) && name.length() > 0) {
        name.pop_back();
    }
    if (IsKeyPressed(KEY_ENTER)) {
        confirmation = true;
    }

    DrawTexture(texture, 0, 0, WHITE);
    DrawRectangle(WIDTH/2 - 200, HEIGHT/2 - 100, 400, 200, BROWN);
    DrawText("Insert Name",   WIDTH/2 - 190, HEIGHT/2 - 90, 32, LIGHTGRAY);
    DrawText(name.c_str(),    WIDTH/2 - 190, HEIGHT/2 - 50, 32, WHITE);
}

void drawInitialScreen(Texture2D texture) {
    DrawTexture(texture, 0, 0, WHITE);
    DrawRectangle(WIDTH/2 - 200, HEIGHT/2 - 100, 400, 200, BROWN);
    DrawText("Press Any Key",      WIDTH/2 - 190, HEIGHT/2 - 80, 32, LIGHTGRAY);
    DrawText("To Start The Game",  WIDTH/2 - 190, HEIGHT/2 - 20, 32, LIGHTGRAY);
}

void drawBackground(Texture2D texture, float offset) {
    DrawTexture(texture, (int)offset,                0, WHITE);
    DrawTexture(texture, (int)offset + texture.width, 0, WHITE);
}



void drawFloor() {
    DrawRectangle(0, 903, 1920, 200, BROWN);
}

void drawPlayer(Texture2D texture, Position &pos) {
    DrawTextureEx(texture, {pos.x, pos.y}, 0.0f, 0.2f, WHITE);
}

void drawMob(Texture2D texture, Position &pos) {
    DrawTextureEx(texture, {pos.x, pos.y}, 0.0f, 0.1f, WHITE);
}


void updateBackground(float &offset) {
    if (IsKeyDown(KEY_D)) offset -= BACKGROUND_SPEED;
    if (IsKeyDown(KEY_A)) offset += BACKGROUND_SPEED;
    if (offset <= -1920) offset = 0;
    if (offset >=  1920) offset = 0;
}

void updatePlayer(Position &pos) {
    if (IsKeyDown(KEY_D)) pos.x += PLAYER_SPEED;
    if (IsKeyDown(KEY_A)) pos.x -= PLAYER_SPEED;

    if (pos.x >= 1200) pos.x = 1200;
    if (pos.x <= 0)    pos.x = 0;


    if (IsKeyPressed(KEY_W) && pos.y >= FLOOR_Y) {
        pos.y -= PLAYER_JUMP_HEIGHT;
    }

    if (pos.y < FLOOR_Y) {
        pos.y += GRAVITY;
    }
    if (pos.y >= FLOOR_Y) {
        pos.y = FLOOR_Y;
    }
}


void spawnMob(Position &pos, bool &active) {
    static size_t count = 0;
    if (count >= 10) return;
    if (!active && GetRandomValue(1, 100) <= 20) {
        pos.x = GetRandomValue(100, 1800);
        pos.y = FLOOR_Y + 120;
        active = true;
        count++;
    }
}

void updateMob(Position &pos, bool &active, float &mobDirection, int &moveTimer, float offset) {
    if (!active) return;

    if (IsKeyDown(KEY_D)) pos.x -= BACKGROUND_SPEED;
    if (IsKeyDown(KEY_A)) pos.x += BACKGROUND_SPEED;

    moveTimer++;
    if (moveTimer >= 60) {
        mobDirection = (GetRandomValue(0, 1) == 0) ? -1.0f : 1.0f;
        moveTimer = 0;
    }
    pos.x += mobDirection * 0.5f;

    if (pos.x <= -100 || pos.x >= 2100) {
        active = false;
    }
}


void spawnBoss(Position &pos, bool &active) {
    if (!active && GetRandomValue(1, 100) <= 1) {
        pos.x = GetRandomValue(100, 1800);
        pos.y = FLOOR_Y - (1309 * 0.1f);
        active = true;
    }
}


bool setContact(Personagem* p, Personagem* m) {
 return CheckCollisionRecs(p->getHitbox(), m->getHitbox());
}

void drawBattle(Personagem* player, Personagem* mob) {
    ClearBackground(BLACK);
    DrawText(player->getNome().c_str(),                              100,  900, 32, WHITE);
    DrawText(TextFormat("HP: %d/%d", player->getVidaAtual(), player->getVidaMax()), 100,  940, 28, GREEN);
    DrawText(mob->getNome().c_str(),                                1600,  900, 32, WHITE);
    DrawText(TextFormat("HP: %d/%d", mob->getVidaAtual(),    mob->getVidaMax()),   1600,  940, 28, RED);
    DrawText("[1] Ataque 1",              700, 1000, 32, YELLOW);
    DrawText("[2] Ataque 2",              700, 1050, 32, YELLOW);
    DrawText("[3] Escudo - Passar a vez", 700, 1100, 32, BLUE);
}

BattleState playerAction(Personagem* player, Personagem* mob, BattleState state, int &shield) {
    if (state != PLAYER_TURN) return state;
    shield = 0;

    Ataque* atq1 = player->getAtaque1();
    Ataque* atq2 = player->getAtaque2();

    if (IsKeyPressed(KEY_ONE) && atq1 != nullptr) {
        int roll = GetRandomValue(1, 100);
        if (roll <= atq1->getChanceSucesso()) {
            int dano = atq1->getModDanoBase() - mob->getDefesaBase();
            if (dano > 0) mob->AddVidaAtual(-dano);
        }

        if (mob->getVidaAtual() <= 0) return BATTLE_WIN;
        return MOB_TURN;
    }

    if (IsKeyPressed(KEY_TWO) && atq2 != nullptr) {
        int roll = GetRandomValue(1, 100);
        if (roll <= atq2->getChanceSucesso()) {
            int dano = atq2->getModDanoBase() - mob->getDefesaBase();
            if (dano > 0) mob->AddVidaAtual(-dano);
        }
        if (mob->getVidaAtual() <= 0) return BATTLE_WIN;
        return MOB_TURN;
    }

    if (IsKeyPressed(KEY_THREE)) {
        shield = 1;
        return MOB_TURN;
    }

    return PLAYER_TURN;
}


BattleState mobAction(Personagem* player, Personagem* mob, int shield) {
    int escolha = GetRandomValue(1, 3);

    Ataque* ataque = nullptr;
    if      (escolha == 1) ataque = mob->getAtaque1();
    else if (escolha == 2) ataque = mob->getAtaque2();

    if (ataque != nullptr) {
        int roll = GetRandomValue(1, 100);
        if (roll <= ataque->getChanceSucesso()) {
            int defesa = shield ? player->getDefesaBase() + 5 : player->getDefesaBase();
            int dano   = ataque->getModDanoBase() - defesa;
            if (dano > 0) player->AddVidaAtual(-dano);
        }
    }

    if (player->getVidaAtual() <= 0) return BATTLE_LOSE;
    return PLAYER_TURN;
}