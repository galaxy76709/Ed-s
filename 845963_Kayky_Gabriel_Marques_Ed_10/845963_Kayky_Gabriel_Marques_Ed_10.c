
/*
   Exemplo 1000 - v0.0. - 15 / 05 / 2025
   Author: Kayky_Gabriel_Marques

   Para compilar em terminal (janela de comandos):
   Linux  : gcc -o exemplo1000        exemplo1000.c
   Windows: gcc -o exemplo1000        exemplo1000.c

   Para executar em terminal (janela de comandos):
   Linux  :  ./exemplo1000
   Windows:    exemplo1000
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


//---------------------
/**
   Method_00 - nao faz nada.
 */
void method_00(void)
{
   // nao faz nada
   
} // end method_00 ( )
//---------------------

typedef
struct _array { 
    /* 
      nesta estrutura contem: 
      tamanho e o tamanho
      data tamanho alocado na memoria (usando apontados);
      index o indice (percorrer o arranjo); 
    */
    int  tamanho;
    ints   data;
    int   index;
} _array;

typedef _array * ref_array;
 

//--------------------- 

ref_array new_array ( int number) {
    // alocando espaco 
    ref_array tmp_array = (ref_array) malloc (sizeof (_array));

    // condicao
    if (tmp_array == null) {
        IO_printf("\n Falta de espaço\n");

    }
    else {
        tmp_array -> tamanho  = 0;
        tmp_array -> data     = null;
        tmp_array -> index    = -1;

        if ( number > 0 ) {
            //guardando infos
            tmp_array -> tamanho = number;
            tmp_array -> data    = (ints) malloc (number * sizeof(int)); 
            tmp_array -> index   = 0;
        } // end if de dentro
    } // end if (condicao primaria)

    return (tmp_array); 
    
}


void Free_array (ref_array tmp_array){
    //condicao que previno dados nulos 
    if ( tmp_array != NULL ){

        if (tmp_array -> data != NULL){
            //espaco reciclado
            free(tmp_array -> data);
        }
        //espaco reciclado 
        free ( tmp_array );
    }
}


void Print_array (ref_array array) {

    // conficao de verificao de existencia 
    if (array -> data) {
        // laço de repeticao de 0 ao tamanho de "tamanho"
        for (   array -> index = 0; array -> index < array -> tamanho; array -> index = array -> index + 1 )
        {
            IO_printf("%d ", array -> data  [ array -> index ] ); // sera printado o valor que esta dentro do indice do laco de repeticao 
        }
    }
}

//---------------------


//--------------------- P_11
/*
@param first_value         - entrada do primeiro valor do intervalo
@param second_value        - entrada do primeiro valor do intervalo
@ retun (numero_aleatorio) - retorna um valor randomico 

*/
int Rand_number ( int first_value, int second_value  ) {      
    

int numero_aleatorio =  first_value + rand() % (second_value - first_value);

return ( numero_aleatorio ); 

   
}
//---------------------


//---------------------
/** 
   questao_01 - gerar valor aleatorio, verificar se faz parte de um intervalo, printar o valor dentro de um arranjo dentro de um arquivo 
 */ 
