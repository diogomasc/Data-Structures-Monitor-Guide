#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Programa que implementa busca em vetor e lista encadeada
 *
 * Este programa demonstra:
 * - Implementação com vetor
 * - Implementação com lista encadeada
 * - Busca de elementos
 * - Alocação dinâmica de memória
 */

#define TAMANHO 10

// Estrutura para nó da lista encadeada
typedef struct No
{
    int valor;
    struct No *proximo;
} No;

// Função para buscar em vetor
int busca_vetor(int vetor[], int tamanho, int busca)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] == busca)
        {
            return 1; // Encontrou
        }
    }
    return 0; // Não encontrou
}

// Função para inserir na lista encadeada
No *inserir_lista(No *inicio, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if (inicio == NULL)
    {
        return novo;
    }

    No *atual = inicio;
    while (atual->proximo != NULL)
    {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    return inicio;
}

// Função para buscar na lista encadeada
int busca_lista(No *inicio, int busca)
{
    No *atual = inicio;
    while (atual != NULL)
    {
        if (atual->valor == busca)
        {
            return 1; // Encontrou
        }
        atual = atual->proximo;
    }
    return 0; // Não encontrou
}

// Função para liberar a memória da lista
void liberar_lista(No *inicio)
{
    No *atual = inicio;
    while (atual != NULL)
    {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main()
{
    int vetor[TAMANHO];
    No *inicio_lista = NULL;
    int numero_busca;

    // Leitura dos números
    printf("Digite %d numeros inteiros:\n", TAMANHO);
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
        // Inserindo o mesmo número na lista encadeada
        inicio_lista = inserir_lista(inicio_lista, vetor[i]);
    }

    // Número a ser buscado
    printf("\nDigite um numero para buscar: ");
    scanf("%d", &numero_busca);

    // Busca no vetor
    printf("\nResultado da busca no vetor: ");
    if (busca_vetor(vetor, TAMANHO, numero_busca))
    {
        printf("Numero encontrado!\n");
    }
    else
    {
        printf("Numero nao encontrado!\n");
    }

    // Busca na lista encadeada
    printf("Resultado da busca na lista encadeada: ");
    if (busca_lista(inicio_lista, numero_busca))
    {
        printf("Numero encontrado!\n");
    }
    else
    {
        printf("Numero nao encontrado!\n");
    }

    // Liberando a memória alocada
    liberar_lista(inicio_lista);

    return 0;
}
