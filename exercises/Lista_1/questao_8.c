#include <stdio.h>

/**
 * @brief Programa que calcula o fatorial de forma iterativa e recursiva
 *
 * Este programa demonstra:
 * - Implementação iterativa vs recursiva
 * - Cálculo de fatorial
 * - Formatação de saída
 */

// Função para calcular fatorial de forma iterativa
unsigned long long fatorial_iterativo(int n)
{
    unsigned long long resultado = 1;
    for (int i = n; i >= 1; i--)
    {
        resultado *= i;
    }
    return resultado;
}

// Função para calcular fatorial de forma recursiva
unsigned long long fatorial_recursivo(int n)
{
    if (n <= 1)
        return 1;
    return n * fatorial_recursivo(n - 1);
}

// Função para imprimir a sequência do fatorial
void imprimir_sequencia_fatorial(int n)
{
    printf("%d! = ", n);
    for (int i = n; i >= 1; i--)
    {
        printf("%d", i);
        if (i > 1)
            printf("*");
    }
}

int main()
{
    int n;
    char metodo;

    do
    {
        printf("\n=== CALCULO DE FATORIAL ===\n");
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &n);

        if (n < 0)
        {
            printf("Por favor, digite um numero positivo.\n");
            continue;
        }

        printf("\nEscolha o metodo (I - Iterativo, R - Recursivo): ");
        scanf(" %c", &metodo);

        unsigned long long resultado;
        if (metodo == 'I' || metodo == 'i')
        {
            resultado = fatorial_iterativo(n);
            printf("\nMetodo Iterativo:\n");
        }
        else if (metodo == 'R' || metodo == 'r')
        {
            resultado = fatorial_recursivo(n);
            printf("\nMetodo Recursivo:\n");
        }
        else
        {
            printf("Metodo invalido!\n");
            continue;
        }

        imprimir_sequencia_fatorial(n);
        printf(" = %llu\n", resultado);

        printf("\nDeseja calcular outro fatorial? (S/N): ");
        scanf(" %c", &metodo);

    } while (metodo == 'S' || metodo == 's');

    return 0;
}
