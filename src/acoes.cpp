#include "acoes.hpp"
#include <iostream>

Ataque::Ataque() : nomeAtaque("ataque sem nome"), modDanoBase(10), chanceSucesso(80) {
    std::cout << "ataque construido" << std::endl;
}
Ataque::~Ataque(){
    std::cout << "ataque destruido" << std::endl;
}

std::string Ataque::getNomeAtaque() const   { return this->nomeAtaque; }
int Ataque::getModDanoBase() const          { return this->modDanoBase; }
int Ataque::getChanceSucesso() const        { return this->chanceSucesso; }