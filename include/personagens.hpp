    #pragma once
    #include <string>
    #include "itens.hpp"
    #include "acoes.hpp"
    #include "raylib.h"

    class Personagem{
        protected:
            std::string nome;
            int vidaMax;
            int vidaAtual;
            int danoBase;
            int defesaBase;
            Talisma* talismaSegurado;
            Ataque* ataque1;
            Ataque* ataque2;
            Rectangle hitbox;

        public:
            Personagem();
            Personagem(std::string nomeDado);
            ~Personagem();
            std::string getNome() const;
            int getVidaAtual() const;
            int getVidaMax() const;
            int getDanoBase() const;
            int getDefesaBase() const;
            Talisma* getTalismaSegurado() const;

            void setHitbox(int x, int y, int WIDTH, int HEIGHT);

            void AddVidaAtual(int diferenca);
            void UsarAtaque(Ataque* ataqueUsado, Personagem* alvo);
            void PegarNovoTalisma(Talisma* novoTalisma);

    };


    class Jogador : public Personagem{
        protected:
            //inventario

        public:
            Jogador();
            Jogador(std::string nomeDado);
            ~Jogador();
            int UsarItem();
            
    };




