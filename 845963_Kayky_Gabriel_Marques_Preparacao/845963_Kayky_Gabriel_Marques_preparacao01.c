
/*
   preparacao_01 - v0.0. - 07 / 04 / 2025
   Author: Kayky_Gabriel_Marques

   Para compilar em terminal (janela de comandos):
   Linux      : gcc -o preparacao_01         preparacao_01.c
   Windows: gcc -o  preparacao_01         preparacao_01.c

   Para executar em terminal (janela de comandos):
   Linux      :  ./preparacao_01
   Windows:     preparacao_01
 */
// dependencias
#include "io.h"     // para definicoes proprias
#include <stdio.h>  // biblioteca de apoio
#include <stdlib.h> // biblioteca de apoio
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define My_pi 3.14159
#define Max   100

//---------------------
double radius_of_a_circle(double ray, double division, bool one_call) {
   if (one_call) {
       IO_id("funcao radius_of_a_circle - Method01 - v1.0");
   }

   double result = 0.0;

   // Verificar se ray e division sao validos
   if (ray != 0.0 && division != 0.0) {
       result = (2.0 * My_pi * ray) / division;
   }

   return result;
}
//---------------------


//---------------------
/**
  Method_01 - calcula o perímetro dividido por um valor.
*/
//---------------------
void method_01(void) {
   IO_id("PREPARACAO - Method01 - v2.0");

   // declarando variavel 
   double ray      = 0.0;
   double division = 0.0;

   // atribuindo valor as variaveis
   IO_printf("Digite o raio: \n");
   IO_scanf("%lf", &ray);  

   IO_printf("Digite o divisor: \n");
   IO_scanf("%lf", &division);  

   // chamada da funcao
   double result = radius_of_a_circle(ray, division, true);

   //mostrando o valor 
   IO_printf("O perimetro (2 pi r) dividido por %lf e: %f\n", division, result);

//
   // end method 01
   IO_pause("Apertar ENTER para continuar");
}//---------------------




//---------------------
/**
  first < middel < final 
  a      b        c
*/
//---------------------
bool logic ( char first, char middle, char last ){
   // identificar
   
      IO_id("funcao  - Method02 - v1.0");

      // variavel auxilicar para verificacao 
      bool is_true = (first < middle) && (middle < last);


         return is_true;
} 


void pass (int numbers ) {
   // declarando variaveis 
   char  first_letter    = '  ';
   char  middle_letter   = '  ';
   char  last_letter     = '  ';
   int   count           =   0 ; // - > funcoa para auxilio no while 

   // loop de repeticao para parar o funcionamento da funcao 
   while (count < numbers  ){


      //  iniciando variaveis 
      IO_printf ("Valor do primeiro caractere  %c.\n");
      IO_scanf (" %c", &first_letter );
    

      IO_printf ("Valor do segundo caractere  %c.\n");
      IO_scanf (" %c", &middle_letter );

      IO_printf ("Valor do terceiro caractere  %c.\n");
      IO_scanf (" %c", &last_letter );

        // verifiacao apos a leitura
        /*
        IO_printf("primeiro do teste: %c\n",  first_letter);
        IO_printf("segundo do teste:  %c\n", middle_letter);
        IO_printf("terceito do teste: %c\n ",  last_letter);
         */

   // chamada da funcao para verificacao 
   bool result = logic(first_letter, middle_letter, last_letter);

   if (  result   ) {
       IO_printf("Os digitos estao em ordem.\n");

   } else {

       IO_printf("Os digitos nao estao em ordem.\n");
   }

   count = count + 1;
   }

}



//---------------------
/**
  Method_02 - calcula o perímetro dividido por um valor.
*/
//---------------------
void method_02(void) {
   IO_id("PREPARACAO - Method02 - v2.0");

   // declarando variavel 
   int   numbers         =  0 ;

   // iniciando os valores 
   IO_print("Digite o valor de vezes que sera repetido o teste. \n");
   IO_scanf ("%d", &numbers);   

   //chamada da funcao 
   pass ( numbers );


//
   // end method 02
   IO_pause("Apertar ENTER para continuar");
}//---------------------


/*
funcao auxiliar para verificar se o numero esta dentro do vetor

*/                 
int is_on_brake (int A, int B, int number){
// inicio de loop recursivo 

return (number >= A && number < B);

}


//---------------------
/**
  Method_02 - calcula o perímetro dividido por um valor.
*/
//---------------------
void method_03(void) {
   IO_id("PREPARACAO - Method03 - v2.0");

   // declarando variavel 
   int   numbers          =  0 ;
   int   closed           =  0 ;
   int   open             =  0 ;
   int   value            =  0;


   // iniciando os valores 
   IO_print("Digite o valor de vezes que sera repetido o teste. \n");
   IO_scanf ("%d", &numbers);   

   IO_print("Digite o valor do primero intevalor [ fechado ]. \n");
   IO_scanf ("%d", &closed);   

    IO_print("Digite o valor do segundo intevalor ( aberto ). \n");
    IO_scanf ("%d", &open);   

    // inicio do laco de repeticao 
   for (int i = 0; i < numbers; i = i + 1){
      IO_printf("\n Digite o valor %d.\n", i + 1 );
      IO_scanf("%d", &value);

   if(is_on_brake (closed, open, value)){

      if (value % 2 == 0 ){ // condicao de par
         int dobro = value * 2;
         int half = value / 2;

         if (is_on_brake(closed, open, dobro) && is_on_brake(closed, open, half)){
            IO_printf("\n O valor [%d] esta dentro do intervalo\n", value);
         }

      } else {
         
      }
   }

} // end for 


//
   // end method 03
   IO_pause("Apertar ENTER para continuar");
}//---------------------





