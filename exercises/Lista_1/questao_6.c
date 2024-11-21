#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Programa de cadastro de clientes usando lista encadeada
 *
 * Este programa demonstra:
 * - Implementação de lista encadeada
 * - Alocação dinâmica de memória
 * - Manipulação de strings
 * - Gerenciamento de dados de clientes
 */

#define MAX_NOME 100
#define MAX_RG 20
#define MAX_CPF 15
#define MAX_TELEFONE 20

// Estrutura para armazenar os dados do cliente
typedef struct Cliente
{
    char nome[MAX_NOME];
    char rg[MAX_RG];
    char cpf[MAX_CPF];
    char telefone[MAX_TELEFONE];
    struct Cliente *proximo;
} Cliente;

// Função para criar um novo nó de cliente
Cliente *criar_cliente()
{
    Cliente *novo = (Cliente *)malloc(sizeof(Cliente));
    if (!novo)
    {
        printf("Erro na alocacao de memoria!\n");
        exit(1);
    }
    novo->proximo = NULL;
    return novo;
}

// Função para inserir cliente na lista
Cliente *inserir_cliente(Cliente *lista)
{
    Cliente *novo = criar_cliente();

    // Limpa o buffer
    getchar();

    // Lê os dados do cliente
    printf("\nNome completo: ");
    fgets(novo->nome, MAX_NOME, stdin);
    novo->nome[strcspn(novo->nome, "\n")] = 0;

    printf("RG: ");
    fgets(novo->rg, MAX_RG, stdin);
    novo->rg[strcspn(novo->rg, "\n")] = 0;

    printf("CPF: ");
    fgets(novo->cpf, MAX_CPF, stdin);
    novo->cpf[strcspn(novo->cpf, "\n")] = 0;

    printf("Telefone: ");
    fgets(novo->telefone, MAX_TELEFONE, stdin);
    novo->telefone[strcspn(novo->telefone, "\n")] = 0;

    // Se a lista estiver vazia
    if (!lista)
    {
        return novo;
    }

    // Insere no final da lista
    Cliente *atual = lista;
    while (atual->proximo)
    {
        atual = atual->proximo;
    }
    atual->proximo = novo;

    return lista;
}

// Função para mostrar todos os clientes
void mostrar_clientes(Cliente *lista)
{
    if (!lista)
    {
        printf("\nNenhum cliente cadastrado!\n");
        return;
    }

    printf("\n=== LISTA DE CLIENTES ===\n");
    Cliente *atual = lista;
    int contador = 1;

    while (atual)
    {
        printf("\nCliente %d:\n", contador++);
        printf("Nome: %s\n", atual->nome);
        printf("RG: %s\n", atual->rg);
        printf("CPF: %s\n", atual->cpf);
        printf("Telefone: %s\n", atual->telefone);
        printf("-------------------------\n");
        atual = atual->proximo;
    }
}

// Função para liberar a memória da lista
void liberar_lista(Cliente *lista)
{
    Cliente *atual = lista;
    while (atual)
    {
        Cliente *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main()
{
    Cliente *lista = NULL;
    char continuar;

    do
    {
        printf("\n=== CADASTRO DE CLIENTE ===\n");
        lista = inserir_cliente(lista);

        printf("\nDeseja cadastrar outro cliente? (S/N): ");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    // Mostra todos os clientes cadastrados
    mostrar_clientes(lista);

    // Libera a memória alocada
    liberar_lista(lista);

    return 0;
}
