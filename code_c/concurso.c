#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "concurso.h"

unsigned int tabela(int numero){
    return numero % TAMANHO_TABELA;
}

Tabela * criar_tabela() {
    Tabela * nova_tabela = (Tabela *) malloc(sizeof(Tabela));
    
    for(int i = 0; i < TAMANHO_TABELA; i++){
        nova_tabela->tabela[i] = NULL;
    }
    return nova_tabela;
}

void inserir_concurso(Tabela * tabela, Concurso concurso){
    unsigned int indice = hash(concurso.numero);
    while(tabela->tabela[indice] != NULL && tabela->tabela[indice]-> numero != concurso.numero){
        indice = (indice + 1) % TAMANHO_TABELA;
    }
    if(tabela->tabela[indice] != NULL){
        printf("Concurso %d já existe!\n", concurso.numero);
    }
    else{
        tabela->tabela[indice] = (Concurso*) malloc(sizeof(Concurso));
        * tabela->tabela[indice] = concurso;
        printf("Concurso %d inserido com sucesso!\n", concurso.numero);
    }
}

