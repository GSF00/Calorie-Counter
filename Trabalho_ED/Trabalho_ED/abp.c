#include <string.h>
#include <stdlib.h>
#include "abp.h"

int comp_ABP;

NODO_ABP* Inicializa_ABP(void)
{
    return NULL;
}

NODO_ABP* Insere_ABP(NODO_ABP *raiz, char nome[MAX_NAME + 1], int calorias)
{
    if (raiz == NULL)
    {
        raiz = (NODO_ABP*) malloc(sizeof(NODO_ABP));
        strcpy(raiz->info.chave, nome);

        //raiz->info.chave = nome;
        raiz->info.calorias = calorias;
        raiz->esq = NULL;
        raiz->dir = NULL;
    }
    else if (strcmp(raiz->info.chave, nome) > 0)
        raiz->esq = Insere_ABP(raiz->esq, nome, calorias);
    else if (strcmp(raiz->info.chave, nome) < 0)
        raiz->dir = Insere_ABP(raiz->dir, nome, calorias);
    return raiz;
}

NODO_ABP* Consulta_ABP(NODO_ABP *a, char *chave)
{
    while (a!=NULL)
    {
        comp_ABP++;
        if (!strcmp(a->info.chave, chave))
        {
            return a;
        }
        else
        {
            if (strcmp(a->info.chave, chave) > 0)
                a = a->esq;
            else
                a = a->dir;
        }
    }
    return NULL;
}

int Altura_ABP(NODO_ABP *raiz)
{
    int esq, dir;

    if(!raiz)
        return 0;

    esq = Altura_ABP(raiz->esq);
    dir = Altura_ABP(raiz->dir);

    if(esq >= dir)
        return esq + 1;

    return dir + 1;
/*
    if(Altura_ABP(raiz->esq) >= Altura_ABP(raiz->dir))
        return Altura_ABP(raiz->esq) + 1;

    return Altura_ABP(raiz->dir) + 1;
*/
}

int Numero_nodos_ABP(NODO_ABP *raiz)
{
    if(!raiz)
        return 0;

    return 1 + Numero_nodos_ABP(raiz->esq) + Numero_nodos_ABP(raiz->dir);
}
