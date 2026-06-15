#pragma once
#include "personagens.hpp"

// ─── Iniciais ───────────────────────────────────────────
class Arara : public Personagem {
public:
    Arara();
    ~Arara();
};

class Tucano : public Personagem {
public:
    Tucano();
    ~Tucano();
};

class Preguica : public Personagem {
public:
    Preguica();
    ~Preguica();
};

// ─── Inimigos Padrões ───────────────────────────────────
class Capivara : public Personagem {
public:
    Capivara();
    ~Capivara();
};

class LoboGuara : public Personagem {
public:
    LoboGuara();
    ~LoboGuara();
};

class Tamandua : public Personagem {
public:
    Tamandua();
    ~Tamandua();
};

// ─── Bosses ─────────────────────────────────────────────
class Onca : public Personagem {
public:
    Onca();
    ~Onca();
};

class Sucuri : public Personagem {
public:
    Sucuri();
    ~Sucuri();
};