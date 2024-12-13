#include <stdio.h>

// Função para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Particiona o array e retorna o índice do pivô
int particionar(int array[], int inicio, int fim) {
    int pivo = array[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++) {
        if (array[j] < pivo) {
            i++;
            trocar(&array[i], &array[j]);
        }
    }
    trocar(&array[i + 1], &array[fim]);
    return (i + 1);
}

// Implementação do QuickSort
void quickSort(int array[], int inicio, int fim) {
    if (inicio < fim) {
        int indicePivo = particionar(array, inicio, fim);
        quickSort(array, inicio, indicePivo - 1);
        quickSort(array, indicePivo + 1, fim);
    }
}

// Função para imprimir o array
void imprimirArray(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// Função principal para testar o QuickSort
int main() {
    int dados[] = {10, 7, 8, 9, 1, 5};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    quickSort(dados, 0, tamanho - 1);
    printf("Array ordenado: \n");
    imprimirArray(dados, tamanho);
    return 0;
}
