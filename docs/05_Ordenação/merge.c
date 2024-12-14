#include <stdio.h>
#include <stdlib.h>

// Declaração das funções
void mergeSort(int vetor[], int inicio, int fim);
void merge(int vetor[], int inicio, int meio, int fim);

// Função principal do MergeSort
void mergeSort(int vetor[], int inicio, int fim)
{
  // Verifica se o vetor é nulo
  if (vetor == NULL)
  {
    printf("Erro: vetor nulo!\n");
    return;
  }

  // Verifica se o vetor possui mais de um elemento
  if (inicio < fim)
  {
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

// Função de Intercalação
void merge(int vetor[], int inicio, int meio, int fim)
{
  // Determina o tamanho dos subvetores esquerdo e direito
  int tamEsq = meio - inicio + 1;
  int tamDir = fim - meio;

  // Aloca memória para os subvetores temporários e verifica se a alocação foi bem-sucedida
  int *esquerdo = (int *)malloc(tamEsq * sizeof(int));
  int *direito = (int *)malloc(tamDir * sizeof(int));

  if (esquerdo == NULL || direito == NULL)
  {
    printf("Erro: falha na alocação de memória!\n");
    free(esquerdo);
    free(direito);
    return;
  }

  // Copia os dados do vetor original para os subvetores temporários
  for (int i = 0; i < tamEsq; i++)
  {
    esquerdo[i] = vetor[inicio + i];
  }
  for (int j = 0; j < tamDir; j++)
  {
    direito[j] = vetor[meio + 1 + j];
  }

  // Índices para percorrer os subvetores e o vetor original
  int i = 0;      // Índice do subvetor esquerdo
  int j = 0;      // Índice do subvetor direito
  int k = inicio; // Índice do vetor original

  // Passo 1: Compara e intercala os elementos dos subvetores no vetor original
  while (i < tamEsq && j < tamDir)
  {
    if (esquerdo[i] <= direito[j])
    {
      vetor[k] = esquerdo[i];
      i++;
    }
    else
    {
      vetor[k] = direito[j];
      j++;
    }
    k++;
  }

  // Passo 2: Copia os elementos restantes do subvetor esquerdo, se houver
  while (i < tamEsq)
  {
    vetor[k] = esquerdo[i];
    i++;
    k++;
  }

  // Passo 3: Copia os elementos restantes do subvetor direito, se houver
  while (j < tamDir)
  {
    vetor[k] = direito[j];
    j++;
    k++;
  }

  // Libera a memória alocada para os subvetores temporários
  free(esquerdo);
  free(direito);
}

// Exemplo de execução
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
