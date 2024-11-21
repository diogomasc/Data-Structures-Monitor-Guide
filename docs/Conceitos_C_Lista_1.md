# Guia de Conceitos e Comandos em C

## Índice

1. [Conceitos Básicos](#conceitos-básicos)
2. [Estruturas de Dados](#estruturas-de-dados)
3. [Gerenciamento de Memória](#gerenciamento-de-memória)
4. [Entrada e Saída](#entrada-e-saída)
5. [Funções das Bibliotecas](#funções-das-bibliotecas)

## Conceitos Básicos

### Tipos de Dados

- **int**: Números inteiros (ex: 1, -5, 1000)
- **float**: Números decimais (ex: 3.14, -2.5)
- **char**: Caracteres individuais (ex: 'a', '1', '@')
- **unsigned long long**: Números inteiros muito grandes e sempre positivos
- **double**: Números decimais de dupla precisão (ex: 3.141592653589793)
- **void**: Tipo sem valor, usado principalmente com ponteiros

### Operadores

#### Operadores Aritméticos
```c
int a = 10, b = 3;
int soma = a + b;      // 13
int sub = a - b;       // 7
int mult = a * b;      // 30
int div = a / b;       // 3 (divisão inteira)
int resto = a % b;     // 1 (resto da divisão)
```

#### Operadores Lógicos
```c
int x = 5, y = 10;
if (x > 0 && y < 20) { }  // AND lógico
if (x < 0 || y > 8)  { }  // OR lógico
if (!(x == y))       { }  // NOT lógico
```

### Variáveis e Ponteiros

Um ponteiro é como um "controle remoto" que aponta para um lugar na memória do computador.

<p align="center">
  <img src="https://pati.arisa.com.br/wiki/images/f/f1/Anya_int_pointer.jpg" width="300" alt="Anya pointing to int pointer">
</p>

```c
char nome[] = "Anya";     // Variável normal
char *ponteiro;           // Ponteiro do tipo char
ponteiro = nome;          // ponteiro aponta para nome
printf("%s", ponteiro);   // Mostra Anya

// Operações com ponteiros
int x = 10;
int *p = &x;             // & obtém o endereço
printf("%d", *p);        // * acessa o valor (10)
```

### Estruturas de Controle

#### if-else
```c
if (idade >= 18) {
    printf("Maior de idade");
} else if (idade >= 13) {
    printf("Adolescente");
} else {
    printf("Criança");
}
```

#### switch
```c
switch (opcao) {
    case 1:
        printf("Um");
        break;
    case 2:
        printf("Dois");
        break;
    default:
        printf("Outro");
}
```

#### Loops
```c
// for tradicional
for (int i = 0; i < 5; i++) {
    printf("%d ", i);
}

// while
int i = 0;
while (i < 5) {
    printf("%d ", i);
    i++;
}

// do-while
do {
    printf("Executa pelo menos uma vez");
} while (false);
```

### Comandos de Controle

- **continue**: Pula para a próxima iteração do loop

```c
for(int i = 0; i < 5; i++) {
    if(i == 2) continue;  // Pula quando i é 2
    printf("%d ", i);     // Mostra: 0 1 3 4
}
```

## Estruturas de Dados

### Arrays
```c
// Array unidimensional
int vetor[5] = {1, 2, 3, 4, 5};

// Array bidimensional (matriz)
int matriz[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};

// Acesso aos elementos
printf("%d", vetor[0]);      // Primeiro elemento
printf("%d", matriz[1][2]);  // Elemento na linha 1, coluna 2
```

### Lista Simplesmente Encadeada

É como um "trem" onde cada vagão (nó) está conectado ao próximo.

```c
struct No {
    int valor;          // O dado que queremos guardar
    struct No* proximo; // Ponteiro para o próximo vagão
};
```

Exemplo de criação de um nó:

```c
No *novo = (No *)malloc(sizeof(No));  // Cria um novo vagão
novo->valor = 10;                     // Coloca o valor dentro
novo->proximo = NULL;                 // Indica que é o último vagão
```

## Gerenciamento de Memória

### Stack vs Heap
```c
// Variáveis na Stack (automáticas)
int x = 10;                // Alocada na stack
int vetor[5];             // Array na stack

// Variáveis no Heap (dinâmicas)
int *p = malloc(sizeof(int));   // Alocada no heap
int *v = calloc(5, sizeof(int)); // Array no heap
```

### malloc (Memory Allocation)

Reserva um espaço na memória:

```c
char *nome = (char *)malloc(50 * sizeof(char));  // Reserva espaço para 50 caracteres
```

### realloc (Reallocate)

Aumenta ou diminui um espaço já reservado:

```c
nomes = (char **)realloc(nomes, quantidade * sizeof(char *));  // Redimensiona o array
```

### free

Libera a memória que não precisamos mais:

```c
free(nome);  // Devolve a memória para o sistema
```

### sizeof

Diz o tamanho de um tipo ou estrutura em bytes:

```c
sizeof(int)     // Geralmente 4 bytes
sizeof(char)    // Sempre 1 byte
sizeof(struct No)  // Tamanho total da estrutura
```

## Entrada e Saída

### Printf Formatado
```c
int x = 10;
float f = 3.14;
char c = 'A';
char str[] = "Hello";

printf("Inteiro: %d\n", x);         // Inteiro: 10
printf("Float: %.2f\n", f);         // Float: 3.14
printf("Char: %c\n", c);            // Char: A
printf("String: %s\n", str);        // String: Hello
printf("Hex: %x\n", x);            // Hex: a
```

### Scanf Seguro
```c
int num;
char str[50];

// Leitura segura de números
if (scanf("%d", &num) != 1) {
    printf("Erro na leitura\n");
}

// Leitura segura de strings
if (scanf("%49s", str) != 1) {
    printf("Erro na leitura\n");
}
```

### Leitura de Strings

```c
// fgets: Lê uma linha inteira com segurança
fgets(nome, 100, stdin);  // Lê até 99 caracteres ou até encontrar \n

// Removendo o \n do final
nome[strcspn(nome, "\n")] = 0;  // Substitui \n por \0

// getchar: Limpa o buffer de entrada
getchar();  // Remove caracteres extras deixados por scanf
```

## Funções das Bibliotecas

### stdlib.h

- **malloc**: Aloca memória
- **realloc**: Realoca memória
- **free**: Libera memória
- **exit**: Termina o programa
- **atoi**: Converte string para int
- **atof**: Converte string para float

### string.h

- **strcpy**: Copia uma string
- **strlen**: Retorna tamanho da string
- **strcmp**: Compara strings
- **strcat**: Concatena strings
- **strcspn**: Encontra primeira ocorrência de caractere

### Exemplos Práticos

#### Alocação Dinâmica de Matriz de Strings

```c
// Aloca array de ponteiros para strings
char **nomes = (char **)malloc(quantidade * sizeof(char *));

// Aloca cada string individualmente
for(int i = 0; i < quantidade; i++) {
    nomes[i] = (char *)malloc(100 * sizeof(char));
}
```

#### Manipulação de Lista Encadeada

```c
// Criando novo nó
No *novo = (No *)malloc(sizeof(No));
novo->valor = 10;
novo->proximo = NULL;

// Inserindo no final da lista
if(lista == NULL) {
    lista = novo;
} else {
    No *atual = lista;
    while(atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
}
```

#### Leitura Segura de Strings

```c
char nome[100];
fgets(nome, 100, stdin);     // Lê a string
getchar();                   // Limpa o buffer
nome[strcspn(nome, "\n")] = 0;  // Remove o \n
```

Este guia serve como referência para os conceitos fundamentais de programação em C, com foco especial nas estruturas e comandos mais utilizados em nossos exercícios. Cada seção foi organizada de forma progressiva, do mais básico ao mais avançado, permitindo um aprendizado gradual e consistente.
