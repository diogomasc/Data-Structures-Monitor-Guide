#include <stdio.h>

/**
 * @brief Programa que realiza análise estatística de números reais
 *
 * Este programa demonstra:
 * - Modularização de código
 * - Cálculos estatísticos básicos
 * - Manipulação de números reais
 */

#define TAMANHO 10

// Função para calcular a média dos elementos
float calcular_media(float vetor[], int tamanho)
{
    float soma = 0;
    for (int i = 0; i < tamanho; i++)
    {
        soma += vetor[i];
    }
    return soma / tamanho;
}

// Função para encontrar o maior elemento
float encontrar_maior(float vetor[], int tamanho)
{
    float maior = vetor[0];
    for (int i = 1; i < tamanho; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }
    }
    return maior;
}

// Função para encontrar o menor elemento
float encontrar_menor(float vetor[], int tamanho)
{
    float menor = vetor[0];
    for (int i = 1; i < tamanho; i++)
    {
        if (vetor[i] < menor)
        {
            menor = vetor[i];
        }
    }
    return menor;
}

// Função para contar elementos positivos e negativos
void contar_positivos_negativos(float vetor[], int tamanho, int *positivos, int *negativos)
{
    *positivos = 0;
    *negativos = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] > 0)
        {
            (*positivos)++;
        }
        else if (vetor[i] < 0)
        {
            (*negativos)++;
        }
    }
}

int main()
{
    float numeros[TAMANHO];
    int positivos, negativos;

    // Leitura dos números
    printf("Digite %d numeros reais:\n", TAMANHO);
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%f", &numeros[i]);
    }

    // Calculando e mostrando resultados
    printf("\nResultados da analise:\n");
    printf("Media: %.2f\n", calcular_media(numeros, TAMANHO));
    printf("Maior elemento: %.2f\n", encontrar_maior(numeros, TAMANHO));
    printf("Menor elemento: %.2f\n", encontrar_menor(numeros, TAMANHO));

    contar_positivos_negativos(numeros, TAMANHO, &positivos, &negativos);
    printf("Quantidade de elementos positivos: %d\n", positivos);
    printf("Quantidade de elementos negativos: %d\n", negativos);

    return 0;
}
