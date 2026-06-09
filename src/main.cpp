#include <iostream>
#include <string>
#include "personagens.hpp"
#include "itens.hpp"
#include "acoes.hpp"
#include "menu.hpp"
#include "pokedex.hpp"

int main() {
    Menu menu;
    Pokedex pokedex;
   
    pokedex.inicializarPokedex();

  
    while (menu.getEstadoAtual() != EstadoMenu::CONCLUIDO) {
        menu.exibirTela(pokedex);
        menu.processarEntrada(pokedex);
    }

   
    Personagem* pokemonJogador = menu.getPokemonEscolhido();

    
    std::cout << "\n==========================================\n";
    std::cout << "      AVANCANDO PARA A PRIMEIRA BATALHA   \n";
    std::cout << "==========================================\n";
    
    Personagem* inimigoComum = pokedex.sortearInimigoComum();
    std::cout << "Um(a) " << inimigoComum->getNome() << " selvagem apareceu!\n\n";

    Ataque ataquePadrao;
    pokemonJogador->UsarAtaque(&ataquePadrao, inimigoComum);
    
    std::cout << "\n==========================================\n";
    std::cout << "          FASE FINAL: O CHEFAO            \n";
    std::cout << "==========================================\n";
    
    Personagem* boss = pokedex.sortearBoss();
    std::cout << "CUIDADO! O(a) Lendario(a) " << boss->getNome() << " bloqueia o seu caminho!\n\n";
    
    boss->UsarAtaque(&ataquePadrao, pokemonJogador);

    return 0;
}