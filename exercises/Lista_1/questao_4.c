#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Programa para cálculo de reajuste de indenização de plano de saúde
 *
 * Este programa demonstra:
 * - Alocação dinâmica de memória
 * - Manipulação de strings
 * - Vetores paralelos
 * - Cálculos percentuais
 */

#define MAX_NOME 100

// Função para calcular o reajuste baseado na idade
float calcular_reajuste(float valor_base, int idade)
{
    if (idade <= 12)
    {
        return valor_base * 1.30; // 30% de aumento
    }
    else if (idade <= 49)
    {
        return valor_base * 1.10; // 10% de aumento
    }
    else if (idade <= 65)
    {
        return valor_base * 1.15; // 15% de aumento
    }
    else
    {
        return valor_base * 1.35; // 35% de aumento
    }
}

int main()
{
    char **nomes = NULL;
    int *idades = NULL;
    float *indenizacoes = NULL;
    int quantidade = 0;
    float valor_base;
    char continuar;

    printf("Digite o valor base da indenizacao: ");
    scanf("%f", &valor_base);
    getchar(); // Limpa o buffer

    do
    {
        // Realocando memória para mais um paciente
        quantidade++;
        nomes = (char **)realloc(nomes, quantidade * sizeof(char *));
        idades = (int *)realloc(idades, quantidade * sizeof(int));
        indenizacoes = (float *)realloc(indenizacoes, quantidade * sizeof(float));

        if (!nomes || !idades || !indenizacoes)
        {
            printf("Erro na alocacao de memoria!\n");
            return 1;
        }

        // Alocando espaço para o nome
        nomes[quantidade - 1] = (char *)malloc(MAX_NOME * sizeof(char));
        if (!nomes[quantidade - 1])
        {
            printf("Erro na alocacao de memoria!\n");
            return 1;
        }

        // Lendo dados do paciente
        printf("\nPaciente %d:\n", quantidade);
        printf("Nome completo: ");
        fgets(nomes[quantidade - 1], MAX_NOME, stdin);
        nomes[quantidade - 1][strcspn(nomes[quantidade - 1], "\n")] = 0; // Remove o \n

        printf("Idade: ");
        scanf("%d", &idades[quantidade - 1]);
        getchar(); // Limpa o buffer

        // Calculando indenização
        indenizacoes[quantidade - 1] = calcular_reajuste(valor_base, idades[quantidade - 1]);

        printf("\nDeseja cadastrar outro paciente? (S/N): ");
        scanf("%c", &continuar);
        getchar(); // Limpa o buffer

    } while (continuar == 'S' || continuar == 's');

    // Mostrando resultados
    printf("\n=== RELATORIO DE PACIENTES ===\n");
    for (int i = 0; i < quantidade; i++)
    {
        printf("\nPaciente: %s\n", nomes[i]);
        printf("Idade: %d\n", idades[i]);
        printf("Indenizacao reajustada: R$ %.2f\n", indenizacoes[i]);
    }

    // Liberando memória
    for (int i = 0; i < quantidade; i++)
    {
        free(nomes[i]);
    }
    free(nomes);
    free(idades);
    free(indenizacoes);

    return 0;
}
