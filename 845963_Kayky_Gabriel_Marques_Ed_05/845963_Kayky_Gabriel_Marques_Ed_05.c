
/*
   Exemplo0 500 - v0.0. - 13 / 03 / 2025
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
//funcao auxiliar para method_01 e method_04
//------------------------------
void  vector_Pa_three (int *vector,int N_numbers, int raze_of_int, bool print_one ) {
// Variavel estatica para controlar se a mensagem ja foi impressa
static bool already_printed = false;

// Imprime a identificação apenas na primeira chamada
if (!already_printed) {
    IO_id("Metodo auxiliar vector_Pa_three | version - V 2.0 \n");
    already_printed = true; // Marca que a mensagem já foi impressa
}
   //dica:  An = a1 + (n - 1 ) * R

   int first_term = 3;  // numero que dara inicio a pa (sendo o primiero 3 )

   for (int i = 0; i < N_numbers; i++) { // serve para realizar a conta 
      vector[i] = first_term + (i * raze_of_int); // raze of = 3
  }

  if (print_one) { 
  for (int i = 0; i < N_numbers; i++) {// mostra para revelar 
      printf("A sequencia e: [%d]\n", vector[i]);
      }
   }

}
//---------------------


//---------------------
/** 
  Method_01. 
*/ 
void method_01 ( void ) 
{ 
  // identificar 
  IO_id("EXEMPLO0501 - Method04 - v3.0");

    // iniciando minha variavel
    int  raze_of   =  3;
    int  N_numbers =  0;

      printf("Digite o valor (N)\n");
      scanf("%d", &N_numbers ); getchar ( );

      printf("O valor do N e [%d]\n", N_numbers);



      int *vector = (int *) malloc (N_numbers * sizeof(int )); // aolocando memoria

      if (vector == NULL){
         IO_println("Erro: o ponteiro nao esta apontando a nada");
      }

      vector_Pa_three (vector, N_numbers, raze_of, true); 
      
  // encerrar 
     printf ( "\nApertar ENTER para continuar.\n" );
     getchar() ;// limpando o buffer 

} // end method_01 ( ) 
//---------------------


// funcao auxiliar para mehtod_02
//---------------------
int  vector_Pa_multiple_fifteen (int *vector,int N_numbers, int raze_of_int ) {
   // indentificacao
   IO_id ("Metodo auxilixar vector_Pa_three | version - V 2.0 \n ");

   //dica:  An = a1 + (n - 1 ) * R
   int first_term = 15;  // numero que dara inicio a pa (sendo o primiero 3 )

   for (int i = 0; i < N_numbers; i++) { // serve para realizar a conta 
      vector[i] = first_term + (i * raze_of_int);
  }

  for (int i = 0; i < N_numbers; i++) {// mostra para revelar 
     printf("A sequencia e: [%d]\n", vector[i]);
  }


}
//---------------------


//---------------------
/**
   Method_02 -
 */
void method_02(void)
{ 
  // identificar 
  IO_id("EXEMPLO0502 - Method04 - v1.0");

    // iniciando minha variavel
    int  raze_of   =  15;
    int  N_numbers =   0;

      printf("Digite o valor (N)\n");
      scanf("%d", &N_numbers ); getchar ( );

      printf("O valor do N e [%d]\n", N_numbers);



      int *vector = (int *) malloc (N_numbers * sizeof(int )); // aolocando memoria com base na quantidade de numeros (N_numbers)

      if (vector == NULL){
         IO_println("Erro: o ponteiro nao esta apontando a nada");
      }

      vector_Pa_multiple_fifteen (vector, N_numbers, raze_of); 

      free(vector);
  // encerrar 
     printf ( "\nApertar ENTER para continuar.\n" );
     getchar() ;// limpando o buffer 

} // end method_02 ( ) 
//---------------------


// funcao auxiliar para mehtod_03
//---------------------
int  vector_Pg_a_quarter (int *vector, int N_numbers, double raze_of_double ) {
  
   // indentificacao
   IO_id ("Metodo auxilixar vector_Pg_a_quarter | version - V 3.0 \n ");

   //dica:  An = a1 + (n - 1 ) * R
   int first_term = 0;  // numero que dara inicio a pa (sendo o primiero 3 )
   IO_println("Digita o primeiro valor");

   first_term = IO_readint("Ler o numero");
      // Gera a PG
      vector[0] = first_term; // O primeiro termo é fixo
      for (int i = 1; i < N_numbers; i++) {
          vector[i] = (vector[i - 1] * raze_of_double); // Calcula o próximo termo
      }

  for (int i = 0; i < N_numbers; i++) {// mostra para revelar 
      printf("A sequencia e: [%d]\n", vector[i]);
  }
printf("\n");
}
//---------------------


