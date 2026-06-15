#include "pokedex.hpp"


Arara::Arara() {
    nome      = "Arara";
    vidaMax   = 50;
    vidaAtual = 50;
    danoBase  = 10;
    defesaBase = 5;

    ataque1 = new Ataque("Bico Afiado", 20, 80);
    ataque2 = new Ataque("Garra",       15, 90);
}
Arara::~Arara() {
    delete ataque1;
    delete ataque2;
}

Tucano::Tucano() {
    nome       = "Tucano";
    vidaMax    = 50;
    vidaAtual  = 50;
    danoBase   = 8;
    defesaBase = 7;
    ataque1 = new Ataque("Bicada",    15, 85);
    ataque2 = new Ataque("Investida", 20, 70);
}
Tucano::~Tucano() {
    delete ataque1;
    delete ataque2;
}

Preguica::Preguica() {
    nome       = "Preguica";
    vidaMax    = 50;
    vidaAtual  = 50;
    danoBase   = 5;
    defesaBase = 15;
    ataque1 = new Ataque("Arranhadela", 10, 90);
    ataque2 = new Ataque("Abraco",      25, 50);
}
Preguica::~Preguica() {
    delete ataque1;
    delete ataque2;
}


Capivara::Capivara() {
    nome       = "Capivara";
    vidaMax    = 50;
    vidaAtual  = 50;
    danoBase   = 12;
    defesaBase = 8;
    ataque1 = new Ataque("Mordida",   15, 80);
    ataque2 = new Ataque("Investida", 20, 65);
}
Capivara::~Capivara() {
    delete ataque1;
    delete ataque2;
}

LoboGuara::LoboGuara() {
    nome       = "Lobo Guara";
    vidaMax    = 50;
    vidaAtual  = 50;
    danoBase   = 18;
    defesaBase = 5;
    ataque1 = new Ataque("Presa", 25, 75);
    ataque2 = new Ataque("Urro",  30, 60);
}
LoboGuara::~LoboGuara() {
    delete ataque1;
    delete ataque2;
}

Tamandua::Tamandua() {
    nome       = "Tamandua";
    vidaMax    = 50;
    vidaAtual  = 50;
    danoBase   = 14;
    defesaBase = 10;
    ataque1 = new Ataque("Garras", 20, 75);
    ataque2 = new Ataque("Lingua", 15, 85);
}
Tamandua::~Tamandua() {
    delete ataque1;
    delete ataque2;
}


Onca::Onca() {
    nome       = "Onca";
    vidaMax    = 75;
    vidaAtual  = 75;
    danoBase   = 30;
    defesaBase = 15;
    ataque1 = new Ataque("Rugido", 35, 80);
    ataque2 = new Ataque("Pata",   40, 65);
}
Onca::~Onca() {
    delete ataque1;
    delete ataque2;
}

Sucuri::Sucuri() {
    nome       = "Sucuri";
    vidaMax    = 75;
    vidaAtual  = 75;
    danoBase   = 25;
    defesaBase = 20;
    ataque1 = new Ataque("Constricao", 30, 75);
    ataque2 = new Ataque("Bote",       45, 55);
}
Sucuri::~Sucuri() {
    delete ataque1;
    delete ataque2;
}