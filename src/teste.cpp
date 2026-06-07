#include <iostream>
#include <string>
#include "personagens.hpp"
#include "itens.hpp"
#include "acoes.hpp"


int main_teste(){
    std::cout << "\n Hello World! \n" << std::endl;
    Ataque ataque1;
    Personagem p1("bixo1");
    Personagem p2("bixo2");
    
    std::cout << "Vida bixo2 = " << p2.getVidaAtual() << std::endl;
    p1.UsarAtaque(&ataque1, &p2);
    std::cout << "Vida bixo2 = " << p2.getVidaAtual() << std::endl;

    return 0;
}
