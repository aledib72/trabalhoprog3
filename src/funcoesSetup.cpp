#include <iostream>
#include "funcoesSetup.hpp"


Jogador* CriaPersonagemJogador(){
    std::string nomePersonagem;
    std::cout << "Digite o seu nome: " << std::endl;
    std::getline(std::cin, nomePersonagem);

    int escolha = 0;
    while(1){
        std::cout << "Escolha uma classe (1, 2 ou 3):" << std::endl;
        std::cin >> escolha;
        if(escolha == 1){
            Jogador *novoJogador = new Jogador(nomePersonagem);
            return novoJogador;
        }
        if(escolha == 2){
            Jogador* novoJogador = new Jogador(nomePersonagem);
            return novoJogador;
        }
        if(escolha == 3){
            Jogador* novoJogador = new Jogador(nomePersonagem);
            return novoJogador;
        }
        else{
            std::cout << "Opção inválida, tente novamente." << std::endl;
        }
    }

}