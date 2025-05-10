
/* 
   Exemplo0200 - v0.0. - __ / __ / _____ 
   Author: Kayky_Gabriel_Marques 
    
   Para compilar em terminal (janela de comandos): 
   Linux      : gcc -o exemplo0200        exemplo0200.c 
   Windows: gcc -o exemplo0200        exemplo0200.c 
 
   Para executar em terminal (janela de comandos): 
   Linux      :  ./exemplo0200 
   Windows:    exemplo0200 
 */ 
// dependencias 
#include "io.h" // bibliotecas e outras definicoes 
#include <stdio.h> // biblioteca de apoio 
#include<stdbool.h> // biblioteca de apoio 


/** 
  Method_01. 
*/ 
void method_01 ( void ) 
{ 
  // identificar 
    printf ( "Method_01 - Programa - v1.0\n" ); 

    // iniciando minha variavel
    int number = 0; // tratar de numeros inteiros por hora

   printf("Digite o numero: \n");
      scanf("%d", &number);
         getchar(); 

// declarando condicao 
   if (number % 2 == 0) {
      printf("O numero [%d] e par!", number);
         getchar();
   } else if (number % 2 != 0) {
      printf("O numero [%d] e impar!", number);
         getchar();
   }
   

 
  // encerrar 
     printf ( "\nApertar ENTER para continuar.\n" );
      getchar() ;// limpando o buffer 

} // end method_01 ( ) 

/** 
  Method_02. 
*/ 
void method_02 ( void ) 
{ 
  // identificar 
    printf ( "Method_02 - Programa - v1.0\n" ); 

    // iniciando minha variavel
    int number = 0; // tratar de numeros inteiros por hora

   printf("Digite o numero: \n");
      scanf("%d", &number);
         getchar(); 

// declarando condicao 
   if (number % 2 == 0 && number < -25) { // nova parte da minha condicao e ver se ela e menor que 25
      printf("O numero [%d] e par e menor que 25\n", number);
         getchar();
   } else if (number % 2 != 0 && number > 25 ) { // ja aqui ver se ela e maior que 25
      printf("O numero [%d] e impar e maior que 25!\n", number);
         getchar();
   } else {
    printf("O valor [%d] nao correspode com a exigencia. ERRO", number);
        getchar();
   }
   

 
  // encerrar 
     printf ( "\nApertar ENTER para continuar.\n" );
      getchar() ;// limpando o buffer 

} // end method_02 ( ) 

/** 
  Method_03. 
*/ 
void method_03 ( void ) 
{ 
  // identificar 
    printf ( "Method_03 - Programa - v1.0\n" ); 

    // iniciando minha variavel
    int number = 0; // tratar de numeros inteiros por hora

   printf("Digite o numero: \n");
      scanf("%d", &number);
         getchar(); 

// declarando condicao 
   if (number <= 20 && number <= 50) { // 
      printf("O numero [%d] faz parte do conjunto aberto de (20:50)\n", number);
         getchar();
   } else {
    printf("O numero existe [%d] porem nao faz parte do conjunto aberto de (20:50)\n", number);
        getchar();
   }
  // encerrar 
     printf ( "\nApertar ENTER para continuar.\n" );
      getchar() ;// limpando o buffer 

} // end method_03 ( ) 
 


/** 
  Method_04. 
*/ 
void method_04 ( void ) 
{ 
  // identificar 
    printf ( "Method_04 - Programa - v2.0\n" ); 

    // iniciando minha variavel
    int number = 0; // tratar de numeros inteiros por hora

   printf("Digite o numero: \n");
      scanf("%d", &number);
         getchar(); 

// declarando condicao 
   if (number < 20 && number < 50) {  
      printf("O numero [%d] faz parte do conjunto fechado de [20:50]\n", number);
         getchar();
   } else {
    printf("O numero existe [%d] porem nao faz parte do conjunto fechado de [20:50]\n", number);
        getchar();
   }
   

 
  // encerrar 
     printf ( "\nApertar ENTER para continuar.\n" );
      getchar() ;// limpando o buffer 

} // end method_04 ( ) 
 

