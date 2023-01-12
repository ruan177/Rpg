
#include "Enemy.h"

void Enemy::DefineInimigo(Enemy* inimigo)
{
	Enemy* pAux = inimigo;

	pAux->nome = "Bruxa";
	pAux->vida = 0;
	pAux->level = 0;
	pAux->xp = 0;
	pAux->descricao = "Apesar da historias dizerem ser real, mas elas era apenas mulheres que cultivavam ervas medicinais e que por algum motivo incomodovam alguns";

	(pAux + 1)->nome = "Cavaleiro";
	(pAux + 1)->vida = 0;
	(pAux + 1)->level = 0;
	(pAux + 1)->xp = 0;
	(pAux + 1)->descricao = "Apesar um individuo fardado com uma armadura metalica";

	(pAux + 2)->nome = "Templario";
	(pAux + 2)->vida = 0;
	(pAux + 2)->level = 0;
	(pAux + 2)->xp = 0;
	(pAux + 2)->descricao = "Individuo que peregrinaram ate jerusalem";

	(pAux + 3)->nome = "Carrasco";
	(pAux + 3)->vida = 0;
	(pAux + 3)->level = 0;
	(pAux + 3)->xp = 0;
	(pAux + 3)->descricao = "Executor responsavel por aplicar a pena de morte aos índividuos";

	(pAux + 4)->nome = "Paladino";
	(pAux + 4)->vida = 0;
	(pAux + 4)->level = 0;
	(pAux + 4)->xp = 0;
	(pAux + 4)->descricao = "Um cavaleiro que busca o caminho da verdade";

	(pAux + 5)->nome = "Alquimista";
	(pAux + 5)->vida = 0;
	(pAux + 5)->level = 0;
	(pAux + 5)->xp = 0;
	(pAux + 5)->descricao = "Alguns diziam ser responsavel por fazer transmutações, mas muito do que diziam não passavam de surpertições";
}

void Enemy::CriaInimigo(Enemy* inimigo, Personagem* personagem)
{
	srand(time(NULL));
	inimigo->vida = 10 + (rand() % 30) + personagem->level;
	inimigo->level = (rand() % 3) + personagem->level;
	if (inimigo->level == 0)
	{
		inimigo->level = (rand() % 3) + personagem->level;
	}
	inimigo->xp = inimigo->vida;
}

void Enemy::MenuDeCombate(Enemy* inimigo, Personagem* personagem)
{
	Sleep(500);
	system("cls");
	std::cout << "Nome: " << personagem->nome << "|  \tNome do monstro: " << inimigo->nome <<
		"\nVida: " << personagem->vidaTotal << "|  \tVida do monstro: " << inimigo->vida <<
		" \nExp: " << personagem->experiencia << "| \tMonster Level: " << inimigo->level << std::endl;
}