void method_01 ( void ) 
{ 


 // definir dado 
  _array array; // - > chamando o struct 

  int first_value  = 0;
  int second_value = 0;
  int number       = 0;
  int aux          = 0;

  FILE * arquivo = fopen ( "DADOS.TXT", "wt" );

      first_value  = IO_readint ("\n Digite o primeiro valor   :");
      second_value = IO_readint ("\n Digite o primeiro segundo :"); 
      number       = IO_readint ("\n Digite quantidade de N    :");

      //condicao de verificacao de ordem 
      if ( first_value < second_value ) { 

    //montando estrutura de dado do arranjo 
    new_array ( number ); 

        for (array. index = 0; array. index < number ; array .index = array. index + 1) {
           
            aux    = Rand_number ( first_value, second_value );

           array. data [array. index]  = aux; 

           fprintf ( arquivo , "%d\n",aux );

        }
    }
    else {
        IO_printf("Erro. primeiro valor e menor que o segundo ");
    }

    //reciclando o espaco 
    free ( array. data ); 

    //fechando o arquivo 
    fclose (arquivo); 

 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end questao_01 ( ) 
//---------------------



//--------------------- P_12
int  arraySearch ( int target, ref_array array ){
    if (array -> data != NULL) {

        for ( int i = 0; i < array -> tamanho; i = i + 1 ){
          
            if ( array -> data [ i ] == target )
            {
                IO_printf ("\n %d encontrado na posicao [ %d ]\n", target, i);
                return ( i );
            }
        }
        return ( -1 );
    }

}
//---------------------


//---------------------P_13
void  declaring_array ( ref_array tmp_array  ){
    if ( tmp_array -> data != NULL ){

        for (tmp_array -> index = 0; tmp_array -> index < tmp_array -> tamanho; tmp_array -> index = tmp_array -> index + 1  ){
            tmp_array -> data [tmp_array -> index] = IO_readint ("Digite o valor: ");
        }

        tmp_array -> index = 0;
    } else {
        IO_printf ("Espaco insuficiente");
    }
}
//---------------------


//---------------------P_14
ref_array readArrayFromFile (chars fileName) {
FILE *arquivo = fopen(fileName, "rt");
   
ref_array my_array = null;
    int size = 0;

    if (arquivo != null) {
        fscanf(arquivo, "%d", &size);

         my_array = new_array ( size );

        for (int i = 0; i < size; i = i + 1 ) {

            fscanf( arquivo, "%d", &my_array -> data [ i ] );
        }

        fclose ( arquivo );
    }

    return ( my_array );
}
//---------------------


//---------------------
/** 
   questao_02 - gerar valor aleatorio, verificar se faz parte de um intervalo, printar o valor dentro de um arranjo dentro de um arquivo 
 */ 
void method_02 ( void ) 
{ 

    chars arquivo     = IO_readln("Digite o nome do arquivo (ex: DADOS.TXT): ");
    int   valor       = IO_readint("Digite o valor que deseja procurar: ");

    ref_array array = readArrayFromFile ( arquivo );

    if (array != NULL) {
        int resultado = arraySearch(valor, array);
       
        if ( !resultado ) {

            IO_printf("\nValor %d NAO encontrado no arranjo.\n", valor);
        } else {
            IO_printf("\nValor %d foi encontrado no arranjo.\n", valor);        }
        
    }

        // apos a acao reciclar o espaco 
        free ( array -> data );
        free ( array );

 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end questao_02 ( ) 
//---------------------


//---------------------P_15
bool Array_compare ( ref_array array_1, ref_array array_2) {
    // var auxiliare de tamanho 
    int aux_1 = array_1 -> tamanho;
    int aux_2 = array_2 -> tamanho;

    // condicao de existencia 
    if  ( array_1 -> data != null && array_2 != null ){
            
        if(aux_1 != aux_2 ){
                IO_print("Erro, tamanho dos arranjos sao incompativeis");
                    return false;
            } else  {
                
            for (int i = 0; i < aux_1; i = i + 1) {
                IO_printf("Comparando: %d e %d\n", array_1->data[i], array_2->data[i]);

                if (array_1->data[i] != array_2->data[i]) {
                    IO_printf("-> Diferente na posicao [%d]\n", i + 1);

                    return false; // se encontrar diferença, retorna falso
               
                }
            }
        }
        return true; // se todas as posições forem iguais
    }
    return false; // se algum array for nulo
}
//---------------------


//---------------------
void method_03 ( void ){

    chars arquivo_1   = IO_readln ("Digite o nome do arquivo (ex: DADOS1.TXT): ");
    chars arquivo_2   = IO_readln ("Digire o nome do arquivo (ex: DADOS2.TXT): ");

    ref_array array_1 = readArrayFromFile ( arquivo_1 );
    ref_array array_2 = readArrayFromFile ( arquivo_2 );

    if ( array_1 -> data != null ||
         array_2 -> data != null ) {

        bool resultado = Array_compare(array_1, array_2);
       
        if ( resultado == true  ) {

            IO_printf("\nOs arranjo sao equivalentes.\n");

        } else {
            IO_printf("\nOs arranjo NAO sao equivalentes.\n");        }
        
    }

    // recicalndo o espaço ultilizado apos a acao 
        free ( array_1 -> data );
        free ( array_2 -> data );
        free ( array_1 );
        free ( array_2 );

 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
}
//---------------------


//---------------------P_16
ref_array arrayAdd  (ref_array array_1, ref_array array_2, int x ) {
    //atribuindo valores ha varaiveis aux
    int aux_1 = array_1 -> tamanho;
    int aux_2 = array_2 -> tamanho;

     ref_array assist_array = new_array ( aux_1 );

    if (    array_1 != null &&
            array_2 != null && 
      array_1->data != null &&
      array_2->data != null){ // verificao de existencia 

            if  (aux_1 != aux_2 ){
                IO_printf ("O tamanho dos arranjos sao incompativeis");
                free ( assist_array ); // caso os tamanhos nao sejam iguais, recicla o espaço 
        } else {

            for ( int i = 0; i < aux_1 ; i = i + 1 ) {
                assist_array -> data [ i ] = ( array_1 -> data [ i ] * array_2 -> data [ i ] * x );
            
            }

            return ( assist_array );
        }
    }//end primeira condicao

        // recicla o valor caso nao tenha passado da primeira condicao 
        Free_array ( assist_array );
}
//---------------------


//---------------------
void method_04 ( void ){

    chars arquivo_1   = IO_readln  ("Digite o nome do arquivo (ex: DADOS1.TXT): ");
    chars arquivo_2   = IO_readln  ("Digire o nome do arquivo (ex: DADOS2.TXT): ");
    int   x           = IO_readint ("Digite o valor da constante:  ");

    ref_array array_1 = readArrayFromFile ( arquivo_1 );
    ref_array array_2 = readArrayFromFile ( arquivo_2 );


    if ( array_1 -> data != null ||
         array_2 -> data != null ) {

       ref_array resp = arrayAdd (array_1, array_2, x );
    
        Print_array ( resp ); 

        free ( array_1 -> data );
        free ( array_2 -> data );
        free ( resp ->    data );
        free ( array_1 );
        free ( array_2 );
        free (  resp );
    }



 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
}
//---------------------


//---------------------
bool isArrayDecrescent ( ref_array array_1 ){

    //verificando existencia 
    if (  array_1 -> data != null  ) {
        for (int i = 0; i < array_1 -> tamanho; i = i + 1 ) {
            if (array_1 -> data [ i ] > array_1 -> data [ i - 1] ) {// condicao q verifica se o valor anterior e maior 
                return false ;
            }
        }// end laço de repeticao
        return true; 
    }
    return false; // caso o apontados esteja aterrado 
}
//---------------------


//---------------------
void method_05 ( void ){

    chars arquivo_1   = IO_readln  ("Digite o nome do arquivo (ex: DADOS1.TXT): ");

    ref_array array_1 = readArrayFromFile ( arquivo_1 );


    if ( array_1 -> data != null  ) {

        Print_array ( array_1 );

        IO_print("\n");

        bool answer = isArrayDecrescent ( array_1 );

        if ( answer ){
            IO_printf ("\nO arranjo esta em forma decresente  ");

        }else {
            IO_printf("\nO arranjo NAO esta em forma decresente ");
        }

        free ( array_1 -> data );
        free ( array_1 );
    }



 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
}
//---------------------


//---------------------
/** 
 
   Definicao de tipo arranjo bidimensional com inteiros baseado em estrutura 
 */ 
typedef 
 struct s_int_Matrix 
 { 
   int     rows    ; // - > linhas
   int     columns ; // - > linhas
   ints*   data    ; // - > P_01/data
   int     ix,  iy ; // - > posicao x e y
 } 
int_Matrix;
//---------------------


//---------------------
/** 
   Definicao de referencia para arranjo bidimensional com inteiros baseado em estrutura 
 */  
typedef int_Matrix* ref_int_Matrix;
//---------------------


//----funcoes do exemplo -----------------
/** 
 * P_10
   new_int_Matrix    - Reservar espaco para arranjo bidimensional com inteiros 
   @return referencia para arranjo com inteiros 
   @param rows        - quantidade de dados 
   @param columns - quantidade de dados 
 */ 
ref_int_Matrix new_int_Matrix ( int rows, int columns ) 
{ 
 // reserva de espaco 
    ref_int_Matrix tmpMatrix = (ref_int_Matrix) malloc (sizeof(int_Matrix));  // - > matriz temporaria
 
 // estabelecer valores padroes 
    if ( tmpMatrix != NULL )  // condicao que prever se o apontador esta aterrado 

    { 
       tmpMatrix->rows           = 0   ; 
       tmpMatrix->columns        = 0   ; 
       tmpMatrix->data           = NULL; 

     // reservar espaco 
       if (  rows > 0 && columns > 0 )  
       { 
          tmpMatrix->rows         = rows; 
          tmpMatrix->columns      = columns; 
          tmpMatrix->data         = malloc (rows * sizeof(ints)); 

          if ( tmpMatrix->data ) 
          { 
             for (   tmpMatrix->ix = 0; 
                     tmpMatrix->ix < tmpMatrix->rows; 
                     tmpMatrix->ix = tmpMatrix->ix+1 ) 
             { 
                tmpMatrix->data [ tmpMatrix->ix ] = (ints) malloc (columns * sizeof(int)); 
             } // end for 
          }
           // end if 
       } // end if 
       tmpMatrix->ix         = 0; 
       tmpMatrix->iy         = 0; 

   } // end if 
   return ( tmpMatrix ); 
} // end new_int_Matrix ( ) 


/** 
   free_int_Matrix        - Dispensar espaco para arranjo com inteiros 
   @param tmpMatrix - referencia para grupo de valores inteiros 
 */ 
void free_int_Matrix ( ref_int_Matrix matrix ) 
{ 
 // testar se ha' dados 
    if ( matrix != NULL ) 
    { 
       if ( matrix->data != NULL ) 
       { 
          for ( matrix->ix=0; 
                  matrix->ix<matrix->rows; 
                  matrix->ix=matrix->ix+1 ) 
          { 
                free ( matrix->data [ matrix->ix ] ); 
          } // end for 
          free ( matrix->data ); 
       } // end if 
       free ( matrix ); 
    } // end if 
} // end free_int_Matrix ( )


/** 
   printIntMatrix  - Mostrar matrix com valores inteiros. 
   @param array - grupo de valores inteiros 
 */ 
void printIntMatrix ( ref_int_Matrix matrix ) 
{ 
 // testar a existencia 
    if ( matrix != NULL && matrix->data != NULL ) // verificacao se os apontadores estao aterrados
    { 
     // mostrar valores na matriz 
        for ( matrix->ix=0; matrix->ix<matrix->rows; matrix->ix=matrix->ix+1 ) 
        { 
             for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 ) 
             { 
              // mostrar valor 
                 printf ( "%3d\t", matrix->data [ matrix->ix ][ matrix->iy ] ); 
             } // end for 
             printf ( "\n" ); 
        } // end for 
    } // end if 
 } // end printIntArray ( ) 


/** 
   fprintIntMatrix       - Gravar arranjo bidimensional com valores inteiros. 
   @param fileName - nome do arquivo 
   @param matrix     - grupo de valores inteiros 
 */ 
void fprintIntMatrix ( chars fileName, ref_int_Matrix matrix ) 
{ 
 // definir dados locais 
    FILE* arquivo = fopen ( fileName, "wt" ); 

 // testar se ha' dados 
    if ( matrix == NULL ) 
    { 
       printf ( "\nERRO: Nao ha' dados." ); 
    } 
    else 
    { 
     // gravar quantidade de dados 
        fprintf ( arquivo, "%d\n", matrix->rows       ); 
        fprintf ( arquivo, "%d\n", matrix->columns ); 
         
        if ( matrix->data != NULL ) 
        { 
         // gravar valores no arquivo 
            for ( matrix->ix=0; matrix->ix<matrix->rows; matrix->ix=matrix->ix+1 ) 
            { 
               for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 ) 
               { 
                // gravar valor 
                   fprintf ( arquivo, "%d\n", matrix->data [ matrix->ix ][ matrix->iy ] ); 
               } // end for 
            } // end for 
        } // end if 
     // fechar arquivo 
        fclose ( arquivo ); 
  } // end if 
} // end fprintIntMatrix ( ) 


