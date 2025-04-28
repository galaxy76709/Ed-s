
/*
   Exemplo0 600 - v0.0. - 27 / 03 / 2025
   Author: Kayky_Gabriel_Marques

   Para compilar em terminal (janela de comandos):
   Linux      : gcc -o exemplo0600        exemplo0600.c
   Windows: gcc -o exemplo0600        exemplo600.c

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
   writeInts - Gravar em arquivo texto certa quantidade de valores. 
   @param fileName - nome do arquivo 
   @param x - quantidade de valores 
 */ 
void writeInts ( chars fileName, int x ) // chamando a funcao para ler o arquivo
{ 
 // definir dados 
    FILE* arquivo = fopen ( fileName, "wt" );  
    int y = 0; 
 
 // repetir para a quantidade de dados 
    for ( y = 1; y <= x; y = y + 1 ) 
    { 
     // gravar valor 
        fprintf ( arquivo, "%d\n", y ); 
    } // end for 
 
 // fechar arquivo (INDISPENSAVEL para gravacao) 
    fclose ( arquivo ); 
} // end writeInts ( ) 
//---------------------


//---------------------
/** 
   Method_01 - Mostrar certa quantidade de valores. 
 */ 
void method_01 ( ) 
{ 
 // identificar 
    IO_id ( "Method_01 - v0.0" ); 
 
 // executar o metodo auxiliar 
    writeInts ( "DADOS1.TXT", 10 ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_01 ( )
//---------------------


//---------------------
 /** 
   readInts - Ler de arquivo texto certa quantidade de valores. 
   @param fileName - nome do arquivo 
   @param x - quantidade de valores 
*/ 
void readInts(char* fileName) 
{ 
    // definir dados 
    FILE* arquivo = fopen(fileName, "rt"); 
    int x = 0;  // Variável para armazenar os valores lidos
    
    if (arquivo != NULL) { // condicao que preve se o ponteiro esta aterrado 
       

    // tentar ler o primeiro valor
    while (fscanf(arquivo, "%d", &x) != EOF) 
    { 
        // mostrar valor 
        printf("%d\n", x); 
    }
}
    
    printf("Erro ao abrir o arquivo, o descritor esta aterrado %s\n", fileName);
    // fechar arquivo
    fclose(arquivo); 
}
//--------------------- 


//---------------------
/** 
   Method_02. 
 */ 
void method_02 ( ) 
{ 
 // identificar 
    IO_id ( "Method_02 - v0.0" ); 
 
 // executar o metodo auxiliar 
    readInts ( "DADOS1.TXT" ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_02 ( ) 
//---------------------


//---------------------
/** 
   writeDoubles - Gravar em arquivo texto certa quantidade de valores. 
   @param fileName - nome do arquivo 
   @param x        - quantidade de valores 
   funcao que serve para gravar valores reais
 */ 
void writeDoubles ( chars fileName, int x ) 
{ 
 // definir dados 
    FILE* arquivo = fopen ( fileName, "wt" ); 
    int y = 0; 
 
 // gravar quantidade de valores 
    IO_fprintf ( arquivo, "%d\n", x ); 
 // repetir para a quantidade de dados 
    for ( y = 1; y <= x; y = y + 1 ) 
    { 
     // gravar valor 
        IO_fprintf ( arquivo, "%lf\n", (0.1*y) ); 
    } // end for 
 
 // fechar arquivo (INDISPENSAVEL para gravacao) 
    fclose ( arquivo ); 
} // end writeDoubles ( ) 
//---------------------


//---------------------
/** 
   Method_03. 
 */ 
void method_03 ( ) 
{ 
 // identificar 
    IO_id ( "Method_03 - v0.0" ); 
 
 // executar o metodo auxiliar 
    writeDoubles ( "DADOS2.TXT", 10 ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_03 ( ) 
//---------------------


//---------------------
/** 
   readDoubles - Ler de arquivo texto certa quantidade de valores. 
   @param fileName - nome do arquivo 
   @param x        - quantidade de valores 
   funcao para ler valores reais
 */ 
void readDoubles ( chars fileName ) 
{ 
 // definir dados 
    FILE* arquivo = fopen ( fileName, "rt" ); 
    int        x =   0  ; 
    int        y =   1  ; 
    double     z =   0.0; 
 
 // tentar ler a quantidade de dados 
    fscanf ( arquivo, "%d", &x ); 
 // repetir enquanto houver dados e 
 // quantidade nao tiver sido alcancada 
    while ( ! feof ( arquivo ) && y <= x ) 
    { 
     // tentar ler 
        fscanf ( arquivo, "%lf", &z ); 
     // mostrar valor 
        printf ( "%2d: %lf\n", y, z ); 
     // passar ao proximo 
        y = y + 1; 
    } // end while 
 
 // fechar arquivo (RECOMENDAVEL para leitura) 
    fclose ( arquivo ); 
} // end readDoubles ( )
//---------------------


//--------------------- 
/** 
   Method_04. 
 */ 
void method_04 ( ) 
{ 
 // identificar 
    IO_id ( "Method_04 - v0.0" ); 
 
 // executar o metodo auxiliar 
    readDoubles ( "DADOS2.TXT" ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_04 ( )
//---------------------


//---------------------
/** 
   writeText - Gravar em arquivo texto certa quantidade de valores. 
   @param fileName - nome do arquivo 
   @param x - quantidade de valores 
 */ 
void writeText ( chars fileName ) 
{ 
 // definir dados 
    FILE* arquivo = fopen ( fileName, "wt" ); 
    chars linha     = IO_new_chars ( STR_SIZE ); 
 
 // repetir ate' desejar parar 
    IO_println ( "Gravar linhas (para terminar, entrar com \"PARAR\"):\n" ); 
    do 
    { 
     // ler do teclado 
        strcpy ( linha, IO_readln ( "" ) ); 
     // gravar valor 
        IO_fprintf ( arquivo, "%s\n", linha ); 
    } 
    while ( strcmp ( "PARAR", linha ) != 0 ); 
 
 // fechar arquivo (INDISPENSAVEL para gravacao) 
    fclose ( arquivo ); 
} // end writeText ( ) 
//---------------------


//---------------------
/** 
   Method_05. 
 */ 
void method_05 ( ) 
{ 
 // identificar 
    IO_id ( "Method_05 - v0.0" ); 
 
 // executar o metodo auxiliar 
    writeText ( "DADOS5.TXT" ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_05 ( ) 
//---------------------


//---------------------
/** 
   readText - Ler de arquivo texto certa quantidade de valores.
   @param fileName - nome do arquivo
 */
void readText(chars fileName) 
{ 
    // definir dados 
    FILE* arquivo = fopen(fileName, "rt"); 
    
    // verificar se o arquivo foi aberto
    if (arquivo == NULL) 
    {
        IO_printf("\nERRO: Nao foi possivel abrir o arquivo [%s]\n", fileName);
        return;
    }
    
    chars linha = IO_new_chars(STR_SIZE); 
 
    // tentar ler o primeiro 
    strcpy(linha, IO_freadln(arquivo)); 
    
    // repetir enquanto houver dados 
    while (!feof(arquivo) && strcmp("PARAR", linha) != 0) 
    { 
        // mostrar valor 
        IO_printf("%s\n", linha); 
        
        // tentar ler o proximo 
        strcpy(linha, IO_freadln(arquivo)); 
    } // end while 
 
    // fechar arquivo (RECOMENDAVEL para leitura) 
    fclose(arquivo); 
    
    // liberar memoria
    free(linha);
} // end readText ( )
//---------------------

//---------------------
/** 
   Method_06. 
 */ 
void method_06() 
{ 
    // identificar 
    IO_id("Method_06 - v0.0"); 
 
    // executar o metodo auxiliar 
    readText("DADOS3.TXT"); 
 
    // encerrar 
    IO_pause("Apertar ENTER para continuar"); 
} // end method_06 ( )
//---------------------


//---------------------
/**
   copyText - Copiar arquivo texto. 
   @param fileOut - nome do arquivo de saida     (destino) 
   @param fileIn  - nome do arquivo de entrada   (origem ) 
*/ 
void copyText ( chars fileOut, chars fileIn ) 
{ 
    // definir dados 
    FILE* saida    = fopen ( fileOut, "wt" ); 
    FILE* entrada  = fopen ( fileIn , "rt" ); 
    chars linha    = IO_new_chars ( STR_SIZE ); 
    int contador   = 0; 
 
    // testar se arquivos foram abertos corretamente
    if ( entrada != NULL && saida != NULL )
    {
        // ler a primeira linha da origem
        strcpy ( linha, IO_freadln ( entrada ) );

        // repetir enquanto nao for "PARAR" e nao for fim do arquivo
        while ( ! feof ( entrada ) && strcmp ( linha, "PARAR" ) != 0 )
        {
            // contar linha lida
            contador++;

            // gravar no destino
            IO_fprintln ( saida, linha );

            // ler a proxima linha da origem
            strcpy ( linha, IO_freadln ( entrada ) );
        }

        // informar total de linhas copiadas
        IO_printf ( "Lines read = %d\n", contador );

        // fechar arquivos
        fclose ( saida );
        fclose ( entrada );
    }
    else
    {
        IO_printf ( "Erro ao abrir arquivos.\n" );
    }
} // end copyText
//---------------------

 
//---------------------
/** 
   Method_07. 
 */ 
void method_07 ( ) 
{ 
 // identificar 
    IO_id ( "Method_07 - v0.0" ); 
 
 // executar o metodo auxiliar 
    copyText ( "DADOS4.TXT", "DADOS3.TXT" ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_07 ( ) 
//---------------------
 

//---------------------
/** 
   appendText - Gravar em arquivo texto certa quantidade de valores. 
   @param fileName - nome do arquivo 
   @param x - quantidade de valores 
 */ 
void appendText ( chars fileName ) 
{ 
 // definir dados 
    FILE* arquivo = fopen ( fileName, "at" ); 
    chars linha     = IO_new_chars ( STR_SIZE ); 
 
 // repetir ate' desejar parar 
    IO_println ( "Gravar linhas (para terminar, entrar com \"PARAR\"):\n" ); 
    do 
    { 
     // ler do teclado 
        strcpy ( linha, IO_readln ( "" ) ); 
     // gravar valor 
        IO_fprintln ( arquivo, linha ); 
    } 
    while ( strcmp ( "PARAR", linha ) != 0 ); 
 
 // fechar arquivo (INDISPENSAVEL para gravacao) 
    fclose ( arquivo ); 
} // end appendText ( ) 
//---------------------


//---------------------
/** 
   Method_08. 
 */ 
void method_08 ( ) 
{ 
 // identificar 
    IO_id ( "EXEMPLO0710 - Method_08 - v0.0" ); 
 
 // executar o metodo auxiliar 
    appendText ( "DADOS4.TXT" ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_08 ( ) 

//---------------------


//---------------------
/** 
   readWords - Ler palavras de arquivo. 
   @param fileName - nome do arquivo 
 */ 
void readWords ( chars fileName ) 
{ 
 // definir dados 
    FILE* arquivo = fopen ( fileName, "rt" ); 
    chars linha     = IO_new_chars ( STR_SIZE ); 
 
 // tentar ler a primeira 
    strcpy ( linha, IO_fread ( arquivo ) ); 
 // repetir enquanto houver dados 
    while ( ! feof (arquivo) && 
                  strcmp ( "PARAR", linha ) != 0 ) 
    { 
     // mostrar valor 
        printf ( "%s\n", linha ); 
     // tentar ler o proximo 
        strcpy ( linha, IO_fread ( arquivo ) ); 
    } // end while 
 
 // fechar arquivo (RECOMENDAVEL para leitura) 
    fclose ( arquivo ); 
} // end readWords ( )
//---------------------


//---------------------
/** 
   Method_09. 
 */ 
//---------------------
void method_09 ( ) 
{ 
 // identificar 
    IO_id ( "Method_09 - v0.0" ); 
 
 // executar o metodo auxiliar 
    readWords ( "DADOS4.TXT" ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_09 ( )
//---------------------

/** 
   searchWord - Procurar palavra em arquivo. 
   @return true, se encontrar; false, caso contrario 
   @param fileName - nome do arquivo 
   @param word       - palavra a procurar 
 */ 
bool searchWord ( chars fileName, chars word ) 
{ 
 // definir dados 
    FILE* arquivo = fopen ( fileName, "rt" ); 
    chars linha     = IO_new_chars ( STR_SIZE ); 
 
 // tentar ler a primeira 
    strcpy ( linha, IO_fread ( arquivo ) ); 
 // repetir enquanto houver dados 
    while ( ! feof (arquivo) && 
                  strcmp ( word, linha ) != 0 ) 
    { 
     // tentar ler o proximo 
        strcpy ( linha, IO_fread ( arquivo ) ); 
    } // end while 
 
 // fechar arquivo (RECOMENDAVEL para leitura) 
    fclose ( arquivo ); 
     
 // retornar resultado 
    return ( strcmp ( word, linha ) == 0 ); 
} // end ifarchdWord ( ) 
 
/** 
   Method_10. 
 */ 
void method_10 ( ) 
{ 
 // identificar 
    IO_id ( "Method_10 - v0.0" ); 
 
 // procurar palavra 
    IO_printf ( "Procurar (\"%s\") = %d\n", "pqr", searchWord ( "DADOS4.TXT", "pqr" ) ); 
    IO_printf ( "Procurar (\"%s\") = %d\n", "pqs", searchWord ( "DADOS4.TXT", "pqs" ) ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_10 ( )


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
      IO_println(" 1 - Method_01  EX 01.");
      IO_println(" 2 - Method_02  EX 02.");
      IO_println(" 3 - Method_03  EX 03.");
      IO_println(" 4 - Method_04  EX 04.");
      IO_println(" 5 - Method_05  EX 05.");
      IO_println(" 6 - Method_06  EX 06.");
      IO_println(" 7 - Method_07  EX 07.");
      IO_println(" 8 - Method_08  EX 08.");
      IO_println(" 9 - Method_09  EX 09.");
      IO_println("10 - Method_10  EX 10.");
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


      default:
         IO_pause(IO_concat("Valor diferente das opcoes [0 a 10] (",
                            IO_concat(IO_toString_d(x), ")")));
      } // end switch
   } while (x != 0);

   // encerrar
   IO_pause("Apertar ENTER para terminar");
   return (0);
} // end main ( )