//---------------------
/**
   Method_03 -
 */
   void method_03() 
{
  // identificar 
  IO_id("EXEMPLO0503 - Method04 - v1.0");

  // iniciando minha variavel
  double  raze_of_double   =  0.25; // -> retrata 1/4
  int     N_numbers        =     0;

    printf("Digite o valor (N)\n");
    scanf("%d", &N_numbers ); getchar ( );

    printf("O valor do N e [%d]\n", N_numbers);



    int *vector = (int *) malloc (N_numbers * sizeof(int )); // aolocando memoria com base na quantidade de numeros (N_numbers)

    if (vector == NULL){
       IO_println("Erro: o ponteiro nao esta apontando a nada");
    }

    vector_Pg_a_quarter (vector, N_numbers, raze_of_double); 

    free(vector);
   // encerrar 
   IO_pause("Apertar ENTER para continuar");
}
//---------------------


//funcao de auxilio para method_04
//---------------------
double * reverse_sequence (int *vector,int N_numbers, int raze_of_NONE){
   IO_id ("Funcao auxilixar reverse_sequence | version - V 5.0 \n ");

      double *reverse = (double *)malloc(N_numbers * sizeof(double)); // alocando memoria para meu vetor reverse

      if (reverse == NULL) {
         IO_println("Erro: apontador e nulo");
         return NULL; // retornarar o erro
      }
 
   
   for (int i = 0; i < N_numbers; i++){
      if (vector[i] != 0){
         reverse [i] =   1.0 / vector[i];  // " a " sera o valor de raze_of
   // rize_of = 0.33   0.33 = 1 / a [ i ]
   }else {
      printf("Erro: o valor de [%d], erro logico", i);
      reverse[i] = 0.0 ;

   }  

   }

   for (int i = 0; i < N_numbers; i++){
      printf("O valor e: [%lf] \n", reverse[i]);
   } 


   return reverse;
   /*
      double a = { 2.00 }
      rize_of = 1 / a [ 0 ] 
      rize_of = 0.5
   */

}
//---------------------


//---------------------
/**
   Method_04 
 */
