### Ordenação por Bolha (BubbleSort) em C

A **Ordenação por Bolha** (BubbleSort) é um algoritmo de ordenação simples que funciona com base na comparação de elementos adjacentes em uma lista. Caso estejam fora de ordem, ele os troca de lugar. Esse processo é repetido várias vezes até que toda a lista esteja ordenada. O nome "Bolha" vem do fato de que os valores maiores se "movem" para o final da lista (como bolhas subindo à superfície), enquanto os menores vão para o início.

<p align="center">
  <img src="https://i.sstatic.net/XNbE0.gif" width="70%" alt="Ordenação por Bolha (BubbleSort)">
</p>

#### Como funciona:

- A cada iteração, o algoritmo percorre a lista comparando dois elementos consecutivos.
- Se o elemento da esquerda for maior que o da direita, eles são trocados.
- Esse processo continua até que a lista esteja ordenada.

#### Exemplificação:

Considere a lista de números:

```plaintext
[32, 1, 9, 6]
```

1. Primeira iteração:

   - Compara 32 e 1 → troca → `[1, 32, 9, 6]`
   - Compara 32 e 9 → troca → `[1, 9, 32, 6]`
   - Compara 32 e 6 → troca → `[1, 9, 6, 32]`
   - Resultado após a primeira iteração: `[1, 9, 6, 32]`

2. Segunda iteração:
   - Compara 1 e 9 → não troca.
   - Compara 9 e 6 → troca → `[1, 6, 9, 32]`
   - Resultado após a segunda iteração: `[1, 6, 9, 32]`

A lista já está ordenada, e o algoritmo terminou.

### Implementação do BubbleSort em C:

A implementação em C do algoritmo BubbleSort funciona da seguinte forma:

```c
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    // Loop para controlar o número de passagens
    for (i = 0; i < n-1; i++) {
        // Loop interno para fazer as comparações
        for (j = 0; j < n-i-1; j++) {
            // Troca os elementos se estiverem na ordem errada
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {32, 1, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array antes da ordenação: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Array depois da ordenação: ");
    printArray(arr, n);

    return 0;
}
```

### Explicação do Código:

- **Função `bubbleSort`:**
  - Essa função recebe um vetor `arr[]` e o seu tamanho `n` como parâmetros.
  - Utiliza dois loops: o loop externo (`for (i = 0; i < n-1; i++)`) controla o número de passagens, e o loop interno (`for (j = 0; j < n-i-1; j++)`) realiza as comparações e as trocas.
  - Se o elemento da posição `j` for maior que o elemento da posição `j+1`, os dois elementos são trocados de lugar.
- **Função `printArray`:**
  - Essa função apenas imprime o vetor na tela para verificarmos o estado do vetor antes e depois da ordenação.

### Saída do Programa:

Para a entrada:

```plaintext
[32, 1, 9, 6]
```

A saída será:

```plaintext
Array antes da ordenação: 32 1 9 6
Array depois da ordenação: 1 6 9 32
```

### Complexidade de Tempo:

- **Pior Caso:** O algoritmo BubbleSort tem uma complexidade de tempo de **O(n²)** no pior caso, o que ocorre quando a lista está completamente desordenada. Nesse caso, o algoritmo realiza o maior número de comparações e trocas.
- **Melhor Caso:** No melhor caso (quando a lista já está ordenada), a complexidade é **O(n)**, já que o algoritmo pode ser otimizado para verificar se houve trocas durante a iteração e terminar mais cedo caso a lista já esteja ordenada.

### Características:

- **Estabilidade:** O BubbleSort é um algoritmo estável, ou seja, mantém a ordem dos elementos iguais no vetor.
- **Simples:** A implementação do BubbleSort é fácil de entender e de implementar, tornando-o ideal para fins educativos.

### Limitações:

Embora o BubbleSort seja simples e útil em listas pequenas ou quando a lista já está quase ordenada, ele não é eficiente para listas grandes, pois a sua complexidade de tempo quadrática pode tornar o algoritmo lento em grandes volumes de dados. Para conjuntos de dados maiores, algoritmos mais eficientes, como QuickSort ou MergeSort, são geralmente preferidos.

### Conclusão:

O BubbleSort é um algoritmo interessante do ponto de vista educacional devido à sua simplicidade. No entanto, devido à sua baixa eficiência para grandes conjuntos de dados, é raramente usado em sistemas de produção.
