#include "personagens.hpp"
#include <iostream>
#include  <ctime>

//Construtores e destrutor

Personagem::Personagem() : nome("indefinido"), vidaAtual(30), vidaMax(30){ }

Personagem::Personagem(std::string nomeDado) : 
    nome(nomeDado), vidaAtual(30), vidaMax(30), danoBase(10), defesaBase(10){
        std::cout << this->nome << " criado!" << std::endl;
    }

Personagem::Personagem(std::string nomeDado, int vidaMax, int danoBase, int defesaBase, Ataque* ataque1) : 
    nome(nomeDado), vidaAtual(vidaMax), vidaMax(vidaMax), danoBase(danoBase), defesaBase(defesaBase), ataque1(ataque1) { }

Personagem::~Personagem(){ }

std::string Personagem::getNome() const         { return this->nome; }
int Personagem::getVidaAtual() const            { return this->vidaAtual; }
int Personagem::getVidaMax() const              { return this->vidaMax; }
int Personagem::getDanoBase() const             { return this->danoBase; }
int Personagem::getDefesaBase() const           { return this->defesaBase; }
Ataque* Personagem::getAtaque1() const          { return this->ataque1; }
Ataque* Personagem::getAtaque2() const          { return this->ataque2; }
Talisma* Personagem::getTalismaSegurado() const { return this->talismaSegurado; }

void Personagem::setHitbox(int x, int y, int WIDTH, int HEIGHT){
    this->hitbox.x = x;
    this->hitbox.y = y;
    this->hitbox.width = WIDTH;
    this->hitbox.height = HEIGHT;
}


void Personagem::AddVidaAtual(int diferenca){
    if( (this->vidaAtual + diferenca) >= this->vidaMax){
        this->vidaAtual = this->vidaMax;
        return;
    }
    if( (this->vidaAtual - diferenca) <= 0 ){
        this->vidaAtual = 0;
        return;
    }
    this->vidaAtual += diferenca;
    return;

}


void Personagem::UsarAtaque(Ataque* ataqueUsado, Personagem* alvo){
    srand(time(0));
    int randomNum = rand() % 101; //gera um numero entre 0 e 100
    if( ataqueUsado->getChanceSucesso() >= randomNum ){
        std::cout << ataqueUsado->getNomeAtaque() << "acertou!" << std::endl;
        
        int danoCausado = int(float(this->danoBase) + float(ataqueUsado->getModDanoBase() * this->danoBase * 0.5) - float(alvo->defesaBase * this->danoBase * 0.2));
        if( int chanceCritico = 10 >= randomNum){
            std::cout << "Acerto crítico!" << danoCausado << std::endl;
            danoCausado = danoCausado * 2;
        }
        std::cout << "Dano causado: " << danoCausado << std::endl;
        alvo->AddVidaAtual( -danoCausado);
        return;
    }
    std::cout << ataqueUsado->getNomeAtaque() << "falhou!" << std::endl;
    return;
}





Jogador::Jogador() { }
Jogador::Jogador(std::string nomeDado) { }
Jogador::~Jogador() { }