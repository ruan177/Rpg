#include "OrdenacaoeBusca.h"

using namespace std;
const int TAM = 6;
int item = 0;
void mapa(Enemy* inimigo, Personagem* personagem);
void Combate(Enemy* inimigo, Personagem* personagem, Enemy* inicio, Fila* fila);

int main()
{
	Personagem personagem;
	personagem.CriarPersonagem();
	personagem.HUD();
	Enemy inimigo[TAM];
	inimigo->DefineInimigo(inimigo);
    mapa(inimigo, &personagem);
    return 0;
}
void mapa(Enemy* inimigo, Personagem* personagem)// funcao principal que simula um mapa e que contem todas as outras funcoes
{
    string Dialogos[8];
    Dialogo dialogo;
    dialogo.vetDialogo(Dialogos);
    string nome, historia;
    Enemy* inicio = inimigo;
    Fila fila;
    Pilha pilha;
    Inventario novoItem;
    
    int escolha, chance, chance2, i, j, escolha2, escolha3, opcao, dano = 0;
    
    do {
        cout << endl << "Menu de acoes" << endl <<
            "1. Explorar as regioes ao Norte " << endl <<
            "2. Descansar" << endl <<
            "3. Explorar as regioes ao Sul " << endl <<
            "4. Acessar Bestiario" << endl <<
            "5. Acessar Inventario" << endl <<
            "6. Abrir Livro de Historia do Jogo" << endl <<
            "7. Sair" << endl;
        cout << endl << endl;
        cin >> escolha;

        if (escolha < 1 || escolha > 6)
            cout << "Escolha invalida !! ";
    } while (escolha < 1 || escolha > 6);

    do {
        switch (escolha)
        {
        case 1:
            cout << " Explorando as regioes ao Norte....." << endl;
            chance = rand() % 100 + 1;
            if (chance < 50)
            {
                cout << "Um inimigo esta vindo em sua direcao" << endl;
                i = rand() % TAM;
                inimigo->CriaInimigo(inimigo + i, personagem);
                Sleep(2000);
                Combate(inimigo + i, personagem, inicio, &fila);
            }
            cout << " Voce encontrou um item, o item foi adicionado ao inventario" << endl;
            item++;
            mapa(inicio, personagem);


            break;

        case 2:
            cout << "Descansando......";
            if (personagem->vidaTotal <= 99)
            {
                personagem->vidaTotal += 10 * personagem->level;
                if (personagem->vidaTotal > 100 && personagem->level == 1)
                {
                    personagem->vidaTotal = 100;
                }
                else if (personagem->vidaTotal > 120 && personagem->level == 2)
                {
                    personagem->vidaTotal = 120;
                }
                else if (personagem->vidaTotal > 140 && personagem->level == 3)
                {
                    personagem->vidaTotal = 140;
                }
                else if (personagem->vidaTotal > 160 && personagem->level == 4)
                {
                    personagem->vidaTotal = 160;
                }

            }
            personagem->HUD();
            mapa(inicio, personagem);


            break;

        case 3:
            cout << " Explorando as regioes ao Sul....." << endl;
            chance2 = rand() % 100 + 1;
            if (chance2 < 10)
            {
                cout << "Um inimigo esta vindo em sua direcao" << endl;
                j = rand() % TAM;
                inimigo->CriaInimigo(inimigo + j, personagem);
                Sleep(2000);
                Combate(inimigo + j, personagem, inicio, &fila);
            }
            cout << " Voce encontrou um item, o item foi adicionado ao inventario" << endl;
            item++;
            mapa(inicio, personagem);


            break;

        case 4:
            cout << "Acessando Bestiario....." << endl;
            opcao = MenuBestiario();


            switch (opcao)
            {
            case 1:
                imprime(inicio);
                Sleep(50);

                break;

            case 2:
                cout << " Digite o nome do inimigo que deseja buscar: ";
                cin >> nome;
                buscaNaoOrdenada(inicio, nome);
                Sleep(50);

                break;

            case 3:
                cout << " Ordenando Bestiario....." << endl;
                merge(inimigo, 0, TAM - 1);
                Sleep(50);

                break;

            default:
                cout << "Saindo do bestiario....";
                system("cls");
                mapa(inicio, personagem);
            }

            break;

        case 5:
            cout << " \nAcessando Inventario";
            
            if (item > 0)
            {
                novoItem = fila.preencheVetor();
                fila.inserirNaFila(&novoItem);
                item--;
                
            }

            escolha2 = fila.menu();
            do {
                switch (escolha2)
                {
                case 1:
                    if (fila.eVazia())
                    {
                        cout << "O inventario esta vazio";

                    }
                    else
                    {
                        cout << " Digite o nome da espada que deseja procurar: "<< endl;
                        cin >> nome;
                        dano = fila.procurar(nome);
                        if (dano == 0)
                        {
                            cout << "\nEspada nao encontrada" << endl;

                        }
                        else
                        {
                            cout << "\n A espada " << nome << " esta no inventario";

                        }
                    }

                    break;

                case 2:
                    cout << "Visualizando o inventario...";
                    fila.imprime();
                    break;

                case 3:
                    cout << "Removendo primeiro item...";
                    fila.removerDaFila();

                    break;

                case 4:
                    cout << "Esvaziando o inventario ...";
                    fila.esvaziaFila();

                    break;

                default:
                    cout << "Saindo..." << endl;
                    Sleep(50);
                    system("cls");
                    personagem->HUD();
                    mapa(inicio, personagem);

                }
            } while (escolha != TAM - 1);
            break;

        case 6:
            cout << " Acessando Livro de Historias....";
            if (pilha.eVazia())
            {
                for (i = 0; i < TAM + 2; i++)
                {
                    pilha.cadastrarPilha(Dialogos[i]);
                }
            }
            
            escolha3 = pilha.Menu();
            do {
                switch (escolha3)
                {
                case 1:
                    std::cout << " Imprimindo historia......" << std::endl;
                    pilha.imprimir();
                    Sleep(50);
                    break;

                case 2:
                    pilha.excluirDaPilha();
                    Sleep(50);
                    break;

                default:
                    cout << "Saindo..." << endl;
                    Sleep(50);
                    system("cls");
                    mapa(inicio, personagem);
                }
            }while (escolha3 <1 || escolha3 > TAM - 3);
                        
            //mapa(inicio, personagem);
            break;

        default:
            cout << "Saindo......";
        }
    } while (escolha != TAM + 1);

}
void Combate(Enemy* inimigo, Personagem* personagem, Enemy* inicio, Fila* fila)// funcao combate responsavel por gerencia o menu de combate
{
    inimigo->MenuDeCombate(inimigo, personagem);

    int escolha;
    int chance;
    int chance2;
    int dano_do_monstro = 6 * inimigo->level / 2;
    int dano_do_jogador = 32 * personagem->level / 2;

    if (personagem->vidaTotal >= 1 && inimigo->vida >= 1)
    {
        cout << endl << "Menu de acoes" << endl;
        cout << "1 atacar" << endl;
        cout << "2 esquivar" << endl;
        cout << "3 curar" << endl;
        cout << endl << endl;

        cin >> escolha;

        switch (escolha)
        {
        case 1:
            chance = rand() % 100 + 1;
            cout << " ";
            if (chance >= 50)
            {
                cout << " Atacando.... o/a " << inimigo->nome << endl;
                inimigo->vida = inimigo->vida - dano_do_jogador; //variavel que atualiza a vida do monstro
                cout << " Voce tirou " << dano_do_jogador << " de vida do inimigo" << endl;
                Sleep(1000);
                inimigo->MenuDeCombate(inimigo, personagem);
                Combate(inimigo, personagem, inicio, fila);
            }
            else
            {
                cout << "\n\n";
                cout << "O inimigo defendeu e revidou ......" << endl;
                personagem->vidaTotal = personagem->vidaTotal - dano_do_monstro; //variavel que a atualiza a vida do personagem
                cout << " voce perdeu " << dano_do_monstro << " HP ";
                inimigo->MenuDeCombate(inimigo, personagem);
                Combate(inimigo, personagem, inicio, fila);
            }

            break;

        case 2:
            chance2 = rand() % 100 + 1;
            if (chance2 >= 50)
            {
                cout << "Voce se esquivou! " << endl;
                cout << "Boa esquiva, voce ganhou uma pequena cura" << endl;
                personagem->vidaTotal += personagem->level * 6 / 2;
                Sleep(2000);
                inimigo->MenuDeCombate(inimigo, personagem);
                Combate(inimigo, personagem, inicio, fila);

            }
            else
            {
                cout << "\n\n";
                cout << "Fallha na esquiva  ......" << endl;
                personagem->vidaTotal = personagem->vidaTotal - dano_do_monstro; //variavel que a atualiza a vida do personagem
                cout << " Voce perdeu" << dano_do_monstro << " de HP dos" << personagem->vidaTotal;
                inimigo->MenuDeCombate(inimigo, personagem);
                Combate(inimigo, personagem, inicio, fila);
            }
            break;

        case 3:
            if (personagem->vidaTotal < personagem->vida)
            {
                cout << "Se curando.... " << endl;
                personagem->cura = personagem->level * 10 / 2;
                personagem->vidaTotal += personagem->cura;
            }
            else
            {
                cout << " Vida Cheia!!!" << endl;
            }

            inimigo->MenuDeCombate(inimigo, personagem);
            Combate(inimigo, personagem, inicio, fila);
            break;

        default:
            cout << "Opção Invalida!!!!";
            Combate(inimigo, personagem, inicio, fila);
        }
    }
    if (personagem->vidaTotal <= 1)
    {
        system("cls");
        cout << " Voce morreu!!! ";
        Sleep(5000);
        exit(0);
    }
    if (inimigo->vida <= 1)
    {
        personagem->HUD();
        personagem->xp += inimigo->xp;
        cout << endl << endl;
        Sleep(1500);
    }
    if (personagem->xp >= personagem->experiencia)
    {
        personagem->level++;
        personagem->vidaTotal = 100;
        personagem->vidaTotal += 20;
        personagem->HUD();
        personagem->experiencia = personagem->experiencia * personagem->level + 1;

        Sleep(2000);

    }
    personagem->HUD();
    mapa(inicio, personagem);
}