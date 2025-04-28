
/*
   Exemplo0 400 - v0.0. - 13 / 03 / 2025
   Author: Kayky_Gabriel_Marques

   Para compilar em terminal (janela de comandos):
   Linux      : gcc -o exemplo0200        exemplo0200.c
   Windows: gcc -o exemplo0200        exemplo0200.c

   Para executar em terminal (janela de comandos):
   Linux      :  ./exemplo0200
   Windows:    exemplo0200
 */
// dependencias
#include "io.h"     // para definicoes proprias
#include <stdio.h>  // biblioteca de apoio
#include <stdlib.h> // biblioteca de apoio
#include <string.h>
#include <math.h>
#include <stdbool.h>


//---------------------
/**
   Method_00 - nao faz nada.
 */
void method_00(void)
{
   // nao faz nada
   
} // end method_00 ( )
//---------------------


//---------------------
/** 
   just_four - Gravar em arquivo texto certa quantidade de valores multiplos de 4. 
   @param fileName - nome do arquivo 
   @param x        - quantidade de valores 
 */ 
void just_four ( chars fileName, int x ) // chamando a funcao para ler o arquivo
{ 
 // definir dados 
    FILE* arquivo = fopen ( fileName, "wt" );  
    int y = 0; 

    // como a atividade pede para que comecar com o valor de 4 portanto, inicializando ele sera com 4
    int aux = 4;
 
 // repetir para a quantidade de dados 
    for ( y = 1; y <= x; y = y + 1 ) 
    { 
     // gravar valor 

        fprintf ( arquivo, "%d\n", aux );
        aux = aux + aux; 

    } // end for 
 
 // fechar arquivo (INDISPENSAVEL para gravacao) 
    fclose ( arquivo ); 
} // end just_four ( ) 
//---------------------


