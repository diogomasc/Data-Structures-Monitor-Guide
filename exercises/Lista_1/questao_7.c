#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Programa para determinar o signo do Zodíaco Chinês
 *
 * Este programa demonstra:
 * - Implementação de lista encadeada
 * - Cálculo de resto da divisão
 * - Busca em lista encadeada
 */

#define MAX_SIGNO 20

// Estrutura para armazenar os signos do zodíaco
typedef struct Signo
{
    char nome[MAX_SIGNO];
    int resto;
    struct Signo *proximo;
} Signo;

// Função para criar um novo nó de signo
Signo *criar_signo(const char *nome, int resto)
{
    Signo *novo = (Signo *)malloc(sizeof(Signo));
    if (!novo)
    {
        printf("Erro na alocacao de memoria!\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    novo->resto = resto;
    novo->proximo = NULL;
    return novo;
}

// Função para inserir signo na lista
Signo *inserir_signo(Signo *lista, const char *nome, int resto)
{
    Signo *novo = criar_signo(nome, resto);

    // Se a lista estiver vazia
    if (!lista)
    {
        return novo;
    }

    // Insere no final da lista
    Signo *atual = lista;
    while (atual->proximo)
    {
        atual = atual->proximo;
    }
    atual->proximo = novo;

    return lista;
}

// Função para encontrar o signo baseado no resto
const char *encontrar_signo(Signo *lista, int resto)
{
    Signo *atual = lista;
    while (atual)
    {
        if (atual->resto == resto)
        {
            return atual->nome;
        }
        atual = atual->proximo;
    }
    return "Signo não encontrado";
}

// Função para liberar a memória da lista
void liberar_lista(Signo *lista)
{
    Signo *atual = lista;
    while (atual)
    {
        Signo *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

// Função para inicializar a lista de signos
Signo *inicializar_signos()
{
    Signo *lista = NULL;

    // Inserindo todos os signos na ordem
    lista = inserir_signo(lista, "Macaco", 0);
    lista = inserir_signo(lista, "Galo", 1);
    lista = inserir_signo(lista, "Cao", 2);
    lista = inserir_signo(lista, "Porco", 3);
    lista = inserir_signo(lista, "Rato", 4);
    lista = inserir_signo(lista, "Boi", 5);
    lista = inserir_signo(lista, "Tigre", 6);
    lista = inserir_signo(lista, "Coelho", 7);
    lista = inserir_signo(lista, "Dragao", 8);
    lista = inserir_signo(lista, "Serpente", 9);
    lista = inserir_signo(lista, "Cavalo", 10);
    lista = inserir_signo(lista, "Carneiro", 11);

    return lista;
}

int main()
{
    int ano;
    Signo *lista = inicializar_signos();
    char continuar;

    do
    {
        printf("\n=== ZODIACO CHINES ===\n");
        printf("Digite o ano de nascimento: ");
        scanf("%d", &ano);

        // Calcula o resto e encontra o signo
        int resto = ano % 12;
        const char *signo = encontrar_signo(lista, resto);

        printf("\nPara o ano %d:\n", ano);
        printf("Resto da divisao por 12: %d\n", resto);
        printf("Seu signo no zodiaco chines: %s\n", signo);

        printf("\nDeseja consultar outro ano? (S/N): ");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    // Libera a memória alocada
    liberar_lista(lista);

    return 0;
}
