#include "Pokedex.hpp"
#include <iostream>

Pokedex::Pokedex() {}

Pokedex::~Pokedex() {
    for (auto p : listaIniciais) delete p;
    for (auto p : listaInimigosComuns) delete p;
    for (auto p : listaBosses) delete p;
}

void Pokedex::inicializarPokedex() {
    // 3 Iniciais 
    listaIniciais.push_back(new Personagem("Capivara"));
    listaIniciais.push_back(new Personagem("Lobo Guara"));
    listaIniciais.push_back(new Personagem("Arara Azul"));

    // 2 da primeira batalha
    listaInimigosComuns.push_back(new Personagem("Tucano"));
    listaInimigosComuns.push_back(new Personagem("Preguica"));

    // 3 opçoes de Bosses finais
    listaBosses.push_back(new Personagem("Onca Pintada"));
    listaBosses.push_back(new Personagem("Tamandua Bandeira"));
    listaBosses.push_back(new Personagem("Sucuri"));
}

const std::vector<Personagem*>& Pokedex::getIniciais() const {
    return this->listaIniciais;
}

Personagem* Pokedex::sortearInimigoComum() {
    return sortearElemento(listaInimigosComuns);
}

Personagem* Pokedex::sortearBoss() {
    return sortearElemento(listaBosses);
}