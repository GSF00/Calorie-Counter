#include <string.h>
#include <stdlib.h>
#include "avl.h"

int comp_AVL = 0;

NODO_ABP_AVL* Inicializa_AVL(void)
{
    return NULL;
}

NODO_ABP_AVL* Insere_AVL(NODO_ABP_AVL *raiz, char *nome, int calorias)
{

}

NODO_ABP_AVL* Consulta_AVL(NODO_ABP_AVL *a, char *chave)
{
    while (a!=NULL)
    {
        comp_AVL++;
        if (!strcmp(a->info.chave, chave))
        {
            comp_AVL++;
            return a;
        }
        else
        {
            comp_AVL++;
            if (strcmp(a->info.chave, chave) > 0)
                a = a->esq;
            else
                a = a->dir;
        }
    }
    return NULL;
}
