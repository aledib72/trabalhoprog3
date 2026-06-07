#pragma once
#include <vector>
#include <random>
#include "personagens.hpp"

class Pokedex {
private:
    std::vector<Personagem*> listaIniciais;
    std::vector<Personagem*> listaInimigosComuns;
    std::vector<Personagem*> listaBosses;

public:
    Pokedex();
    ~Pokedex(); 

    void inicializarPokedex();
    
    
    const std::vector<Personagem*>& getIniciais() const;

    Personagem* sortearInimigoComum();
    Personagem* sortearBoss();

    //Template para sorteio de pokemon da batalha
    template <typename T>
    T sortearElemento(const std::vector<T>& lista) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, lista.size() - 1);
        
        return lista[dis(gen)];
    }
};