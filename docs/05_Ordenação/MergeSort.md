# MergeSort

O **MergeSort** é um algoritmo de ordenação baseado na técnica de **divisão e conquista**, considerado eficiente para grandes conjuntos de dados. Ele divide o vetor original em subvetores menores, ordena cada subvetor e os combina (ou intercala) de forma ordenada.

## Funcionamento

O MergeSort funciona em duas etapas principais:

1. **Divisão:**  
   O vetor é recursivamente dividido ao meio até que cada subvetor contenha apenas um elemento. Esses subvetores são considerados ordenados, pois contêm apenas um elemento.

2. **Intercalação (Merge):**  
   Os subvetores são combinados de forma ordenada. O processo compara os menores elementos de cada subvetor e os adiciona à lista resultante.

<p align="center">
  <img width="70%" src="https://miro.medium.com/v2/resize:fit:640/format:webp/1*X-o4Ng1YsdZg13We3J4q9Q.gif" />
</p>

## Algoritmo

### Função Principal do MergeSort

```c
#include <stdio.h>
#include <stdlib.h>

// Declaração das funções
void mergeSort(int vetor[], int inicio, int fim);
void merge(int vetor[], int inicio, int meio, int fim);

// Função principal do MergeSort
void mergeSort(int vetor[], int inicio, int fim){
  // Verifica se o vetor é nulo
  if (vetor == NULL){
    printf("Erro: vetor nulo!\n");
    return;
  }

  // Verifica se o vetor possui mais de um elemento
  if (inicio < fim){
    // Calcula o índice do meio para dividir o vetor
    int meio = inicio + (fim - inicio) / 2; // Evita overflow em vetores grandes

    // Passo 1: Recursivamente ordena a metade esquerda do vetor
    mergeSort(vetor, inicio, meio);

    // Passo 2: Recursivamente ordena a metade direita do vetor
    mergeSort(vetor, meio + 1, fim);

    // Passo 3: Intercala as duas metades ordenadas
    merge(vetor, inicio, meio, fim);
  }
}
```

### Função de Intercalação

```c
// Função de Intercalação
void merge(int vetor[], int inicio, int meio, int fim){
  // Determina o tamanho dos subvetores esquerdo e direito
  int tamEsq = meio - inicio + 1;
  int tamDir = fim - meio;

  // Aloca memória para os subvetores temporários e verifica se a alocação foi bem-sucedida
  int *esquerdo = (int *)malloc(tamEsq * sizeof(int));
  int *direito = (int *)malloc(tamDir * sizeof(int));

  if (esquerdo == NULL || direito == NULL){
    printf("Erro: falha na alocação de memória!\n");
    return;
  }

  // Copia os dados do vetor original para os subvetores temporários
  for (int i = 0; i < tamEsq; i++){
    esquerdo[i] = vetor[inicio + i];
  }
  for (int j = 0; j < tamDir; j++){
    direito[j] = vetor[meio + 1 + j];
  }

  // Índices para percorrer os subvetores e o vetor original
  int i = 0;      // Índice do subvetor esquerdo
  int j = 0;      // Índice do subvetor direito
  int k = inicio; // Índice do vetor original

  // Passo 1: Compara e intercala os elementos dos subvetores no vetor original
  while (i < tamEsq && j < tamDir){
    if (esquerdo[i] <= direito[j]){
      vetor[k] = esquerdo[i];
      i++;
    }
    else{
      vetor[k] = direito[j];
      j++;
    }
    k++;
  }

  // Passo 2: Copia os elementos restantes do subvetor esquerdo, se houver
  while (i < tamEsq){
    vetor[k] = esquerdo[i];
    i++;
    k++;
  }

  // Passo 3: Copia os elementos restantes do subvetor direito, se houver
  while (j < tamDir){
    vetor[k] = direito[j];
    j++;
    k++;
  }

  // Libera a memória alocada para os subvetores temporários
  free(esquerdo);
  free(direito);
}
```

### Exemplo de Execução

