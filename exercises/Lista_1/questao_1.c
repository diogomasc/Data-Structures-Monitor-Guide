#include <stdio.h>

/**
 * @brief Programa que recebe 10 números inteiros e os mostra em uma única linha
 *
 * Este programa demonstra:
 * - Uso de vetores
 * - Entrada de dados com validação
 * - Formatação de saída
 */

#define TAMANHO 10

int main()
{
    int numeros[TAMANHO];

    // Leitura dos números
    printf("Digite %d numeros inteiros:\n", TAMANHO);
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Mostrando os números em uma linha
    printf("\nNumeros digitados: ");
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d", numeros[i]);
        // Adiciona espaço entre os números, exceto após o último
        if (i < TAMANHO - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
