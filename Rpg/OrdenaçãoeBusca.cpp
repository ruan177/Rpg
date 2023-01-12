#include "Pilha.h"

int MenuBestiario()
{
	int opcao;
	do {
		std::cout << std::endl << "Menu de opcoes" << std::endl;
		std::cout << "1 Visualizar Bestiario" << std::endl;
		std::cout << "2 Procurar inimigo" << std::endl;
		std::cout << "3 Ordenar Bestiario" << std::endl;
		std::cout << "4 Sair" << std::endl;

		std::cout << "Digite sua escolha: ";
		std::cin >> opcao;

		if (opcao < 1 || opcao > 4)
			std::cout << "\tEscolha Invalida!" << std::endl;
	} while (opcao < 1 || opcao > 4);

	return opcao;
}
void intercala(Enemy* inimigo, int inicio, int fim, int meio)
{
	int poslivre, inicio_vetor1, inicio_vetor2, i;
	Enemy pAux[6];
	inicio_vetor1 = inicio;
	inicio_vetor2 = meio + 1;
	poslivre = inicio;

	while (inicio_vetor1 <= meio && inicio_vetor2 <= fim)
	{
		if (inimigo[inicio_vetor1].nome <= inimigo[inicio_vetor2].nome)
		{
			pAux[poslivre].nome = inimigo[inicio_vetor1].nome;
			pAux[poslivre].vida = inimigo[inicio_vetor1].vida;
			pAux[poslivre].xp = inimigo[inicio_vetor1].xp;
			pAux[poslivre].level = inimigo[inicio_vetor1].level;
			pAux[poslivre].descricao = inimigo[inicio_vetor1].descricao;

			inicio_vetor1 = inicio_vetor1 + 1;

		}
		else
		{
			pAux[poslivre].nome = inimigo[inicio_vetor2].nome;
			pAux[poslivre].vida = inimigo[inicio_vetor2].vida;
			pAux[poslivre].xp = inimigo[inicio_vetor2].xp;
			pAux[poslivre].level = inimigo[inicio_vetor2].level;
			pAux[poslivre].descricao = inimigo[inicio_vetor2].descricao;
			inicio_vetor2 = inicio_vetor2 + 1;
		}
		poslivre = poslivre + 1;

	}
	for (i = inicio_vetor1; i <= meio; i++)
	{
		pAux[poslivre].nome = inimigo[i].nome;
		pAux[poslivre].vida = inimigo[i].vida;
		pAux[poslivre].xp = inimigo[i].xp;
		pAux[poslivre].level = inimigo[i].level;
		pAux[poslivre].descricao = inimigo[i].descricao;
		poslivre = poslivre + 1;

	}

	for (i = inicio_vetor2; i <= fim; i++)
	{
		pAux[poslivre].nome = inimigo[i].nome;
		pAux[poslivre].vida = inimigo[i].vida;
		pAux[poslivre].xp = inimigo[i].xp;
		pAux[poslivre].level = inimigo[i].level;
		pAux[poslivre].descricao = inimigo[i].descricao;
		poslivre = poslivre + 1;

	}

	for (i = inicio; i <= fim; i++)
	{
		inimigo[i].nome = pAux[i].nome;
		inimigo[i].vida = pAux[i].vida;
		inimigo[i].xp = pAux[i].xp;
		inimigo[i].level = pAux[i].level;
		inimigo[i].descricao = pAux[i].descricao;

	}
}
void merge(Enemy* inimigo, int inicio, int fim)
{
	int meio;
	if (inicio < fim)
	{
		meio = (inicio + fim) / 2;
		merge(inimigo, inicio, meio);
		merge(inimigo, meio + 1, fim);
		intercala(inimigo, inicio, fim, meio);
	}
}
void imprime(Enemy* inimigo)
{
	Enemy* pAux = inimigo;

	for (int i = 0; i < 6; i++)
	{
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "\tNome: " << pAux->nome << std::endl;
		std::cout << "Descricao: " << pAux->descricao << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		pAux = pAux + 1;
	}
}
void buscaNaoOrdenada(Enemy* inimigo, std::string nome)
{
	int achou = 0;
	int i = 0;

	while (i <= 5 && achou == 0)
	{
		if (inimigo[i].nome == nome)
			achou = 1;
		else
			i++;
	}
	if (achou == 0)
		std::cout << "Inimigo nao encontrado";
	else
		std::cout << "Inimigo encontrado: " << inimigo[i].nome << std::endl << inimigo[i].descricao << std::endl;

}

