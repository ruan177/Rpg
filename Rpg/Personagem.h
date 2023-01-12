#pragma once
#include "Bibliotecas.h"

class Personagem{
public:
    std::string nome;
    std::string classe;
    int level;
    int xp, vida, vidaMaxima, vidaTotal, experiencia, cura;

    Personagem();
    void HUD();
    void CriarPersonagem();

};


