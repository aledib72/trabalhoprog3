#pragma once
#include "personagens.hpp"

class Ataque{
    protected:
        int modDanoBase;
        int chanceSucesso;

    public:
        Ataque();
        ~Ataque();
        void UsarAtaque(Personagem* atacante, Personagem* alvo);
};

class Defesa{
    protected:
        int modDefesa;
};
