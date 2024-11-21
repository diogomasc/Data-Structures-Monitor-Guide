# Recursividade em C

## Introdução

A recursividade é um conceito fundamental na programação onde uma função resolve um problema chamando a si mesma com uma instância menor do mesmo problema. Este documento explora implementações recursivas em C com análise de complexidade.

## 1. Conceitos Fundamentais

Uma função recursiva possui dois componentes principais:

1. **Caso Base**: condição que interrompe a recursão
2. **Caso Recursivo**: chamada da função para uma instância menor do problema

### Estrutura Básica

```c
tipo_retorno funcao_recursiva(parametros) {
    // Caso base
    if (condicao_parada) {
        return valor_base;
    }

    // Caso recursivo
    return funcao_recursiva(parametros_reduzidos);
}
```

## 2. Exemplos de Implementações Recursivas

### 2.1 Fatorial

O fatorial de um número n (representado por n!) é o produto de todos os números inteiros positivos menores ou iguais a n.

#### Implementação

```c
int fatorial(int n) {
    // Caso base
    if (n <= 1) return 1;

    // Caso recursivo
    return n * fatorial(n - 1);
}
```

#### Análise

- **Complexidade de Tempo**: O(n)
  - Uma chamada recursiva para cada número de n até 1
- **Complexidade de Espaço**: O(n)
  - Pilha de chamadas armazena n chamadas recursivas

### Visualização do Fatorial

<div style="text-align: center;">
    <img src="http://luizricardo.org/wordpress/wp-content/upload-files/2016/04/top-5-programming-animated-gifs_recursion-animted-gif.gif" alt="Demonstração do Fatorial" style="width: 50%;">
</div>

### 2.2 Fibonacci

A sequência de Fibonacci é definida como: F(0) = 0, F(1) = 1, e F(n) = F(n-1) + F(n-2) para n > 1.

#### Implementação Recursiva

```c
int fibonacci_recursivo(int n) {
    // Casos base
    if (n <= 1) return n;

    // Caso recursivo
    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}
```

#### Implementação Iterativa (para comparação)

```c
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
```

#### Análise

- **Versão Recursiva**:
  - Complexidade de Tempo: O(2^n)
  - Complexidade de Espaço: O(n)
- **Versão Iterativa**:
  - Complexidade de Tempo: O(n)
  - Complexidade de Espaço: O(1)

### 2.3 Maior Valor em um Vetor

Encontrar o maior valor em um vetor usando recursão.

#### Implementação

```c
int maior_valor_recursivo(int vetor[], int tamanho) {
    // Caso base
    if (tamanho == 1) return vetor[0];

    // Caso recursivo
    int maior_resto = maior_valor_recursivo(vetor, tamanho - 1);
    return (vetor[tamanho - 1] > maior_resto) ? vetor[tamanho - 1] : maior_resto;
}
```

#### Análise

- **Complexidade de Tempo**: O(n)
  - Uma chamada recursiva para cada elemento
- **Complexidade de Espaço**: O(n)
  - Pilha de chamadas armazena n chamadas recursivas

## 3. Vantagens e Desvantagens

### Vantagens

1. Código mais limpo e elegante
2. Problemas complexos podem ser divididos em subproblemas mais simples
3. Sequências com padrões recursivos são facilmente implementadas

### Desvantagens

1. Maior uso de memória devido à pilha de chamadas
2. Pode ser mais lento que soluções iterativas
3. Risco de estouro de pilha para entradas muito grandes

## 5. Dicas de Implementação

1. Sempre identifique claramente o caso base
2. Garanta que o problema seja reduzido a cada chamada recursiva
3. Evite recursão infinita verificando as condições de parada
4. Considere usar recursão de cauda quando possível
5. Para problemas complexos, desenhe a árvore de recursão

## 4. Exercícios Propostos

1. **Busca Binária Recursiva**

   - Implemente uma função recursiva para busca binária em um vetor ordenado
   - Compare sua complexidade com a versão iterativa

2. **Soma de Vetor**

   - Crie uma função recursiva que calcule a soma de todos os elementos de um vetor
   - Analise sua complexidade de tempo e espaço

3. **Torre de Hanoi**
   - Implemente a solução recursiva para o problema da Torre de Hanoi
   - Calcule o número de movimentos necessários para n discos
