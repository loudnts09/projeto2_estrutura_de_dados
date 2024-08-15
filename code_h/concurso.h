#ifndef CONCURSO_H
#define CONCURSO_H

#define TAMANHO_TABELA 100

typedef struct Concurso{
    int numero;
    char formato_data[11];
    int valores[6];
} Concurso;

typedef struct Tabela{
    Concurso * tabela[TAMANHO_TABELA];
} Tabela;

unsigned int hash(int numero);
Tabela * criar_tabela();
void inserir_concurso(Tabela * tabela, Concurso concurso);
Concurso * buscar_concurso(Tabela * tabela, int numero);
void remover_concurso(Tabela * tabela, int numero);

#endif