/** 
 * P_04
   IO_readintMatrix  - Ler arranjo bidimensional com valores inteiros. 
   @return referencia para o grupo de valores inteiros 
 */ 
ref_int_Matrix IO_readintMatrix ( ) 
{ 
 // definir dados locais 
    int   rows       = 0; 
    int   columns = 0; 
    chars text = IO_new_chars ( STR_SIZE ); 
 
 // ler a quantidade de dados 
    do 
    {    rows       = IO_readint ( "\nlinhas  =  "      ); } 
    while ( rows    <= 0 ); 
    do 

    {    columns = IO_readint    ( "\ncolunas =  "      ); } 
    while ( columns <= 0 ); 
 
 // reservar espaco para armazenar valores 
    ref_int_Matrix matrix = new_int_Matrix ( rows, columns ); 
 
 // testar se ha' espaco 
    if ( matrix != NULL ) 
    { 
       if ( matrix->data == NULL ) 
       { 
        // nao ha' espaco 
           matrix->rows        = 0; 
           matrix->columns = 0; 
           matrix->ix             = 0; 
           matrix->iy             = 0; 
       } 
      else 
      { 
       // ler e guardar valores na matriz 
          for ( matrix->ix=0; matrix->ix<matrix->rows; matrix->ix=matrix->ix+1 ) 
          { 
               for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 ) 
               { 
                // ler e guardar valor 
                   strcpy ( text, STR_EMPTY ); 
                   matrix->data [ matrix->ix ][ matrix->iy ] 
                   = IO_readint ( IO_concat ( 
                                        IO_concat ( IO_concat ( text, IO_toString_d ( matrix->ix ) ), ", "  ), 
                                        IO_concat ( IO_concat ( text, IO_toString_d ( matrix->iy ) ), " : " ) ) ); 
               } // end for 
               printf ( "\n" ); 
          } // end for 
       } // end if 
  } // end if 
 
 // retornar dados lidos 
    return ( matrix ); 
} // end IO_readintMatrix ( ) 


