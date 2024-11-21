# Busca Binária (Binary Search)

## O que é Busca Binária?

A Busca Binária é um algoritmo eficiente de busca que funciona em arrays ordenados. Ela utiliza a técnica de "dividir para conquistar" para encontrar a posição de um elemento específico no array.

## Comparação Visual: Busca Binária vs Busca Sequencial

![Comparação entre Busca Binária e Sequencial](https://miro.medium.com/v2/resize:fit:640/format:webp/1*EYkSkQaoduFBhpCVx7nyEA.gif)

Na imagem acima, podemos ver a diferença entre:

- **Busca Sequencial**: verifica cada elemento um por um (O(n))
- **Busca Binária**: divide o array pela metade a cada etapa (O(log n))

## Implementação em C

```c
#include <stdio.h>

// Função que implementa a busca binária
int buscaBinaria(int vetor[], int inicio, int fim, int valor) {
    // Enquanto o intervalo de busca for válido
    while (inicio <= fim) {
        // Calculamos o meio de forma segura para evitar overflow
        int meio = inicio + (fim - inicio) / 2;

        // Se encontramos o valor no meio
        if (vetor[meio] == valor)
            return meio; // Retornamos a posição do valor

        // Se o valor está na metade direita
        if (vetor[meio] < valor)
            inicio = meio + 1; // Ajustamos o início do intervalo
        // Se o valor está na metade esquerda
        else
            fim = meio - 1; // Ajustamos o fim do intervalo
    }

    // Valor não encontrado
    return -1;
}

int main() {
    // Array de entrada ordenado
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    // Calculamos o tamanho do array
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    // Valor que queremos encontrar
    int valorProcurado = 6;

    // Chamamos a função de busca binária
    int resultado = buscaBinaria(vetor, 0, tamanho - 1, valorProcurado);

    // Verificamos se o valor foi encontrado
    if (resultado != -1)
        printf("Valor %d encontrado na posição: %d\n", valorProcurado, resultado);
    else
        printf("Valor %d não encontrado!\n", valorProcurado);

    return 0;
}
```

## Passo a Passo da Busca

Vamos buscar o valor 6 no vetor [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]:

1. **Primeira Iteração:**

   - Meio = (0 + 15) / 2 = 7
   - vetor[7] = 8
   - 6 < 8, então procuramos na primeira metade

2. **Segunda Iteração:**

   - Meio = (0 + 6) / 2 = 3
   - vetor[3] = 4
   - 6 > 4, então procuramos na segunda metade

3. **Terceira Iteração:**
   - Meio = (4 + 6) / 2 = 5
   - vetor[5] = 6
   - Encontramos o valor!

## Variáveis Importantes

- `inicio`: marca o início do intervalo de busca
- `fim`: marca o fim do intervalo de busca
- `meio`: calculado como `inicio + (fim - inicio) / 2`
- `valorProcurado`: o valor que queremos encontrar

## Características Principais

- Funciona apenas em arrays **ordenados**
- Complexidade de tempo: O(log n)
- Complexidade de espaço: O(1)
- Muito mais eficiente que a busca linear para grandes conjuntos de dados

## Vantagens

- Muito eficiente para grandes conjuntos de dados
- Reduz significativamente o número de comparações necessárias
- Tempo de execução logarítmico

## Desvantagens

- Requer que o array esteja ordenado, portanto, não funciona em estruturas de dados não sequenciais
- Não é eficiente para pequenos conjuntos de dados

## Casos de Uso

- Dicionários digitais
- Sistemas de busca
- Bancos de dados indexados

## Complexidade

| Caso        | Tempo    |
| ----------- | -------- |
| Melhor Caso | O(1)     |
| Caso Médio  | O(log n) |
| Pior Caso   | O(log n) |

## Dicas de Implementação

1. Sempre verifique se o array está ordenado antes de aplicar
2. Cuidado com overflow ao calcular o meio do array
3. Considere usar `inicio + (fim - inicio) / 2` em vez de `(inicio + fim) / 2`
4. Mantenha o controle correto dos índices de início e fim

### Implementação da Busca Binária Usando Recursividade

```c
int buscaBinariaRecursiva(int vetor[], int inicio, int fim, int valor) {
    // Caso base: array vazio ou valor encontrado
    if (inicio > fim)
        return -1;

    // Calcula o meio
    int meio = inicio + (fim - inicio) / 2;

    // Se encontrou o valor
    if (vetor[meio] == valor)
        return meio;
    // Se o valor é menor que o meio
    else if (vetor[meio] < valor)
        return buscaBinariaRecursiva(vetor, meio + 1, fim, valor);
    // Se o valor é maior que o meio
    else
        return buscaBinariaRecursiva(vetor, inicio, meio - 1, valor);
}
```
