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


// Operações

// Função que inicializa uma AVL
NODO_ABP_AVL* Inicializa_AVL(void);

// Função que realiza uma rotação simples a direita em uma AVL
NODO_ABP_AVL* rotacao_direita(NODO_ABP_AVL* p);

// Função que realiza uma rotação simples a esquerda em uma AVL
NODO_ABP_AVL* rotacao_esquerda(NODO_ABP_AVL *p);

// Função que realiza uma rotação dupla a direita em uma AVL
NODO_ABP_AVL* rotacao_dupla_direita(NODO_ABP_AVL *p);

// Função que realiza uma rotação dupla a esquerda em uma AVL
NODO_ABP_AVL* rotacao_dupla_esquerda(NODO_ABP_AVL *p);

// Função que realiza o caso 1 de uma inserção em uma AVL
NODO_ABP_AVL* Caso1(NODO_ABP_AVL *a, int *ok);

// Função que realiza o caso 2 de uma inserção em uma AVL
NODO_ABP_AVL* Caso2(NODO_ABP_AVL *a, int *ok);

// Função que adiciona um elemento em ordem lexicográfica em uma AVL
NODO_ABP_AVL* InsereAVL(NODO_ABP_AVL *a, INFO_AVL x, int *ok);

// Função que consulta as calorias de um elemento em uma AVL
NODO_ABP_AVL* Consulta_AVL(NODO_ABP_AVL *a, char *chave);

// Função que calcula a altura de uma AVL
int Altura_AVL(NODO_ABP_AVL *raiz);

// Função que calcula o número de nodos em uma AVL
int Numero_nodos_AVL(NODO_ABP_AVL *raiz);
