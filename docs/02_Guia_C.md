# Fundamentos

## 1. Fundamentos do Pensamento Computacional

### 1.1 Conceitos Básicos

#### 1.1.1 Instruções

Uma instrução é um comando dado ao computador para executar uma tarefa específica. Para realizar um processo completo, precisamos de várias instruções organizadas em uma sequência lógica.

> 💡 Para se tornar um bom programador, é essencial desenvolver:
>
> - Lógica de programação
> - Raciocínio estruturado
> - Pensamento crítico
> - Visão sistêmica

#### 1.1.2 Algoritmo

Um algoritmo é uma sequência de passos bem definidos que resolve um problema específico. É como uma receita que detalha todas as etapas necessárias para atingir um objetivo.

#### 1.1.3 Componentes Necessários para Programação

Para criar e executar um programa em C, você precisa de:

1. **Linguagem de Programação**: O conjunto de regras e comandos que você usará para escrever o código.
2. **IDE (Ambiente de Desenvolvimento Integrado)**: Software para escrever e testar seu código.
3. **Compilador**: Ferramenta que transforma seu código fonte em código executável.
4. **Máquina Virtual/Gerador de Código**: Software que permite executar o programa.

#### 1.1.4 Tipos de Linguagens de Programação

- **Compiladas**: C, C++
- **Interpretadas**: PHP, JavaScript, Python, Ruby
- **Híbridas**: Java (JVM), C# (.NET)

## 1.2 Regras da Linguagem de Programação

### 1.2.1 Regras Léxicas

- Define a ortografia correta das palavras e símbolos.
- Exemplo:
  - ✅ `main`
  - ❌ `maim`

### 1.2.2 Regras Sintáticas

- Define como combinar palavras e símbolos.
- Exemplo:
  - ✅ `x = 2 + y`
  - ❌ `x =+ 2 y`

### 1.2.3 Regras Semânticas

- Define o significado das instruções.
- Exemplo:
  - `=` → atribuição
  - `==` → comparação de igualdade

## 2. Sobre a Linguagem C

C é uma linguagem:

- Compilada
- De propósito geral
- Estruturada
- Imperativa
- Procedural
- Criada em 1972 por Dennis Ritchie na AT&T Bell Labs
- Desenvolvida originalmente para o sistema Unix

## 3. Roteiro de Estudos

### 3.1 Conceitos Fundamentais

- Computação básica
- História do C
- Diferença entre alto e baixo nível
- Algoritmos (definição, características, complexidade)
- Processamento de dados
- Entrada/saída
- Memória (stack, heap, segmentos de memória)
- Variáveis (escopo, tempo de vida, tipos)
- Função `main()`
- Bibliotecas (header files, linking)

### 3.2 Nível Iniciante

- Tipos de dados (`int`, `float`, `double`, `char`, `void`)
- Estrutura do código (sintaxe, indentação, boas práticas)
- Declaração de variáveis (local, global)
- Entrada/saída (`printf` (formatação, especificadores), `scanf` (buffer, leitura))
- Operadores:
  - Aritméticos (`+`, `-`, `*`, `/`, `%`)
  - Relacionais (`<`, `>`, `<=`, `>=`, `==`, `!=`) e lógicos (`&&`, `||`, `!`)
  - Incremento/decremento (pré-fixado `++x`, pós-fixado `x++`)
- Números aleatórios (`rand()`, `srand()`, `time()`)
- Estruturas de controle:
  - Condicionais (`if-else` (simples, encadeado), `switch-case`)
  - Loops (`for` (contador, infinito), `while`, `do-while`)

### 3.3 Nível Intermediário

- Arrays e strings (unidimensional, multidimensional, caracteres)
- Números binários e hexadecimais (conversão, operações)
- Funções (protótipo, definição, parâmetros, retorno)
- Ponteiros (declaração, operadores, aritmética)

### 3.4 Nível Avançado

- Manipulação de arquivos (texto, binário, posicionamento)
- Estruturas:
  - `struct` (campos, alinhamento, aninhamento)
  - `union` (uso de memória, aplicações)
  - `enum` (constantes, escopo)
- Recursividade (direta, indireta, `tail recursion`)
- Diretivas de compilação (`#include`, `#define`, `#ifdef`)
- Bibliotecas principais:
  - `stdio.h` (entrada/saída padrão)
  - `stdlib.h` (funções utilitárias)
  - `math.h` (funções matemáticas)
  - `string.h` (manipulação de strings)
  - `time.h` (funções de tempo)
- Alocação dinâmica de memória (`malloc`, `calloc`, `realloc`, `free`)
- Estruturas de dados:
  - Filas (FIFO, circular, prioridade)
  - Pilhas (LIFO, operações `push/pop`)
  - Listas encadeadas (simples, dupla, circular)
  - Árvores:
    - Árvore Binária (percursos, altura, balanceamento)
    - Árvore Binária de Busca (BST) (inserção, remoção, busca)
    - Árvore AVL (rotações, fator de balanceamento)
- Algoritmos de ordenação (complexidade, estabilidade, uso de memória):
  - Métodos simples:
    - Selection Sort (O(n²), in-place)
    - Insertion Sort (O(n²), adaptativo)
    - Bubble Sort (O(n²), estável)
  - Métodos avançados:
    - Shell Sort (O(n log n), in-place)
    - Quick Sort (O(n log n), particionamento)
    - Merge Sort (O(n log n), divisão e conquista)
    - Heap Sort (O(n log n), heap binário)
- Algoritmos de busca:
  - Busca linear (O(n), sequencial)
  - Busca binária (O(log n), array ordenado)
