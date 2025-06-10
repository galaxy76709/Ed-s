
/*
   Exemplo0 1000 - v0.0. - 12 / 05 / 2025
   Author: Kayky_Gabriel_Marques

   Para compilar em terminal (janela de comandos):
   Linux      : gcc -o exemplo1000        exemplo1000.c
   Windows    : gcc -o exemplo1000        exemplo1000.c

   Para executar em terminal (janela de comandos):
   Linux      :  ./exemplo1000
   Windows:    exemplo1000
 */

//---------------------
// dependencias
    // para definicoes proprias
#include <stdio.h>  // biblioteca de apoio
#include <stdlib.h> // biblioteca de apoio
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "io.h"
//---------------------


//---------------------
/**
   Method_00 - nao faz nada.
 */
void method_00(void)
{
   // nao faz nada
   
} // end method_00 ( )
//---------------------


#include "io.h"
#include <string.h>

//-----------------------------------------
// f_01: Extrair a primeira palavra invertida
void f_01(char r[], char s[]) {
    int x = 0;
    int y = 0;
    int z = 0;
    r[0] = '\0';

    while (z < strlen(s) && s[z] == ' ') {
        z = z + 1;
    }

    y = z;
    while (y < strlen(s) && s[y] != ' ') {
        y = y + 1;
    }

    while (x < y - z) {
        r[x] = s[y - x - 1];
        x = x + 1;
    }

    r[y - z] = '\0';
}
//---------------------


//-----------------------------------------
// method_01: Testa a questao 1
void method_01() {
    char text[] = " abacate maduro barato";
    char result[100];

    IO_printf("Questao numero 1\n");
    IO_printf("Texto de entrada: \"%s\"\n", text);

    f_01(result, text);

    IO_printf("A resposta eh: \"%s\"\n", result);

    IO_pause("Apertar ENTER para continuar");
}
//-----------------------------------------



//-----------------------------------------
// f_02
int f_02(int a[], int b[], int n, int begin, int end) {
    int m = 0;
    while (0 <= begin && begin <= end && end < n )
    {
      a [ m ] = b [ begin ];

         m++  ;
      ++begin ; 

      return (m);
    }
    
}
//---------------------



//---------------------
/** 
   Method_02. 
 */ 
