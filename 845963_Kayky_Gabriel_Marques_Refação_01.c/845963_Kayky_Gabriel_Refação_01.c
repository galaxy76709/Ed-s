
/*
   Exemplo 0800 - v0.0. - 29 / 04 / 2025
   Author: Kayky_Gabriel_Marques

   Para compilar em terminal (janela de comandos):
   Linux  : gcc -o exemplo0800        exemplo0800.c
   Windows: gcc -o exemplo0800        exemplo0800.c

   Para executar em terminal (janela de comandos):
   Linux      :  ./exemplo0200
   Windows:    exemplo0200
 */

//---------------------
// dependencias
#include "io.h"     // para definicoes proprias
#include <stdio.h>  // biblioteca de apoio
#include <stdlib.h> // biblioteca de apoio
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define Max_size 100
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


//---------------------
/** 
   questao_01 - Qual o ultimo valor de x a aparecer na tela? 
 */ 
void question_01 ( void ) 
{ 
 // definir dado 
    int n = 8, x = 4, y = n, z = 0;
 
    while ( z  <  y ){

        printf("\nz: %d\ny: %d \n", z, y);

        printf("\nx: %d\n", x);

        x = x + 3 * z - 1;

        printf("\nx: %d\n", x);

        if (x % 7 == 0){
  
            y = y + 1;
        printf("\ny: %d\n", y);

        } else {

            printf("\nx: %d", x);

        }

       z = z + 1;   
    }
 
 // executar o metodo auxiliar 
 
 printf ("A resposta e letra E) nenhuma das outras %d ", x);
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end questao_01 ( ) 
//---------------------


//---------------------



//--------------------- 
/** 
   Method_02. 
 */ 
void question_02 ( ) 
{ 
 // definir dados 
    char s [ ] = "A12*3-d4+(B+C)/E5;";
    int x = 0;

    for (x = strlen (s) / 2; x < strlen (s); x = x + 1)
    {
        if('A' <= s[x] && s[x] <= 'Z')
        { printf("%c", s [ x ] ); x = x + 2; }

        printf("A resposta e D) ");
    }

    
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_02 ( ) 
//---------------------


int f_03 (int x )
{
    int y = x;

    if ( x % 2 == 0 )

    y = f_03 (x - 1);

    else if (x < 2)
    y = y + f_03 ( x - 2 );

    return ( y );
}


//---------------------
/** 
   Method_03. 
 */ 
void question_03 ( ) 
{ 
 // definir dados 
    int x = 10;

    int resp = f_03 ( x );

    printf("f_03 ( %d ) = %d\n", 10, f_03(10));

    printf("Resposta letra E) %d", resp);


 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_03 ( ) 

//---------------------

//--------------------- 
/** 
   Method_04. 
 */ 
void question_04 ( ) 
{ 
   // definir dados 
   int n = 123321, x = 0, y = 0 ,z = 0, p = 1;

   while ( p <= n )
   {
      p = p * 10;
      z = z + 1;
   }

   p = p / 10;
   z = z / 2;

   while ( x < z )
   {

   if (  n / p == n % 10 ){ 
   
   y = y + 1;
   
   n = n % p / 10;

   p = p / 100;

   x = x + 1;
      
   }
   
   else  x = z; 

}

   
   
   printf ("Resposta A) y = %d, z = %d", y , z);

 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_04 ( )
//---------------------



//---------------------
/** 
   Method_05. 
 */ 
void question_05 ( ) 
{ 

  // (início)
  	 int n = 5, y = 3, x = 1, impar = 1;
  	
  	     x = x + 1; // (I)
  	    printf("%d\t%d\n", x, y); // imprime valor inicial
	
  	while (x <= n) // (II)
  	{
  	y = y + impar;
   printf("%d\t%d\n", x, y);
  	
  	impar = 2 * x - 1;
  	x = x + 1; // (III)
  	}
	
   printf("A resposta e letra D)  x = x + 1; // (I)  (x <= n) // (II) x = x + 1; // (III) ");

 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_05 ( )
//---------------------

bool is_Multiple_Of_7(int value) {
  
   while (value >= 10 || value <= -10) {
      // caso tiver mais de um numero (usei apenas 10 tomar cuidado ao usar)
      
      int last = value % 10;
      
      int rest = value / 10;
      
      value = rest - 2 * last;
   
   }
   return (value == 0 || value == 7 || value == -7);
}


//---------------------
/** 
   Method_06. 
 */ 
void question_06 ( ) 
{ 
 
   int numbers[] = {28, 30, 35, 91, 231, 105};

   for (int i = 0; i < 6; i++) {

      int x = numbers[i];
           
      IO_printf("Valor: %d -> ", x);

      if (is_Multiple_Of_7(x)) {
          IO_printf("Multiplo de 7\n");

      } else {
          IO_printf("Nao e multiplo de 7\n");

      }
  }

 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_06 ( ) 
//---------------------
 

double somatorio(double limite) {

   double soma = 0.0;

   int n = 1;

   int sinal = 1;


   while (IO_abs_d(soma) < limite) {

       soma += sinal * (1.0 / n);

       n = n + 1;

       sinal = sinal * -1;

   }

   return soma;
}


//---------------------

/** 
   Method_07. 
 */ 
void question_07 ( ) 
{ 
    double limite = 0.0;

    double limite = IO_readdouble("Digite o limite do somatorio: ");
    
    double resultado = somatorio(limite);

    IO_printf("Somatorio (limite %.2lf): %.6lf\n", limite, resultado);


 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_07 ( ) 
//---------------------


bool testar(char *palavra1, char *palavra2, int tamSilaba) {

   int len1 = strlen(palavra1);
   int len2 = strlen(palavra2);


   if (tamSilaba <= len1 && tamSilaba <= len2) {
       char ultima[10], primeira[10];

       strncpy(ultima, palavra1 + len1 - tamSilaba, tamSilaba);
       ultima[tamSilaba] = '\0';


       strncpy(primeira, palavra2, tamSilaba);
       primeira[tamSilaba] = '\0';


       return (strcmp(ultima, primeira) == 0);
   }

   return false;
}

//---------------------
/** 
   Method_08. 
 */ 
void question_08 ( ) 
{ 
 
    char palavra1[Max_size];

    char palavra2[Max_size];
    
    int tam = 0;

    IO_printf("Informe a primeira palavra: ");
    IO_scanf("%s", palavra1);

    IO_printf("Informe a segunda palavra: ");
    IO_scanf("%s", palavra2);

    tam = IO_readint("Informe o tamanho da silaba (>=2): ");

    if (testar(palavra1, palavra2, tam)) {
        IO_printf("Ha parequema entre as palavras.\n");

    } else {
        IO_printf("Nao ha parequema entre as palavras.\n");

    }

 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_08 ( )
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
      IO_id("EXEMPLO0 800 - Programa - v0.0 \n");

      // ler do teclado
      IO_println("Opcoes");
      IO_println(" 0  -            parar");
      IO_println(" 1 - question_01  ques 01.");
      IO_println(" 2 - question_02  ques 02.");
      IO_println(" 3 - question_03  ques 03.");
      IO_println(" 4 - question_04  ques 04.");
      IO_println(" 5 - question_05  ques 05.");
      IO_println(" 6 - question_06  ques 06.");
      IO_println(" 7 - question_07  ques 07.");
      IO_println(" 8 - question_08  ques 08.");
      IO_println("");

      x = IO_readint("Entrar com uma opcao: ");

      // testar valor
      switch (x)
      {
         case  0:    method_00 ( );   break; 
         case  1:  question_01 ( );   break;
         case  2:  question_02 ( );   break;   
         case  3:  question_03 ( );   break;
         case  4:  question_04 ( );   break;
         case  5:  question_05 ( );   break;  
         case  6:  question_06 ( );   break;
         case  7:  question_07 ( );   break;        
         case  8:  question_08 ( );   break;
        

      default:
         IO_pause(IO_concat("Valor diferente das opcoes [0 a 10] (",
                            IO_concat(IO_toString_d(x), ")")));
      } // end switch
   } while (x != 0);

   // encerrar
   IO_pause("Apertar ENTER para terminar");
   return (0);
} // end main ( )