#include "pokedex.hpp"
#include "acoes.hpp"
#include <iostream>

Pokedex::Pokedex() {}

Pokedex::~Pokedex() {
    for (auto p : listaIniciais) delete p;
    for (auto p : listaInimigosComuns) delete p;
    for (auto p : listaBosses) delete p;
}

void Pokedex::inicializarPokedex() {
    // 3 Iniciais 
    listaIniciais.push_back(new Personagem("Capivara",
        40, 15, 10,
         new Ataque("Mordida", 10, 90) ));
         
    listaIniciais.push_back(new Personagem("Lobo Guara",
        40, 15, 10, new Ataque ));
    listaIniciais.push_back(new Personagem("Arara Azul",
        40, 15, 10, new Ataque ));

    // 2 da primeira batalha
    listaInimigosComuns.push_back(new Personagem("Tucano",
        40, 15, 10, new Ataque ));
    listaInimigosComuns.push_back(new Personagem("Preguica",
        40, 15, 10, new Ataque ));

    // 3 opçoes de Bosses finais
    listaBosses.push_back(new Personagem("Onca Pintada",
        40, 15, 10, new Ataque ));
    listaBosses.push_back(new Personagem("Tamandua Bandeira",
        40, 15, 10, new Ataque ));
    listaBosses.push_back(new Personagem("Sucuri",
        40, 15, 10, new Ataque ));
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