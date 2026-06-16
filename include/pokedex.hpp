#pragma once
#include "personagens.hpp"

class Arara : public Personagem {
public:
    Arara(); Arara(std::string nome);
    ~Arara();
    std::string getTipo() const override { return "Inicial"; }
};

class Tucano : public Personagem {
public:
    Tucano(); Tucano(std::string nome);
    ~Tucano();
    std::string getTipo() const override { return "Inicial"; }
};

class Preguica : public Personagem {
public:
    Preguica(); Preguica(std::string nome);
    ~Preguica();
    std::string getTipo() const override { return "Inicial"; }
};

class Capivara : public Personagem {
public:
    Capivara();
    ~Capivara();
    std::string getTipo() const override { return "Mob"; }
};

class LoboGuara : public Personagem {
public:
    LoboGuara();
    ~LoboGuara();
    std::string getTipo() const override { return "Mob"; }
};

class Tamandua : public Personagem {
public:
    Tamandua();
    ~Tamandua();
    std::string getTipo() const override { return "Mob"; }
};

class Onca : public Personagem {
public:
    Onca();
    ~Onca();
    std::string getTipo() const override { return "Boss"; }
};

class Sucuri : public Personagem {
public:
    Sucuri();
    ~Sucuri();
    std::string getTipo() const override { return "Boss"; }
};