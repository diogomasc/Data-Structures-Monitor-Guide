#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

// Função para calcular fatorial recursivamente
int fatorial(int n) {
    if (n <= 1) return 1;
    return n * fatorial(n - 1);
}

// Função para mostrar o cálculo do fatorial
void mostra_fatorial(int n) {
    printf("%d! = ", n);
    for(int i = n; i > 0; i--) {
        printf("%d", i);
        if(i > 1) printf(" * ");
    }
    printf(" = %d\n", fatorial(n));
}

// Função Fibonacci recursiva
int fibonacci_recursivo(int n) {
    if (n <= 1) return n;
    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}

// Função Fibonacci iterativa
int fibonacci_iterativo(int n) {
    if (n <= 1) return n;
    
    int anterior = 0, atual = 1, proximo;
    for(int i = 2; i <= n; i++) {
        proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }
    return atual;
}

// Função para encontrar o maior valor em um vetor recursivamente
int maior_valor_recursivo(int vetor[], int tamanho) {
    if (tamanho == 1) return vetor[0];
    
    int maior_resto = maior_valor_recursivo(vetor, tamanho - 1);
    return (vetor[tamanho - 1] > maior_resto) ? vetor[tamanho - 1] : maior_resto;
}

int main() {
    int opcao, n, *vetor, tamanho;

    do {
        system(CLEAR);
        printf("\n=== DEMONSTRACAO DE RECURSIVIDADE ===\n");
        printf("1. Calcular e mostrar Fatorial\n");
        printf("2. Fibonacci Recursivo\n");
        printf("3. Fibonacci Iterativo (comparacao)\n");
        printf("4. Encontrar Maior Valor em Vetor\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite um numero para calcular o fatorial: ");
                scanf("%d", &n);
                if(n < 0) {
                    printf("Por favor, digite um numero positivo!\n");
                } else {
                    mostra_fatorial(n);
                }
                break;

            case 2:
                printf("Digite a posicao de Fibonacci desejada: ");
                scanf("%d", &n);
                if(n < 0) {
                    printf("Por favor, digite um numero positivo!\n");
                } else {
                    printf("Fibonacci(%d) = %d\n", n, fibonacci_recursivo(n));
                }
                break;

            case 3:
                printf("Digite a posicao de Fibonacci desejada: ");
                scanf("%d", &n);
                if(n < 0) {
                    printf("Por favor, digite um numero positivo!\n");
                } else {
                    printf("Fibonacci(%d) = %d\n", n, fibonacci_iterativo(n));
                }
                break;

            case 4:
                printf("Digite o tamanho do vetor: ");
                scanf("%d", &tamanho);
                if(tamanho <= 0) {
                    printf("Tamanho invalido!\n");
                    break;
                }
                
                vetor = (int*)malloc(tamanho * sizeof(int));
                if(vetor == NULL) {
                    printf("Erro na alocacao de memoria!\n");
                    break;
                }

                printf("Digite os elementos do vetor:\n");
                for(int i = 0; i < tamanho; i++) {
                    printf("Elemento %d: ", i+1);
                    scanf("%d", &vetor[i]);
                }

                printf("Maior valor no vetor: %d\n", maior_valor_recursivo(vetor, tamanho));
                free(vetor);
                break;

            case 0:
                printf("Programa finalizado!\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

        if(opcao != 0) {
            printf("\nPressione Enter para continuar...");
            getchar();
            getchar();
        }

    } while(opcao != 0);

    return 0;
}
