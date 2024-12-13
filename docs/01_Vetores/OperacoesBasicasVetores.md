# Operações Básicas em Vetores

## Introdução

Os **vetores**, ou **arrays**, são estruturas de dados fundamentais que armazenam uma sequência de elementos do mesmo tipo em posições consecutivas da memória RAM. Essa característica permite o **acesso aleatório** aos elementos, ou seja, qualquer elemento do vetor pode ser acessado diretamente sem a necessidade de percorrer os elementos anteriores. Por exemplo, é possível acessar diretamente o décimo elemento de um vetor sem precisar passar pelo primeiro, segundo ou qualquer outro elemento anterior. Essa propriedade é amplamente explorada em diversas aplicações computacionais, conforme destacado por Cormen et al. (2009).

Para armazenar uma sequência de números inteiros, um vetor pode ser declarado em C utilizando a seguinte sintaxe:

```c
int v[N];
```

Nesse caso, `N` é uma constante que determina o tamanho máximo do vetor. Os elementos são armazenados em posições indexadas que variam de `0` a `(N - 1)`. Assim, o vetor pode ser representado como `v[0..(N - 1)]`.

O estado do vetor pode variar de acordo com a quantidade de elementos armazenados:

- **Vazio**: Quando `n == 0`, o vetor não contém nenhum elemento.
- **Parcialmente preenchido**: Quando `0 < n < N`, o vetor possui alguns elementos ocupando suas posições iniciais.
- **Cheio**: Quando `n == N`, todas as posições do vetor estão ocupadas.

Por exemplo, considere um vetor `v` com capacidade para armazenar até `N` números inteiros. Se o vetor for declarado como `int v[N]`, ele ocupará na memória um espaço correspondente ao armazenamento de `N` elementos consecutivos. Dessa forma, o vetor pode ser usado para organizar e manipular dados de maneira eficiente, facilitando operações como busca, inserção e exclusão, cujas implementações serão analisadas em detalhes mais adiante, junto com a complexidade associada a cada operação.

## 1. Busca em Vetor

A busca é uma operação fundamental que consiste em encontrar a posição de um elemento específico no vetor.

### Implementação

```c
int buscaElemento(int elemento, int vetor[], int tamanho) {
    for(int indice = tamanho - 1; indice >= 0; indice--) {
        if(vetor[indice] == elemento) {
            return indice;  // Retorna o índice onde o elemento foi encontrado
        }
    }
    return -1;  // Retorna -1 se o elemento não foi encontrado
}
```

### Análise

- **Complexidade de Tempo**: O(n)
  - No pior caso, precisamos verificar todos os elementos
  - No melhor caso (elemento encontrado na última posição), O(1)
- **Complexidade de Espaço**: O(1)
  - Usa apenas variáveis simples, independente do tamanho do vetor

## 2. Adição de Elemento

Adicionar um elemento a um vetor envolve colocá-lo na primeira posição disponível.

### Implementação

```c
int adicionaElemento(int elemento, int vetor[], int *tamanho, int capacidade) {
    if (*tamanho >= capacidade) return 0;  // Vetor está cheio
    vetor[*tamanho] = elemento;  // Adiciona o elemento na primeira posição disponível
    (*tamanho)++;
    return 1;  // Adição bem sucedida
}
```

### Análise

- **Complexidade de Tempo**: O(1)
  - Adiciona o elemento diretamente na posição final
- **Complexidade de Espaço**: O(1)
  - Usa apenas variáveis simples

## 3. Remoção de Elemento

A remoção de um elemento envolve não apenas removê-lo, mas também reorganizar o vetor para manter os elementos contíguos.

### Implementação

```c
int removeElemento(int elemento, int vetor[], int *tamanho) {
    int posicao = buscaElemento(elemento, vetor, *tamanho);
    if(posicao == -1) return 0;  // Elemento não encontrado

    // Desloca elementos à direita de posicao uma posição para a esquerda
    for(int indice = posicao; indice < *tamanho - 1; indice++) {
        vetor[indice] = vetor[indice + 1];
    }
    (*tamanho)--;  // Reduz o tamanho do vetor
    return 1;  // Remoção bem sucedida
}
```

### Análise

- **Complexidade de Tempo**: O(n)
  - O(n) para buscar o elemento
  - O(n) para deslocar os elementos após a remoção
- **Complexidade de Espaço**: O(1)
  - Usa apenas variáveis simples

## 4. Impressão de Vetor

Imprimir um vetor consiste em exibir todos os seus elementos sequencialmente.

### Implementação

```c
void imprimeVetor(int vetor[], int tamanho) {
    for(int indice = 0; indice < tamanho; indice++) {
        printf("%d ", vetor[indice]);
    }
    printf("\n");
}
```

### Análise

- **Complexidade de Tempo**: O(n)
  - Precisamos percorrer todos os elementos do vetor
- **Complexidade de Espaço**: O(1)
  - Usa apenas variáveis simples

## 5. Inserção de Múltiplos Elementos

Esta função permite ao usuário inserir vários elementos no vetor enquanto desejar.

### Implementação

```c
int inserir(int posicao, int vetor[], int tamanho, int capacidade) {
    int elemento, resp, i;
    printf("Elementos do vetor:\n");
    for(i = posicao; i < capacidade; i++) {
        printf("Informe o %dº elemento: ", i + 1);
        scanf("%d", &elemento);
        vetor[i] = elemento;
        printf("Deseja inserir novo elemento? 1-Sim 2-Não\n");
        scanf("%d", &resp);
        if(resp == 2) break;
    }
    return i + 1;
}
```