/** 
   freadintMatrix       - Ler arranjo bidimensional com valores inteiros. 
   @return referencia para o grupo de valores inteiros 
   @param fileName - nome do arquivo 
 */ 
ref_int_Matrix freadintMatrix ( chars fileName ) 
{ 
 // definir dados locais 
    ref_int_Matrix matrix = NULL; 
    int      rows         = 0; 
    int      columns      = 0; 
    FILE* arquivo         = fopen ( fileName, "rt" ); 
 // ler a quantidade de dados 
    fscanf ( arquivo, "%d", &rows       ); 
    fscanf ( arquivo, "%d", &columns ); 
    if ( rows <= 0 || columns <= 0 ) 
    { 
       IO_printf ( "\nERRO: Valor invalido.\n" ); 
    } 
    else 
    { 
     // reservar espaco para armazenar 
        matrix = new_int_Matrix ( rows, columns ); 
     // testar se ha' espaco 
        if ( matrix != NULL && matrix->data == NULL ) 
        { 
         // nao ha' espaco 
            matrix->rows        = 0; 
            matrix->columns = 0; 
            matrix->ix             = 0; 
            matrix->iy             = 0; 
        } 
        else 
        { 
         // testar a existência 
            if ( matrix != NULL ) 
            { 
              // ler e guardar valores na matriz 
                 matrix->ix = 0; 
                 while ( ! feof ( arquivo ) && matrix->ix < matrix->rows ) 
                 { 
                     matrix->iy = 0; 
                     while ( ! feof ( arquivo ) && matrix->iy < matrix->columns ) 
                     { 
                      // guardar valor 
                         fscanf ( arquivo, "%d", &(matrix->data [ matrix->ix ][ matrix->iy ]) ); 
                      // passar ao proximo 
                         matrix->iy = matrix->iy+1; 
                     } // end while 
                  // passar ao proximo 
                     matrix->ix = matrix->ix+1; 
                 } // end while 
                matrix->ix = 0; 
                matrix->iy = 0; 
           } // end if 
        } // end if 
     } // end if 
 // retornar matriz lida 
    return ( matrix ); 
} // end freadintMatrix ( )

