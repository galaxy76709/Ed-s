/*
Torneio de tênis

A prefeitura contratou um novo professor para ensinar as crianças do bairro a jogar tênis na quadra de tênis do parque municipal. O professor convidou todas as crianças do bairro interessadas em aprender a jogar tênis. Ao final do primeiro mês de aulas e treinamentos foi organizado um torneio em que cada participante disputou exatamente seis jogos. O professor vai usar o desempenho no torneio para separar as crianças em três grupos, de forma a ter grupos de treino em que os participantes tenham habilidades mais ou menos iguais, usando o seguinte critério:

- participantes que venceram 5 ou 6 jogos serão colocados no Grupo 1;
- participantes que venceram 3 ou 4 jogos serão colocados no Grupo 2;
- participantes que venceram 1 ou 2 jogos serão colocados no Grupo 3;
- participantes que não venceram nenhum jogo não serão convidados a continuar com os treinamentos.

Dada uma lista com o resultado dos jogos de um participante, escreva um programa para determinar em qual grupo ele será colocado.

Entrada

A entrada consiste de seis linhas, cada linha indicando o resultado de um jogo do participante. Cada linha contém um único caractere: V se o participante venceu o jogo, ou P se o jogador perdeu o jogo. Não há empates nos jogos.

Saída

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define null NULL

// funcao que recebe vetor de resultados e retorna o grupo
int grupos(char s[], int tamanho) {
// var aux
    int result   = 0;
    int vitorias = 0;

// laco de repeticoa que vai de 0 a lenght - 1 
    for (int i = 0; i < tamanho; i = i + 1) {
// caso o valor na posicao de i seja igual a V -> vitoria 
        if (s[i] == 'V') {
            vitorias = vitorias + 1;
        }
    }

// printf opcional para verificar a quantidade de vitorias
// printf("%d", vitorias);

    // condicoes propostas pela atividade
    if (vitorias >= 5) {
        return 1;
    } else if (vitorias >= 3) {
        return 2;
    } else if (vitorias >= 1) {
        return 3;
    } else if (vitorias >= 0 ){
        return -1; // não será convidado a continuar
    }

    return (result); // retorna a soma do resultado (não será executado)
}

// 3 teste 
int main() {
    // declarando variaveis 
    char s[6]; // -> seis partidas 

    // Ler os 6 resultados do jogador
    for (int i = 0; i < 6; i = i + 1) {
        scanf(" %c", &s[i]); // espaço antes de %c para ignorar whitespaces
    }

    // chamada da funcao
    int grupo = grupos(s, 6);

    // condicao de verificacao de valor
    if (grupo != -1) {
        printf("%d\n", grupo);
    }

    return 0;
}
