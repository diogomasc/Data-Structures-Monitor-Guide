#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Programa para cálculo de norma e soma de vetores
 *
 * Este programa demonstra:
 * - Alocação dinâmica de memória
 * - Cálculos matemáticos
 * - Manipulação de múltiplos vetores
 */

// Função para calcular a norma de um vetor
float calcular_norma(float vetor[], int tamanho)
{
    float soma = 0;
    for (int i = 0; i < tamanho; i++)
    {
        soma += vetor[i] * vetor[i];
    }
    return sqrt(soma);
}

// Função para calcular o vetor soma
void calcular_vetor_soma(float vetor1[], float vetor2[], float vetor3[], float resultado[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        resultado[i] = vetor1[i] + vetor2[i] + vetor3[i];
    }
}

// Função para imprimir um vetor
void imprimir_vetor(float vetor[], int tamanho)
{
    printf("[ ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%.2f ", vetor[i]);
    }
    printf("]\n");
}

int main()
{
    int N;
    float *vetor1, *vetor2, *vetor3, *vetor_soma;
    float norma1, norma2, norma3;

    // Leitura do tamanho dos vetores
    printf("Digite o tamanho dos vetores (N): ");
    scanf("%d", &N);

    if (N <= 0)
    {
        printf("Tamanho invalido!\n");
        return 1;
    }

    // Alocação dos vetores
    vetor1 = (float *)malloc(N * sizeof(float));
    vetor2 = (float *)malloc(N * sizeof(float));
    vetor3 = (float *)malloc(N * sizeof(float));
    vetor_soma = (float *)malloc(N * sizeof(float));

    if (!vetor1 || !vetor2 || !vetor3 || !vetor_soma)
    {
        printf("Erro na alocacao de memoria!\n");
        return 1;
    }

    // Leitura dos vetores
    printf("\nDigite os elementos do primeiro vetor:\n");
    for (int i = 0; i < N; i++)
    {
        printf("Elemento %d: ", i + 1);
        scanf("%f", &vetor1[i]);
    }

    printf("\nDigite os elementos do segundo vetor:\n");
    for (int i = 0; i < N; i++)
    {
        printf("Elemento %d: ", i + 1);
        scanf("%f", &vetor2[i]);
    }

    printf("\nDigite os elementos do terceiro vetor:\n");
    for (int i = 0; i < N; i++)
    {
        printf("Elemento %d: ", i + 1);
        scanf("%f", &vetor3[i]);
    }

    // Calculando as normas
    norma1 = calcular_norma(vetor1, N);
    norma2 = calcular_norma(vetor2, N);
    norma3 = calcular_norma(vetor3, N);

    // Calculando o vetor soma
    calcular_vetor_soma(vetor1, vetor2, vetor3, vetor_soma, N);

    // Mostrando resultados
    printf("\n=== RESULTADOS ===\n");
    printf("Norma do primeiro vetor: %.2f\n", norma1);
    printf("Norma do segundo vetor: %.2f\n", norma2);
    printf("Norma do terceiro vetor: %.2f\n", norma3);

    // Identificando o vetor com maior norma
    printf("\nVetor com maior norma: ");
    if (norma1 >= norma2 && norma1 >= norma3)
    {
        printf("Primeiro vetor (%.2f)\n", norma1);
    }
    else if (norma2 >= norma1 && norma2 >= norma3)
    {
        printf("Segundo vetor (%.2f)\n", norma2);
    }
    else
    {
        printf("Terceiro vetor (%.2f)\n", norma3);
    }

    printf("\nVetor soma: ");
    imprimir_vetor(vetor_soma, N);

    // Liberando memória
    free(vetor1);
    free(vetor2);
    free(vetor3);
    free(vetor_soma);

    return 0;
}