void method_02 ( ) 
{ 
    int a[10]; // destino
    int b[] = {2, 5, 3, 6, 1, 7, 4}; // origem
    int n = 7;
    int begin = 2, end = 5;
    int m = 0;
    int i = 0;

    IO_printf("Questao numero 2\n");
    IO_printf("Valores de entrada: ");
    for (i = 0; i < n; i++) {
        IO_printf("%d ", b[i]);
    }
    IO_printf("\n");

    m = f_02(a, b, n, begin, end);

    IO_printf("Valores copiados para o novo vetor:\n");
    for (i = 0; i < m; i++) {
        IO_printf("%d ", a[i]);
    }
    IO_printf("Resposta letra (B) \n");

 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_02 ( ) 
//---------------------


//---------------------
// p_03 Trocar linhas p e q da matriz m1 (com m linhas e n colunas)
void p_03(int p, int q, int m, int n, int m1[][10]) {
    int z = 0;

    if (0 <= p && p < n && 0 <= q && q < n) {
        for (int x = 0; x < m; x++) {
            for (int y = n - 1; y >= 0; y--) {
                z = m1[p][x];
                m1[p][x] = m1[q][x];
                m1[q][x] = z;
            }
        }
    }
}
//---------------------


//---------------------
// method_03 atualizado:
void method_03(void) {
    IO_printf("Questao numero 3\n");

    int m[3][10] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    IO_printf("Matriz original:\n");
    for (int i = 0; i < 3; i = i + 1 ) {
        for (int j = 0; j < 3; j++) {
            IO_printf("%d ", m[i][j]);
        }
        IO_printf("\n");
    }

    // chamada correta para p_03
    p_03(0, 2, 3, 3, m);

    IO_printf("Matriz apos troca:\n");
    for (int i = 0; i < 3; i = i + 1 ) {
        for (int j = 0; j < 3; j = j + 1 ) {
            IO_printf("%d ", m[i][j]);
        }
        IO_printf("Resposta letra C)\n");
    }

    IO_pause("Apertar ENTER para continuar");
}// end method_03 ( ) 
//---------------------


//---------------------
void p_04(int x, int y, int a[]) {

    if (x < y - 1) {

        a [ x ]  =  a [ x ]  +  a [ y ] ;

        p_04 ( ( x  +  y )  /  2 ,  y ,  a ) ;

    } else {

        a [ x ]  =  0 ;

    }
}
//---------------------


//---------------------
void method_04( void ) {
    int a[] = {1, 2, 3, 4, 5, 6, 7};

    IO_printf("Questao numero 4\n");

    IO_printf("Valores de entrada:\n");
    for (int i = 0; i < 7; i = i + 1 ) {
        IO_printf("%d ", a[i]);
    }
    IO_printf("\n");

    p_04(0, 6, a);

    IO_printf("Valores apos o chamado da funcao:\n");
    for ( int i = 0; i < 7; i = i + 1 ) {
        IO_printf("%d ", a[i]);
    }

    IO_printf("\nResposta letra (D)\n");

    IO_pause("Apertar ENTER para continuar");
   }
//-----------------------------------------


//---------------------
struct y  {
   int a;
   int b;
   int c;
};
//---------------------


//---------------------
void p_05 (struct y * r ) {

   int d = r -> a;
   int e = r -> c;

   if ( d < e ) {

      ( *r ).a = e;
      ( *r ).c = d;

   }

   d = r -> b;
   e = r -> c;

   if ( d < e ) {
      r -> b = e;
      r -> c = d; 
   }

   d = ( *r ).a;
   e =   r -> b;

   if ( d < e ) {
         r -> a = e;
      ( *r ).b  = d;
   }
}
//---------------------


//---------------------
void method_05(void) {
    struct y x = { .a = 2, .b = 1, .c = 3 };

    IO_printf("Questao numero 5\n");

    IO_printf("Valores de entrada:\n");
    IO_printf("a = %d, b = %d, c = %d\n", x.a, x.b, x.c);

    p_05(&x);

    IO_printf("Valores apos a funcao:\n");
    IO_printf("a = %d, b = %d, c = %d\n", x.a, x.b, x.c);

    IO_printf("\nResposta letra (C)\n");

    IO_pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
void q_06 (char s[]) {
    int i = 0;
    int j = 0;

    int space_flag = 0; // Flag para indicar se o último caractere foi espaço
    
    while ( s [ i ]  !=  '\0' ) { // vai estar lendo ate encontrar \0
    // condicao que preve um espaco 
        if (s[i] == ' ') { 

    //caso nao tenha o espaco o 
            if ( ! space_flag )  {
    // a nova string recebera o valor da mesma posicao de que esta a antiga
                s [j = j + 1 ]  =  s [ i ] ;
                space_flag = 1;
            }
        } else {
        // caso contrario, vai ignorar o espaco em branco 
            s [ j = j + 1 ] = s [ i ] ;
            space_flag = 0;
        }

        i = i + 1 ;
    }

    s [ j ]  =  '\0'; // Terminar a string corretamente
} 
//---------------------


//---------------------
void  method_06 ( void ) {
    // iniciando variavel de exemplo 
    char str[] = "   amarelo   branco   dourado   ";

    IO_printf("Antes: \"%s\"\n", str);
    
    //chamado da funcao q_06
    q_06 ( str );
    
    //mostrando resposta
    printf("Resposta: \"%s\"\n", str);

    IO_pause("Apertar ENTER para continuar");
    
}// end method_06
//---------------------


//---------------------
typedef struct {
    int l, c;
    int data[10][10];
} matriz;
//---------------------


// Funcao que monta a matriz triangular inferior
//---------------------
void q_07(matriz *m) {
    int i = 0, j = 0;
    int counter = 1;
    
    // Zerar toda a matriz primeiro
    while ( i  <  m-> l ) {
        j = 0;
        while ( j  < m-> c ) {
            m -> data [ i ] [ j ]  = 0;
            j = j + 1 ; 
        }
        i = i + 1;
    }
    
    // Preencher a triangular inferior + diagonal
    i = 0;
    while (i < m->l) {
        j = 0;
        while  ( j  <=  i  &&  j  <  m -> c )  {
            m -> data [ i ] [ j ]  =  counter  *  10  +  ( j  +  1 ) ;
            j = j + 1 ; 
        }
        counter = counter ;
        i = i + 1;
    }

    
}
//---------------------



//---------------------
void method_07() {

    matriz m;
    m.l = 3;
    m.c = 3;
    
    // Chamada para a função que monta a matriz
    q_07(&m);
    
    // Exibir a matriz resultante
    IO_printf("Matriz triangular inferior:\n");
    for ( int  i  =  0 ;  i  <  m.l ; i = i + 1) {

        for ( int  j  =  0 ;  j  <  m.c ; j = j + 1  ) {

            printf("%d\t", m.data [ i ] [ j ] );

        }
       IO_printf("\n");
    }

    IO_pause("Apertar ENTER para continuar");
    
}// end method_07
//---------------------


//---------------------
void imprimir_linha(int quantidade, FILE *arquivo) {
    int i = quantidade;
    while (i > 0) {
        fprintf(arquivo, "*");
        i = i - 1;
    }
    fprintf(arquivo, "\n");
}
//---------------------


//---------------------
void gerar_piramide(int topo, int atual, FILE *arquivo) {
    if (atual > topo) {
        return;
    }

    imprimir_linha(atual, arquivo);
    gerar_piramide(topo, atual + 1, arquivo);
    if (atual != topo) {
        imprimir_linha(atual, arquivo);
    }
}
//---------------------


//---------------------
void method_08(void) {
    FILE *arquivo = fopen("QUESTAO08.TXT", "wt");
    int n = 4;

    if (arquivo != NULL) {
        gerar_piramide( n - 1, 1, arquivo );
        fclose(arquivo);
        IO_printf("Padrao piramidal gravado no arquivo QUESTAO08.TXT\n");
    } else {
        IO_printf("Erro ao abrir o arquivo!\n");
    }

    IO_pause("Apertar ENTER para continuar");
}
//---------------------



//------------------------------------------
/*
  Funcao principal.
  @return codigo de encerramento
*/
int main()
{
   // definir dado
   int x = 0;

   // repetir até desejar parar
   do
   {
      // identificar
      IO_id("EXEMPLO0 700 - Programa - v1.5 \n");

      // ler do teclado
      IO_println("Opcoes");
      IO_println(" 0  - Method_00 parar");
      IO_println(" 1 - Questao_01.");
      IO_println(" 2 - Questao_02.");
      IO_println(" 3 - Questao_03.");
      IO_println(" 4 - Questao_04.");
      IO_println(" 5 - Questao_05.");
      IO_println(" 6 - Questao_06.");
      IO_println(" 7 - Questao_07.");
      IO_println(" 8 - Questao_08.");
      IO_println("");

      x = IO_readint("Entrar com uma opcao: ");

      // testar valor
      switch (x)
      {
         case  0:  method_00 ( );   break; 
         case  1:  method_01 ( );   break;
         case  2:  method_02 ( );   break;   
         case  3:  method_03 ( );   break;
         case  4:  method_04 ( );   break;
         case  5:  method_05 ( );   break;  
         case  6:  method_06 ( );   break;
         case  7:  method_07 ( );   break;        
         case  8:  method_08 ( );   break;
    

      default:
         IO_pause(IO_concat("Valor diferente das opcoes [0 a 10] (",
                            IO_concat(IO_toString_d(x), ")")));
      } // end switch
   } while (x != 0);

   // encerrar
   IO_pause("Apertar ENTER para terminar");
   return (0);
} // end main ( )