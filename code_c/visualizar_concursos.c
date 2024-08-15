#include "visualizar_concursos.h"
#include <stdio.h>

void visualizar_concursos(Tabela * tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        if (tabela->tabela[i] != NULL) {
            printf("Concurso %d\n", tabela->tabela[i]->numero);
            printf("Data: %s\n", tabela->tabela[i]->formato_data);
            printf("Números: ");
            for (int j = 0; j < 6; j++) {
                printf("%d ", tabela->tabela[i]->valores[j]);
            }
            printf("\n\n");
        }
    }
}
