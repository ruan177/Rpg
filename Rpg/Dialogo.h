#pragma once
#include "Fila.h"
class Dialogo{
public:
	std::string dialogo;
	Dialogo* proximo;

	Dialogo();
	void vetDialogo(std::string* vetD);
};