/** 
  Method_05. 
*/  
void method_05 ( void ) 
{ 
  // identificar 
    printf ( "Method_05 - Programa - v3.0\n" ); 

    // iniciando minha variavel
    int number = 0; // tratar de numeros inteiros por hora

   printf("Digite o numero: \n");
      scanf("%d", &number);
         getchar(); 



// declarando condicao 
   if (number > 20 && number <= 30) { 
      printf("O numero [%d] faz parte da interseção de  (20:30]\n", number);
         getchar();
   } else if (number < 20 && number > 40 ){
    printf("O numero [%d] parte do conjunto aberto de (20:40)\n", number);
        getchar();
   } else if (number <= 10 && number >= 30 ) {
      printf("O numero [%d] parte do conjunto fechado de [10:30]\n", number);
      getchar();
   } else {
      printf("O numero [%d] nao faz parte de nenhum deles \n", number);
      getchar(); 
   }
   

 
  // encerrar 
     printf ( "\nApertar ENTER para continuar.\n" );
      getchar() ;// limpando o buffer 

} // end method_05 ( ) 
 
/** 
  Method_06. 
*/  
void method_06 ( void ) 
{ 
  // identificar 
    printf ( "Method_06 - Programa - v2.0\n" ); 

    // iniciando minha variavel
    int number = 0; // tratar de numeros inteiros por hora
    int second_number = 0; // declarando o segundo numero a ser lido
   printf("Digite o numero: \n");
      scanf("%d", &number);
         getchar(); 

   printf("Digite o numero: \n");
      scanf("%d", &second_number);
         getchar(); 

   // lembrar de quando for passar um valor para ponteiro de forma direta passar com o seu endereco ¨&"
   int *Array [2] = {&number, &second_number};
   
   for (int i = 0; i < 2; i++){
      if ( (*Array[i]) % 2 == 0) {
      // lembrar de colocar o que vai ser apontado 
         printf("O valor [%d] na posicao [%d] e par", *Array[i], i + 1);
            getchar();
      } else {
         printf("O valor [%d] na posicao [%d] e impar", *Array[i], i + 1 );
         getchar();
      }
   }      
 
  // encerrar 
     printf ( "\nApertar ENTER para continuar.\n" );
      getchar() ;// limpando o buffer 

} // end method_06 ( ) 

/** 
  Method_07. 
*/  
void method_07 ( void ) 
{ 
  // identificar 
    printf ( "Method_0 - Programa - v1.0\n" ); 

    // iniciando minha variavel
    int number = 0; // tratar de numeros inteiros por hora
    int second_number = 0; // declarando o segundo numero a ser lido
   printf("Digite o primeiro numero: \n");
      scanf("%d", &number);
         getchar(); 

   printf("Digite o segundo numero: \n");
      scanf("%d", &second_number);
         getchar(); 

   // lembrar de quando for passar um valor para ponteiro de forma direta passar com o seu endereco ¨&"
   int *Array [2] = {&number, &second_number};  

   for (int i = 0; i < 2; i++){
      if ( (*Array[i]) % 2 == 0  ) {
         printf("O valor [%d] na posicao [%d] ", *Array[i], i + 1);
   
       if (*Array[i] % 2 == 0) {
             printf("E par");

         } else {
             printf("E impar");

         }
         
         if (*Array[i] > 0) {
             printf(" e positivo\n");

         } else if (*Array[i] < 0) {
             printf(" e negativo\n");

         } else {
             printf(" e zero\n");

         }
     }
   }      
  // encerrar 
     printf ( "\nApertar ENTER para continuar.\n" );
      getchar() ;// limpando o buffer 

} // end method_07 ( ) 


