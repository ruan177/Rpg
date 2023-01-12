#pragma once
#include "Inventario.h"
class Fila
{
public:
	Inventario* inicio, * fim; //ponteiro que aponta para estrutura  de inicio e de final
	int tamanho; // saber o tamanho da lista

	Fila();
	int menu();
	bool eVazia();
	void inserirNaFila(Inventario* inventario);
	void imprime();
	void removerDaFila();
	void esvaziaFila();
	int procurar(std::string nome);
	Inventario preencheVetor();
};

