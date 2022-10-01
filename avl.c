#include <string.h>
#include <stdlib.h>
#include "avl.h"

int comp_AVL;
int rotacao_AVL;

NODO_ABP_AVL* Inicializa_AVL(void)
{
    return NULL;
}

NODO_ABP_AVL* rotacao_direita(NODO_ABP_AVL* p)
{
    NODO_ABP_AVL *u;
    u = p->esq;
    p->esq = u->dir;
    u->dir = p;
    p->fator = 0;
    p = u;
    rotacao_AVL++;
    return p;
}

NODO_ABP_AVL* rotacao_esquerda(NODO_ABP_AVL *p)
{
    NODO_ABP_AVL *z;
    z = p->dir;
    p->dir = z->esq;
    z->esq = p;
    p->fator = 0;
    p = z;
    rotacao_AVL++;
    return p;
}

NODO_ABP_AVL* rotacao_dupla_direita(NODO_ABP_AVL *p)
{
    NODO_ABP_AVL *u, *v;
    u = p->esq;
    v = u->dir;
    u->dir = v->esq;
    v->esq = u;
    p->esq = v->dir;
    v->dir = p;
    if (v->fator == 1) p->fator = -1;
    else p->fator = 0;
    if (v->fator == -1) u->fator = 1;
    else u->fator = 0;
    p = v;
    rotacao_AVL = rotacao_AVL + 2;
    return p;
}

NODO_ABP_AVL* rotacao_dupla_esquerda(NODO_ABP_AVL *p)
{
    NODO_ABP_AVL *z, *y;
    z = p->dir;
    y = z->esq;
    z->esq = y->dir;
    y->dir = z;
    p->dir = y->esq;
    y->esq = p;
    if (y->fator == -1) p->fator = 1;
    else p->fator = 0;
    if (y->fator == 1) z->fator = -1;
    else z->fator = 0;
    p = y;
    rotacao_AVL = rotacao_AVL + 2;
    return p;
}

NODO_ABP_AVL* Caso1(NODO_ABP_AVL *a, int *ok)
{
    NODO_ABP_AVL *z;
    z = a->esq;
    if (z->fator == 1)
        a = rotacao_direita(a);
    else
        a = rotacao_dupla_direita(a);
    a->fator = 0;
    *ok = 0;
    return a;
}

NODO_ABP_AVL* Caso2(NODO_ABP_AVL *a, int *ok)
{
    NODO_ABP_AVL *z;
    z = a->dir;
    if (z->fator == -1)
        a = rotacao_esquerda(a);
    else
        a = rotacao_dupla_esquerda(a);
    a->fator = 0;
    *ok = 0;
    return a;
}

NODO_ABP_AVL* InsereAVL(NODO_ABP_AVL *a, INFO_AVL x, int *ok)
{
    /* Insere nodo em uma árvore AVL, onde A representa a raiz da árvore,
    x, a chave a ser inserida e h a altura da árvore */
    if (a == NULL)
    {
        a = (NODO_ABP_AVL*) malloc(sizeof(NODO_ABP_AVL));
        a->info = x;
        a->esq = NULL;
        a->dir = NULL;
        a->fator = 0;
        *ok = 1;
    }
    else if (strcmp(a->info.chave, x.chave) > 0)
    {
        a->esq = InsereAVL(a->esq, x, ok);
        if (*ok)
        {
            switch (a->fator)
            {
            case -1:
                a->fator = 0;
                *ok = 0;
                break;
            case 0:
                a->fator = 1;
                break;
            case 1:
                a = Caso1(a,ok);
                break;
            }
        }
    }
    else
    {
        a->dir = InsereAVL(a->dir, x, ok);
        if (*ok)
        {
            switch (a->fator)
            {
            case 1:
                a->fator = 0;
                *ok = 0;
                break;
            case 0:
                a->fator = -1;
                break;
            case -1:
                a = Caso2(a, ok);
                break;
            }
        }
    }
    return a;
}

NODO_ABP_AVL* Consulta_AVL(NODO_ABP_AVL *a, char *chave)
{
    while (a!=NULL)
    {
        comp_AVL++;
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

int Altura_AVL(NODO_ABP_AVL *raiz)
{
    if(!raiz)
        return 0;

    //if(!(raiz->esq) && !(raiz->dir))
        //return 1;

    if(Altura_AVL(raiz->esq) >= Altura_AVL(raiz->dir))
        return Altura_AVL(raiz->esq) + 1;

    return Altura_AVL(raiz->dir) + 1;
}

int Numero_nodos_AVL(NODO_ABP_AVL *raiz)
{
    if(!raiz)
        return 0;

    return 1 + Numero_nodos_AVL(raiz->esq) + Numero_nodos_AVL(raiz->dir);
}
