#include <stdio.h>

/**
 * @brief Programa que gera a série de Fibonacci de forma recursiva
 *
 * Este programa demonstra:
 * - Implementação recursiva da série de Fibonacci
 * - Formatação de saída em série
 */

// Função recursiva para calcular o n-ésimo termo de Fibonacci
unsigned long long fibonacci(int n)
{
    if (n <= 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Função para imprimir a série de Fibonacci
void imprimir_serie_fibonacci(int n)
{
    printf("Serie de Fibonacci com %d termos:\n", n);
    for (int i = 1; i <= n; i++)
    {
        printf("%llu", fibonacci(i));
        if (i < n)
            printf(", ");
    }
    printf("\n");
}

int main()
{
    int n;
    char continuar;

    printf("\n=== SERIE DE FIBONACCI ===\n");
    printf("Digite a quantidade de termos desejada: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Por favor, digite um numero positivo.\n");
        return 1;
    }

    // Para números muito grandes, alertar sobre o tempo de processamento
    if (n > 40)
    {
        printf("\nAVISO: Numeros muito grandes podem demorar para processar.\n");
        printf("Deseja continuar? (S/N): ");
        scanf(" %c", &continuar);
        if (continuar != 'S' && continuar != 's')
            return 1;
    }

    imprimir_serie_fibonacci(n);

    return 0;
}
