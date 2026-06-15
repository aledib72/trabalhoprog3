#pragma once
#include <string>
#include "pokedex.hpp"
#include "personagens.hpp"

enum BattleState { 
    PLAYER_TURN, 
    MOB_TURN,
    BATTLE_WIN,
    BATTLE_LOSE };