#include "io.h" // Biblioteca personalizada assumida com IO_printf, IO_scanf, etc.

// Funções lógicas auxiliares
int is_upper(char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int is_space(char c) {
    return (c == ' ');
}

int is_alphanumeric(char c) {
    return (is_upper(c) || is_lower(c) || is_digit(c) || is_space(c));
}


// Procedimento 04
void method_04(void) {
    IO_id("EXEMPLO0504 - Method_04 - v0.0");

    char texto[80];
    int contador = 0;

    IO_print("Digite uma cadeia de caracteres:\n");
    fgets(texto, 79, stdin); // le ate 78 caracteres + '\0'

    int tamanho = 0;
    while (texto[tamanho] != '\0') {
        tamanho++;
    }

    for (int i = tamanho - 1; i >= 0; i--) {
        if (is_alphanumeric(texto[i])) {
            contador++;
        }
    }

    IO_printf("Total de simbolos alfanumericos (letras, digitos e espacos): %d\n", contador);

    IO_pause("Apertar ENTER para continuar");
}


// Função recursiva para contar símbolos alfanuméricos
int contar_alfanumericos(char texto[], int index) {
   if (index < 0) {
       return 0;
   }

   if (is_alphanumeric(texto[index])) {
       return 1 + contar_alfanumericos(texto, index - 1);
   } else {
       return contar_alfanumericos(texto, index - 1);
   }
}

// Procedimento 05
void method_05(void) {
   IO_id("EXEMPLO0505 - Method_05 - v0.0");

   char texto[80];

   IO_print("Digite uma cadeia de caracteres:\n");
   fgets(texto, 79, stdin); // le ate 78 caracteres + '\0'

   int tamanho = 0;
   while (texto[tamanho] != '\0') {
       tamanho++;
   }

   int resultado = contar_alfanumericos(texto, tamanho - 1);

   IO_printf("Total de simbolos alfanumericos (letras, digitos e espacos): %d\n", resultado);

   IO_pause("Apertar ENTER para continuar");
}









/* 
  Funcao principal. 
  @return codigo de encerramento 
  @param argc - quantidade de parametros na linha de comandos 
  @param argv - arranjo com o grupo de parametros na linha de comandos 
*/ 
int main ( int argc, char* argv [ ] ) 
{ 
 // definir dado 
    int opcao = 0 ;
 
 // identificar 
    IO_printf ( "%s\n", "Exemplo0100 - Programa = v0.0" ) ; 
    IO_printf ( "%s\n", "Autor: Kayky Gabeil Marques" ); 
    IO_printf ( "\n" ); // mudar de linha 
 
 // acoes 
 
 // repetir 
    do 
    { 
     // para mostrar opcoes 
        printf ( "\n%s\n", "Opcoes:"          ); 
        printf ( "\n%s"   , "0 - Terminar"    ); 
        printf ( "\n%s"   , "1 - Method_01" ); 
        printf ( "\n%s"   , "2 - Method_02" ); 
        printf ( "\n%s"   , "3 - Method_03" ); 
        printf ( "\n%s"   , "4 - Method_04" ); 
        printf ( "\n%s"   , "5 - Method_05" ); 
        printf ( "\n" ); 
 
     // ler a opcao do teclado 
        printf  ( "\n%s", "Opcao = " ); 
        scanf  ( "%d", &opcao ); 
        getchar( );  // para limpar a entrada de dados 
 
     // para mostrar a opcao lida 
        printf  ( "\n%s%d", "Opcao = ", opcao ); 
 
 
 
 
 
 
 
 
 
    // escolher acao dependente da opcao 
        switch ( opcao ) 
        { 
          case   0:  /* nao fazer nada */      break; 
          case   1:     method_01 ( );         break; 
          case   2:     method_02 ( );         break; 
          case   3:     method_03 ( );         break; 
          case   4:     method_04 ( );         break; 
          case   5:     method_05 ( );         break; 
          default: // comportamento padrao 
                           printf ( "\nERRO: Opcao invalida.\n" ); 
                           break; 
        } // end switch 
    } 
    while ( opcao != 0 ); 
 
 // encerrar 
    printf    ( "\n\nApertar ENTER para terminar." ); 
    getchar( );  // aguardar por ENTER 
    return   ( 0 ); // voltar ao SO (sem erros) 
} // end main ( ) 
 
/*   
---------------------------------------------- documentacao complementar 
 
---------------------------------------------- notas / observacoes / comentarios 
 
 
---------------------------------------------- previsao de testes 
 
a.) a 
b.) 4.2 
c.) 10 
d.) 1 
e.) abc def 
f .) abc def 
*/