#pragma once
#include "Enemy.h"

class Inventario{
public: 
	std::string nome;
	int dano;
	std::string descricao;
	Inventario* proximo;
};

