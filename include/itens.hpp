#pragma once

class Talisma {
protected:
    int cura;

public:

    Talisma() : cura(20) {}
    Talisma(int _cura) : cura(_cura) {}
    ~Talisma() {}

    int getCura() const { return cura; }
};