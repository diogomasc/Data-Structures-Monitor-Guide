### Ordenação por Inserção (Insertion Sort) em C

A ordenação por inserção (Insertion Sort) é um algoritmo simples e intuitivo usado para ordenar elementos. Ele se baseia na ideia de dividir uma lista em duas partes: uma parte já ordenada e outra desordenada. Gradualmente, os elementos da parte desordenada são inseridos na posição correta dentro da parte ordenada, de forma semelhante a como ordenamos cartas de um baralho.

#### Como funciona?

1. Percorre os elementos da lista a partir do segundo elemento.
2. Compara o elemento atual com os elementos anteriores da parte ordenada.
3. Move os elementos maiores para a direita, criando espaço para inserir o elemento atual em sua posição correta.

<p align="center" >
  <img width="70%"  src="https://sp-ao.shortpixel.ai/client/to_webp,q_lossless,ret_img,w_892,h_276/https://blog.shahadmahmud.com/wp-content/uploads/2020/04/is3.gif" alt="Ordenação por Inserção (Insertion Sort)">
</p>

#### Implementação em C

```c
#include <stdio.h>

// Função de ordenação por inserção
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int valorAtual = arr[i]; // Elemento a ser inserido
        int j = i - 1;

        // Move os elementos da parte ordenada maiores que o valorAtual
        while (j >= 0 && arr[j] > valorAtual) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insere o valorAtual na posição correta
        arr[j + 1] = valorAtual;
    }
}

// Função para imprimir o array
void imprimirArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Programa principal
int main() {
    int arr[] = {6, 5, 8, 2;
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    imprimirArray(arr, tamanho);

    insertionSort(arr, tamanho);

    printf("Array ordenado:\n");
    imprimirArray(arr, tamanho);

    return 0;
}
```

#### Como funciona o exemplo?

Para o array `{6, 5, 8, 2}`:

1. **Passo 1**: `i = 1, valorAtual = 5`

   - Compara 5 com 6. Como 5 < 6, desloca 6 para a direita e insere 5 antes de 6.
   - Resultado: `{5, 6, 8, 2}`.

2. **Passo 2**: `i = 2, valorAtual = 8`

   - Compara 8 com 6. Como 8 > 6, não há trocas.
   - Resultado: `{5, 6, 8, 2}`.

3. **Passo 3**: `i = 3, valorAtual = 2`
   - Compara 2 com 8, 6 e 5. Desloca todos para a direita e insere 2 no início.
   - Resultado final: `{2, 5, 6, 8}`.

#### Análise de Complexidade

- **Melhor caso**: O(n), quando a lista já está ordenada.
- **Pior caso**: O(n²), quando a lista está em ordem inversa.
- **Estável**: Sim, a posição relativa dos elementos iguais é preservada.

#### Exemplo com lista quase ordenada

Considere a lista `{1, 2, 3, 4, 5, 7, 6}`:

```c
int arr[] = {1, 2, 3, 4, 5, 7, 6};
```

- O algoritmo identificará rapidamente que os elementos estão ordenados até o penúltimo. Apenas 6 precisará ser movido uma posição à esquerda.
- Isso demonstra a eficiência do algoritmo para listas quase ordenadas.

#### Vantagens do Insertion Sort

1. Simples de implementar.
2. Eficiente para listas pequenas ou quase ordenadas.
3. É um algoritmo **estável**.

#### Desvantagens

1. Ineficiente para listas grandes, devido à complexidade O(n²) no pior caso.
2. Requer múltiplas comparações e deslocamentos para cada inserção.

Com essa base, você pode adaptar o algoritmo para diversos contextos em C, utilizando-o em aplicações que demandam ordenação eficiente de listas pequenas ou quase ordenadas.
