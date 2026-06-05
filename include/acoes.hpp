#pragma once

class Ataque{
    protected:
        int modDanoBase;
        int chanceSucesso;

    public:
        int virtual UsarAtaque();
};