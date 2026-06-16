#pragma once
#include <string>
#include "pokedex.hpp"
#include "personagens.hpp"

enum GameState {
    INITIAL_SCREEN,
    NAME_SCREEN,
    CHOOSE_STARTER,
    OVERWORLD,
    BATTLE,
    GAME_OVER
};

enum BattleState { 
    PLAYER_TURN, 
    MOB_TURN,
    BATTLE_WIN,
    BATTLE_LOSE };
