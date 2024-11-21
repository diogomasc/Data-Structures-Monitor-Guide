#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

// Função para buscar um elemento no vetor
int buscaElemento(int elemento, int vetor[], int tamanho) {
    for(int indice = 0; indice < tamanho; indice++) {
        if(vetor[indice] == elemento) {
            return indice;
        }
    }
    return -1;
}

// Função para inverter o vetor
void inverteVetor(int vetor[], int tamanho) {
    int temporario;
    for(int indice = 0; indice < tamanho / 2; indice++) {
        temporario = vetor[indice];
        vetor[indice] = vetor[tamanho - 1 - indice];
        vetor[tamanho - 1 - indice] = temporario;
    }
}

// Função para remover um elemento do vetor
int removeElemento(int elemento, int vetor[], int *tamanho) {
    int posicao = buscaElemento(elemento, vetor, *tamanho);
    if(posicao == -1) return 0;

    for(int indice = posicao; indice < *tamanho - 1; indice++) {
        vetor[indice] = vetor[indice + 1];
    }
    (*tamanho)--;
    return 1;
}

// Função para adicionar um elemento no vetor
int adicionaElemento(int elemento, int vetor[], int *tamanho, int capacidade) {
    if (*tamanho >= capacidade) return 0;
    vetor[*tamanho] = elemento;
    (*tamanho)++;
    return 1;
}

// Função para imprimir o vetor
void imprimeVetor(int vetor[], int tamanho) {
    if (tamanho == 0) {
        printf("Vetor vazio!\n");
        return;
    }
    printf("Vetor: ");
    for(int indice = 0; indice < tamanho; indice++) {
        printf("[ %d ] ", vetor[indice]);
    }
    printf("\n");
}

int main() {
    int capacidade;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &capacidade);

    if (capacidade <= 0) {
        printf("Tamanho invalido!\n");
        return 1;
    }

    int *vetor = (int*)malloc(capacidade * sizeof(int));
    if (vetor == NULL) {
        printf("Erro na alocacao de memoria!\n");
        return 1;
    }

    int tamanho = 0;
    int opcao;
    int elemento;

    do {
        system(CLEAR);
        printf("\n=== MENU DE OPERACOES ===\n");
        printf("1. Adicionar novo valor\n");
        printf("2. Remover valor\n");
        printf("3. Buscar valor\n");
        printf("4. Imprimir vetor\n");
        printf("5. Inverter vetor\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor a ser adicionado: ");
                scanf("%d", &elemento);
                if (adicionaElemento(elemento, vetor, &tamanho, capacidade)) {
                    printf("Valor %d adicionado com sucesso!\n", elemento);
                } else {
                    printf("Erro: Vetor cheio!\n");
                }
                break;

            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &elemento);
                if (removeElemento(elemento, vetor, &tamanho)) {
                    printf("Valor %d removido com sucesso!\n", elemento);
                } else {
                    printf("Valor nao encontrado no vetor!\n");
                }
                break;

            case 3:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &elemento);
                int posicao = buscaElemento(elemento, vetor, tamanho);
                if (posicao != -1) {
                    printf("Valor %d encontrado na posicao %d\n", elemento, posicao);
                } else {
                    printf("Valor nao encontrado no vetor!\n");
                }
                break;

            case 4:
                imprimeVetor(vetor, tamanho);
                break;

            case 5:
                if (tamanho > 0) {
                    inverteVetor(vetor, tamanho);
                    printf("Vetor invertido com sucesso!\n");
                    imprimeVetor(vetor, tamanho);
                } else {
                    printf("Vetor vazio! Nao e possivel inverter.\n");
                }
                break;

            case 0:
                printf("Programa finalizado!\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

        if(opcao != 0) {
            printf("\nPressione qualquer tecla para continuar...");
            getchar(); 
            getchar();
        }

    } while(opcao != 0);

    free(vetor);
    return 0;
}