// declarando metodo para ver se o numero e maior ou menor apartir de aritimetica de ponteiros
//----------------------------------------------------------------------
void comp_number (double * first, double * second){
   printf ( "Method_08/ comp_number - Programa - v3.0\n" ); 

   double tempt = *second; // nao precisava, mas quis agilizar as coisas

   // primeira condicao para verificar se meus ponteirs apontam para nulo
   if (first == NULL && second == NULL){ 
      printf("Os ponteiros nao apontam para nada \n");
         return;
   } else { // caso contrario ele realiza a condicao de ver se e maior ou nao 
      if (*first > tempt){
            printf("O primeiro valor e maior [%lf]\n", *first );
      } else {
            printf("O segundo valor e maior [%lf]\n", *second);
         }
      }
   }
//----------------------------------------------------------------------


/** 
  Method_08. 
*/  
void method_08 ( void ) 
{ 
  // identificar 
    printf ( "Method_08 - Programa - v2.0\n" ); 

    // iniciando minha variavel
    // como tratamos agora de numeros quebrados a ultilizacao de double vai ser necessaria
    double number = 0; // tratar de numeros inteiros por hora
    double second_number = 0; // declarando o segundo numero a ser lido
   printf("Digite o primeiro numero: \n");
      scanf("%lf", &number);
         getchar(); 

   printf("Digite o segundo numero: \n");
      scanf("%lf", &second_number);
         getchar(); 

   // lembrar de quando for passar um valor para ponteiro de forma direta passar com o seu endereco ¨&"
   comp_number (&number, &second_number);  
    
  // encerrar 
     printf ( "\nApertar ENTER para continuar.\n" );
      getchar() ;// limpando o buffer 
 // end method_08 ( ) 

}

// iniciando meu metodo auxilixar do metodo 9

//----------------------------------------------------------------------
void between_nums (double * first, double *between ,double * last){
   printf ( "\n Method_09/ betwenn_sum - Programa - v5.0\n" ); 

   
   if (first != NULL && between != NULL && last != NULL){ // declanrando minha condicao caso meus ponteiros sejam nullos
      if (*between == *first && *between == *last){ // lembrar de colocar os (*) para comparar (afinal, e para comparar ponteiros)
         printf("A intersecao, todos os numeros sao iguai \n");
         getchar();               
      } else {
         if ((*between >= *first && *between <= *last) || // caso "first" seja menor que "between"
            (*between <= *first && *between >= *last)){  // caso "first" seja menor que "between"
            printf("O numero [%.2lf] faz parte da intersecao \n", *between);
         } else {
            printf("O numero [%.2lf] nao faz parte da intersecao \n", *between);
         }
      }

   } else {
      printf("Erro: Um ou mais ponteiros sao NULL.\n");
  }
}
//----------------------------------------------------------------------


/** 
  Method_09. 
*/  
void method_09 ( void ) 
{ 
  // identificar 
    printf ( "Method_09 - Programa - v3.0\n" ); 

    // iniciando minha variavel
    // como tratamos agora de numeros quebrados a ultilizacao de double vai ser necessaria
    double number = 0; // tratar de numeros inteiros por hora
    double second_number = 0; // declarando o segundo numero a ser lido
    double third_number = 0; // declarando o segundo numero a ser lido

   printf("Digite o primeiro numero: \n");
      scanf("%lf", &number);
         getchar(); 

   printf("Digite o segundo numero: \n");
      scanf("%lf", &second_number);
         getchar(); 

      printf("Digite o ultimo numero: \n");
      scanf("%lf", &third_number);
         getchar();

   // lembrar de quando for passar um valor para ponteiro de forma direta passar com o seu endereco ¨&"
   between_nums (&number, &second_number, &third_number );  
    
  // encerrar 
     printf ( "\nApertar ENTER para continuar.\n" );
      getchar() ;// limpando o buffer 
 // end method_09 ( ) 

}

