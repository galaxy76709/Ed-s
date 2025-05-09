
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
#include <stdio.h>  // biblioteca de apoio
#include <stdlib.h> // biblioteca de apoio
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "io.h"
#define Max_size 100
//---------------------


// enum para os tipos de símbolo
//---------------------
typedef enum {
    MAIUSCULA,
    MINUSCULA,
    DIGITO,
    LOGICO,
    ARITMETICO,
    RELACIONAL,
    SEPARADOR,
    OUTRO
} TipoSimbolo;
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
int pair_dividers (int value){
//definindo valores
    int count = 0;
    int i     = 1;

// iniciando laço de repeticao 
    while (i <= value)
    {
        if  (value %  i == 0 && value % 2 == 0 )
        {count = count + 1;}

        i = i + 1;
    }//end while

    return count;

}
//---------------------


//---------------------
int odd_divisors (int value){
    //definindo valores
        int count = 0;
        int i     = 1;
    
    // iniciando laço de repeticao 
        while (i <= value)
        {
            if  (value %  i == 0 && value % 2 != 0 )
            {count = count + 1;}
    
            i = i + 1;
        }// end while 
    
        return count;
    
    }
//---------------------


//---------------------
/** 
   questao_01 - Qual o ultimo valor de x a aparecer na tela? 
 */ 