//----funcoes do exemplo -----------------


//---------------------
ref_int_Matrix  matrixTranspose ( ref_int_Matrix  matrix_1  ) {
    
    // verificao de existenica 
        if ( matrix_1  ==  null  ||  matrix_1 -> data  ==  null ) {
            return null;
        }

    if ( matrix_1 -> rows <= 0 || matrix_1 -> columns <= 0 ) 
    { 
       IO_printf ( "\nERRO: Valor invalido.\n" ); 
    } 

    // Criar nova matriz com linhas e colunas invertidas
    ref_int_Matrix matrix_2 = new_int_Matrix(matrix_1->columns, matrix_1->rows);

    if ( matrix_2  ==  null  ||  matrix_2 -> data  ==  null ) {
        return null;
    }

    for ( matrix_1 -> ix  =  0 ; matrix_1 -> ix  <  matrix_1 -> rows ;  matrix_1 -> ix = matrix_1 -> ix + 1) {
        for ( matrix_1 -> iy  =  0 ;  matrix_1 -> iy  <  matrix_1 -> columns ;  matrix_1 -> iy = matrix_1 -> iy + 1 ) {
            matrix_2 -> data [ matrix_1 -> iy ] [ matrix_1 -> ix ]  =  matrix_1 -> data [ matrix_1 -> ix ] [ matrix_1 -> iy ];
        }
    }

    return ( matrix_2 );
    
}
//---------------------


//---------------------
void method_06 ( void ) {
    chars arquivo_1   = IO_readln  ("Digite o nome do arquivo (ex: DADOS1.TXT): ");
  
    //iniciando a referenciacao da matriz
        ref_int_Matrix      assist_matrix      =  null;
   
    
    //iniciando valores da nova matris ( valores estes estao zerados )
        assist_matrix = IO_readintMatrix();

    
    if ( assist_matrix  !=  null  &&  assist_matrix -> data  != null ) {

    // atribuindo valores 
        fprintIntMatrix ( arquivo_1 ,  assist_matrix );

    // Obter matriz transposta
        ref_int_Matrix other_matrix = matrixTranspose ( assist_matrix );

    // mostrando a resposta    
        IO_println("\nMatriz Transposta:");
        printIntMatrix( other_matrix );

    
    // reciclando a memoria 
        free_int_Matrix ( assist_matrix );
        free_int_Matrix (  other_matrix );

    } else {
        IO_println ("\nErro: ponteiro esta aterrado. \n ");
    }

     // encerrar 
        IO_pause ( "Apertar ENTER para continuar" ); 
}
//---------------------


//---------------------
bool  matrixZero (ref_int_Matrix matrix_1) {
    // coondicao de existencia 
    if (matrix_1 != null && matrix_1 -> data != null) { 

        bool answer = false; 

        for (matrix_1 -> ix = 0; matrix_1 -> ix < matrix_1 -> rows; matrix_1 -> ix = matrix_1 -> ix + 1) {// laco para ler linhas
            for ( matrix_1 -> iy = 0; matrix_1 -> iy < matrix_1 -> columns; matrix_1 -> iy = matrix_1 -> iy + 1) // laco para ler colunas 
            {
                //condicao que preve se algum resultado do indice de matrix_1 seja diferente de o
                if ( matrix_1 -> data [ matrix_1  ->  ix ] [ matrix_1  ->  iy ]  !=  0 ){
                    // caso for, retorne false 
                    return ( answer ); 
                } 
            }// fim for iy
            
        } // fim for ix

        return ( !answer ) ;

    } else {
        return  ( false ) ;
    }
}
//---------------------


//---------------------
void method_07 ( void ) {
    chars arquivo_1   = IO_readln  ("Digite o nome do arquivo (ex: DADOS1.TXT): ");
  
    //iniciando a referenciacao da matriz
        ref_int_Matrix      assist_matrix      =  null;
   
    
    //iniciando valores da nova matris ( valores estes estao zerados )
        assist_matrix = IO_readintMatrix();

    
    if ( assist_matrix  !=  null  &&  assist_matrix -> data  != null ) {

    // atribuindo valores 
        fprintIntMatrix ( arquivo_1 ,  assist_matrix );

    
    //chamado da funcao principal
        bool answer = matrixZero ( assist_matrix ); 

    // mostrando a resposta    
        IO_println("\nResposta: "); 

    // condicao que preve se o resultado for falso 
        if ( !answer ) {

            IO_println ("A matrix contem elemtentos alem de '0'");
        } else {

            IO_println ("A matrix so contem o numero'0'");

        }


    
    // reciclando a memoria 
        free_int_Matrix ( assist_matrix );


    } else {
        IO_println ("\nErro: ponteiro esta aterrado. \n ");
    }

     // encerrar 
        IO_pause ( "Apertar ENTER para continuar" ); 
}
//---------------------


