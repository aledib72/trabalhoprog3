#pragma once
#include <string>
#include "pokedex.hpp"
#include "personagens.hpp"

// Define as telas da sua Máquina de Estados
enum class EstadoMenu {
    BOAS_VINDAS,
    INSERIR_NOME,
    ESCOLHER_INICIAL,
    CONCLUIDO
};

class Menu {
private:
    std::string nomeJogador;
    EstadoMenu estadoAtual;
    Personagem* pokemonEscolhido;

public:
    Menu();
    
    // Separação de responsabilidades (ideal para o Raylib no futuro)
    void exibirTela(const Pokedex& pokedex) const;   // O "Draw"
    void processarEntrada(const Pokedex& pokedex);   // O "Update"
    
    // Getters para a main acessar os dados
    EstadoMenu getEstadoAtual() const;
    std::string getNomeJogador() const;
    Personagem* getPokemonEscolhido() const;
};