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

// Função que adiciona um elemento em ordem lexicográfica em uma AVL
NODO_ABP_AVL* Insere_AVL(NODO_ABP_AVL *raiz, char *nome, int calorias);

// Função que consulta as calorias de um elemento em uma AVL
NODO_ABP_AVL* Consulta_AVL(NODO_ABP_AVL *a, char *chave);
