
#include "Dialogo.h"
Dialogo::Dialogo()
{
    proximo = NULL;
}
void Dialogo::vetDialogo(std::string *vetD)
{

    *vetD = "Voce e um ajudante de Alexandre Yersin que trabalha ardoamente para descobrir uma cura de uma doença que esta asolando sua ciadade, certo dia por conta de um descuido de seu mestre seu laboratorio foi descoberto pelos templarios,que roubaram toda sua pesquisa para levar a igreja que pretende destrui-la,e agora cabe a você ajudar seu mestre a recuperar sua pesquisa antes que os templarios cheguem a igreja";
    *(vetD + 1) = "Nesta jornada voce encontrara diversos inimigos, sejam eles bruxas, alquimistas, carrascos, derrote-os para que ganhe recompensas podendo chegar mais proximoa resposta do que procura";
    *(vetD + 2) = "Siga em frente mas nao se descuide, voce encontrara diversos itens pelo caminho, mas nao podera usa-los ja que nao possui a destreza necessaria para equipa-los";
    *(vetD + 3) = "Talvez voce nunca encontre o que procura mas nunca desista, explore todos os mundos, leia sobre os inimigos, sobre os tipos de espadas, quanto mais conheciemnto adquirir mais facil sera o caminho";
    *(vetD + 4) = "Mas nao se esqueca, nem todas batalhas serao faceis";
    *(vetD + 5) = "Parece que nao ha nada de interessante por aqui, tente novamente mais tarde";
    *(vetD + 6) = "As colinas ao sul parecem interessantes sempre ha inimigos ou itens la";
    *(vetD + 7) = "Parabens seu progresso parece estar indo bem, continue e nao desista";
}
