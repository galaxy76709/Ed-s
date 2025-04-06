
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
//funcao auxiliar para method_01
//------------------------------
int Recursion_three(int N_numbers, int sum, bool one_call) { // indentificacao
   if (one_call){ 
   IO_id ("\nMetodo auxilixar Recursion_three | version - V 2.0 \n ");
}

   if (N_numbers >0 ) {
      IO_printf("%d \n", sum); // Imprime o valor atual (3, 6, 9, ...)
      Recursion_three(N_numbers - 1, sum + 3, false ); // Chama recursivamente com o próximo múltiplo de 3
   }
}
//---------------------


//---------------------
/** 
 Method_01. 
*/ 
void method_01(void) {
   // identificar 
   IO_id("EXEMPLO0601 - Method_01 - v3.0");

   // declarar valores
   int Numbers = 0;
   int value   = 0;


   IO_printf("Digite o valor de ( N )");   
   scanf("%d", &Numbers);  getchar( );

   IO_printf("Digite o numero: ");
   scanf("%d", &value);  getchar( );


   int after_call = Recursion_three(Numbers, value, true );   // motor da recursividade 

   IO_printf("o valor = %d", value);
   
   // encerrar 
   IO_pause("Apertar ENTER para continuar");
} // end method_01 ( ) 
//---------------------


//---------------------
//funcao auxiliar para method_02
//------------------------------
int Recursion_mult_three(int N_numbers, int sum, bool one_call) { // indentificacao
   if (one_call){ 
   IO_id ("\nMetodo auxilixar Recursion_mult_three | version - V 2.0 \n ");
}

   if (N_numbers <= 0  ) 
   {  return 0;   }

      IO_printf("%d \n", sum); // Imprime o valor atual (3, 6, 9, ...)
      Recursion_mult_three(N_numbers - 1, sum - 3, false ); // -> 
   }

//---------------------


//---------------------
/**
   Method_02 -
 */
void  method_02    (void)
{ 
  // identificar 
  IO_id("EXEMPLO0602 - Method04 - v1.0");

   // declarar valores
   int Numbers = 0;
   int value   = 0;

  IO_printf("Digite o valor de vezes ( N )");   
  scanf("%d", &Numbers);  getchar( );

  IO_printf("Digite o numero: ");
  scanf("%d", &value);  getchar( );


  int after_call = Recursion_mult_three(Numbers, value * Numbers, true );   // motor da recursividade 

  IO_printf("o valor = %d", after_call);

   // encerrar 
   IO_pause("Apertar ENTER para continuar");
} // end method_02 ( ) 
//---------------------


//---------------------
//funcao auxiliar para method_03
//------------------------------
double Recursion_frac_three(int N_numbers, int step, bool one_call) {
   if (one_call) {
       IO_id("\nMetodo auxiliar frac | version - V 3.0 \n");
   }

   if (N_numbers > 0) {
       double denominator = 1 + (step * 3);
       double result = 1.0 / denominator;
       IO_printf("1/%lf = %lf\n", denominator, result);
       return result + Recursion_frac_three(N_numbers - 1, step + 1, false);
   }
   return 0.0; 
}
//---------------------


