#include "personagens.hpp"


//Construtores e destrutor

Personagem::Personagem() : nome("indefinido"), vidaAtual(20), vidaMax(20){ }
Personagem::~Personagem(){ }

std::string Personagem::getNome() const         { return this->nome; }
int Personagem::getVidaAtual() const            { return this->vidaAtual; }
int Personagem::getVidaMax() const              { return this->vidaMax; }
int Personagem::getDanoBase() const             { return this->danoBase; }
int Personagem::getDefesaBase() const           { return this->defesaBase; }
Talisma* Personagem::getTalismaSegurado() const { return this->talismaSegurado; }

void Personagem::addVidaAtual(int diferenca){
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