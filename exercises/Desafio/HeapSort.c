#include <stdio.h>

// Função para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para criar um heap
void criarHeap(int array[], int tamanho, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < tamanho && array[esquerda] > array[maior])
        maior = esquerda;

    if (direita < tamanho && array[direita] > array[maior])
        maior = direita;

    if (maior != i) {
        trocar(&array[i], &array[maior]);
        criarHeap(array, tamanho, maior);
    }
}

// Implementação do HeapSort
void heapSort(int array[], int tamanho) {
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        criarHeap(array, tamanho, i);

    for (int i = tamanho - 1; i > 0; i--) {
        trocar(&array[0], &array[i]);
        criarHeap(array, i, 0);
    }
}

// Função para imprimir o array
void imprimirArray(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// Função principal para testar o HeapSort
int main() {
    int dados[] = {12, 11, 13, 5, 6, 7};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    heapSort(dados, tamanho);
    printf("Array ordenado: \n");
    imprimirArray(dados, tamanho);
    return 0;
}
