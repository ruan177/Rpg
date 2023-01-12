#pragma once
#include "Personagem.h"

class Enemy {
public:
	std::string nome;
	int vida;
	int xp;
	int level;
	std::string descricao;

	void DefineInimigo(Enemy* inimigo);
	void CriaInimigo(Enemy* inimigo, Personagem* personagem);
	void MenuDeCombate(Enemy* inimigo, Personagem* personagem);
};