//---------------------
bool  matrixCompare (ref_int_Matrix matrix_1, ref_int_Matrix matrix_2) {
    // coondicao de existencia 
    if ( matrix_1 != null && matrix_1 -> data != null ||
         matrix_2 != null && matrix_2 -> data != null ) { 

        bool answer = false; 

        for ( int i = 0 ; i < matrix_1 -> rows; i =  i + 1) {// laco para ler linhas
           
            for ( int j = 0; j < matrix_1 -> columns; j  =  j  + 1) // laco para ler colunas 
            {
                //condicao que preve se algum resultado do indice de matrix_1 e 2 nao sao iguais 
                if ( matrix_1 -> data [ i ] [ j ]  !=   matrix_2 -> data [ i ] [ j ] ){
                    
                    // caso for, retorne false 
                    return ( answer ); 
                } 
            }// fim for iy
            
        } // fim for ix

        return ( !answer ) ;

    } else {
        return  ( false ) ;
    }
}
//---------------------


//---------------------
void method_08 ( void ) {
    
    chars arquivo_1   = IO_readln  ("Digite o nome do arquivo (ex: DADOS1.TXT): ");
    chars arquivo_2   = IO_readln  ("Digite o nome do arquivo (ex: DADOS2.TXT): ");

  
    //iniciando a referenciacao da matriz
        ref_int_Matrix      assist_matrix      =  null;
        ref_int_Matrix      assist_matrix_2    =  null;

   
    
    //iniciando valores da nova matris ( valores estes estao zerados )
        assist_matrix  = IO_readintMatrix();
        
        assist_matrix_2 = IO_readintMatrix();


    
    if ( assist_matrix != null && assist_matrix->data != null &&
        assist_matrix_2 != null && assist_matrix_2->data != null &&
        assist_matrix->rows == assist_matrix_2->rows &&
        assist_matrix->columns == assist_matrix_2->columns ) { // caso de existencia 

    // atribuindo valores 
        fprintIntMatrix ( arquivo_1 ,  assist_matrix   );

        fprintIntMatrix ( arquivo_2 ,  assist_matrix_2 );

    
    //chamado da funcao principal
        bool answer = matrixCompare ( assist_matrix, assist_matrix_2 ); 

    // mostrando a resposta    
        IO_println("\nResposta: "); 

    // condicao que preve se o resultado for falso 
        if ( answer ) {

            IO_println ("\nAmbas matrizes sao iguais  ");
        } else {

            IO_println ("\nAs matrizes NAO sao iguais ");

        }


    
    // reciclando a memoria 
        free_int_Matrix ( assist_matrix  );
        free_int_Matrix ( assist_matrix_2 );



    } else {
        IO_println ("\nErro: ponteiro esta aterrado ou tamanho nao se coincidem  \n ");
    }

     // encerrar 
        IO_pause ( "Apertar ENTER para continuar" ); 
}
//---------------------


//---------------------
ref_int_Matrix readMatrixFromFile(chars fileName) 
{ 
    // definir dados locais 
    ref_int_Matrix matrix = NULL; 
    int rows    = 0; 
    int columns = 0; 
    FILE* arquivo = fopen(fileName, "rt"); 

    // ler a quantidade de dados 
    fscanf(arquivo, "%d", &rows); 
    fscanf(arquivo, "%d", &columns); 

    if (rows <= 0 || columns <= 0) 
    { 
        IO_printf("\nERRO: Valor invalido.\n"); 
    } 
    else 
    { 
        // reservar espaço para armazenar 
        matrix = new_int_Matrix(rows, columns); 

        // testar se há espaço alocado corretamente 
        if (matrix != NULL && matrix->data == NULL) 
        { 
            // nao ha' espaco 
            matrix->rows    = 0; 
            matrix->columns = 0; 
            matrix->ix      = 0; 
            matrix->iy      = 0; 
        } 
        else 
        { 
            // testar a existência 
            if (matrix != NULL) 
            { 
                // ler e guardar valores na matriz 
                matrix->ix = 0; 
                while (!feof(arquivo) && matrix->ix < matrix->rows) 
                { 
                    matrix->iy = 0; 
                    while (!feof(arquivo) && matrix->iy < matrix->columns) 
                    { 
                        fscanf(arquivo, "%d", &(matrix->data[matrix->ix][matrix->iy])); 
                        matrix->iy = matrix->iy + 1; 
                    } 
                    matrix->ix = matrix->ix + 1; 
                } 
                matrix->ix = 0; 
                matrix->iy = 0; 
            } 
        } 
    } 

    // fechar o arquivo
    fclose(arquivo);

    // retornar matriz lida 
    return (matrix); 
} // end readMatrixFromFile
//---------------------


