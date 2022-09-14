// TAD ABP
// Atributos

#define MAX_NAME 100
#define MAX_ENTRY 150

typedef struct info
{
    char chave[MAX_NAME + 1];
    int calorias;
} INFO;

struct nodo_abp
{
    INFO info;
    struct nodo_abp *esq;
    struct nodo_abp *dir;
};

typedef struct nodo_abp NODO_ABP;


// Opera��es

// Fun��o que inicializa uma ABP
NODO_ABP* Inicializa_ABP(void);

// Fun��o que adiciona um elemento em ordem lexicogr�fica em uma ABP
NODO_ABP* Insere_ABP(NODO_ABP *raiz, char *nome, int calorias);

// Fun��o que consulta as calorias de um elemento em uma ABP
NODO_ABP* Consulta_ABP(NODO_ABP *a, char *chave);
