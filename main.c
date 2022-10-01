#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abp.h"
#include "avl.h"

#define MAX_BUFFER 256

int comp_ABP = 0;
int comp_AVL = 0;
int rotacao_AVL = 0;

int main(int argc, char *argv[])
{
    FILE *arq_tabela, *arq_consumo, *arq_saida; // arquivos usados no programa
    NODO_ABP *ABP; // estrutura de dados ABP
    NODO_ABP *Consultado_ABP; // variavel tempor�ria para a consulta em uma ABP
    NODO_ABP_AVL *AVL; // estrutura de dados AVL
    NODO_ABP_AVL *Consultado_AVL; // variavel tempor�ria para a consulta em uma AVL
    INFO_AVL temp_info; // variavel tempor�ria para a inser��o em uma AVL
    char linha[MAX_ENTRY + 1];
    char *nome;
    char *calorias_str, *quantidade_str;
    int calorias = 0, quantidade = 0;
    int soma_calorias_ABP = 0;
    int soma_calorias_AVL = 0;
    int altura_ABP = 0;
    int altura_AVL = 0;
    int numero_nodos_ABP = 0;
    int numero_nodos_AVL = 0;
    int ok;
    int len;
    char buffer[MAX_BUFFER];

    // Teste se a chamada da main foi correta
    if(argc != 4)
    {
        printf("Numero incorreto de parametros.\nPara chamar o programa digite: main <arq_tabela_calorias> <arq_consumo_diario> <arq_saida>");
        return 1;
    }

    // Abertura do arquivo com a tabela de calorias
    if(!(arq_tabela = fopen(argv[1], "r")))
    {
        printf("Erro ao abrir a tabela de calorias\n");
        return 1;
    }

    // Abertura do arquivo com o consumo di�rio
    if(!(arq_consumo = fopen(argv[2], "r")))
    {
        printf("Erro ao abrir o consumo diario\n");
        return 1;
    }

    // Abertura do arquivo de sa�da
    if(!(arq_saida = fopen(argv[3], "w")))
    {
        printf("Erro ao abrir o arquivo de saida\n");
        return 1;
    }

    ABP = Inicializa_ABP(); // Inicializa ABP
    AVL = Inicializa_AVL(); // Inicializa AVL

    // Escreve no arquivo de sa�da
    fputs("Calorias calculadas para ", arq_saida);
    fputs(argv[2], arq_saida);
    fputs(" usando a tabela ", arq_saida);
    fputs(argv[1], arq_saida);
    fputs(".\n\n", arq_saida);

    // Leitura da tabela e inser��es na ABP e na AVL
    while(fgets(linha, MAX_ENTRY + 1, arq_tabela))
    {
        nome = strtok_r(linha, ",", &calorias_str);
        nome = strlwr(nome);
        calorias = atoi(calorias_str);

        ABP = Insere_ABP(ABP, nome, calorias); // Insere linha atual na ABP

        strcpy(temp_info.chave, nome);
        temp_info.calorias = calorias;
        AVL = InsereAVL(AVL, temp_info, &ok); // Insere linha atual na AVL
    }

    // Fechamento do arquivo com a tabela de calorias
    fclose(arq_tabela);

    altura_ABP = Altura_ABP(ABP); // Calcula altura da ABP
    altura_AVL = Altura_AVL(AVL); // Calcula a altura da AVL

    numero_nodos_ABP = Numero_nodos_ABP(ABP); // Calcula o n�mero de nodos da ABP
    numero_nodos_AVL = Numero_nodos_AVL(AVL); // Calcula o n�mero de nodos da AVL

    // Consulta ao arquivo com o consumo di�rio e c�lculo das calorias ingeridas
    while(fgets(linha, MAX_ENTRY + 1, arq_consumo))
    {
        nome = strtok_r(linha, ",", &quantidade_str);
        nome = strlwr(nome);
        quantidade = atoi(quantidade_str);

        // Consulta item atual
        Consultado_ABP = Consulta_ABP(ABP, nome);
        Consultado_AVL = Consulta_AVL(AVL, nome);

        // Soma calorias
        soma_calorias_ABP += (Consultado_ABP->info.calorias * quantidade / 100);
        soma_calorias_AVL += (Consultado_AVL->info.calorias * quantidade / 100);

        // Retira "\n" de quantidade_str
        len = strlen(quantidade_str);
        quantidade_str[len-1] = 0;

        // Escreve no arquivo de sa�da
        sprintf(buffer, "%sg de %s (%d calorias por 100g) = %d calorias\n\n", quantidade_str, nome, Consultado_ABP->info.calorias, (Consultado_ABP->info.calorias * quantidade / 100));
        fputs(buffer, arq_saida);
    }

    // Fechamento do arquivo com o consumo di�rio
    fclose(arq_consumo);

    // Escreve no arquivo de sa�da
    sprintf(buffer, "Total de %d calorias consumidas no dia.\n\n======== ESTAT�STICAS ABP ============\n\n", soma_calorias_ABP);
    fputs(buffer, arq_saida);
    sprintf(buffer, "Numero de nodos: %d\nAltura: %d\nRotacoes: 0\nComparacoes: %d\n\n", numero_nodos_ABP, altura_ABP, comp_ABP);
    fputs(buffer, arq_saida);
    sprintf(buffer, "\n======== ESTAT�STICAS AVL ============\n\nNumero de nodos: %d\nAltura: %d\nRotacoes: %d\nComparacoes: %d\n\n", numero_nodos_AVL, altura_AVL, rotacao_AVL, comp_AVL);
    fputs(buffer, arq_saida);

    // Fechamento do arquivo de sa�da
    fclose(arq_saida);

    return 0;
}