## 6. Inversão de Vetor

A inversão consiste em trocar a ordem dos elementos do vetor, de modo que o primeiro elemento se torne o último, o segundo se torne o penúltimo, e assim por diante.

Podemos demonstrar a importância da inversão de vetores complementando o texto com exemplos de **casos reais onde a inversão é útil**. Veja uma possível reformulação:

Isso pode parecer desnecessário, mas pode ser importante em alguns algoritmos, como em situações onde precisamos processar os dados em ordem inversa. Alguns exemplos incluem:

- **Reversão de strings**: Quando uma string é armazenada como vetor de caracteres, inverter os elementos pode ser necessário, como em algoritmos de palíndromos ou na conversão de números para diferentes bases numéricas.
- **Transformação de dados**: Em algumas aplicações de processamento de sinais ou gráficos, os vetores precisam ser invertidos para representar simetrias ou reordenar dados.
- **Cálculo em estruturas temporais**: Em algoritmos que trabalham com dados temporais (ex.: séries temporais), pode ser útil inverter os elementos para realizar cálculos do final para o início, como no caso de previsões ou análises retrospectivas.
- **Ordenação inversa para exibição**: Em contextos como exibição de logs, mensagens ou histórico, pode ser necessário inverter a ordem para mostrar os dados do mais recente ao mais antigo.
- **Manipulação de pilhas simuladas com vetores**: Em algumas implementações, pode-se inverter um vetor para representar diretamente o comportamento de uma pilha (estrutura LIFO).

Esses exemplos mostram que, embora a inversão de um vetor possa parecer trivial, ela desempenha um papel importante em várias áreas da computação prática.

### Implementação

```c
void inverteVetor(int vetor[], int tamanho) {
    int temporario;
    for(int indice = 0; indice < tamanho / 2; indice++) {
        temporario = vetor[indice];
        vetor[indice] = vetor[tamanho - 1 - indice];
        vetor[tamanho - 1 - indice] = temporario;
    }
}
```

### Análise

- **Complexidade de Tempo**: O(n/2) = O(n)
  - Precisamos trocar metade dos elementos
- **Complexidade de Espaço**: O(1)
  - Usa apenas uma variável auxiliar

## Considerações Importantes

1. **Eficiência vs Simplicidade**

   - As implementações apresentadas priorizam a simplicidade
   - Existem versões mais eficientes para casos específicos

2. **Gerenciamento de Memória**

   - Em C, o programador é responsável por garantir que não há acesso fora dos limites do vetor
   - O tamanho do vetor deve ser sempre controlado

3. **Casos Especiais**
   - Vetor vazio (tamanho = 0)
   - Vetor com um único elemento (tamanho = 1)
   - Elemento não encontrado na busca
   - Remoção do último elemento

## Demonstração

Vamos demonstrar o uso das funções com um vetor de tamanho 10:

```c
#include <stdio.h>

#define TAM 10

int main() {
    int vetor[TAM];
    int tamanhoVetor = 0; // Inicializa o tamanho do vetor com 0 para acompanhar o número de elementos adicionados

    adicionaElemento(5, vetor, &tamanhoVetor, TAM);
    adicionaElemento(10, vetor, &tamanhoVetor, TAM);
    adicionaElemento(15, vetor, &tamanhoVetor, TAM);

    printf("Vetor após inserções: ");
    imprimeVetor(vetor, tamanhoVetor);

    inverteVetor(vetor, tamanhoVetor);
    printf("Vetor após inversão: ");
    imprimeVetor(vetor, tamanhoVetor);

    removeElemento(10, vetor, &tamanhoVetor);
    printf("Vetor após remoção: ");
    imprimeVetor(vetor, tamanhoVetor);

    int valorProcurado = 5;
    int resultadoBusca = buscaElemento(valorProcurado, vetor, tamanhoVetor);

    if (resultadoBusca != -1) {
        printf("Valor %d encontrado na posição: %d\n", valorProcurado, resultadoBusca);
    } else {
        printf("Valor %d não encontrado!\n", valorProcurado);
    }

    return 0;
}
```

## Explicação sobre o uso de `tamanhoVetor`

A variável `tamanhoVetor` é inicializada com 0 para indicar que o vetor está vazio no início. Isso é importante porque utilizamos `tamanhoVetor` para controlar quantos elementos estão atualmente no vetor. Como estamos utilizando um ponteiro para `tamanhoVetor`, podemos modificar o valor dessa variável dentro de funções, permitindo um gerenciamento dinâmico do tamanho do vetor durante as operações de adição e remoção.

## Exercícios Propostos

1. **Modificação da Busca**

   - Implemente uma versão da busca que retorna a primeira ocorrência do elemento
   - Implemente uma versão que conta quantas vezes um elemento aparece no vetor

2. **Otimização da Remoção**

   - Modifique a função de remoção para remover todas as ocorrências de um elemento
   - Implemente uma versão que remove elementos sem manter a ordem original

3. **Inserção Ordenada**
   - Crie uma função que insere um elemento em um vetor mantendo-o ordenado
   - Analise a complexidade desta operação
