#pragma once
#include "Dialogo.h"
class Pilha{
public:
	Dialogo* inicio, * fim;
	int tamanho;

	Pilha();
	int Menu();
	bool eVazia();
	void cadastrarPilha(std::string dialogo);
	void imprimir();
	void excluirDaPilha();
	void Esvazia();

};

