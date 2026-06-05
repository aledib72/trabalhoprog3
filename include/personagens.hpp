#pragma once
#include <string>
#include "itens.hpp"

class Personagem{
    protected:
        std::string nome;
        int vidaMax;
        int vidaAtual;
        int danoBase;
        int defesaBase;
        Talisma* talismaSegurado;

    public:
        std::string getNome() const;
        int getVidaAtual() const;
        int getVidaMax() const;
};


class Jogador : public Personagem{
    protected:
        //inventario

    protected:
        int UsarItem();
        int Atacar();
        int Defender();
};