//---------------------
/**
   Method_03 -
 */
   void method_03() 
{
  // identificar 
  IO_id("EXEMPLO0603 - Method_03 - v1.0");

   // declarar valores
   int Numbers = 0;
   int value   = 0;

  IO_printf("Digite o valor de vezes ( N ): \n");   
  scanf("%d", &Numbers);  getchar( );

  IO_printf("Digite o numero: \n ");
  scanf("%d", &value);  getchar( );


  double after_call = Recursion_frac_three(Numbers, value, true );   // motor da recursividade 

  IO_printf("o valor = %lf", after_call);

   // encerrar 
   IO_pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
//funcao de auxilio para method_04
//---------------------
double Recursion_frac_three_B(int N_numbers, int step, bool one_call) {
   if (one_call) {
       IO_id("\nMetodo auxiliar Recursion_frac_three_B | version - V 2.0 \n");
   }

   if (N_numbers > 0) {
      double denominator = 0.0;
      if (N_numbers == 1) {
         denominator = 1.0;  // me garante que o ultimo termo e = 1/1

     } else {
         denominator = (N_numbers - 1) * 3;  // Gera 12, 9, 6, 3 para N_numbers=5,4,3,2
     }
      //IO_printf("\n denominador %lf \n", denominator); - > verificacao de codigo 

      double result = 1.0 / denominator;
     // IO_printf("\b denominador %lf \n ", result);

      IO_printf("\n 1/%lf = %lf\n", denominator, result);
      return result + Recursion_frac_three_B(N_numbers - 1, step, false);

   }
   return 1.0;
}
//--------------------- 


//---------------------
/**
   Method_04 
 */
void method_04()
{

  
   // declarar valores
   int Numbers = 0;
   int value   = 0;

   // identificar
   IO_id("EXEMPLO0604 - Method04 - v1.0");

  IO_printf("Digite o valor de vezes ( N ): \n");   
  scanf("%d", &Numbers);  getchar( );

  IO_printf("Digite o numero:\n");
  scanf("%d", &value);  getchar( );


  double after_call = Recursion_frac_three_B (Numbers, value, true );   // motor da recursividade 

  IO_printf("o valor = %lf", after_call);


   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_04 ( )
//---------------------


// Função para calcular numeros pares (1, 3, 5, 7,...)
//---------------------
int calculating_odd(int n) {

   return (2 * n - 1);
}
//---------------------


// Função auxiliar modificada
//---------------------
int Recursion_sum_odd(int step, bool one_call) {
   if (step == 1) {
      return 3; // Primeiro termo fixo da sequência
   } else {
      // Pega o termo anterior e soma o (step-1) número ímpar
      return Recursion_sum_odd(step - 1, false) + calculating_odd(step - 1);
   }
}
//---------------------


//---------------------
/**
   Method05 - Ler valores e contar positivos menores que 100 e pares (alternativo).
 */
void method_05()
{
   
   // definir dado
   int result = 0;
   int N_numbers = 0;
   // identificar
   IO_id("EXEMPLO0605 - Method05 - v1.0");

    // Ler entrada do usuario
    IO_printf("Digite a quantidade de termos (N): ");
    scanf("%d", &N_numbers); 
    getchar();

    // Mostrar a sequencia completa
    for (int i = 1; i <= N_numbers; i++) {
        int term = Recursion_sum_odd (i, true);
        IO_printf("Termo %d: %d\n", i, term);
        result = result + term;
        
        IO_printf("\nO resultado apos a soma e = %d \n", result);
    }

      // encerrar
      IO_pause("Apertar ENTER para continuar");

} // end method_05 ( )
//---------------------


//funcao de auxilio para method_06
//---------------------
int invert_sum_mult_three (int N_numbers,int step, bool one_call ) {
   if (one_call) {
      IO_id("\nMetodo auxiliar frac | version - V 3.0 \n");
  }

  if (N_numbers > 0) {
  //  printf("step = %d", step);
      double denominator = 1 + (step); // - > o valor de step precisa ser constante, sempre somado a mais 6 
      //printf("step = %d", step);

      double result = 1.0 / denominator; // - > p resultado pega o inverso de seu resultado 
      IO_printf("1/%lf = %lf\n", denominator, result);
      return result + invert_sum_mult_three(N_numbers - 1, "step" +6 , false); // vai retornar o valor todo apos a operecao 
  }
  return 0.0; 

}
//---------------------


//---------------------
/**
   Method06 - Ler valores e contar positivos menores que 100 e pares (alternativo).
 */
void method_06()
{
   // identificar
   IO_id("EXEMPLO0606 - Method06 - v2.0");
  
   // declarar valores
   int Numbers = 0;
   int value   = 3;

  IO_printf("Digite o valor de vezes ( N ): \n");   
  scanf("%d", &Numbers);  getchar( );


  double after_call = invert_sum_mult_three (Numbers, value, true );   // motor da recursividade 

  IO_printf("o valor = %lf", after_call);
//
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_06 ( )
//---------------------



//funcao de auxilio para method_07
//---------------------
char revers_char (char *vector_char ,int N_numbers,bool one_call ) { // -> erro na hr de declrar a funcao, retornando um valor inteiro 
   // indentificacao
   if (one_call) { 
   IO_id ("Metodo auxilixar revers_char | version - V 2.0 \n ");
   }

   // passo base, Numbers como 
      if (N_numbers <= 0){
         return '\0'; // com isso, o final da string sera um declarar um '\0'
      }

      //invertendo a string
      IO_printf("%c", vector_char[N_numbers - 1]);


      revers_char(vector_char, N_numbers - 1, false );
}


//---------------------
/**
   Method_07 - Ler palavra, contar e mostrar numeros.""
 */
//---------------------
void method_07()
{
   IO_id("EXEMPLO0607 - Method07 - v2.0");

   // declarando varival
   char string[99];

   IO_printf("Digite uma string: ");

   // uso de fgets esta nas anotaçoes 
   fgets(string, 100, stdin);


   // Remove o '\n' que o fgets pode adicionar
   string[strcspn(string, "\n")] = '\0';

   int size = strlen(string); // pegando o index de "string" e passando esse valor para size 
   IO_printf("String invertida: ");

   // chamda da funcao recursiva 
   revers_char(string, size, true );
   IO_printf("\n");


 // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_07 ( )
//---------------------



//---------------------
//funcao de auxilio para method_08
bool Myis_digit(char letter) {
   // Verifica se um único caractere é dígito
   return (letter >= '0' && letter <= '9');
}
//---------------------


//---------------------
//funcao de auxilio para method_08
//---------------------
int is_pair(char *letter, bool one_call, int *count) { 
   if (one_call) {
       IO_id("betwen_numbers - v 2.0");
   }

   // Caso base
   if (*letter == '\0') {
       IO_printf("\nHouveram [%d] digitos pares.\n", *count);
       return *count;
   }

   if (Myis_digit(*letter)) {
      // converte 
       int value = *letter - '0';
       
       if (value % 2 != 0) {
           IO_printf("O numero [%c] e impar\n", *letter);
       } else {
           IO_printf("O numero [%c] e par\n", *letter);
           (*count)++;
       }
   }

   return is_pair(letter + 1, false, count);
}
//---------------------


//---------------------
/**
   Method_08 - Ler palavra, contar e mostrar numeros.""
 */
//---------------------
void method_08 () {
   // identificar
   IO_id("EXEMPLO0608 - Method08 - v4.0");
   
   char input[100];
   int count = 0;

   IO_printf("Digite uma string: ");

   // uso de fgets esta nas anotaçoes 
   fgets(input, 100, stdin);

   printf("Analisando a string: %s\n", input);

   is_pair(input, true, &count);
      
   // encerrar
   IO_pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
//funcao de auxilio para method_09
//---------------------
int between_C_P  (char *letter,int *count, bool one_call  ) {
   if (one_call) { 
   // indentificacao
   IO_id ("Metodo auxilixar between_C_P  | version - V 2.0 \n ");
   }

   // caso base 
   if (*letter == '\0'){ // - > faltou o *
      IO_printf("Houveram [%d] caracteres que estao entre 'C' e 'P'. \n", *count );
      return *count;
   }

   // variavel auxiliar 
   bool is_between = (  *letter > 'C' && *letter < 'P');

   if (!is_between){
   IO_printf("O caractere [%c] nao esta entre 'C' e 'P' \n", *letter);
   } else {
      IO_printf("O caractere [%c] esta entre 'C' e 'P' \n", *letter);
      *count = *count + 1;
   }

   return between_C_P (letter + 1, count, false);
}
//---------------------


//---------------------
/**
   Method_09 - Ler palavra, contar e mostrar caracteres alfanumericos 
 */
void method_09()
{
    // identificar
    IO_id("EXEMPLO0609 - Method09 - v2.0");

// iniciando variaveis
   char input[100];
   int count = 0;

   IO_printf("Digite uma string: ");
   

   // uso de fgets esta nas anotaçoes 
   fgets(input, 100, stdin);

   
    // Remove o '\n' do final
    input[strcspn(input, "\n")] = '\0';

    printf("Analisando a string: %s\n", input);


    between_C_P(input, &count, true);

   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_09 ( )
//---------------------


//---------------------
// Função para calcular o enesimo numero par da serie de Fibonacci
int fib_even_term(int n) {
   if (n == 1) return 2;       // Primeiro numero par e 2
   if (n == 2) return 8;       // Segundo número par e 8
   return 4 * fib_even_term(n - 1) + fib_even_term(n - 2);
}
//---------------------


// Função para somar os n primeiros numero pares da serie de Fibonacci
//---------------------
int sum_even_fib(int n) {
   if (n == 0) return 0;
   return fib_even_term(n) + sum_even_fib(n - 1);
}
//---------------------


//---------------------
void method_10() {

      // identificar
      IO_id("EXEMPLO0610 - Method10 - v2.0");

   int n = 0;
   IO_printf("Digite N: ");

   scanf("%d", &n); getchar ();

   int sum = sum_even_fib(n);
   printf("Soma dos %d primeiros pares de Fibonacci: %d\n", n, sum);
}
//---------------------


//---------------------
// Função para calcular potencia recursiva (x^e)
int pow_in_x(int x, int e) {
   if (e == 0) return 1; // caso o valor seja elevado a 0 seu resultado e 1
   return x * pow_in_x(x, e - 1); // o valor x * x assim que 'e' for igual a 0
}
//---------------------


//---------------------
// Funcao recursiva para calcular f(x, n) = 1 + x^3 + x^5 + ... + x^(2n+1) - > formula 
int f_xn_recursive(int x, int n) {
   if (n == 0) {
       return 1 + pow_in_x(x, 1); // 1 + x^1
   } else {
       int exponent = 2 * n + 1;
       return pow_in_x(x, exponent) + f_xn_recursive(x, n - 1);
   }
}
//---------------------


//---------------------
void method_11() {
   IO_id("EXEMPLO0611 - Method11 - v2.0");

   int x = 0;
   int n = 0;

   IO_printf("Digite o valor de x (base): ");
   IO_scanf("%d", &x); 

   IO_printf("Digite o valor de n (limite de soma): ");
   IO_scanf("%d", &n); 

   int resultado = f_xn_recursive(x, n);
   IO_printf("Resultado da funcao f(x, n): %d\n", resultado);

   IO_pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
// Funcao recursiva para calcular fatorial
int fatorial(int n) {
   if (n <= 1) return 1;
   return n * fatorial(n - 1);
}
//---------------------


//---------------------
// Funcao recursiva para calcular method 12
double calcular_e_recursivo(int term, int max) {
   if (term == 0) {
       return 1.0; // Primeiro termo é 1
   } else {
       int numerator = 2 * term + 1;
       int exponent = 1 << term; // 2^termo
       int denominator = fatorial(exponent);
       return (double)numerator / denominator + calcular_e_recursivo(term - 1, max);
   }
}
//---------------------


// --------------------
void method_12() {
   IO_id("EXEMPLO0612 - Method12 - v2.0");

   int n = 0;

   IO_printf("Digite o número de termos: ");
   IO_scanf("%d", &n);

   double result = calcular_e_recursivo(n - 1, n); // Começa do termo n-1 ate 0
   IO_printf("Resultado : %.10lf\n", result);

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
      IO_id("EXEMPLO0 600 - Programa - v0.0 \n");

      // ler do teclado
      IO_println("Opcoes");
      IO_println(" 0  - Method_00 parar");
      IO_println(" 1 - Method_01  procedimento recursivo para mostrar essa quantidade em valores multiplos de 3");
      IO_println(" 2 - Method_02  procedimento recursivo para mostrar essa quantidade em valores multiplos de 3 ( decresente ).");
      IO_println(" 3 - Method_03  mostrar essa quantidade em multiplos de 3, em ordem decrescente");
      IO_println(" 4 - Method_04  procedimento recursivo para mostrar essa quantidade em valores da sequência de inversos dos multiplos de 3");
      IO_println(" 5 - Method_05  calcular a soma de valores gerados pela adicao dos primeiros impares positivos a partir de 3");
      IO_println(" 6 - Method_06  calcular a soma dos inversos (1/x) dos primeiros valores impares positivos multiplos do valor 3");
      IO_println(" 7 - Method_07  ler uma cadeia de caracteres e chamar procedimento recursivo para mostrar cada simbolo separadamente, de tras para frente, um por linha ");
      IO_println(" 8 - Method_08  contar os digitos com valores pares em uma cadeia de caracteres.Testar essa funcao para cadeias de diferentes tamanhos. ");
      IO_println(" 9 - Method_09  calcular a quantidade de maiusculas maiores que 'C' e menores que 'P' em uma cadeia de caracteres.  ");
      IO_println("10 - Method_10  calcular certo termo par da serie de Fibonacci começando em 1");
      IO_println("11 - Method_11  calcular o valor da funcao definida abaixo,lidos os valores de (x) e (n) do teclado");
      IO_println("12 - Method_12   calcular o valor indicado abaixo, lido o número de termos (n) do teclado");

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