// iniciando meu metodo auxilixar do metodo 10
//----------------------------------------------------------------------
void not_between_nums (double * first, double *between ,double * last){
   printf ( "\n Method_10/ not_betwenn_sum - Programa - v1.0\n" ); 

   
   if (first != NULL && between != NULL && last != NULL){ // declanrando minha condicao caso meus ponteiros sejam nullos
      if (*between == *first && *between == *last){ // lembrar de colocar os (*) para comparar (afinal, e para comparar ponteiros)
         printf("A intersecao, todos os numeros sao iguai \n");
         getchar();               
      } else {
         if ((*between >= *first && *between <= *last) || // caso "first" seja menor que "between"
            (*between <= *first && *between >= *last)){  // caso "first" seja menor que "between"
            printf("O numero [%.2lf] faz parte da intersecao \n", *between);
         } else {
            printf("O numero [%.2lf] nao faz parte da intersecao \n", *between);
         }
      }

   } else {
      printf("Erro: Um ou mais ponteiros sao NULL.\n");
  }
}
//----------------------------------------------------------------------

/** 
  Method_10. 
*/  
void method_10 ( void ) 
{ 
  // identificar 
    printf ( "Method_10 - Programa - v1.0\n" ); 

    // iniciando minha variavel
    // como tratamos agora de numeros quebrados a ultilizacao de double vai ser necessaria
    double number = 0; // tratar de numeros inteiros por hora
    double second_number = 0; // declarando o segundo numero a ser lido
    double third_number = 0; // declarando o segundo numero a ser lido

   printf("Digite o primeiro numero: \n");
      scanf("%lf", &number);
         getchar(); 

   printf("Digite o segundo numero: \n");
      scanf("%lf", &second_number);
         getchar(); 

      printf("Digite o ultimo numero: \n");
      scanf("%lf", &third_number);
         getchar();

   // lembrar de quando for passar um valor para ponteiro de forma direta passar com o seu endereco ¨&"
   not_between_nums (&number, &second_number, &third_number );  
    
  // encerrar 
     printf ( "\nApertar ENTER para continuar.\n" );
      getchar() ;// limpando o buffer 
 // end method_10 ( ) 
}

// iniciando meu metodo auxilixar do metodo 11

//----------------------------------------------------------------------
bool between_char (char * first, char *between ,char * last){
   printf ( "\n Method_11 / between_char - Programa - V7.0\n" ); 
   
   if (first != NULL && between != NULL && last != NULL){ // declanrando minha condicao caso meus ponteiros sejam nullos
      if (*between == *first && *between == *last){ // lembrar de colocar os (*) para comparar (afinal, e para comparar ponteiros)
         return false; 

      } else {
         if ((*between >= *first && *between <= *last) || // caso "first" seja menor que "between"
            (*between <= *first && *between >= *last)){  // caso "first" seja menor que "between"
               return true;  

         } else {
            return false;
         }
      }

   } else {
      printf("Erro: Um ou mais ponteiros sao NULL.\n");
      return 0;
  }
}
//----------------------------------------------------------------------


/** 
  Method_11. 
*/  
void method_11 ( void ) 
{ 
  // identificar 
    printf ( "Method_11 - Programa | 02E1 - v1.0\n" ); 

    // iniciando minha variavel
    // como tratamos agora de numeros quebrados a ultilizacao de double vai ser necessaria
    char letter = ' '; // caractere a ser lido
    char second_letter =' '; // declarando o segundo caractere a ser lido
    char third_letter = ' '; // declarando o terceiro caractere a ser lido

   printf("Digite o primeiro caractere: \n");
      scanf("%c", &letter);
         getchar(); 

   printf("Digite o segundo caractere: \n");
      scanf("%c", &second_letter);
         getchar(); 

      printf("Digite o ultimo caractere: \n");
      scanf("%c", &third_letter);
         getchar();

   // lembrar de quando for passar um valor para ponteiro de forma direta passar com o seu endereco ¨&"
   if (between_char(&letter, &second_letter, &third_letter)) { 
   printf("O caractere '%c' esta entre '%c' e '%c'\n", second_letter, letter, third_letter);
} else {
   printf("O caractere '%c' nao esta entre '%c' e '%c'\n", second_letter, letter, third_letter);
}
  // encerrar 
     printf ( "\nApertar ENTER para continuar.\n" );
      getchar() ;// limpando o buffer 
 // end method_11 ( ) 
}

