#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abp.h"
#include "avl.h"

int comp_ABP = 0;

int main(int argc, char *argv[])
{
    FILE *arq_tabela, *arq_consumo, *arq_saida; // arquivos usados no programa
    NODO_ABP *ABP; // estrutura de dados ABP
    NODO_ABP *Consultado_ABP; // variavel temporária para a consulta em uma ABP
    NODO_ABP_AVL *AVL; // estrutura de dados AVL
    NODO_ABP_AVL *Consultado_AVL; // variavel temporária para a consulta em uma AVL
    char linha[MAX_ENTRY + 1];
    char *nome;
    char *calorias_str, *quantidade_str;
    int calorias = 0, quantidade = 0;
    int soma_calorias_ABP = 0;
    int soma_calorias_AVL = 0;

    if(argc != 4)
    {
        printf("Numero incorreto de parametros.\nPara chamar o programa digite: main <arq_tabela_calorias> <arq_consumo_diario> <arq_saida>");
        return 1;
    }

    if(!(arq_tabela = fopen(argv[1], "r")))
    {
        printf("Erro ao abrir a tabela de calorias\n");
        return 1;
    }

    if(!(arq_consumo = fopen(argv[2], "r")))
    {
        printf("Erro ao abrir o consumo diario\n");
        return 1;
    }

    if(!(arq_saida = fopen(argv[3], "w")))
    {
        printf("Erro ao abrir o arquivo de saida\n");
        return 1;
    }

    ABP = Inicializa_ABP(); // Inicializa ABP
    AVL = Inicializa_AVL(); // Inicializa AVL

    while(fgets(linha, MAX_ENTRY + 1, arq_tabela))
    {
        nome = strtok_r(linha, ",", &calorias_str);
        nome = strlwr(nome);
        calorias = atoi(calorias_str);

        ABP = Insere_ABP(ABP, nome, calorias); // Insere linha atual na ABP
        //AVL = Insere_AVL(AVL, nome, calorias); // Insere linha atual na AVL

        printf("Nome = %s\nCalorias_str = %s\nCalorias = %d\n", nome, calorias_str, calorias);
    }

    fclose(arq_tabela);

    while(fgets(linha, MAX_ENTRY + 1, arq_consumo))
    {
        nome = strtok_r(linha, ",", &quantidade_str);
        nome = strlwr(nome);
        quantidade = atoi(quantidade_str);

        Consultado_ABP = Consulta_ABP(ABP, nome);
        //Consultado_AVL = Consulta_AVL(AVL, nome);

        soma_calorias_ABP += (Consultado_ABP->info.calorias * quantidade / 100);
        //soma_calorias_AVL += (Consultado_AVL->info.calorias/100);
    }

    fclose(arq_consumo);

    printf("O total de calorias consumidas foi de: %d\n", soma_calorias_ABP);
    printf("O total de comparacoes na ABP foi de: %d\n", comp_ABP);

    return 0;
}