void question_01 ( void ) 
{ 
 // definir dado 
 int n     = 0;
 int count = 0;

 n = IO_readint("Digite a quantidade de valores: ");

 while (count < n) {
    int x = IO_readint("Digite um valor inteiro: ");
    int pair = pair_dividers(x);
    int odd = odd_divisors(x);

    if (pair > odd) {
        IO_printf("Mais divisores pares.\n");
    } 

    else if (odd > pair) 
    {
        IO_printf("Mais divisores ímpares.\n");
    } 

    else 
    {
        IO_printf("Mesma quantidade de divisores pares e impares.\n");
    }

    count = count + 1;
}// end while



 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end questao_01 ( ) 
//---------------------


//---------------------

//---------------------
bool prime_divisors (int value){
    //definindo valores
    bool result = false;
    int i = 2;
    int divider = 0;

    if (value > 1) {// condicao de valor
        while (i <= value / 2) { // laco de repeticao

            if (value % i == 0) {

                divider = divider + 1;
            }

            i = i + 1;
        }

        result = (divider   == 0);

    } else {

        result = false;
    }

    return result;
}
//---------------------


//--------------------- 
/** 
   Method_02. 
 */ 
void question_02 ( ) 
{ 
 // definir dados 
 int n        = 0; 
 int contador = 0;

    n = IO_readint("Digite a quantidade de valores: ");


 while ( contador  <  n ) {

     int x = IO_readint("Digite um valor inteiro: ");
     bool resposta = prime_divisors ( x ) ;

     // condicao de verificao 
     if (resposta) {
         IO_printf("%d e primo.\n", x);
     } else {
         IO_printf("%d NAO e primo.\n", x);
     }

     contador = contador + 1;
 }// end while
    
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_02 ( ) 
//---------------------



// ----------------------------
// Funções de verificação
// ----------------------------

bool testar_simbolo_logico(char c) {
    bool resultado = false;

    switch (c) {
        case '&':
        case '|':
        case '!':
            resultado = true;
            break;
        default:
            resultado = false;
    }

    return resultado;
}

bool testar_simbolo_aritmetico(char c) {
    bool resultado = false;

    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            resultado = true;
            break;
        default:
            resultado = false;
    }

    return resultado;
}

bool testar_simbolo_relacional(char c) {
    bool resultado = false;

    switch (c) {
        case '>':
        case '<':
        case '=':
            resultado = true;
            break;
        default:
            resultado = false;
    }

    return resultado;
}

bool testar_separador(char c) {
    bool resultado = false;

    switch (c) {
        case ' ':
        case '.':
        case ',':
        case ';':
        case ':':
        case '_':
            resultado = true;
            break;
        default:
            resultado = false;
    }

    return resultado;
}

// ----------------------------
// Procedimento principal
// ----------------------------

void question_03() {
    char array[Max_size]; // define o tamanho máximo da string (somente 100 )

    IO_printf("Digite uma cadeia de caracteres: ");
    IO_scanf("%s", array);  // lê string SEM espaços. Para incluir espaços, usar fgets em C padrão

    int i = 0;

    while (array[i] != '\0') {
        char c = array[i];

        if (testar_simbolo_logico(c)) {
            IO_printf("'%c' e um operador logico\n", c);
        } else if (testar_simbolo_aritmetico(c)) {
            IO_printf("'%c' e um operador aritmetico\n", c);
        } else if (testar_simbolo_relacional(c)) {
            IO_printf("'%c' e um operador relacional\n", c);
        } else if (testar_separador(c)) {
            IO_printf("'%c' e um separador\n", c);
        } else {
            IO_printf("'%c' e outro simbolo\n", c);
        }

        i = i + 1;
    }

 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_03 ( ) 

//---------------------


// retorna true se c for letra maiuscula
bool testar_maiuscula(char c) {
    bool resultado = false;
    if (c >= 'A' && c <= 'Z') {
        resultado = true;
    }
    return resultado;
}

// retorna true se c for letra minuscula
bool testar_minuscula(char c) {
    bool resultado = false;
    if (c >= 'a' && c <= 'z') {
        resultado = true;
    }
    return resultado;
}

// retorna true se c for digito
bool testar_digito(char c) {
    bool resultado = false;
    if (c >= '0' && c <= '9') {
        resultado = true;
    }
    return resultado;
}

// retorna true se c for operador logico
bool testar_simbolo_logico(char c) {
    bool resultado = false;
    switch (c) {
        case '&': case '|': case '!':
            resultado = true;
            break;
        default:
            resultado = false;
    }
    return resultado;
}

// retorna true se c for operador aritmetico
bool testar_simbolo_aritmetico(char c) {
    bool resultado = false;
    switch (c) {
        case '+': case '-': case '*': case '/': case '%':
            resultado = true;
            break;
        default:
            resultado = false;
    }
    return resultado;
}

// retorna true se c for operador relacional
bool testar_simbolo_relacional(char c) {
    bool resultado = false;
    switch (c) {
        case '<': case '>': case '=':
            resultado = true;
            break;
        default:
            resultado = false;
    }
    return resultado;
}

// retorna true se c for separador
bool testar_separador(char c) {
    bool resultado = false;
    switch (c) {
        case ' ': case '.': case ',': case ';': case ':': case '_':
            resultado = true;
            break;
        default:
            resultado = false;
    }
    return resultado;
}


// usa apenas 1 return, resultado inicial = OUTRO
TipoSimbolo identificar_tipo(char c) {
    TipoSimbolo tipo = OUTRO;

    if (testar_maiuscula(c)) {
        tipo = MAIUSCULA;
    }
    else if (testar_minuscula(c)) {
        tipo = MINUSCULA;
    }
    else if (testar_digito(c)) {
        tipo = DIGITO;
    }
    else if (testar_simbolo_logico(c)) {
        tipo = LOGICO;
    }
    else if (testar_simbolo_aritmetico(c)) {
        tipo = ARITMETICO;
    }
    else if (testar_simbolo_relacional(c)) {
        tipo = RELACIONAL;
    }
    else if (testar_separador(c)) {
        tipo = SEPARADOR;
    }

    return tipo;
}


//--------------------- 
/** 
   Method_04. 
 */ 
void question_04 ( ) 
{ 

   
    char cadeia[Max_size]; // tamanho maximo de 100 
    
    // definindo variaveis
    IO_printf("Digite uma cadeia de caracteres (sem espaços): ");
    IO_scanf("%s", cadeia);

    // contadores iniciais
    int contMai = 0, contMin = 0, contDig = 0;
    int contLog = 0, contAri = 0, contRel = 0, contSep = 0, contOut = 0;

    int i = 0;
    while (cadeia[i] != '\0') {
        TipoSimbolo tipo = identificar_tipo(cadeia[i]);

        // switch para agrupar as contagens
        switch (tipo) {
            case MAIUSCULA:    contMai = contMai + 1;  break;
            case MINUSCULA:    contMin = contMai + 1;  break;
            case DIGITO:       contDig = contDig + 1;  break;
            case LOGICO:       contLog = contLog + 1;  break;
            case ARITMETICO:   contAri = contAri + 1;  break;
            case RELACIONAL:   contRel = contRel + 1;  break;
            case SEPARADOR:    contSep = contSep + 1;  break;
            default:           contOut = contOut + 1;  break;
        }

        i = i + 1;
    }

    // exibe os resultados
    IO_printf("\nResultados da análise:\n");
    IO_printf("Maiusculas:      %d\n", contMai);
    IO_printf("Minusculas:      %d\n", contMin);
    IO_printf("Digitos:         %d\n", contDig);
    IO_printf("Operadores logicos:   %d\n", contLog);
    IO_printf("Operadores aritmeticos:%d\n", contAri);
    IO_printf("Operadores relacionais:%d\n", contRel);
    IO_printf("Separadores:     %d\n", contSep);
    IO_printf("Outros simbolos: %d\n", contOut);


 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_04 ( )
//---------------------


// Funcao para verificar se o valor esta no intervalo [inferior, superior]
bool no_intervalo(double inferior, double superior, double valor) {
    bool resultado = false;

    if (valor >= inferior && valor <= superior) {
        resultado = true;
    }

    return resultado;
}

// Funcao para retornar o maior dentre tres valores
double maior3(double x, double y, double z) {
    double maior = x;

    if (y > maior) {
        maior = y;
    }

    if (z > maior) {
        maior = z;
    }

    return maior;
}


//---------------------
/** 
   Method_05. 
 */ 
void question_05 ( ) 
{ 
    //declarando valores

        int n = 0;
        int n = IO_readint("Digite a quantidade de valores: ");
        
        // contadores e somadores
        int cont_baixo = 0, cont_medio = 0, cont_alto = 0;
        double soma_baixo = 0.0, soma_medio = 0.0, soma_alto = 0.0;
    
        for (int i = 0; i < n; i++) {
            double x = IO_readdouble("Digite um valor real: ");
    
            if (x < -21.75) {
                soma_baixo += x;
                cont_baixo++;
            } else if (no_intervalo(-21.75, 71.25, x)) {
                soma_medio += x;
                cont_medio++;
            } else {
                soma_alto += x;
                cont_alto++;
            }
        }
    
        // cálculo das médias
        double media_baixo = (cont_baixo > 0) ? soma_baixo / cont_baixo : 0.0;
        double media_medio = (cont_medio > 0) ? soma_medio / cont_medio : 0.0;
        double media_alto  = (cont_alto  > 0) ? soma_alto  / cont_alto  : 0.0;
    
        // exibir resultados
        IO_printf("\nMedia dos valores < -21.75:           %lf\n", media_baixo);
        IO_printf("Media dos valores entre [-21.75,71.25]: %lf\n", media_medio);
        IO_printf("Media dos valores > 71.25:            %lf\n", media_alto);
    
        double maior_media = maior3(media_baixo, media_medio, media_alto);
        IO_printf("\nMaior media encontrada: %lf\n", maior_media);
    
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_05 ( )
//---------------------



// Funcao para testar se valor esta no intervalo aberto ]a:b[
    bool dentro_intervalo_aberto(int a, int b, int x) {
        bool resultado = false;
    
        if (x > a && x < b) {
            resultado = true;
        }
    
        return resultado;
    }
    
    // Funcao para verificar se e impar e nao multiplo de 3
    bool impar_nao_multiplo_3(int x) {
        bool resultado = false;
    
        if (x % 2 != 0 && x % 3 != 0) {
            resultado = true;
        }
    
        return resultado;
    }
    
    // Função para somar cubos dos inversos dos ímpares não múltiplos de 3 no intervalo aberto ]a:b[
    double soma_inversos_dos_cubos(int a, int b) {
        int valor = 0;
        double soma = 0.0;
    
        do {
            valor = IO_readint("Digite um valor inteiro (-1 para encerrar): ");
    
            if (valor != -1 && valor != 0) { // evitar divisão por zero
    
                if (dentro_intervalo_aberto(a, b, valor) && impar_nao_multiplo_3(valor)) {
                    soma += 1.0 / pow(valor, 3);
                }
            }
    
        } while (valor != -1);
    
        return soma;
    }


//---------------------
/** 
   Method_06. 
 */ 
void question_06 ( ) 
{ 
 
    int a = IO_readint("Digite o valor de a: ");
    int b = IO_readint("Digite o valor de b: ");

    double resultado = soma_inversos_dos_cubos(a, b);

    IO_printf("\nSoma dos cubos dos inversos dos impares nao multiplos de 3 no intervalo aberto ]a:b[: %lf\n", resultado);

 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_06 ( ) 
//---------------------
 


// Testar se valor está em ]a:b[
    bool no_intervalo(double a, double b, double x) {
        bool resultado = false;
    
        if (x > a && x < b) {
            resultado = true;
        }
    
        return resultado;
    }
//---------------------


//---------------------
void analisar_intervalos(double a, double b, 
                        int* dentro, int* abaixo, 
                        int* acima) {
    double valor = 0.0;
    *dentro = 0;
    *abaixo = 0;
    *acima  = 0;
    
    do {
       valor = IO_readdouble("Digite um valor real (0 para encerrar): ");
    
    if (valor != 0.0) {
      
        if (no_intervalo(a, b, valor)) {
            (*dentro)++;

       } else if (valor < a) {
           (*abaixo)++;
           
       } else if (valor > b) {
          (*acima)++;
                }
      }
 
    } while (valor != 0.0);
}
//---------------------


//---------------------
/** 
   Method_07. 
 */ 
void question_07 ( ) 
{ 
    double a = IO_readdouble("Digite o valor de a (limite inferior): ");
    double b = IO_readdouble("Digite o valor de b (limite superior): ");

    int dentro = 0, abaixo = 0, acima = 0;

    analisar_intervalos(a, b, &dentro, &abaixo, &acima);

    int total = dentro + abaixo + acima;

    double porc_abaixo = 0.0, porc_acima = 0.0;

    if (total > 0) {
        porc_abaixo = 100.0 * abaixo / total;
        porc_acima  = 100.0 * acima  / total;
    }

    IO_printf("\nQuantidade dentro do intervalo ]a:b[: %d\n", dentro);
    IO_printf("Quantidade abaixo do intervalo: %d\n", abaixo);
    IO_printf("Quantidade acima do intervalo:  %d\n", acima);
    IO_printf("Porcentagem abaixo: %.2lf%%\n", porc_abaixo);
    IO_printf("Porcentagem acima:  %.2lf%%\n", porc_acima);
  
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_07 ( ) 
//---------------------


//---------------------
// Testar se os valores estão em ordem crescente
bool crescente(double x, double y, double z) {
    return (x < y && y < z);
}

// Testar se os valores estão em ordem decrescente
bool decrescente(double x, double y, double z) {
    return (x > y && y > z);
}

// Retornar o maior entre três valores
double maior(double x, double y, double z) {
    double maior = x;

    if (y > maior) {
        maior = y;
    }
    if (z > maior) {
        maior = z;
    }

    return maior;
}

// Retornar o menor entre três valores
double menor(double x, double y, double z) {
    double menor = x;

    if (y < menor) {
        menor = y;
    }
    if (z < menor) {
        menor = z;
    }

    return menor;
}
//---------------------


//---------------------
/** 
   Method_08. 
 */ 
void question_08 ( ) 
{ 
    // ler os três valores
    double x = IO_readdouble("Digite o primeiro valor (x): ");
    double y = IO_readdouble("Digite o segundo valor (y): ");
    double z = IO_readdouble("Digite o terceiro valor (z): ");

    // usar funções para verificar ordem
    bool ehCrescente   = crescente(x, y, z);
    bool ehDecrescente = decrescente(x, y, z);

    if (ehCrescente) {
        IO_printf("Os valores estao em ordem crescente.\n");

    } else if (ehDecrescente) {
       
        IO_printf("Os valores estao em ordem decrescente.\n");
    } else {

        double maior_valor = maior(x, y, z);
        double menor_valor = menor(x, y, z);
        
        IO_printf("Os valores nao estao em ordem crescente nem decrescente.\n");
        IO_printf("Maior valor: %.2lf\n", maior_valor);
        IO_printf("Menor valor: %.2lf\n", menor_valor);
    }


 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_08 ( )
//---------------------

// Verificar se y é sucessor de x na ordem alfabética (código ASCII)
bool sucessor(char x, char y) {  return (x < y); }

// Verificar se três caracteres estão em ordem alfabética crescente
bool crescente(char x, char y, char z) {

    return (sucessor(x, y) && sucessor(y, z));

 }

// Verificar se três caracteres estão em ordem alfabética decrescente
bool decrescente(char x, char y, char z) {
    return (x > y && y > z);
}


void question_09 ( ) {
    // Ler os três caracteres
    char x = IO_readchar("Digite o primeiro caractere (x): ");
    char y = IO_readchar("Digite o segundo caractere (y): ");
    char z = IO_readchar("Digite o terceiro caractere (z): ");

    // Avaliar ordem
    bool ehCrescente = crescente(x, y, z);
    bool ehDecrescente = decrescente(x, y, z);

    if (ehCrescente) {
        IO_printf("Os caracteres estao em ordem alfabetica crescente.\n");
    } else if (ehDecrescente) {
        IO_printf("Os caracteres estao em ordem alfabetica decrescente.\n");
    } else {
        IO_printf("Os caracteres NAO estao em ordem alfabetica crescente nem decrescente.\n");
    }

    IO_pause("Apertar ENTER para continuar");
}


// Verificar se as strings estão em ordem alfabética crescente
bool ordem_crescente(char* x, char* y, char* z) {
    return (strcmp(x, y) <= 0 && strcmp(y, z) <= 0);
}

// Verificar se as strings estão em ordem alfabética decrescente
bool ordem_decrescente(char* x, char* y, char* z) {
    return (strcmp(x, y) >= 0 && strcmp(y, z) >= 0);
}

// Obter a menor string entre as três
char* Menor(char* x, char* y, char* z) {
    char* menor = x;
    if (strcmp(y, menor) < 0) {
        menor = y;
    }
    if (strcmp(z, menor) < 0) {
        menor = z;
    }
    return menor;
}

// Obter a maior string entre as três
char* Maior(char* x, char* y, char* z) {
    char* maior = x;
    if (strcmp(y, maior) > 0) {
        maior = y;
    }
    if (strcmp(z, maior) > 0) {
        maior = z;
    }
    return maior;
}


void question_10 ( ) {
    // Declaração das variáveis
    chars x = IO_new_chars(STR_SIZE);
    chars y = IO_new_chars(STR_SIZE);
    chars z = IO_new_chars(STR_SIZE);

    // Leitura das strings
    x = IO_readstring("Digite a primeira cadeia de caracteres (x): ");
    y = IO_readstring("Digite a segunda cadeia de caracteres (y): ");
    z = IO_readstring("Digite a terceira cadeia de caracteres (z): ");

    // Verificações de ordem
    if (ordem_crescente(x, y, z)) {
        IO_printf("As cadeias estao em ordem alfabetica crescente.\n");
    } else if (ordem_decrescente(x, y, z)) {
        IO_printf("As cadeias estao em ordem alfabetica decrescente.\n");
    } else {
        IO_printf("As cadeias NAO estao em ordem alfabetica crescente nem decrescente.\n");
        IO_printf("Menor cadeia: %s\n", Menor(x, y, z));
        IO_printf("Maior cadeia: %s\n", Maior(x, y, z));
    }

    IO_pause("Apertar ENTER para continuar");
}

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
      IO_println(" 9 - question_09  ques 09.");
      IO_println("10 - question_10  ques 10 ");
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
         case  9:  question_09 ( );   break;
         case  10:  question_10 ( );   break;

        

      default:
         IO_pause(IO_concat("Valor diferente das opcoes [0 a 10] (",
                            IO_concat(IO_toString_d(x), ")")));
      } // end switch
   } while (x != 0);

   // encerrar
   IO_pause("Apertar ENTER para terminar");
   return (0);
} // end main ( )