void method_04()
{
   // definir dado

   // identificar
   IO_id("EXEMPLO0504 - Method04 - v1.0");


  // iniciando minha variavel
  int     raze_of_none   =     3; // -> neste metodo raze_of nao serve para muito alem de incrementar na outr funcao do metodo 1
  int     N_numbers      =     0;

    printf("Digite o valor (N)\n");
    scanf("%d", &N_numbers ); getchar ( );

    printf("O valor do N e [%d]\n", N_numbers);


    int *vector = (int *) malloc (N_numbers * sizeof(int )); // aolocando memoria com base na quantidade de numeros (N_numbers)

    if (vector == NULL){
       IO_println("Erro: o ponteiro nao esta apontando a nada");
    }


      vector_Pa_three (vector, N_numbers, raze_of_none, false ); 
  double * result =   reverse_sequence  (vector, N_numbers, raze_of_none); 

  if (result != NULL){
      free(result);
  }

    free(vector);

//
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_04 ( )
//---------------------


//funcao de auxilio para method_05
//---------------------
double * increasing_even_values (int *vector,int N_numbers){
   IO_id ("Funcao auxilixar increasing_even_values | version - V 2.0 \n ");

      double *reverse_even = (double *)malloc(N_numbers * sizeof(double)); // alocando memoria para meu vetor reverse

      int new_value = 0;

   scanf("%d", &new_value); getchar ( );

      if (reverse_even == NULL) {
         IO_println("Erro: apontador e nulo");
         return NULL; // retornarar o erro
      }
 
   
   for (int i = 0; i < N_numbers; i++){
      if (vector[i] != 1){
         reverse_even [i] =   1.0 / pow(new_value, vector[i]);  
      // reverse_even   =  1.0 /  x^0
   }else {
      printf("Comportamento logico, se [i] for elevado seu valor sera 1", i);
      reverse_even[i] = 1.0 ;

   }  

   }

   for (int i = 0; i < N_numbers; i++){
      printf("O valores pares crescentes sao: [%lf] \n", reverse_even[i]);
   } 


   return reverse_even;
   /*
      double a = { 2.00 }
      rize_of = 1 / a [ 0 ] 
      rize_of = 0.5
   */

}
//---------------------


//---------------------
/**
   Method05 - Ler valores e contar positivos menores que 100 e pares (alternativo).
 */
void method_05()
{
   
   // definir dado

   // identificar
   IO_id("EXEMPLO0505 - Method04 - v1.0");


  // iniciando minha variavel
  int     N_numbers      =     0;

    printf("Digite o valor (N)\n");
    scanf("%d", &N_numbers ); getchar ( );

    printf("O valor do N e [%d]\n", N_numbers);


    int *vector = (int *) malloc (N_numbers * sizeof(int )); // aolocando memoria com base na quantidade de numeros (N_numbers)

    if (vector == NULL){
       IO_println("Erro: o ponteiro nao esta apontando a nada");
    }

      // Preencha o vetor com valores adequados (exemplo: 2, 4, 6, ...)
    for (int i = 0; i < N_numbers; i++) {
      vector[i] = 2 * (i + 1); // Exemplo: preenche com valores pares crescentes
  }


  double * result =   increasing_even_values  (vector, N_numbers); 

  if (result != NULL){
      free(result);
  }

    free(vector);

//
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_05 ( )
//---------------------


//funcao de auxilio para method_06
//---------------------
int sum_not_multiples_of_four(int *vector,int N_numbers ) {
   // indentificacao
   IO_id ("Metodo auxilixar vector_Pa_three | version - V 2.0 \n ");

      int result = 0; // valor auxiliar para o resultado da soma    
   

   for (int i = 0; i < N_numbers; i++) { // serve para realizar a conta
         bool is_mult_four  =  (!(vector[i] % 4 == 0 )  &&  (vector[i] % 3 == 0)); // funcao auxiliar para condicao 
         bool just_positive = (  vector[ i ] >=  0 );


   // indeice      0  1  2   3   4
   // Ex: vector [ 3  6  9  12  15 ]
   //                        |_> nao faz parte da condicao           
         if ( is_mult_four && just_positive ) {
            result += vector[i];
      }

  }

  for (int i = 0; i < N_numbers; i++) {// mostra para revelar 
     printf("A sequencia e: [%d]\n", vector[i]);

  }

return result;

}
//---------------------


//---------------------
/**
   Method06 - Ler valores e contar positivos menores que 100 e pares (alternativo).
 */
void method_06()
{
   // identificar
   IO_id("EXEMPLO0506 - Method06 - v2.0");
  

  // iniciando minha variavel
  int     N_numbers      =     0;

    printf("Digite o valor (N)\n");
    scanf("%d", &N_numbers ); getchar ( );

    printf("O valor do N e [%d]\n", N_numbers);


    int *vector = (int *) malloc (N_numbers * sizeof(int )); // aolocando memoria com base na quantidade de numeros (N_numbers)

    if (vector == NULL){
       IO_println("Erro: o ponteiro nao esta apontando a nada");
    }

      // Preencha o vetor com valores adequados (exemplo: 2, 4, 6, ...)
    for (int i = 0; i < N_numbers; i++) {
      vector[i] = 3 * (i + 1); // Exemplo: preenche com valores pares crescentes
  }


  int  result =   sum_not_multiples_of_four  (vector, N_numbers); 

  printf("A soma dos valores que sao multiplos de 3 mas nao de 4 e: %d\n", result);


  if (vector != NULL){
      free(vector);
  }



//
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_06 ( )
//---------------------



//funcao de auxilio para method_07
//---------------------
double sum_not_multiples_of_five (int *vector,int N_numbers ) { // -> erro na hr de declrar a funcao, retornando um valor inteiro 
   // indentificacao
   IO_id ("Metodo auxilixar sum_not_multiples_of_five | version - V 3.0 \n ");

//--

// ex pratico 
// indeice      0  1  2   3   4
// Ex: vector [ 4  8  12  16  20 ]
//                             |_> nao faz parte da condicao sendo esta mesmo multiplo de 5
// [ 4  8  12  16  20 ]
//  1/4 + 1/8 + 1/12 + 1/16 + 1/24 -> quando n for 5

//--
      int count     = 0;
      int value     = 0;
      double result = 0.0; // valor auxiliar para o resultado da soma   
    

      for (int i = 0; i < N_numbers; i++) {
         bool is_mult_four = (vector[i] % 4 == 0);
         bool is_mult_five = (vector[i] % 5 == 0);
         bool is_positive = (vector[i] >=  0);
 
         if (is_mult_four && !is_mult_five && is_positive) {
             result += 1.0 / vector[i];
         }   
     }
   
         // decidi usar i do while pois, sempre que o N_numbers precisa de verificar um numero ele "verifica" uma vez mais doq foi digitado 
        //   1/4 + 1/8 + 1/12 + 1/16 + (1/20) + 1/24 -> quando n for 5
       //                                  |_> como n foi 5 e ele precisa passar por 1/20 no do while ele sempre anda um a mais que foi colocado com escopo 

  for (int i = 0; i < N_numbers; i++) {// mostra para revelar 
     printf("A sequencia e: [%d]\n", vector[i]);

  }

return result;

}


//---------------------
/**
   Method_07 - Ler palavra, contar e mostrar numeros.
 */
void method_07()
{
   IO_id("EXEMPLO0507 - Method07 - v2.0");


  // iniciando minha variavel
   int     N_numbers      =     0;

    printf("Digite o valor (N)\n");
    scanf("%d", &N_numbers ); getchar ( );

    printf("O valor do N e [%d]\n", N_numbers);


    int *vector = (int *) malloc (N_numbers * sizeof(int )); // aolocando memoria com base na quantidade de numeros (N_numbers)

    if (vector == NULL){
       IO_println("Erro: o ponteiro nao esta apontando a nada");
    }

      // Preencha o vetor com valores adequados (exemplo: 2, 4, 6, ...)
    for (int i = 0; i < N_numbers; i++) {
      vector[i] = 4 * (i + 1); // Exemplo: preenche com valores multiplos de 4 crescentes
  }


    double  result =   sum_not_multiples_of_five  (vector, N_numbers);  // -> erro na declracao como double, ia ocorrer um truncamento 

  printf("A soma dos valores que sao multiplos de 4 mas nao de 5 e: %.2lf\n", result);


   if (vector != NULL){
      free(vector);
    }

 // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_07 ( )
//---------------------


//funcao de auxilio para method_08
//---------------------
int sum_five_index(int *vector,int N_numbers ) {
   // indentificacao
   IO_id ("Metodo auxilixar sum_five_index | version - V 2.0 \n ");

      int result = 0; // valor auxiliar para o resultado da soma    
   

   for (int i = 0; i < N_numbers; i++) { // serve para realizar a conta
         bool just_positive = (  vector[ i ] >=  0 );

   // indeice     i:   0   1   2   3   4
   // Ex: vector  n: [ 5   6   8  11  15 ]
   //                pode ver que o valor de n  e somado com o index do vetor ( i ), com tudo sera acumulado em uma variavel de auxilio 
   
         if (   just_positive  ) {
            result += vector[i] + i ; // -> result sempre vai atribuir o valor da soma de vector mais a quantidade de i (seu index)
      }

  }

  printf("Sequencia do vetor:\n");


   for (int i = 0; i < N_numbers; i++) {
      printf("[%d] = %d\n", i, vector[i]);
   }

return result;

}
//---------------------


//---------------------
/**
   Method_08 
 */
void method_08() {
   // identificar
   IO_id("EXEMPLO0508 - Method08 - v3.0");
  

  // iniciando minha variavel
  int     N_numbers      =     0;

    printf("Digite o valor (N)\n");
    scanf("%d", &N_numbers ); getchar ( );

    printf("O valor do N e [%d]\n", N_numbers);


    int *vector = (int *) malloc (N_numbers * sizeof(int )); // aolocando memoria com base na quantidade de numeros (N_numbers)

    if (vector == NULL){
       IO_println("Erro: o ponteiro nao esta apontando a nada");
    }

  // Preenche o vetor (exemplo: 5, 6, 7, ...)
  for (int i = 0; i < N_numbers; i++) {
   vector[i] = 5 + i; // Exemplo: [5, 6, 7, ...]
}

  int  result =   sum_five_index  (vector, N_numbers); 

  printf("A soma dos valores e: %d\n", result);


  if (vector != NULL){
      free(vector);
  }



//
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_08 ( )
//---------------------


//funcao de auxilio para method_09
//---------------------
int Sq_Nat_Sum (int *vector,int N_numbers ) {
   // indentificacao
   IO_id ("Metodo auxilixar Square Natural Sum  | version - V 2.0 \n ");

      int result = 0;

   for (int i = 0; i < N_numbers; i++) { // serve para realizar a conta
         bool just_positive = (  vector[ i ] >=  0 );


   
         if (   just_positive  ) {
            printf("vector[%d] = %d (quadrado = %d)\n", i, vector[i], vector[i] * vector[i]);
            result += vector[i] * vector[i]; // Cálculo direto      }

         }

  }

return result;

}
//---------------------


//---------------------
/**
   Method_09 - Ler palavra, contar e mostrar caracteres alfanumericos 
 */
void method_09()
{
    // identificar
    IO_id("EXEMPLO0509 - Method09 - v2.0");

  // iniciando minha variavel
  int     N_numbers      =     0;

    printf("Digite o valor (N)\n");
    scanf("%d", &N_numbers ); getchar ( );

    printf("O valor do N e [%d]\n", N_numbers);


    int *vector = (int *) malloc (N_numbers * sizeof(int )); // aolocando memoria com base na quantidade de numeros (N_numbers)

    if (vector == NULL){
       IO_println("Erro: o ponteiro nao esta apontando a nada");
    }

  // Preenche o vetor (exemplo: 5, 6, 7, ...)
  for (int i = 0; i < N_numbers; i++) {
   vector[i] = 5 + i; // Exemplo: [5, 6, 7, ...]
}

  int  result =   Sq_Nat_Sum  (vector, N_numbers); 

  printf("A soma dos valores e: %d\n", result);


  if (vector != NULL){
      free(vector);
  }

   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_09 ( )
//---------------------


//funcao de auxilio para method_10
//---------------------
double sum_inverse_ending_with_3(int N_terms) {
   // Identification
   IO_id("Metodo auxiliar - Sum of Inverses Ending with 3 | Version - V1.0");

   double result       = 0.0;
   int    count         = 0;
   int    current_number  = 1;

   while (count < N_terms) {
      if (current_number % 10 == 3) {  // - > verificar se o numero termina em 3

         printf("1/%d = %lf\n", current_number, 1.0/current_number);

         result += 1.0 / current_number;
         count++;
      }
      current_number++;
   }

   return result;
}
//---------------------


//---------------------
/**
   Method_10 - Ler palavra, contar e mostrar caracteres alfanumericos 
 */
void method_10()
{
    // identificar
    IO_id("EXEMPLO510 - Method10 - v2.0");

  // iniciando minha variavel
  int     N_numbers      =     0;

    printf("Digite o valor (N)\n");
    scanf("%d", &N_numbers ); getchar ( );

    printf("O valor do N e [%d]\n", N_numbers);

    if (N_numbers <= 0) {
      IO_println("Erro: N deve ser positivo.");
      IO_pause("Apertar ENTER para continuar");
      return;
  }

  // calculando a soma
  double result = sum_inverse_ending_with_3(N_numbers);

//mostrando o resultado 
  printf("\nA soma dos %d inversos de numeros terminando com 3 e: %lf\n", N_numbers, result);

   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_10 ( )
//---------------------


//funcao de auxilio para method_10
//---------------------
int calculate_factorial(int number) {
   // Identification
   IO_id("Metodo auxiliar - calculate_factorial| Version - V2.0");


   // Caso base: fatorial de 0 ou 1 é 1
   if (number <= 1) {
       return 1;
   } else {
       // Chamada recursiva: n! = n * (n-1)!
       return number * calculate_factorial(number - 1);
   }
}
//---------------------


//---------------------
/**
   Method_11.
 */
void method_11()
{
   // identificar
   IO_id("EXEMPLO0511 - Method11 - v2.0");


  // iniciando minha variavel
  int     inputNumber       =     0;

    printf("Digite o valor (N)\n");
    scanf("%d", &inputNumber  ); getchar ( );

    printf("O valor do N e [%d]\n", inputNumber );

   // Verificar se o número é positivo
   if (inputNumber < 0) {
      printf("Error: The number must be positive.\n");
   } else {
      // Calcular e mostrar o fatorial
      int factorialResult = calculate_factorial(inputNumber);

      //mostrando o resultado 
      printf("\nO fatorial de %d e: %d\n", inputNumber , factorialResult  );

   }

   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_11 ( )
//---------------------


                                                         //--  Ideias apos a aula de dia 26/03



// Função auxiliar para calcular o fatorial de forma recursiva
//---------------------
int calculate_factorial(int number) {
      // Identification
      IO_id("Metodo auxiliar - calculate_factorial | Version - V1.0");

   // Caso base: fatorial de 0 ou 1 é 1
   if (number <= 1) {
       return 1;
   } else {
       // Chamada recursiva: n! = n * (n-1)!
       return number * calculate_factorial(number - 1);
   }
}
//---------------------


// Funcao auxiliar para calcular o termo da sequencia
//---------------------
double calculate_sequence_term(int term) {
      // Identification
      IO_id("Metodo auxiliar - calculate_sequence_term | Version - V1.0");

   // Numerador: 2*term (2, 4, 6...)
   int numerator = 2 * term;
   
   // Denominador: (2*term + 1)! (3!, 5!, 7!...)
   int denominator_factorial = calculate_factorial(2 * term + 1);
   
   // Retorna (1 + numerator/denominator_factorial)
   return 1.0 + (double)numerator / denominator_factorial;
}
//---------------------


// Funcao auxiliar para calcular o produto da sequencia
//---------------------
double calculate_sequence_product(int terms) {
   // Identification
   IO_id("Metodo auxiliar - calculate_sequence_product | Version - V 2.0");


   double product = 1.0;
   
   for (int i = 1; i <= terms; i++) {
       double term = calculate_sequence_term(i);
       product *= term;
       
       // Mostrar cada termo para debug (opcional)
       printf("Term %d: (1 + %d/%d!) = %lf\n", 
              i, 2*i, 2*i+1, term);
   }
   
   return product;
}
//---------------------


//---------------------
/**
   Method_12.
 */
void method_12()
{
   // identificar
   IO_id("EXEMPLO0512 - Method12 - v2.0");


 // Variavel para armazenar o número de termos
 int numberOfTerms = 0;

 // Ler o valor de entrada
 printf("Enter the number of terms (n): ");
 scanf("%d", &numberOfTerms); getchar();

 // Verificar se o numero e positivo
 if (numberOfTerms <= 0) {
     printf("Error: O numero precisa ser positivo.\n");
 } else {
     // Calcular e mostrar o resultado
     double result = calculate_sequence_product(numberOfTerms);
     printf("\nO resultado do produto dos %d primeiros termos e: %lf\n", numberOfTerms, result); }


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
      IO_println(" 1 - Method_01  testar a funcao para gerar valores multiplos de 3 em ordem crescente");
      IO_println(" 2 - Method_02  testar a funcao para gerar valores multiplos de 3 e 5 em ordem crescente.");
      IO_println(" 3 - Method_03  testar a funcao para gerar potencias de 4 em ordem decrescente.");
      IO_println(" 4 - Method_04  testar a funcao para gerar valores crescentes nos denominadores (sequencia dos inversos) multiplos de 3");
      IO_println(" 5 - Method_05  testar a funço para gerar valores pares crescentes nos denominadores da sequencia: 1 1/x2 1/x4 1/x6");
      IO_println(" 6 - Method_06  testar a funcao para gerar valores pares crescentes nos denominadores da sequencia: 1 1/x2 1/x4 1/x6.");
      IO_println(" 7 - Method_07  calcular a soma dos inversos (1/x) dos primeiros valores positivos,começando no valor 4, multiplos de 4 e nao multiplos de 5 ");
      IO_println(" 8 - Method_08  calcular a soma da adicao dos primeiros numeros naturais comecando no valor 5. ");
      IO_println(" 9 - Method_09  calcular a soma dos quadrados dos números naturais começando no valor 25. ");
      IO_println("10 - Method_10  calcular a soma dos inversos (1/x) das adições de números naturais terminando no valor 3.");
      IO_println("11 - Method_11  mediante o uso da funcao, calcular e mostrar o fatorial desse valor em outro metodo");
      IO_println("12 - Method_10  ler uma quantidade inteira do teclado (n) e,mediante o uso da função, calcular e mostrar o resultado em outro método de");

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
