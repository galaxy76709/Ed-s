/*Zero para cancelar

Seu chefe está ao telefone, nervoso. Ele quer que você compute a soma de uma sequência de números que ele vai falar para você ao telefone, para saber o total das vendas em sua mais recente viagem de negócios.
Infelizmente, de vez em quando seu chefe fala números errados para você ao telefone.

Felizmente, seu chefe rapidamente percebe que falou um número errado e diz "zero", que como combinado previamente quer dizer gnore o último número corrente.

Infelizmente, seu chefe pode cometer erros repetidos, e diz "zero" para cada erro.

Por exemplo, seu chefe pode falar ao telefone "Um, três, cinco, quatro, zero, zero, sete, zero, zero, seis", o que significa uma soma total igual a 7,conforme explicado na tabela abaixo:

Fala do chefe	Números correntes (após fala)	Explicação
"um, três, cinco, quatro"	1,3,5,4	registre os quatro números
"zero, zero"	1, 3	ignore os dois últimos números
"sete"	1, 3, 7	registre o sete ao final da lista
"zero, zero"	1	ignore os dois últimos números
"seis"	1, 6	registre o seis ao final da lista
Para não deixar seu chefe ainda mais nervoso, escreva um programa que determine a soma total dos números falados por seu chefe ao telefone. A soma será da lista final dos números corrigidos.

Entrada

A primeira linha da entrada contém um inteiro N, a quantidade de números inteiros (incluindo os "zeros") que o seu chefe falou ao telefone. Cada uma das N linhas seguintes contém um número inteiro Xi.

Saída

Seu programa deve produzir uma única linha na saída, contendo um único inteiro, a soma correta dos números, levando em conta que o valor 0 significa erro, conforme descrito.

*/

//Aluno: Kayky Gabriel Marques| Matricula: 845963. Aed1 Professor: Thledo Cruz
#include <stdio.h>
#include <stdlib.h>

int calcular_soma_corrigida(int length , int* sequencia) {
// iniciando variavel aux 
// alocando memoria para fazer a pilha
    int* pilha = ( int* )  malloc (  length * sizeof ( int ) ); // -> nao queria usar sizeof mas deu branco ,:(
    int topo = 0;

// laco de repeticao
    for ( int i = 0; i < length; i = i + 1 ) { 

// index do arranjo e atribuido ao number
        int number = sequencia[i];

// condicoa de verificacao caso seja igual a 0 ou menor que ( limite fisico )
        if (number == 0 && topo > 0) {

// desfaz o ultimo numero inserido
            topo = topo - 1 ; 

        } else if (number != 0) {

            pilha[topo] = number;
            topo = topo + 1;
        }
    }

// variavel aux para a soma da pilha
    int soma = 0;

    for (int i = 0; i < topo; i = i + 1 ) {
        soma += pilha[i];
    }

// reciclagem da pilha
    free   ( pilha ); 
    return ( soma  );
}


int main() {
    int N = 0 ;
    scanf("%d", &N);
    getchar();

    if (N <= 0) {
        printf("0\n");
        return 0;
    }

    int* numeros = (int*) malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &numeros[i]);
    }

    int resultado = calcular_soma_corrigida(N, numeros);
    printf("%d\n", resultado);

    free(numeros);
    return 0;
}
