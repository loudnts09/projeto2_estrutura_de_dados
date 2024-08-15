#include "carregar_concursos.h"
#include <stdio.h>
#include <stdlib.h>

void carregar_concursos(Tabela * tabela, const char * nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        Concurso concurso;
        sscanf(linha, "%d,%[^,],%d,%d,%d,%d,%d,%d",
               &concurso.numero, concurso.formato_data,
               &concurso.valores[0], &concurso.valores[1],
               &concurso.valores[2], &concurso.valores[3],
               &concurso.valores[4], &concurso.valores[5]);

        inserir_concurso(tabela, concurso);
    }

    fclose(arquivo);
}
