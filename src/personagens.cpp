#include "personagens.hpp"
#include <iostream>

Personagem::Personagem()
    : nome("indefinido"), vidaAtual(30), vidaMax(30),
      danoBase(10), defesaBase(10),
      talismaSegurado(nullptr), ataque1(nullptr), ataque2(nullptr)
{
    hitbox = {0, 0, 0, 0};
}

Personagem::Personagem(std::string nomeDado)
    : nome(nomeDado), vidaAtual(30), vidaMax(30),
      danoBase(10), defesaBase(10),
      talismaSegurado(nullptr), ataque1(nullptr), ataque2(nullptr)
{
    hitbox = {0, 0, 0, 0};
    std::cout << this->nome << " criado!" << std::endl;
}

Personagem::~Personagem() {}


std::string Personagem::getNome()      const { return this->nome; }
int         Personagem::getVidaAtual() const { return this->vidaAtual; }
int         Personagem::getVidaMax()   const { return this->vidaMax; }
int         Personagem::getDanoBase()  const { return this->danoBase; }
int         Personagem::getDefesaBase()const { return this->defesaBase; }

Ataque* Personagem::getAtaque1() const { return this->ataque1; }
Ataque* Personagem::getAtaque2() const { return this->ataque2; }

Talisma* Personagem::getTalismaSegurado() const { return this->talismaSegurado; }


void Personagem::setHitbox(float x, float y, int WIDTH, int HEIGHT) {
    this->hitbox.x      = x;
    this->hitbox.y      = y;
    this->hitbox.width  = WIDTH;
    this->hitbox.height = HEIGHT;
}

Rectangle Personagem::getHitbox() const {
    return hitbox;
}


void Personagem::AddVidaAtual(int diferenca) {
    if ((this->vidaAtual + diferenca) >= this->vidaMax) {
        this->vidaAtual = this->vidaMax;
        return;
    }

    if ((this->vidaAtual + diferenca) <= 0) {
        this->vidaAtual = 0;
        return;
    }
    this->vidaAtual += diferenca;
}


void Personagem::UsarAtaque(Ataque* ataqueUsado, Personagem* alvo) {
 
    int roll = GetRandomValue(0, 100);
    if (ataqueUsado->getChanceSucesso() >= roll) {
        int danoCausado = this->danoBase +
            (int)(ataqueUsado->getModDanoBase() * this->danoBase * 0.01f);
        alvo->AddVidaAtual(-danoCausado);
    }
}

void Personagem::PegarNovoTalisma(Talisma* novoTalisma) {
    this->talismaSegurado = novoTalisma;
}


bool Personagem::operator==(const Personagem& other) const {
    Rectangle a = this->getHitbox();
    Rectangle b = other.getHitbox();
    return (a.x < b.x + b.width  &&
            a.x + a.width > b.x  &&
            a.y < b.y + b.height &&
            a.y + a.height > b.y);
}


Jogador::Jogador() : Personagem() {}

Jogador::Jogador(std::string nomeDado) : Personagem(nomeDado) {}

Jogador::~Jogador() {}

int Jogador::UsarItem() {
    if (talismaSegurado == nullptr) return 0;
    AddVidaAtual(talismaSegurado->getCura());
    delete talismaSegurado;
    talismaSegurado = nullptr;
    return 1;
}