//---------------------
/** 
  Method_01. 
*/ 
void method_01 ( void ) 
{ 
  // identificar 
  IO_id("EXEMPLO0711 - Method01 - v2.0");

  int number = 0;
   
  //declarando valores
  IO_printf("Digite a quantidade de numeros: \n");
   IO_scanf("%d", &number);
  
   just_four("just_four.TXT", number);

 // encerrar 
 IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_01 ( )
//---------------------


//---------------------
/** 
   back_fifteen    - Gravar em arquivo texto certa quantidade de valores multiplos de 15, par e decresente. 
   @param fileName - nome do arquivo 
   @param x        - quantidade de valores 
 */ 
void back_fifteen  ( chars fileName, int x ) // chamando a funcao para ler o arquivo
{ 
 // definir dados 
    FILE* arquivo = fopen ( fileName, "wt" );  

    // desta forma os valores sempre serao pares
    int aux = 15 * 2 * x;
 
 // repetir para a quantidade de dados 
    for ( int i = x - 1; i >= 0; i-- ) 
    { 
      // condicao se for impar 
         // gravar valor 
        fprintf ( arquivo, "%d\n", aux );
        aux = aux - 30; // diminuindo desta forma sera printar de forma decresente
    } // end for 
 
 // fechar arquivo (INDISPENSAVEL para gravacao) 
    fclose ( arquivo ); 
} // end back_fifteen ( ) 


//---------------------
/** 
  Method_02. 
*/ 
void method_02 ( void ) 
{ 
  // identificar 
  IO_id("EXEMPLO0712 - Method02 - v2.0");

  int number = 0;
   
  //declarando valores
  IO_printf("Digite a quantidade de numeros: \n");
   IO_scanf("%d", &number);
  
   back_fifteen ("back_fifteen.TXT", number);

 // encerrar 
 IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_02 ( ) 
//---------------------


//---------------------
/** 
   sequence_three - Gravar em arquivo texto certa quantidade de valores multiplos de 3 positivos. 
   @param fileName - nome do arquivo 
   @param x        - quantidade de valores 
 */ 
void sequence_three ( chars fileName, int x ) // chamando a funcao para ler o arquivo
{ 
 // definir dados 
    FILE* arquivo = fopen ( fileName, "wt" );  
    int y = 0; 

   // sendo aux 1, e multiplicando por 3, vamos sempre achar o formato de 3 9 27 ...
    int aux = 1;
 
 // repetir para a quantidade de dados 
    for ( y = 1; y <= x; y = y + 1 ) 
    { 
     // gravar valor 

        fprintf ( arquivo, "%d\n", aux );
        aux = aux * 3; 

    } // end for 
 
 // fechar arquivo (INDISPENSAVEL para gravacao) 
    fclose ( arquivo ); 
} // end just_four ( ) 
//---------------------


//---------------------
/**
   Method_03 -
 */
   void method_03() 
{
  // identificar 
  IO_id("EXEMPLO0503 - Method03 - v1.0");

  int number = 0;

  //declarando valores
  IO_printf("Digite a quantidade de numeros: \n");
   IO_scanf("%d", &number);

   if (number > 0 ) {
      sequence_three ("sequence_three.TXT", number);
  
   } else {
      IO_printf("Erro, valor menor ou igual a zero ");
   }
  
  

 // encerrar 
 IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_03 ( ) 
//---------------------


//---------------------
/** 
   sequence_three - Gravar em arquivo texto certa quantidade de valores multiplos de 4. 
   @param fileName - nome do arquivo 
   @param x        - quantidade de valores 
 */ 
void division_sequence_three ( chars fileName, int x ) // chamando a funcao para ler o arquivo
{ 
 // definir dados 
    FILE* arquivo = fopen ( fileName, "wt" );  
   
    int y = x; 


 // repetir para a quantidade de dados 
  while (y > 0 ){

   //decrementacao
   y = y - 1;

   // realizando associacao 
   int aux = y;

   // operacao principal
   aux = pow (3, y);

   double answer = 1.0 / (double) aux;

   // revelando valores
   fprintf(arquivo, "%lf\n", answer);
  }
 
 // fechar arquivo (INDISPENSAVEL para gravacao) 
    fclose ( arquivo ); 
} // end just_four ( ) 
//---------------------


//---------------------
/**
   Method_04 
 */
void method_04()
{
   // definir dado

   // identificar
   IO_id("EXEMPLO0704 - Method04 - v1.0");


  // iniciando minha variavel
  int number = 0;

  //declarando valores
  IO_printf("Digite a quantidade de numeros: \n");
   IO_scanf("%d", &number);

   if (number > 0 ) {
      division_sequence_three ("division_sequence_three.TXT", number);
  
   } else {
      IO_printf("Erro, valor menor ou igual a zero ");
   }
  

//
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_04 ( )
//---------------------


//funcao de auxilio para method_05
/** 
   record_sequence - Gravar em arquivo texto certa quantidade de valores 1/x^n. 
   @param fileName - nome do arquivo 
   @param x        - quantidade de valores 
   @param numbers  - quantidade de vezes   
 */ 
//---------------------
void record_sequence (chars fileName, int numbers, double x){

   // abrindo o arquivo
   FILE * arquivo = fopen (fileName, "wt");

 // 
 fprintf (arquivo, "1.0\n");

   int exponent = 3;

   for (int i = 0; i < numbers - 1; i = i + 1){

   double Pow_ = pow(x, exponent);

   double result = 1.0 / Pow_;

   fprintf(arquivo, "%lf\n", result);

   exponent = exponent + 2;

 }


   // fechando o arquivo
   fclose(arquivo);
}//end pensando 
//---------------------


//---------------------
/**
   Method05 - Ler valores e contar positivos menores que 100 e pares (alternativo).
 */
void method_05()
{ 
   // definir dado
   int    numbers = 0  ;
   double x       = 0.0;
   // identificar
   IO_id("EXEMPLO0705 - Method05 - v1.0");


  //declarando valores
  IO_printf("Digite a quantidade de numeros: \n");
   IO_scanf("%d", &numbers);

   IO_printf("Digite o valor a ser elevado:   \n");
   IO_scanf("%lf",    &x);


   if (numbers > 0 ) {
      record_sequence ("record_sequence.TXT", numbers, x);
  
   } else {
      IO_printf("Erro, valor menor ou igual a zero ");
   }

//
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_05 ( )
//---------------------


//funcao de auxilio para method_06
/** 
   read_sequence - le a funcao do metodo 05. 
   @param fileName - nome do arquivo 
   @param numbers  - quantidade de vezes que roda 
 */ 
//---------------------
void read_sequence (chars fileName, int numbers){

   // abrindo o arquivo
   FILE * arquivo = fopen (fileName, "rt");

   //declarando variaveis 
   double value    = 0.0;
   int    count    = 0  ; 

   // confirindo se o ponteiro existe

 if (arquivo == null){
   IO_print("Erro, apontador esta aterrado.");
 }

 while ( fscanf   (arquivo, "%lf", &value)   != EOF   )
 {
   count = count + 1;
   IO_printf("Value: %lf\n ", value);
   IO_printf("count: %d\n",count ); }
 
   // fechando o arquivo
   fclose(arquivo);
}//end pensando 
//---------------------


//---------------------
/**
   Method06 - Ler valores e contar positivos menores que 100 e pares (alternativo).
 */
void method_06()
{
   // identificar
   IO_id("EXEMPLO0706 - Method06 - v2.0");

      // definir dado
      int numbers = 0;
  
      IO_printf("Digite a quantidade de numeros a ler: \n");
      IO_scanf("%d", &numbers);
  
      if (numbers > 0) {
          read_sequence("record_sequence.TXT", numbers);
      } else {
          IO_printf("Erro, valor menor ou igual a zero.\n");
      }
//
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_06 ( )
//---------------------


//funcao de auxilio para method_07
/** 
   read_sequence - le a funcao do metodo 04. 
   @param fileName - nome do arquivo 
   @param numbers  - quantidade de vezes que roda 
 */ 
//---------------------
void read_division_sequence_three  (chars fileName, int numbers){

   // abrindo o arquivo
   FILE * arquivo = fopen (fileName, "rt");

   //declarando variaveis 
   double value       = 0.0 ;
   double  New_value  = 0.0 ;
   int     count       = 0   ; 

   // confirindo se o ponteiro existe

 if (arquivo == null){
   IO_print("Erro, apontador esta aterrado.");
 }

 while ( fscanf   (arquivo, "%lf", &value)   != EOF   )
 {
   // mostrando quantas vezes o loop se realiza
   count = count + 1;

   // operacao de armazenar valor e proceguir 
   New_value = New_value + value;
   
   IO_printf("Value: %lf\n ", value);
   IO_printf("count: %d\n",count );
   IO_printf("Novo valor: %lf\n",New_value);

 }
 //revelando o valor total
IO_printf("O valor apos a soma: %lf", New_value);

   // fechando o arquivo
   fclose(arquivo);
}//end pensando 
//---------------------


//---------------------
/**
   Method_07 - 
 */
void method_07()
{
   IO_id("EXEMPLO0707 - Method07 - v2.0");

         // definir dado
         int numbers = 0;
  
         IO_printf("Digite a quantidade de numeros a ler: \n");
         IO_scanf("%d", &numbers);
     
         if (numbers > 0) {
            read_division_sequence_three("division_sequence_three.TXT", numbers);
            
         } else {
             IO_printf("Erro, valor menor ou igual a zero.\n");
         }
   //

 // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_07 ( )
//---------------------


//gerador de fibonacci
//importante, nao usar numeros tao grandes, por conta de sua complexidade ser  N^2
//---------------------
int fibonacci (int number){
   if ( number == 0 || number == 1 ){
      return 1;
   }

   return fibonacci (number - 1) + fibonacci(number - 2);
}
//---------------------


//funcao de auxilio para method_08
//---------------------
void writ_fibonacci (chars fileName, int number){
   // declarando arquivo
   FILE * arquivo = fopen (fileName, "wt");

   //declarando variaveis
   int count = 0;
   int index = 0;

   // inicniando loop 
  while (count < number)
  { 

   // chamada de funcao com atribuicao 
   int answer = fibonacci (index); 

   // conficao principal
   if (answer % 2 == 0 ){
   fprintf(arquivo, "valor: %d\n", answer);
   count = count + 1; 
      }

      index = index + 1;

   
   }// end wilhe 

   //fechando o arquivo
   fclose(arquivo);
}// end writ_fibonacci


//---------------------


//---------------------
/**
   Method_08 
 */
void method_08() {
   // identificar
   IO_id("EXEMPLO0708 - Method08 - v3.0");
  
         // definir dado
      int numbers = 0;
  
      IO_printf("Digite a quantidade de numeros a ler: \n");
        IO_scanf("%d", &numbers);
     
     if (numbers > 0) {
     writ_fibonacci("RESULTADO08.TXT", numbers);       
   } else {
         IO_printf("Erro, valor menor ou igual a zero.\n");
         }
   //

//
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_08 ( )
//---------------------


// -------------------------
// funcao de apoio para metodo 09
/**
 * count_uppercase_in_file - Contar maiusculas em cada linha e gravar o resultado.
 * @param fileName - Nome do arquivo para ler
 */
void count_uppercase_in_file(chars fileName) {
   FILE *arquivoEntrada = fopen(fileName, "rt");
   FILE *arquivoSaida = fopen("RESULTADO09.TXT", "wt");

   if (arquivoEntrada == NULL || arquivoSaida == NULL) {
       IO_print("Erro ao abrir o arquivo.\n");
       return;
   }

   char text[100];

   while (fgets(text, 100, arquivoEntrada) != NULL) {
       int uppercaseCount = 0;
       int length = strlen(text);

       for (int i = 0; i < length; i++) {
           if (text[i] >= 'A' && text[i] <= 'Z') {
               uppercaseCount++;
           }
       }

       fprintf(arquivoSaida, "%s -> maiusculas: %d\n", text, uppercaseCount);
   }

   fclose(arquivoEntrada);
   fclose(arquivoSaida);
} // end count_uppercase_in_file


//---------------------
/**
   Method_09 - 
 */
void method_09()
{
    // identificar
    IO_id("EXEMPLO0709 - Method09 - v2.0");

    chars fileName = "cadeias.txt";

    count_uppercase_in_file(fileName);

   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_09 ( )
//---------------------


// -------------------------
// funcao de apoio para metodo 10
/**
 * count_digits_greater_equal_3 - Contar dígitos >= 3 em cada linha e gravar o resultado.
 * @param fileName - Nome do arquivo para ler
 */
void count_digits_greater_equal_3(chars fileName) {
    FILE *arquivoEntrada = fopen(fileName, "rt");
    FILE *arquivoSaida = fopen("RESULTADO10.TXT", "wt");

    if (arquivoEntrada == NULL || arquivoSaida == NULL) {
        IO_print("Erro ao abrir o arquivo.\n");
        return;
    }

    char text[100];

    while (fgets(text, 100, arquivoEntrada) != NULL) {
        int digitCount = 0;
        int length = strlen(text);

        for (int i = 0; i < length; i++) {
            if (text[i] >= '3' && text[i] <= '9') {
                digitCount++;
            }
        }

        fprintf(arquivoSaida, "%s -> Digitos >= 3: %d\n", text, digitCount);
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);
} // end count_digits_greater_equal_3


//---------------------
/**
   Method_10 - 
 */
void method_10()
{
    // identificar
    IO_id("EXEMPLO710 - Method10 - v2.0");

    
    chars fileName = "cadeias.txt";

    count_digits_greater_equal_3(fileName);


  // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_10 ( )
//---------------------



// -------------------------
// method 11
/**
 * method_11 - Ler valor inteiro e gravar divisores ímpares em ordem decrescente.
 */
void method_11() {
   IO_id("EXEMPLO0711 - Method11 - v1.0");

   int x = 0;
   IO_printf("Digite um valor inteiro: ");
   IO_scanf("%d", &x);

   FILE *arquivo = fopen("RESULTADO_E1.TXT", "wt");

   if (arquivo == NULL) {
       IO_print("Erro ao abrir o arquivo.\n");
       return;
   }

   for (int i = x; i >= 1; i--) {
       if (x % i == 0 && i % 2 != 0) {
           fprintf(arquivo, "%d\n", i);
       }
   }

   fclose(arquivo);

   IO_pause("Apertar ENTER para continuar");
} // end method_07E1
// -------------------------


// -------------------------
// funcao de apoio para 07E2
/**
 * count_c_words_in_file - Contar palavras que começam com 'c' ou 'C' e até 12 caracteres.
 * @param fileName - Nome do arquivo com palavras
 */
void count_c_words_in_file(chars fileName) {
   FILE *arquivo = fopen(fileName, "rt");

   if (arquivo == NULL) {
       IO_print("Erro ao abrir o arquivo.\n");
       return;
   }

   char palavra[100];
   int contador = 0;

   while (fscanf(arquivo, "%s", palavra) != EOF) {
       if ((palavra[0] == 'c' || palavra[0] == 'C') && strlen(palavra) <= 12) {
           contador++;
       }
   }

   fclose(arquivo);

   IO_printf("Quantidade de palavras com 'c' ou 'C' e até 12 caracteres: %d\n", contador);
} // end count_c_words_in_file

//---------------------


//---------------------
/**
   Method_12.
 */
void method_12()
{
   // identificar
   IO_id("EXEMPLO0712 - Method12 - v2.0");

   chars fileName = "palavras.txt";

   count_c_words_in_file(fileName);

   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_12 ( )
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
      IO_id("EXEMPLO0 500 - Programa - v0.0 \n");

      // ler do teclado
      IO_println("Opcoes");
      IO_println(" 0  - Method_00 parar");
      IO_println(" 1 - Method_01 ler um valor inteiro do teclado e gravar essa quantidade em multiplo de 4,");
      IO_println(" 2 - Method_02 ler um valor inteiro do teclado e gravar essa quantidade em multiplo de 15 ");
      IO_println(" 3 - Method_03 ler um valor inteiro do teclado e gravar essa quantidade em valores da sequencia: 1 3 9 27 81");
      IO_println(" 4 - Method_04 ler um valor inteiro do teclado e gravar essa quantidade em valores decrescentes da sequencia: ... 1/81 1/27 1/9 1/3 1.");
      IO_println(" 5 - Method_05 ler um valor inteiro do teclado (n) e outro valor real (x), gravar essa quantidade (n) em valores reais da sequencia: 1 1/x3 1/x5  1/x7... ");
      IO_println(" 6 - Method_06 ler um valor inteiro do teclado para representar certa quantidade de valores a serem somados dentre os primeiros gravados no exercicio anterior (0715)");
      IO_println(" 7 - Method_07 ler um valor inteiro do teclado, e ate essa quantidade, um valor por vez, calcular a soma dos inversos das potencias do exercicio (0714).");
      IO_println(" 8 - Method_08 ler um valor inteiro do teclado, e ate atingir essa quantidade, um valor por vez, gravar o valor correspondente aos primeiros termos pares da serie de Fibonacci.");
      IO_println(" 9 - Method_09 para calcular a quantidade de maiúsculas em cadeia de caracteres de um arquivo texto.");
      IO_println("10 - Method_10 para contar digitos maiores ou iguais a 3 em uma cadeia de caracteres.");
      IO_println("11 - Method_11 programa ler um valor inteiro do teclado, e gravar em arquivo os seus divisores impares em ordem decrescente");
      IO_println("12 - Method_10 ler palavras de um arquivo, uma por linha, e contar quantas comecam com a letra 'c' (ou 'C') e tenham, no maximo, 12 caracteres");

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
         case  9:  method_09 ( );   break;
         case 10:  method_10 ( );   break;
         case 11:  method_11 ( );   break;
         case 12:  method_12 ( );   break;


      default:
         IO_pause(IO_concat("Valor diferente das opcoes [0 a 12] (",
                            IO_concat(IO_toString_d(x), ")")));
      } // end switch
   } while (x != 0);

   // encerrar
   IO_pause("Apertar ENTER para terminar");
   return (0);
} // end main ( )