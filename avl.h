// TAD AVL
// Atributos
#define MAX_NAME 100

typedef struct info_avl
{
    char chave[MAX_NAME + 1];
    int calorias;
} INFO_AVL;

struct nodo_abp_avl
{
    INFO_AVL info;
    int fator;
    struct nodo_abp_avl *esq;
    struct nodo_abp_avl *dir;
};

typedef struct nodo_abp_avl NODO_ABP_AVL;


// Opera��es

// Fun��o que inicializa uma AVL
NODO_ABP_AVL* Inicializa_AVL(void);

// Fun��o que realiza uma rota��o simples a direita em uma AVL
NODO_ABP_AVL* rotacao_direita(NODO_ABP_AVL* p);

// Fun��o que realiza uma rota��o simples a esquerda em uma AVL
NODO_ABP_AVL* rotacao_esquerda(NODO_ABP_AVL *p);

// Fun��o que realiza uma rota��o dupla a direita em uma AVL
NODO_ABP_AVL* rotacao_dupla_direita(NODO_ABP_AVL *p);

// Fun��o que realiza uma rota��o dupla a esquerda em uma AVL
NODO_ABP_AVL* rotacao_dupla_esquerda(NODO_ABP_AVL *p);

// Fun��o que realiza o caso 1 de uma inser��o em uma AVL
NODO_ABP_AVL* Caso1(NODO_ABP_AVL *a, int *ok);

// Fun��o que realiza o caso 2 de uma inser��o em uma AVL
NODO_ABP_AVL* Caso2(NODO_ABP_AVL *a, int *ok);

// Fun��o que adiciona um elemento em ordem lexicogr�fica em uma AVL
NODO_ABP_AVL* InsereAVL(NODO_ABP_AVL *a, INFO_AVL x, int *ok);

// Fun��o que consulta as calorias de um elemento em uma AVL
NODO_ABP_AVL* Consulta_AVL(NODO_ABP_AVL *a, char *chave);

// Fun��o que calcula a altura de uma AVL
int Altura_AVL(NODO_ABP_AVL *raiz);

// Fun��o que calcula o n�mero de nodos em uma AVL
int Numero_nodos_AVL(NODO_ABP_AVL *raiz);
