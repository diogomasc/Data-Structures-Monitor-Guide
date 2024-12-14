# Ordenação por Seleção (SelectionSort)

O **SelectionSort** é um algoritmo simples de ordenação que funciona iterativamente. Ele encontra o menor elemento de uma sequência não ordenada e o move para a primeira posição. Após isso, considera o restante da sequência (excluindo o elemento já ordenado) e repete o processo até que todos os elementos estejam ordenados.

### Funcionamento

1. **Definição inicial**: Seleciona-se o primeiro elemento como o menor (**minimum**).
2. **Comparação**: Compara-se o valor atual do **minimum** com os elementos restantes da lista.
   - Se algum elemento for menor que o **minimum**, este é atualizado.
3. **Troca**: Após encontrar o menor elemento, realiza-se a troca entre o menor elemento encontrado e o primeiro elemento não ordenado.
4. **Iteração**: Repete-se o processo para os elementos seguintes, ignorando os que já foram ordenados.
5. **Finalização**: Quando todos os elementos forem processados, a lista estará ordenada.

<p align="center">
  <img src="https://i.makeagif.com/media/1-24-2016/VrJ-Br.gif" width="60%"/>
</p>

### Complexidade

- **Melhor caso (lista já ordenada)**: \(O(n^2)\), pois o algoritmo sempre percorre toda a lista.
- **Pior caso (lista em ordem reversa)**: \(O(n^2)\).
- **Espaço**: O algoritmo é in-place, ou seja, não requer memória adicional significativa (\(O(1)\)).

### Pseudocódigo do SelectionSort

```plaintext
Para i de 0 até n-2:
    Defina a posição do menor elemento (minIndex) como i
    Para j de i+1 até n-1:
        Se array[j] < array[minIndex]:
            Atualize minIndex para j
    Se minIndex for diferente de i:
        Troque array[i] e array[minIndex]
```

### Implementação em C

Abaixo está uma implementação completa do algoritmo SelectionSort em C:

```c
#include <stdio.h>

// Função para realizar o SelectionSort
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    // Percorre todo o array
    for (i = 0; i < n - 1; i++) {
        // Encontra o menor elemento na parte não ordenada
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Troca o menor elemento com o primeiro da parte não ordenada
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Programa principal
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}
```

### Exemplo Passo a Passo

Considere o array inicial: **{64, 34, 25, 12, 22, 11, 90}**

#### Iterações

1. **Primeira Iteração**:

   - Menor elemento: **11**
   - Troca: **11 ↔ 64**
   - Array após a troca: **{11, 34, 25, 12, 22, 64, 90}**

2. **Segunda Iteração**:

   - Menor elemento: **12**
   - Troca: **12 ↔ 34**
   - Array após a troca: **{11, 12, 25, 34, 22, 64, 90}**

3. **Terceira Iteração**:

   - Menor elemento: **22**
   - Troca: **22 ↔ 25**
   - Array após a troca: **{11, 12, 22, 34, 25, 64, 90}**

4. **Quarta Iteração**:

   - Menor elemento: **25**
   - Troca: **25 ↔ 34**
   - Array após a troca: **{11, 12, 22, 25, 34, 64, 90}**

5. **Quinta Iteração**:
   - Menor elemento: **64**
   - Troca: Nenhuma troca necessária.
   - Array final: **{11, 12, 22, 25, 34, 64, 90}**

### Características

- **Vantagens**:
  - Simples de implementar.
  - Não requer memória adicional.
- **Desvantagens**:
  - Ineficiente para listas grandes devido à complexidade quadrática.
