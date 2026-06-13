#include "cicloBatalha.hpp"


void TurnoOponente(Jogador* jogador, Personagem* inimigo){
    std::cout << "Turno do Inimigo!" << std::endl;
        int escolha = rand() % 3;

        if(escolha == 0)
                jogador->UsarAtaque(inimigo->getAtaque1(), jogador);
        if(escolha == 1)
                jogador->UsarAtaque(inimigo->getAtaque2(), jogador);
        if(escolha == 2)
                jogador->UsarAtaque(jogador->getAtaque1(), inimigo);

        return;
}

void TurnoJogador(Jogador* jogador, Personagem* inimigo){
    std::cout << "Turno do Jogador!" << std::endl;
        int escolha = 0;
        while(1){
            std::cout << "Escolha uma opcão: " << std::endl;
            std::cout << " 1 - Usar ataque" << jogador->getAtaque1()->getNomeAtaque() << std::endl;
            std::cout << " 2 - Usar ataque" << jogador->getAtaque2()->getNomeAtaque() << std::endl;
            std::cout << " 3 - Cuidar das feridas (curar)" << std::endl;
            std::cin >> escolha;
            if(escolha == 1 || escolha == 2 || escolha == 3)
                break;
            else
                std::cout << "opcao inválida! escolha novamente." << std::endl;
        }
        if(escolha == 1)
                jogador->UsarAtaque(jogador->getAtaque1(), inimigo);
        if(escolha == 2)
                jogador->UsarAtaque(jogador->getAtaque2(), inimigo);
        if(escolha == 3)
                jogador->UsarAtaque(jogador->getAtaque1(), inimigo);

        return;
}


void Batalha(Jogador* jogador, Personagem* inimigo, int fase){

    int sortearTurno = rand() % 3;
    if(sortearTurno == 0){ // 1/3 chance de comecar o turno com ataque inimigo
        TurnoOponente(jogador, inimigo);
        if(jogador->getVidaAtual() == 0){
            std::cout << "Jogador Derrotado!" << std::endl;
        }
    }

    while(1){
        TurnoJogador(jogador, inimigo);
        if(inimigo->getVidaAtual() == 0){
            std::cout << "Oponente "<< inimigo->getNome()<< " Derrotado!" << std::endl;
            delete inimigo;
            return;
        }
        
        TurnoOponente(jogador, inimigo);
        if(jogador->getVidaAtual() == 0){
            std::cout << "Jogador Derrotado!" << std::endl;
        }
    }
}