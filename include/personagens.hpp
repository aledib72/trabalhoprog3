#pragma once
#include <string>
#include "itens.hpp"
#include "acoes.hpp"
#include "raylib.h"

template<typename T>
T limitarValor(T valor, T minimo, T maximo) {
    if (valor < minimo) return minimo;
    if (valor > maximo) return maximo;
    return valor;
}

class Personagem {
protected:
    std::string nome;
    int vidaMax;
    int vidaAtual;
    int danoBase;
    int defesaBase;
    Talisma*  talismaSegurado;
    Ataque*   ataque1;
    Ataque*   ataque2;
    Rectangle hitbox;

public:
    Personagem();
    Personagem(std::string nomeDado);
    virtual ~Personagem();  

    std::string getNome()            const;
    int         getVidaAtual()       const;
    int         getVidaMax()         const;
    int         getDanoBase()        const;
    int         getDefesaBase()      const;
    Ataque*     getAtaque1()         const;
    Ataque*     getAtaque2()         const;
    Rectangle   getHitbox()          const;
    Talisma*    getTalismaSegurado() const;

    void setHitbox(float x, float y, int WIDTH, int HEIGHT);
    void AddVidaAtual(int diferenca);
    void UsarAtaque(Ataque* ataqueUsado, Personagem* alvo);
    void PegarNovoTalisma(Talisma* novoTalisma);

    bool operator==(const Personagem& other) const;

    virtual std::string getTipo() const;
};

class Jogador : public Personagem {
public:
    Jogador();
    Jogador(std::string nomeDado);
    ~Jogador();
    int UsarItem();
};