//---------------------
ref_int_Matrix matrixAdd (ref_int_Matrix matrix_1, ref_int_Matrix matrix_2, int x ){

    // coondicao de existencia 
    if ( matrix_1 != null && matrix_1 -> data != null ||
         matrix_2 != null && matrix_2 -> data != null &&
        matrix_1->rows == matrix_2->rows &&
        matrix_1->columns == matrix_2->columns) { 

        ref_int_Matrix tmp_matrix = new_int_Matrix (matrix_1 -> ix, matrix_1 -> iy);

        if (tmp_matrix != null &&
            tmp_matrix -> data != null ) { 


        for ( int i = 0 ; i < matrix_1 -> rows; i =  i + 1) {// laco para ler linhas
           
            for ( int j = 0; j < matrix_1 -> columns; j  =  j  + 1) // laco para ler colunas 
            {
                    tmp_matrix->data[i][j] = matrix_1->data[i][j] + (x * matrix_2->data[i][j]);
            }// fim for iy
            
        } // fim for ix
        return ( tmp_matrix ); 

        } else {
            IO_printf("\nErro, tamanho apontadores aterrados");
        }
    }
 }
//---------------------


//---------------------
void method_09 ( void ) {
    
    chars arquivo_1   = IO_readln  ("Digite o nome do arquivo (ex: DADOS1.TXT): ");
    chars arquivo_2   = IO_readln  ("Digite o nome do arquivo (ex: DADOS2.TXT): ");
    int   x           = IO_readint ("Digite o valor da constante:               ");
  
    //iniciando a referenciacao da matriz
        ref_int_Matrix      assist_matrix      =  null;
        ref_int_Matrix      assist_matrix_2    =  null;

   
    
    //iniciando valores da nova matris ( valores estes estao zerados )
        assist_matrix  = IO_readintMatrix();
        
        assist_matrix_2 = IO_readintMatrix();


    
    if ( assist_matrix != null && assist_matrix->data != null &&
        assist_matrix_2 != null && assist_matrix_2->data != null &&
        assist_matrix->rows == assist_matrix_2->rows &&
        assist_matrix->columns == assist_matrix_2->columns ) { // caso de existencia 

    // atribuindo valores 
        readMatrixFromFile ( arquivo_1  );

        readMatrixFromFile ( arquivo_2  );

    
    //chamado da funcao principal
        ref_int_Matrix answer = matrixAdd ( assist_matrix, assist_matrix_2, x); 

    // mostrando a resposta    
        IO_println("\nResposta: "); 

        printIntMatrix ( answer );


    
    // reciclando a memoria 
        free_int_Matrix ( assist_matrix  );
        free_int_Matrix ( assist_matrix_2 );
        free_int_Matrix ( answer );



    } else {
        IO_println ("\nErro: ponteiro esta aterrado ou tamanho nao se coincidem  \n ");
    }

     // encerrar 
        IO_pause ( "Apertar ENTER para continuar" ); 
}
//---------------------


//---------------------
ref_int_Matrix matrixProduct ( ref_int_Matrix matrix_1, ref_int_Matrix matrix_2 ){

    // coondicao de existencia 
    if ( matrix_1 != null && matrix_1 -> data != null ||
         matrix_2 != null && matrix_2 -> data != null ) { 

        if (matrix_1->columns != matrix_2->rows){
        IO_println("\nErro: Dimensões incompativeis para multiplicacao.");
    } 

    // Criar matriz resultado com dimensões (linhas de A) x (colunas de B)
    ref_int_Matrix result = new_int_Matrix(matrix_1->rows, matrix_2->columns);

       for (int i = 0; i < result->rows; i = i + 1) {

        for (int j = 0; j < result->columns; j = j + 1) {

            result -> data [ i ] [ j ]  =  0;
            for ( int  k  =  0 ;  k  <  matrix_1 -> columns ;  k = k + 1 ) {

                result -> data [ i ] [ j ]  +=  matrix_1 -> data [ i ] [ k ]  *  matrix_2 -> data [ k ] [ j ] ;
            } 
        }
    }
        return ( result ); 

        } else {
            IO_printf("\nErro, tamanho apontadores aterrados");
        }
    }
//---------------------


