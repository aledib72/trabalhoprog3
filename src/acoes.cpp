#include "acoes.hpp"
#include <iostream>

Ataque::Ataque()
    : nomeAtaque("Ataque Basico"), modDanoBase(10), chanceSucesso(80)
{
}

Ataque::Ataque(std::string _nomeAtaque, int _modDanoBase, int _chanceSucesso)
    : nomeAtaque(_nomeAtaque), modDanoBase(_modDanoBase), chanceSucesso(_chanceSucesso)
{
}

Ataque::~Ataque() {}


std::string Ataque::getNomeAtaque()  const { return this->nomeAtaque; }
int         Ataque::getModDanoBase() const { return this->modDanoBase; }
int         Ataque::getChanceSucesso()const { return this->chanceSucesso; }