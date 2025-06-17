/*
Duplas de tênis

Quatro amigos combinaram de jogar tênis em duplas. Cada um dos amigos tem um nível de jogo, que é representado por um número inteiro: 
quanto maior o número, melhor o nível do jogador.

Os quatro amigos querem formar as duplas para iniciar o jogo. De forma a tornar o jogo mais 
interessante, eles querem que os níveis dos dois times formados sejam o mais próximo possível. 
O nível de um time é a soma dos níveis dos jogadores do time.
primeiro time =  3 +  7 = 10 
segundo time =  10 + 20 = 30

Embora eles sejam muito bons jogadores de tênis, os quatro amigos
não são muito bons em algumas outras coisas, como lógica ou matemática. Você pode ajudá-los e 
encontrar a menor diferença possível entre os níveis dos times que podem ser formados?

Entrada

A entrada contém quatro linhas, cada linha contendo um inteiro A, B, C e D, indicando o nível de jogo dos quatro amigos.

Saída

Seu programa deve produzir uma única linha, contendo um único inteiro, a menor diferença entre os níveis dos dois times formados. 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define null NULL

// Funcao para calcular a menor diferenaca entre as duplas

int last_diference (int A, int B, int C, int D) {
// primeria exprecao: ( A + B ) - ( C + D )
    int soma1 = (A + B) - (C + D);
    if (soma1 < 0) soma1 = -soma1;

// segunda exprecao: ( A + C ) - ( B + D )
    int soma2 = (A + C) - (B + D);
    if (soma2 < 0) soma2 = -soma2;

// terceira exprecao: ( A + D ) - ( B + C )
    int soma3 = (A + D) - (B + C);
    if (soma3 < 0) soma3 = -soma3;

// quarta exprecao ( retornar o menor valor )
    int menor = soma1;
    if (soma2 < menor) menor = soma2;
    if (soma3 < menor) menor = soma3;

// retorno do menor valor
    return menor;
}

int main() {
// iniciando variaveis 
    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;

// Leitura das variaveis 
    scanf("%d", &A);
    getchar();

    scanf("%d", &B);
    getchar();

    scanf("%d", &C);
    getchar();

    scanf("%d", &D);
    getchar();


// saida da menor diferenca
    printf("%d\n", last_diference ( A, B, C, D ));

    return 0;
}
