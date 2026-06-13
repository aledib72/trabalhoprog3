#include "menu.hpp"
#include <iostream>


Menu::Menu() : nomeJogador(""), estadoAtual(EstadoMenu::BOAS_VINDAS), pokemonEscolhido(nullptr) {}


void Menu::exibirTela(const Pokedex& pokedex) const {
    switch (estadoAtual) {
        case EstadoMenu::BOAS_VINDAS:
            std::cout << "\n==========================================\n";
            std::cout << "       BEM-VINDO AO BRASILMON 2D          \n";
            std::cout << "==========================================\n";
            std::cout << "Pressione '1' e Enter para iniciar...\n";
            break;

        case EstadoMenu::INSERIR_NOME:
            std::cout << "\nDigite o seu nome de Treinador: ";
            break;

        case EstadoMenu::ESCOLHER_INICIAL:
            std::cout << "\nBoa sorte, " << nomeJogador << "!\n";
            std::cout << "Escolha o seu Brasilmon Inicial:\n";
            
            auto iniciais = pokedex.getIniciais();
            for (size_t i = 0; i < iniciais.size(); ++i) {
                std::cout << i + 1 << " - " << iniciais[i]->getNome() 
                          << " (Vida: " << iniciais[i]->getVidaMax() << ")\n";
            }
            std::cout << "Digite o numero (1-3): ";
            break;
    }
}


void Menu::processarEntrada(const Pokedex& pokedex) {
    switch (estadoAtual) {
        case EstadoMenu::BOAS_VINDAS: {
            int input;
            std::cin >> input;
            estadoAtual = EstadoMenu::INSERIR_NOME; 
            break;
        }
        case EstadoMenu::INSERIR_NOME: {
            std::cin >> nomeJogador;
            estadoAtual = EstadoMenu::ESCOLHER_INICIAL; 
            break;
        }
        case EstadoMenu::ESCOLHER_INICIAL: {
            int escolha;
            std::cin >> escolha;
            if (escolha >= 1 && escolha <= 3) {
                pokemonEscolhido = pokedex.getIniciais()[escolha - 1];
                std::cout << "\nExcelente! Voce escolheu o(a) " << pokemonEscolhido->getNome() << "!\n";
                estadoAtual = EstadoMenu::CONCLUIDO; 
            } else {
                std::cout << "Opcao invalida. Tente novamente.\n";
            }
            break;
        }
    }
}

// Getters
EstadoMenu Menu::getEstadoAtual() const { return estadoAtual; }
std::string Menu::getNomeJogador() const { return nomeJogador; }
Personagem* Menu::getPokemonEscolhido() const { return pokemonEscolhido; }