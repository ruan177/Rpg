#include "Pilha.h"

Pilha::Pilha()
{
	inicio = NULL;
	fim = NULL;
	tamanho = 0;
}
int Pilha::Menu()
{
	int opcao;
	do {
		std::cout << std::endl << "Menu de opcoes" << std::endl;
		std::cout << "1 Visualizar toda historia" << std::endl;
		std::cout << "2 Remover primeiro dialogo" << std::endl;
		//std::cout << "3 Esvaziar Livro de historias" << std::endl;
		std::cout << "3 Sair" << std::endl;

		std::cout << "Digite sua escolha: ";
		std::cin >> opcao;

		if (opcao < 1 || opcao > 3)
			std::cout << "\tEscolha Invalida!" << std::endl;
	} while (opcao < 1 || opcao > 3);

	return opcao;
}
bool Pilha::eVazia()
{
	if (inicio == NULL)
		return true;
	return false;
}
void Pilha::cadastrarPilha(std::string dialogo)
{
	Dialogo* novo = new Dialogo();
	novo->dialogo = dialogo;
	novo->proximo = NULL;

	if (eVazia())
	{
		inicio = novo;
		fim = novo;
	}
	else
	{
		novo->proximo = inicio;
		inicio = novo;
	}
	tamanho++;
}
void Pilha::imprimir()
{
	if (eVazia())
		std::cout << "Pilha Vazia! ";
	else
	{
		Dialogo* pAux = inicio;

		std::cout << "_________________________________________________________" << std::endl;
		while (pAux != NULL)
		{
			std::cout<< "|" << pAux->dialogo << " " << "|" << std::endl;
			pAux = pAux->proximo;
		}
		std::cout << "_________________________________________________________" << std::endl;
	}
	std::cout << std::endl << "Numero de itens: " << tamanho << std::endl;
}

void Pilha::excluirDaPilha()
{
	if (eVazia())
		std::cout << "Pilha vazia!" << std::endl;
	else
	{
		Dialogo* pAux = inicio;
		inicio = inicio->proximo;
		delete(pAux);
	}
}
void Pilha::Esvazia()
{
    if (eVazia())
        std::cout << "Pilha vazia!" << std::endl;
	else
	{
		Dialogo* pAux = inicio;
		while (pAux != NULL)
		{
			inicio = inicio->proximo;
			delete(pAux);
			pAux = inicio;
		}
		std::cout << "Pilha esvaziada";
	}
}
