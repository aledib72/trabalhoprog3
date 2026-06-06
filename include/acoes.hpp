#pragma once
#include "itens.hpp"
#include <string>


class Ataque{
    protected:
        std::string nomeAtaque;
        int modDanoBase;
        int chanceSucesso;

    public:
        Ataque();
        ~Ataque();
        std::string getNomeAtaque() const;
        int getModDanoBase() const;
        int getChanceSucesso() const;
        
};

class Defesa{
    protected:
        int modDefesa;
};
