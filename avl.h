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

// Fun��o que adiciona um elemento em ordem lexicogr�fica em uma AVL
NODO_ABP_AVL* Insere_AVL(NODO_ABP_AVL *raiz, char *nome, int calorias);

// Fun��o que consulta as calorias de um elemento em uma AVL
NODO_ABP_AVL* Consulta_AVL(NODO_ABP_AVL *a, char *chave);
