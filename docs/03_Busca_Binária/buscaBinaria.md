### Busca Binária (Binary Search)

#### O que é Busca Binária?

A **Busca Binária** é um algoritmo altamente eficiente de busca que opera em **arrays ordenados**. A ideia principal desse algoritmo é usar a técnica de **"dividir para conquistar"**: ele divide o array ao meio a cada passo, descartando metade do conjunto de dados em cada iteração, até encontrar o elemento desejado ou concluir que ele não está presente.

Ao invés de percorrer todos os elementos de forma sequencial (como na busca linear), a busca binária faz comparações sucessivas com o **valor médio** do intervalo de busca, dividindo-o sucessivamente até localizar o elemento ou determinar sua ausência.

#### Comparação Visual: Busca Binária vs Busca Sequencial

<p align="center">
  <img src="https://miro.medium.com/v2/resize:fit:640/format:webp/1*EYkSkQaoduFBhpCVx7nyEA.gif" alt="Comparação entre Busca Binária e Sequencial" />
</p>

Na imagem acima, podemos observar a diferença entre dois tipos de busca:

1. **Busca Sequencial**: A busca sequencial percorre o array de forma linear, verificando cada elemento um por um até encontrar o desejado. Isso resulta em uma complexidade de tempo de **O(n)**.
2. **Busca Binária**: A busca binária, por outro lado, começa no meio do array, comparando o valor procurado com o valor do meio. Se o valor procurado for maior ou menor, o algoritmo descarta metade dos elementos, e assim sucessivamente. Sua complexidade de tempo é muito mais eficiente, sendo **O(log n)**.

### Implementação em C

Abaixo temos uma implementação de busca binária em C, onde o algoritmo é executado de forma **iterativa**:

```c
#include <stdio.h>

// Função que implementa a busca binária
int buscaBinaria(int vetor[], int inicio, int fim, int valor) {
    // Enquanto o intervalo de busca for válido
    while (inicio <= fim) {
        // Calculamos o meio de forma segura para evitar overflow de memória)
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

#### Passo a Passo da Busca

Para entender como o algoritmo de busca binária funciona, vamos seguir um exemplo passo a passo, buscando o valor `6` no vetor `[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]`:

1. **Primeira Iteração:**

   - O intervalo de busca é entre o índice 0 e o índice 15. O valor médio é calculado como `meio = (0 + 15) / 2 = 7`.
   - O valor na posição `7` é `8`.
   - Como `6 < 8`, a busca continua na **primeira metade** do array, ajustando o intervalo para os índices 0 a 6.

2. **Segunda Iteração:**

   - O intervalo de busca é entre os índices 0 e 6. O valor médio é calculado como `meio = (0 + 6) / 2 = 3`.
   - O valor na posição `3` é `4`.
   - Como `6 > 4`, a busca continua na **segunda metade** do array, ajustando o intervalo para os índices 4 a 6.

3. **Terceira Iteração:**
   - O intervalo de busca é entre os índices 4 e 6. O valor médio é calculado como `meio = (4 + 6) / 2 = 5`.
   - O valor na posição `5` é `6`.
   - Encontramos o valor desejado na posição 5!

#### Variáveis Importantes

- **inicio**: O índice inicial do intervalo de busca.
- **fim**: O índice final do intervalo de busca.
- **meio**: O índice calculado como o valor médio do intervalo (meio = `(inicio + fim) / 2`).
- **valorProcurado**: O valor que queremos encontrar no array.

#### Características Principais

- **Array ordenado**: A busca binária só funciona em arrays **ordenados**.
- **Complexidade de tempo**: O tempo de execução da busca binária é **O(log n)**, onde `n` é o número de elementos no array.
- **Complexidade de espaço**: A busca binária utiliza um espaço constante, ou seja, **O(1)**, pois não requer memória adicional significativa, independentemente do tamanho do array.
- **Eficiência**: Muito mais eficiente que a busca linear (O(n)), especialmente para grandes conjuntos de dados.

#### Vantagens

- **Eficiência**: A busca binária é extremamente eficiente para grandes conjuntos de dados, pois divide o problema pela metade a cada iteração.
- **Redução no número de comparações**: Em vez de percorrer todo o array, a busca binária faz um número reduzido de comparações.
- **Tempo logarítmico**: Seu tempo de execução cresce de forma logarítmica, o que significa que para grandes volumes de dados, o algoritmo ainda é rápido.

#### Desvantagens

- **Requer arrays ordenados**: Para que a busca binária funcione, o array precisa estar **ordenado**. Caso contrário, o algoritmo não será aplicável.
- **Desempenho em arrays pequenos**: Para arrays pequenos, a diferença de desempenho entre a busca binária e a busca linear é mínima, então a busca binária pode ser considerada excessiva.

#### Casos de Uso

- **Dicionários digitais**: Onde a busca por palavras pode ser realizada rapidamente em listas ordenadas.
- **Sistemas de busca**: Como motores de busca que trabalham com grandes volumes de dados ordenados.
- **Bancos de dados indexados**: Em consultas a dados estruturados que exigem buscas rápidas.

#### Complexidade

| Caso        | Tempo    |
| ----------- | -------- |
| Melhor Caso | O(1)     |
| Caso Médio  | O(log n) |
| Pior Caso   | O(log n) |

#### Dicas de Implementação

1. **Ordenação**: Certifique-se de que o array está **ordenado** antes de aplicar a busca binária.
2. **Cálculo do meio**: Para evitar problemas de overflow, utilize a fórmula `meio = inicio + (fim - inicio) / 2` ao invés de `meio = (inicio + fim) / 2`.
3. **Controle de intervalo**: Mantenha o controle correto dos índices `inicio` e `fim` para garantir que a busca seja feita dentro dos limites válidos do array.

#### Implementação da Busca Binária Usando Recursividade

Além da implementação iterativa, a busca binária também pode ser realizada de forma **recursiva**. A implementação recursiva pode ser vista abaixo:

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

Neste caso, a função chama a si mesma com um intervalo de busca reduzido a cada iteração, até que o valor seja encontrado ou o intervalo se torne inválido (quando `inicio > fim`). A implementação recursiva é mais elegante, mas pode consumir mais memória devido às chamadas na pilha de

execução, especialmente para arrays grandes.

### Resumo

A busca binária é um algoritmo eficiente e rápido para localizar elementos em arrays ordenados, com uma complexidade de tempo de **O(log n)**. Ela reduz drasticamente o número de comparações necessárias em relação à busca linear e é amplamente utilizada em muitos algoritmos e sistemas que lidam com grandes volumes de dados ordenados.