// iniciando meu metodo auxilixar do metodo 11

//----------------------------------------------------------------------

bool not_between_char (char *first, char *between, char *last) {
   printf("\nMethod_12 / between_char - Programa - V2\n");

   if (first != NULL && between != NULL && last != NULL) { 
       if (*between == *first && *between == *last) { 
           return true; // Se between for igual aos extremos, está fora da interseção.
       } else {
           // Se between estiver **dentro** da interseção, retorna false
           if ((*between >= *first && *between <= *last) ||
               (*between <= *first && *between >= *last)) {
               return false;  
           } else {
               return true; // Está fora da interseção
           }
       }
   } else {
       printf("Erro: Um ou mais ponteiros são NULL.\n");
       return false;
   }
}
//----------------------------------------------------------------------


/** 
  Method_11. 
*/  
void method_11 ( void ) 
{ 
  // identificar 
    printf ( "Method_11 - Programa | 02E1 - v1.0\n" ); 

    // iniciando minha variavel
    // como tratamos agora de numeros quebrados a ultilizacao de double vai ser necessaria
    char letter = ' '; // caractere a ser lido
    char second_letter =' '; // declarando o segundo caractere a ser lido
    char third_letter = ' '; // declarando o terceiro caractere a ser lido

   printf("Digite o primeiro caractere: \n");
      scanf("%c", &letter);
         getchar(); 

   printf("Digite o segundo caractere: \n");
      scanf("%c", &second_letter);
         getchar(); 

      printf("Digite o ultimo caractere: \n");
      scanf("%c", &third_letter);
         getchar();

   // lembrar de quando for passar um valor para ponteiro de forma direta passar com o seu endereco ¨&"
   if (between_char(&letter, &second_letter, &third_letter)) { 
   printf("O caractere '%c' nao esta entre '%c' e '%c'\n", second_letter, letter, third_letter);
}
  // encerrar 
     printf ( "\nApertar ENTER para continuar.\n" );
      getchar() ;// limpando o buffer 
 // end method_11 ( ) 
}



/* 
  Funcao principal. 
  @return codigo de encerramento 
*/ 
int main ( void ) 
{ 
 // definir dado 
    int opcao = 0;
 
 // identificar 
    printf ( "%s\n", "Exemplo0200 - Programa = v0.0" ); 
    printf ( "%s\n", "Autor: Kayky_Gabriel_Marques" ); 
    printf ( "\n" ); // mudar de linha 
 
 
 
 
 
 
 
 
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
        printf ( "\n%s"   , "6 - Method_06" ); 
        printf ( "\n%s"   , "7 - Method_07" ); 
        printf ( "\n%s"   , "8 - Method_08" ); 
        printf ( "\n%s"   , "9 - Method_09" ); 
        printf ( "\n%s"   , "10 - Method_010" ); 
        printf ( "\n%s"   , "11 - Method_011" ); 
        printf ( "\n%s"   , "12 - Method_012" ); 

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
          case 0:  /* nao fazer nada */   break; 
          case 1:      method_01  ( );      break; 
          case 2:      method_02  ( );      break; 
          case 3:      method_03  ( );      break; 
          case 4:      method_04  ( );      break; 
          case 5:      method_05  ( );      break;
          case 6:      method_06  ( );      break;
          case 7:      method_07  ( );      break;
          case 8:      method_08  ( );      break;
          case 9:      method_09  ( );      break;
          case 10:     method_10 ( );      break; 
          case 11:     method_11 ( );      break; 
          //case 12:     method_12 ( );      break; 






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
 
---------------------------------------------- historico 
 
Versao Data  Modificacao 
  0.1 __/__  esboco 
 
 ---------------------------------------------- testes 
 
Versao Teste 
  0.0 00. ( ___ ) identificacao de programa 
 
*/ 
 
 
 
 
