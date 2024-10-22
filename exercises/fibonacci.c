#include <stdio.h>

/*
A Sequência de Fibonacci é uma sequência numérica em que cada número
é a soma dos dois números anteriores, começando normalmente com 0 e 1.
Os primeiros números da sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
Essa sequência é frequentemente encontrada na natureza e tem aplicações em
diversas áreas como matemática, ciência da computação e arte.
*/

// Função recursiva para calcular o número de Fibonacci
int fibonacci(int n) {
    // Uso do if ternário para verificar se n é 0 ou 1
    // Se n <= 1, retorna n (caso base)
    // Caso contrário, chama a função recursivamente
    return (n <= 1) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int numero, i;

    // Solicitação do valor ao usuário
    printf("Até que valor quer imprimir a sequencia de Fibonacci? ");
    scanf("%d", &numero);

    // Exibe a sequência de Fibonacci até o número informado
    printf("Sequencia de Fibonacci ate %d: ", numero);
    for (i = 0; i <= numero; i++) {
        // Chama a função fibonacci para cada valor de i e imprime o resultado
        printf("%d ", fibonacci(i));
    }

    return 0;
}
