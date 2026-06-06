#include <iostream>
#include <string>
#include "personagens.hpp"
#include "itens.hpp"
#include "acoes.hpp"


int main(){
    std::cout << "\n Hello World! \n" << std::endl;
    Ataque ataque1;
    Personagem p1;
    Personagem p2;
    ataque1.UsarAtaque(&p1, &p2);

    return 0;
}
