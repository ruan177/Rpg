#include "Fila.h"

Fila::Fila()
{
    inicio = NULL;
    fim = NULL;
    tamanho = 0;
}
int Fila::menu()
{
    int opcao;
    do {
        std::cout << std::endl << "Menu de opcoes" << std::endl;
        std::cout << "1 Procurar espada" << std::endl;
        std::cout << "2 Imprimir todo Inventario" << std::endl;
        std::cout << "3 Remover do Invenraio" << std::endl;
        std::cout << "4 Esvaziar Inventario" << std::endl;
        std::cout << "5 Sair" << std::endl;

        std::cout << "Digite sua escolha: ";
        std::cin >> opcao;

        if (opcao < 1 || opcao > 5)
            std::cout << "\tEscolha Invalida!" << std::endl;
    } while (opcao < 1 || opcao > 5);

    return opcao;
}

bool Fila::eVazia()
{
    if (inicio == NULL)
        return true;
    return false;
}
int Fila::procurar(std::string nome)
{
    if (eVazia())
        std::cout << "Fila Vazia! \n";
    else
    {
        Inventario* pAux = inicio;

        while (pAux != NULL)
        {
            if (pAux->nome == nome)
                return pAux->dano;
            pAux = pAux->proximo;
        }
    }
    return 0;
}

void Fila::inserirNaFila(Inventario* inventario)
{
    Inventario* novo = new Inventario();
    novo->nome = inventario->nome;
    novo->dano = inventario->dano;
    novo->descricao = inventario->descricao;

    if (eVazia())
    {
        inicio = novo;
        fim = novo;
    }
    else
    {
        fim->proximo = novo;
        fim = novo;
    }
    tamanho++;
}

void Fila::imprime()
{
    std::cout << std::endl << "Tamanho da Fila: " << tamanho << std::endl;
    int item = 0;
    if (eVazia())
        std::cout << "Fila vazia!" << std::endl;
    else
    {
        Inventario* pAux = inicio;

        do
        {
            //item += 1;
            std::cout << "\n_________________________________________" << std::endl;
            //std::cout << item << std:: endl;
            std::cout <<"Espada: " << pAux->nome << std::endl;
            std::cout<<"Dano: " << pAux->dano << std::endl;
            std::cout <<"Descricao: " << pAux->descricao << std::endl;
            std::cout << "_________________________________________" << std::endl;
            pAux = pAux->proximo; //pAux aponta para pAux->proximo
        } while (pAux != NULL);
        std::cout << std::endl << std::endl;
    }
}
void Fila::removerDaFila()
{
    if (eVazia())
        std::cout << "Fila vazia!" << std::endl;
    else
    {
        Inventario* pAux = inicio;
        inicio = inicio->proximo;
        delete(pAux);
    }
}
void Fila::esvaziaFila()
{
    if (eVazia())
        std::cout << "Fila vazia!" << std::endl;
    else
    {
        Inventario* pAux = inicio;
        while (pAux != NULL)
        {
            inicio = inicio->proximo;
            delete(pAux);
            pAux = inicio;
        }
        std::cout << "Fila esvaziada";
    }
}
Inventario Fila::preencheVetor()
{
    Inventario pAux;
    int i = rand() % 5;

    std::string vetNomes[] = { "Claymore", "Estoque", "Machete", "Bastarda", "Florete" };
    std::string vetDesc[] = { "Usada em duas maos remonta a Idade Media e aos escoceses",
        "lamina estreita com uma ponta fina de tres lados para causar golpes de perfuracao",
        "uma faca unica mais curto do que uma espada usada comumente uma ferramenta de corte",
        " nome generico para muitas espadas retas e longas usadas a meio caminho ou em duas maos",
        "espadas longas e retas que sao usadas com uma mao chamados assim por ser um complemento as roupas moda ou a autodefesa" };

    pAux.nome = vetNomes[i];;
    pAux.dano = 8 + rand() % 5;
    pAux.descricao = vetDesc[i];

    return pAux;
}