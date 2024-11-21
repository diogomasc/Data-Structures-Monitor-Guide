#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Programa que remove elementos menores ou iguais a zero de um vetor
 *
 * Este programa demonstra:
 * - Manipulação de vetores
 * - Alocação dinâmica de memória
 * - Remoção de elementos
 */

// Função para remover elementos menores ou iguais a zero
// Retorna o novo tamanho do vetor
int remover_nao_positivos(int vetor[], int tamanho)
{
    int novo_tamanho = 0;

    // Move apenas os elementos positivos para o início do vetor
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] > 0)
        {
            vetor[novo_tamanho] = vetor[i];
            novo_tamanho++;
        }
    }

    return novo_tamanho;
}

// Função para imprimir vetor
void imprimir_vetor(int vetor[], int tamanho)
{
    printf("[ ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d", vetor[i]);
        if (i < tamanho - 1)
            printf(", ");
    }
    printf(" ]\n");
}

int main()
{
    int *vetor = NULL;
    int tamanho;
    char continuar;

    do
    {
        printf("\n=== REMOCAO DE ELEMENTOS NAO POSITIVOS ===\n");
        printf("Digite o tamanho do vetor: ");
        scanf("%d", &tamanho);

        if (tamanho <= 0)
        {
            printf("Tamanho invalido!\n");
            continue;
        }

        // Aloca memória para o vetor
        vetor = (int *)malloc(tamanho * sizeof(int));
        if (!vetor)
        {
            printf("Erro na alocacao de memoria!\n");
            return 1;
        }

        // Lê os elementos do vetor
        printf("\nDigite os elementos do vetor:\n");
        for (int i = 0; i < tamanho; i++)
        {
            printf("Elemento %d: ", i + 1);
            scanf("%d", &vetor[i]);
        }

        // Mostra o vetor original
        printf("\nVetor original:\n");
        imprimir_vetor(vetor, tamanho);

        // Remove elementos não positivos
        int novo_tamanho = remover_nao_positivos(vetor, tamanho);

        // Mostra o vetor resultante
        printf("\nVetor após remover elementos não positivos:\n");
        imprimir_vetor(vetor, novo_tamanho);

        // Libera a memória
        free(vetor);
        vetor = NULL;

        printf("\nDeseja processar outro vetor? (S/N): ");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    return 0;
}
