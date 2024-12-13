# Recursividade em C

## Introdução

A **recursividade** é um conceito fundamental na programação onde uma função resolve um problema chamando a si mesma com uma instância menor do mesmo problema. Este documento explora implementações recursivas em C, acompanhadas de uma análise de complexidade.

Muitos problemas computacionais possuem a característica de que cada instância do problema contém uma instância menor do mesmo problema, o que é denominado **estrutura recursiva**. Em outras palavras, problemas que podem ser quebrados em subproblemas menores, com a solução dos subproblemas levando à solução do problema original.

A técnica para resolver problemas com estrutura recursiva segue uma metodologia bastante clara:

1. Se a instância do problema for **pequena o suficiente**, resolva-a diretamente. Esse é o **caso-base**.
2. Se a instância for maior, reduza-a a uma instância menor (geralmente chamando a função recursivamente) e depois resolva essa instância menor. Após isso, combine as soluções das instâncias menores para resolver o problema original. Este é o **caso-recursivo**.

### Importância do Caso-Base e Caso-Recursivo

Para que um algoritmo recursivo tenha solução e não entre em um **loop infinito**, é fundamental que exista um **caso-base**, que é o momento em que o problema se torna simples o suficiente para ser resolvido diretamente, sem a necessidade de mais chamadas recursivas. Sem isso, a função continuaria chamando a si mesma indefinidamente, sem nunca chegar a uma solução.

Somente após resolver o **caso-base**, podemos aplicar a recursão para reduzir o problema a uma instância menor (o **caso-recursivo**) e, a partir daí, construir a solução do problema original.

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

Por exemplo, o cálculo de fatorial (`n!`) é um problema clássico que possui uma estrutura recursiva. A fórmula recursiva é:

- Caso-base: `fatorial(0) = 1`
- Caso-recursivo: `fatorial(n) = n * fatorial(n - 1)`

### Exemplo de Implementação Recursiva em C

```c
#include <stdio.h>

int fatorial(int n) {
    if (n == 0) { // Caso-base
        return 1;
    } else { // Caso-recursivo
        return n * fatorial(n - 1);
    }
}

int main() {
    int num = 5;
    printf("Fatorial de %d é %d\n", num, fatorial(num));
    return 0;
}
```

### Visualização do Fatorial

<div style="text-align: center;">
    <img src="http://luizricardo.org/wordpress/wp-content/upload-files/2016/04/top-5-programming-animated-gifs_recursion-animted-gif.gif" alt="Demonstração do Fatorial" style="width: 50%;">
</div>

### Análise de Complexidade

A análise de complexidade de uma função recursiva envolve entender quantas vezes a função será chamada até atingir o **caso-base**. No exemplo do cálculo do fatorial, a função se chama recursivamente `n` vezes, uma vez para cada número de `n` até chegar a `0`. Assim, a complexidade de tempo dessa função é **O(n)**, pois ela faz `n` chamadas recursivas.

Além disso, a recursão usa a pilha de chamadas para armazenar o estado de cada instância, o que implica em uma **complexidade de espaço** também de **O(n)**, pois cada chamada recursiva precisa ser armazenada até que o caso-base seja atingido e a pilha seja desempilhada.

## 2. Analisando o algoritmo de Fibonacci

### 2.1 Fibonacci

A sequência de **Fibonacci** é uma das sequências numéricas mais conhecidas e é definida pela relação recursiva:

- **F(0) = 0**
- **F(1) = 1**
- **F(n) = F(n-1) + F(n-2)** para **n > 1**

Isso significa que, a partir do terceiro número, cada termo é a soma dos dois termos anteriores. A sequência começa assim:

```
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
```

Essa sequência tem diversas aplicações, como em algoritmos de programação dinâmica, modelagem de populações e até na natureza, como o arranjo das folhas nas plantas ou o formato da concha de alguns moluscos.

#### Implementação Recursiva

Uma maneira intuitiva de calcular o **n-ésimo** número da sequência de Fibonacci é através de uma função recursiva. O código abaixo mostra uma implementação recursiva simples dessa sequência:

```c
int fibonacci_recursivo(int n) {
    // Casos base
    if (n <= 1) return n;

    // Caso recursivo
    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}
```

### Explicação do Código

1. **Casos Base**:

   - Quando `n` é igual a 0 ou 1, retornamos o valor de `n` diretamente, pois esses são os primeiros dois números da sequência. Estes casos são chamados de **casos base** e são fundamentais para evitar que a função entre em um loop infinito de chamadas recursivas. No caso de `n = 0`, retornamos 0, e no caso de `n = 1`, retornamos 1.

   ```c
   if (n <= 1) return n;
   ```

2. **Caso Recursivo**:

   - Quando `n > 1`, a função chama a si mesma recursivamente para calcular **F(n-1)** e **F(n-2)**. Isso é feito com a expressão:

   ```c
   return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
   ```

   - Esse processo se repete até que `n` atinja 0 ou 1, momento em que os casos base são acionados e as chamadas recursivas começam a retornar e somar os valores, gerando o número desejado de Fibonacci.

### Complexidade de Tempo

A complexidade de tempo da implementação recursiva de Fibonacci é **O(2^n)**, devido à **exponenciação** do número de chamadas recursivas. Para cada chamada de `fibonacci_recursivo(n)`, são feitas duas chamadas recursivas (uma para `n-1` e uma para `n-2`). Isso cria uma árvore de chamadas, onde o número de operações cresce exponencialmente conforme o valor de `n` aumenta.

Por exemplo, para calcular `F(5)`, temos:

- `F(5)` chama `F(4)` e `F(3)`
- `F(4)` chama `F(3)` e `F(2)`
- E assim por diante, criando uma duplicação de chamadas à medida que o valor de `n` aumenta.

### Complexidade de Espaço

A complexidade de espaço também é **O(n)**, pois o número de chamadas recursivas simultâneas na pilha de execução atinge um máximo de `n` no caso mais profundo da recursão. Ou seja, o máximo de memória ocupada pela pilha de chamadas é proporcional a `n`.

### Problemas com a Implementação Recursiva

Embora a implementação recursiva seja elegante e fácil de entender, ela não é eficiente para números grandes de Fibonacci devido à repetição de cálculos. Por exemplo, ao calcular `F(5)`, as chamadas para `F(3)` e `F(2)` são feitas múltiplas vezes. Isso leva a um grande número de chamadas redundantes.

Para melhorar a eficiência, pode-se usar **memoização** ou a abordagem **iterativa**, onde os resultados parciais são armazenados para evitar cálculos repetidos.

#### Exemplo de Implementação Iterativa (Otimizada)

Uma forma mais eficiente de calcular Fibonacci é utilizando uma abordagem iterativa, que tem **complexidade O(n)** tanto em tempo quanto em espaço:

```c
int fibonacci_iterativo(int n) {
    if (n <= 1) return n;

    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}
```

Nesse caso, não há chamadas recursivas e o valor de Fibonacci é calculado de forma sequencial, armazenando apenas os dois valores anteriores à medida que o cálculo avança, tornando a solução muito mais eficiente em termos de tempo e espaço.

### Conclusão

A **sequência de Fibonacci** é um exemplo clássico de um problema que pode ser resolvido de maneira recursiva, mas a implementação recursiva simples pode ser ineficiente para valores grandes devido à duplicação de cálculos. A implementação iterativa ou com memoização é preferível em casos onde a eficiência é necessária.

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
