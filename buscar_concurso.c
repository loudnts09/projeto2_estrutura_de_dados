#include "buscar_concurso.h"
#include <stdio.h>

Concurso * buscar_concurso(Tabela * tabela_hash, int numero) {
    unsigned int indice = hash(numero);

    while (tabela_hash->tabela[indice] != NULL) {
        if (tabela_hash->tabela[indice]->numero == numero) {
            return tabela_hash->tabela[indice];
        }
        indice = (indice + 1) % TAMANHO_TABELA;
    }
    return NULL;
}