Dado um vetor inicial: `[6, 3, 9, 2, 5, 8]`

### Divisão

1. Divide o vetor em `[6, 3, 9]` e `[2, 5, 8]`.
2. Divide `[6, 3, 9]` em `[6]` e `[3, 9]`, e `[2, 5, 8]` em `[2]` e `[5, 8]`.
3. Agora todos os subvetores possuem um único elemento.

### Intercalação

1. Combina `[3, 9]` para obter `[3, 9]` e `[5, 8]` para obter `[5, 8]`.
2. Combina `[6]` e `[3, 9]` para obter `[3, 6, 9]`.
3. Combina `[2]` e `[5, 8]` para obter `[2, 5, 8]`.
4. Combina `[3, 6, 9]` e `[2, 5, 8]` para obter `[2, 3, 5, 6, 8, 9]`.

**Resultado Final:** `[2, 3, 5, 6, 8, 9]`

### Complexidade

| Caso        | Complexidade |
| ----------- | ------------ |
| Melhor Caso | O(n log n)   |
| Pior Caso   | O(n log n)   |
| Caso Médio  | O(n log n)   |

### Vantagens

- Tempo de execução consistente em todos os casos.
- Estável (mantém a ordem relativa de elementos iguais).
- Adequado para grandes conjuntos de dados.

### Desvantagens

- Requer espaço adicional para os arrays temporários.
- Mais complexo que algoritmos simples como o BubbleSort.

### Conclusão

O MergeSort é um dos algoritmos de ordenação mais eficientes e amplamente utilizados. Sua implementação recursiva o torna ideal para aplicações onde a estabilidade e a eficiência são cruciais, especialmente em casos onde o conjunto de dados é muito grande e a memória adicional não é um problema significativo.

## MergeSort completo em C

```c
#include <stdio.h>
#include <stdlib.h>

void mergeSort(int vetor[], int inicio, int fim);
void merge(int vetor[], int inicio, int meio, int fim);

void mergeSort(int vetor[], int inicio, int fim){
  if (vetor == NULL){
    printf("Erro: vetor nulo!\n");
    return;
  }

  if (inicio < fim){
    int meio = inicio + (fim - inicio) / 2;

    mergeSort(vetor, inicio, meio);
    mergeSort(vetor, meio + 1, fim);

    merge(vetor, inicio, meio, fim);
  }
}

void merge(int vetor[], int inicio, int meio, int fim){
  int tamEsq = meio - inicio + 1;
  int tamDir = fim - meio;

  int *esquerdo = (int *)malloc(tamEsq * sizeof(int));
  int *direito = (int *)malloc(tamDir * sizeof(int));

  if (esquerdo == NULL || direito == NULL){
    printf("Erro: falha na alocação de memória!\n");
    free(esquerdo);
    free(direito);
    return;
  }

  for (int i = 0; i < tamEsq; i++){
    esquerdo[i] = vetor[inicio + i];
  }
  for (int j = 0; j < tamDir; j++){
    direito[j] = vetor[meio + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = inicio;

  while (i < tamEsq && j < tamDir){
    if (esquerdo[i] <= direito[j]){
      vetor[k] = esquerdo[i];
      i++;
    }
    else{
      vetor[k] = direito[j];
      j++;
    }
    k++;
  }

  while (i < tamEsq){
    vetor[k] = esquerdo[i];
    i++;
    k++;
  }

  while (j < tamDir){
    vetor[k] = direito[j];
    j++;
    k++;
  }

  free(esquerdo);
  free(direito);
}

int main()
{
  int vetor[] = {6, 3, 9, 2, 5, 8};
  int tamanho = sizeof(vetor) / sizeof(vetor[0]);

  printf("Vetor original: ");
  for (int i = 0; i < tamanho; i++)
  {
    printf("%d ", vetor[i]);
  }

  mergeSort(vetor, 0, tamanho - 1);

  printf("\nVetor ordenado: ");
  for (int i = 0; i < tamanho; i++)
  {
    printf("%d ", vetor[i]);
  }

  return 0;
}
```
