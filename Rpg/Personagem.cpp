#include "Personagem.h"

Personagem::Personagem()
{
	classe = "Alquimista";
	level = 1;
	xp = 0;
	experiencia = 76;
	vida = 100;
	vidaTotal = vida;
	vidaMaxima = vida;
	cura = 0;
}
void Personagem::HUD()
{
	Sleep(500);
	system("cls");
	std::cout << "Nome: " << nome << "\nVida: " << vidaTotal << "\nClass: " << classe << "\nLevel: " << level <<
		"\nxp: " << xp << "\nQuantidade de experiencia: " << experiencia << std::endl;
}
void Personagem::CriarPersonagem()
{
	std::cout << " Digite o nome do personagem: ";
	std::cin >> nome;
}

