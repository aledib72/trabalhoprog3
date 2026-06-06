#include "personagens.hpp"
#include "itens.hpp"
#include "acoes.hpp"
#include <iostream>


Ataque::Ataque() : modDanoBase(10), chanceSucesso(90) {
    std::cout << "ataque construido" << std::endl;
}
Ataque::~Ataque(){
    std::cout << "ataque destruido" << std::endl;
}

void Ataque::UsarAtaque(Personagem* atacante, Personagem* alvo){
    std::cout << this->modDanoBase << std::endl;
    std::cout << atacante->getVidaAtual() << std::endl;
}
    