//---------------------
void method_10(void) {
    // Ler nomes dos arquivos
    chars arquivo_1 = IO_readln("Digite o nome do arquivo (ex: DADOS1.TXT): ");
    chars arquivo_2 = IO_readln("Digite o nome do arquivo (ex: DADOS2.TXT): ");

    // Ler matrizes dos arquivos
    ref_int_Matrix matriz1 = readMatrixFromFile(arquivo_1);
    ref_int_Matrix matriz2 = readMatrixFromFile(arquivo_2);

    // Verificar se as matrizes são válidas e compatíveis para multiplicação
    if (matriz1 != NULL && matriz1->data != NULL &&
        matriz2 != NULL && matriz2->data != NULL &&
        matriz1->columns == matriz2->rows) {

        // Calcular produto
        ref_int_Matrix produto = matrixProduct( matriz1, matriz2 );

        // Mostrar resultado
        IO_println("\nProduto das Matrizes:");
        printIntMatrix(produto);

        // Liberar memoria
        free_int_Matrix(matriz1);
        free_int_Matrix(matriz2);
        free_int_Matrix(produto);

    } else {
        IO_println("\nErro: Matrizes incompativeis ou invalidas para multiplicacao.");
    }

    IO_pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
void sortArrayDown(ref_array array) {
    int temp = 0;

    if (array != null && array->data != null) {

        for (int i = 0; i < array->tamanho - 1; i++) {

            for (int j = i + 1; j < array->tamanho; j++) {

                if (array->data[i] < array->data[j]) {
                    // Trocar os valores de posição

                    temp = array->data[i];

                    array->data[i] = array->data[j];

                    array->data[j] = temp;

                }
            }
        }
    }
}
//---------------------


//---------------------
void method_11 (void) {
    chars arquivo = IO_readln("Digite o nome do arquivo (ex: DADOS1.TXT): ");

    ref_array array = readArrayFromFile(arquivo);

    if (array != null && array->data != null) {
        IO_println("\nAntes da ordenacao:");
        Print_array(array);

        sortArrayDown(array);

        IO_println("\nDepois da ordenacao decrescente:");
        Print_array(array);

        // Liberar memoria
        free(array->data);
        free(array);
    } else {
        IO_println("Erro ao ler o arranjo.");
    }

    IO_pause("Apertar ENTER para continuar");
}
//---------------------

//---------------------
bool identityMatrix(ref_int_Matrix matrix) {
    // Verificar se a matriz é válida e quadrada
    if (matrix == NULL || matrix->data == NULL ||
        matrix->rows <= 0 || matrix->columns <= 0 ||
        matrix->rows != matrix->columns) {
        return false;
    }

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
            if (i == j && matrix->data[i][j] != 1) {
                return false;
            } else if (i != j && matrix->data[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}
//---------------------


//---------------------
ref_int_Matrix matrixProduct(ref_int_Matrix m1, ref_int_Matrix m2) {
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL) {
        return NULL;
    }

    if (m1->columns != m2->rows) {
        IO_println("\nErro: Dimensões incompatíveis para multiplicação.");
        return NULL;
    }

    ref_int_Matrix result = new_int_Matrix(m1->rows, m2->columns);

    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->columns; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < m1->columns; k++) {
                result->data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }

    return result;
}
//---------------------


//---------------------
void method_12(void) {
    chars nome_arquivo_1 = IO_readln("Digite o nome do primeiro arquivo (ex: DADOS1.TXT): ");
    chars nome_arquivo_2 = IO_readln("Digite o nome do segundo arquivo (ex: DADOS2.TXT): ");

    ref_int_Matrix m1 = readMatrixFromFile(nome_arquivo_1);
    ref_int_Matrix m2 = readMatrixFromFile(nome_arquivo_2);

    if (m1 != NULL && m2 != NULL &&
        m1->data != NULL && m2->data != NULL &&
        m1->columns == m2->rows) {

        ref_int_Matrix produto = matrixProduct(m1, m2);

        IO_println("\nProduto das matrizes:");
        printIntMatrix(produto);

        bool ehIdentidade = identityMatrix(produto);

        if (ehIdentidade) {
            IO_println("\nO produto resulta na matriz identidade.");
        } else {
            IO_println("\nO produto NAO resulta na matriz identidade.");
        }

        // Liberação de memória
        free_int_Matrix(m1);
        free_int_Matrix(m2);
        free_int_Matrix(produto);

    } else {
        IO_println("\nErro: Matrizes inválidas ou tamanhos incompatíveis.");
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
      IO_id("EXEMPLO0 1000 - Programa - v0.0 \n");

      // ler do teclado
      IO_println("Opcoes");
      IO_println(" 0  -            parar");
      IO_println(" 1 - method_0   ques 01.");
      IO_println(" 2 - method_02  ques 02.");
      IO_println(" 3 - method_03  ques 03.");
      IO_println(" 4 - method_04  ques 04.");
      IO_println(" 5 - method_05  ques 05.");
      IO_println(" 6 - method_06  ques 06.");
      IO_println(" 7 - method_07  ques 07.");
      IO_println(" 8 - method_08  ques 08.");
      IO_println(" 9 - method_09  ques 09.");
      IO_println("10 - method_10  ques 10 ");
      IO_println("11 - method_11  ques 11 ");
      IO_println("12 - method_12  ques 12 ");

      IO_println("");

      x = IO_readint("Entrar com uma opcao: ");

      // testar valor
      switch (x)
      {
         case   0:  method_00 ( );   break; 
         case   1:  method_01 ( );   break;
         case   2:  method_02 ( );   break;   
         case   3:  method_03 ( );   break;
         case   4:  method_04 ( );   break;
         case   5:  method_05 ( );   break;  
         case   6:  method_06 ( );   break;
         case   7:  method_07 ( );   break;        
         case   8:  method_08 ( );   break;
         case   9:  method_09 ( );   break;
         case  10:  method_10 ( );   break;
         case  11:  method_11 ( );   break;
         case  12:  method_12 ( );   break;


        

      default:
         IO_pause(IO_concat("Valor diferente das opcoes [0 a 12] (",
                            IO_concat(IO_toString_d(x), ")")));
      } // end switch
   } while (x != 0);

   // encerrar
   IO_pause("Apertar ENTER para terminar");
   return (0);
} // end main ( )