
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
// funcao auxiliar para mehtod_01
int count_reals_In_interval(double *array, int n_numbers, double firts_interval, double second_interval)
{
   IO_id("Funcao auxiliar count_reals_In_interval | method_01 - 4.1");

   // adicionando variaveis axuliares
   int count = 0; // -> um dos objetivos que foram solicitados pelo enunciado
   double *ptr = array;

   for (; ptr < array + n_numbers; ptr++)
   { // -> loop para "caminhas" com as posicoes que array aponta

      bool if_true = (*ptr >= firts_interval && *ptr <= second_interval); // condicao booleana

      if (if_true)
      { // -> condicao principal
         printf("O numero [%.2lf] esta no intervalo [ %.2lf : %.2lf ] \n", *ptr, firts_interval, second_interval);
         count++; // -> contador solicitado pelo enunciado              // lembrar de colocar o "*"
      }
      else
      {
         printf("O numero [%.2lf] nao esta no intervalo [ %.2lf : %.2lf ] \n", *ptr, firts_interval, second_interval);
      }
   }

   return count;
}
//---------------------


//---------------------
/**
   Method_01 - Repeticao para ler certa quantidade de valores.
 */
void method_01()
{
   // definir dado
   int n_numbers = 0;         // -> tamanho que array vai ter
   double firts_interval = 0; // -> primeiro e segundo intevalo
   double second_interval = 0;

   // identificar
   IO_id("EXEMPLO0401 - Method01- v1.0");

   // ler do teclado
   printf("Digite o valor do tamanho do array: \n");
   scanf("%d", &n_numbers);
   getchar();

   printf("Digite o valor do intevalo: \n");
   scanf("%lf %lf", &firts_interval, &second_interval);
   getchar();

   // alocacao dinamica para *array ter o tamanho de n_numbers

   double *array = (double *)malloc(n_numbers * sizeof(double));
   // verificando se array aponta para nulo
   if (array == NULL)
   {
      printf("ERRO ao alocar memoria \n");
      return;
      getchar();
   }

   // loop onde que meu ponteiro recebe a posicao do array, compara se e menor que array mais n_numbers
   for (double *pointer = array; pointer < array + n_numbers; pointer++)
   {
      printf("Digite os valore na posicao [%d]\n", pointer - array); // -> com isso mostro a posicao que a onde que ser guardado o valor
      scanf("%lf", pointer);
      getchar();
   }

   int count = count_reals_In_interval(array, n_numbers, firts_interval, second_interval);

   printf("[%d] foi a quantidade de numeros que fazem parte do intervalo de [%.2lf : %.2lf]", count, firts_interval, second_interval);
   getchar();

   free(array);
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_01 ( )
//---------------------


// funcao auxiliar para mehtod_02
//---------------------
void read_last_string(char *letter, int *count, bool one_call)
{
   if (one_call) { 
   IO_id("Funcao auxiliar read_last_string | method_02 - 7.0");
}
     // Caso base
     if (*letter == '\0') {
      printf("Houveram [%d] letras menores que \n", *count);
      return;
  }


  bool if_uppercase  =  *letter  >= 'A'  &&  *letter <= 'Z';
  bool if_letter_c_p = *letter  >  'c'  &&  *letter < 'p';

  // Verifica se a letra e minuscula
  if (if_uppercase ) {
      // Compara cada caractere com c e p 
      if (if_letter_c_p) { // condicao de objetivo 
          printf("A letra [%c] letras maiuscula maior que 'c' e menor que 'p'\n", *letter);
         (*count)++;
  } 
}

  // Chamada recursiva para o próximo caractere
  read_last_string(letter + 1, count, false);
}
//---------------------


//---------------------
/**
   Method_02 -
 */
void method_02(void)
{
   // definir dado
   
char letter[100]; // Array para armazenar a string 
int count = 0;
bool one_call = true;

// identificar 
IO_id ( "EXEMPLO0402 - Method02 - v ?.0" ); 

//iniciando os valores 

  printf("Escreva a frase: ");
   fgets(letter, sizeof(letter), stdin);  
       getchar(); // Limpa o buffer de entrada


        read_last_string(letter, &count, one_call); // Passa a string para o metodo recursivo



   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_02 ( )
//---------------------


//---------------------
// Função para contar letras minúsculas entre 'c' e 'p'
int count_lowercase_c_to_p(char *letter) {
   IO_id("Funcao auxiliar count_lowercase_c_to_p | method_03 - 2.0");

   int count = 0;

   // Percorre a string ate encontrar '\0'
   while (*letter != '\0') {
       // Verifica se o caractere e uma letra minuscula
       bool is_lowercase = *letter >= 'a' && *letter <= 'z';
       // Verifica se a letra está entre 'c' e 'p'
       bool is_between_c_p = *letter > 'c' && *letter < 'p';

       if (is_lowercase && is_between_c_p) {
           printf("A letra [%c] e minuscula e esta entre 'c' e 'p'\n", *letter);
           count++;
       }
       letter++; // Avança para o próximo caractere
   }

   return count;
}
//---------------------


//---------------------
/**
   Method_03 -
 */
   void method_03() {
   char letter[100]; // Array para armazenar a string
   int  count = 0;    // Contador de letras minusculas entre 'c' e 'p'

   // Identificar o método
   IO_id("EXEMPLO0403 - Method03- v 2.0");

   // ler entrada de dados
   printf("Escreva a frase: ");
   if (fgets(letter, sizeof(letter), stdin) == NULL) { // -> caso o "ponteiro" aponte para o nulo 
       printf("Erro ao ler a entrada.\n");  
       return; getchar( );
   }

   // Remover a quebra de linha, se presente
   size_t len = strlen(letter);
   if (len > 0 && letter[len - 1] == '\n') {
       letter[len - 1] = '\0';
   }

   // Chamar a função e obter o resultado
   count = count_lowercase_c_to_p(letter);

   // Exibir o resultado
   printf("Quantidade de letras minusculas entre 'c' e 'p': %d\n", count);

   // Encerrar
   printf("Apertar ENTER para continuar");
   getchar();
}
//---------------------


//funcao de auxilio para filtrar palavras que nao passaram no teste. 
//---------------------
char word_filter (const char *letter, char *output){ 
   IO_id("Funcao auxiliar word_filter | method_04 - 2.0");

   if (letter == NULL){ // -> esqueci que essa comp nao pode usar o "*"
      printf("ERRO: Nada esta sendo apontado \n");
         return -1 ;
   }

   int j = 0;
   for ( int i = 0;  letter[i] != '\0'; i = i + 1){ // - > condicao para ver se a posicao de letter e \0

         bool is_lowercase =   letter[i] >= 'a' &&  letter [i] <=  'z'; // -> esqueci de mostrar o que ele precisa comprar, o seu index (o que esta dentro)
         bool is_between_c_p = letter[i] >  'c' && letter  [i] <   'p';
     
         if (  ! (is_between_c_p && is_lowercase)  ){
            output[j] = letter [i];
            j++;
       }
   }
   output[j] ='\0'; // -> errei o lado em que o barra lol
   return output[j];
}
//---------------------


//---------------------
/**
   Method_04 
 */
void method_04()
{
   // definir dado
   char *letter [99];
   char *output [99];

   // identificar
   IO_id("EXEMPLO0404 - Method04 - v1.0");

   printf("Escreva a frase: \n");
      if(fgets(letter, sizeof(letter), stdin) == NULL){
         printf("ERRO: ao ler a entrada");
            return; getchar ( );
      }

      size_t lenth = strlen (letter);

      if (lenth > 0 && letter[lenth - 1] == '\n'){
         letter [ lenth - 1 ] = '\0';
      }

      word_filter(letter, output);

      printf("Letras filtradas: %s\n", output);
//
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_04 ( )
//---------------------


//funcao de auxilio para filtrar palavras que nao passaram no teste. 
//---------------------
char count_chars_between_cp (const char *letter, int *count){ 
   IO_id("Funcao auxiliar count_chars_between_cp | method_05 - 3.0");

   if (letter == NULL){ // -> esqueci que essa comp nao pode usar o "*"
      printf("ERRO: Nada esta sendo apontado \n");
         return;
   }

   int j = 0;
   for ( int i = 0;  letter[i] != '\0'; i = i + 1){ // - > condicao para ver se a posicao de letter e \0
         bool is_uppercase   = letter[i] >= 'A' &&  letter [i] <=  'Z';
         bool is_lowercase   = letter[i] >= 'a' &&  letter [i] <=  'z'; // -> esqueci de mostrar o que ele precisa comprar, o seu index (o que esta dentro)
         bool is_between_c_p = letter[i] >  'c' && letter  [i] <   'p';
         bool is_between_C_P = letter[i] >  'C' && letter  [i] <   'P';

          // Se for diferente de uma letra maiuscula ou minuscula entre C-P ou c-p, contar
         if (  (is_uppercase && is_between_C_P) || 
            (is_lowercase && is_between_c_p)    ){ // condicao principal 
               printf("o caractere [%c] e tanto maiusculas, quanto minusculas maiores que 'c' ou 'C' e menores que 'P' ou  'p' \n", letter[i]);
               (*count)++; // mais uma vez esqueici do '*' para representar o ponteiro 
             }
   }
   return *count;  // mais uma vez esqueici do '*' para representar o ponteiro
}
//---------------------


//---------------------
/**
   Method05 - Ler valores e contar positivos menores que 100 e pares (alternativo).
 */
void method_05()
{
   // identificar
   IO_id("EXEMPLO0405 - Method05 - v2.0");
   // definir dado
   char *letter [99];
   char *output [99];
   int   count = 0;

   printf("Escreva a frase: \n");
      if(fgets(letter, sizeof(letter), stdin) == NULL){
         printf("ERRO: ao ler a entrada");
            return; getchar ( );
      }

      size_t lenth = strlen (letter);

      if (lenth > 0 && letter[lenth - 1] == '\n'){
         letter [ lenth - 1 ] = '\0';
      }

      count_chars_between_cp (letter, &count);

      printf("A quantidade de letras que sao maiores e menors que 'C', 'c', 'P', 'p' e [%d]: \n", count);

//
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_05 ( )
//---------------------


//---------------------
char count_chars_between_cp_another (const char *letter, char *output, int *count){ 
   IO_id("Funcao auxiliar count_chars_between_cp_another | method_06 - 2.0");

   if (letter == NULL){ // -> esqueci que essa comp nao pode usar o "*"
      printf("ERRO: Nada esta sendo apontado \n");
         return;
   }

   int j = 0;
   for ( int i = 0;  letter[i] != '\0'; i = i + 1){ // - > condicao para ver se a posicao de letter e \0
         bool is_uppercase   = letter[i] >= 'A' &&  letter [i] <=  'Z';
         bool is_lowercase   = letter[i] >= 'a' &&  letter [i] <=  'z'; // -> esqueci de mostrar o que ele precisa comprar, o seu index (o que esta dentro)
         bool is_between_c_p = letter[i] >  'c' && letter  [i] <   'p';
         bool is_between_C_P = letter[i] >  'C' && letter  [i] <   'P';

          // Se for diferente de uma letra maiuscula ou minuscula entre C-P ou c-p, adicionar a outra string
         if (  ! (is_uppercase && is_between_C_P) || 
            (is_lowercase && is_between_c_p)    ){ // condicao principal 
            output[j] = letter [i]; // -> vai fazer uma nova string e printar 
            j++;
       } else {
         printf("o caractere [%c] e tanto maiusculas, quanto minusculas maiores que 'c' ou 'C' e menores que 'P' ou  'p' \n", letter[i]);
         (*count)++; // mais uma vez esqueici do '*' para representar o ponteiro 
       }
   }
   output[j] ='\0'; // -> errei o lado em que o barra lol
   return *count;  // mais uma vez esqueici do '*' para representar o ponteiro
}
//---------------------


//---------------------
/**
   Method06 - Ler valores e contar positivos menores que 100 e pares (alternativo).
 */
void method_06()
{
   // identificar
   IO_id("EXEMPLO0406 - Method06 - v2.0");
   // definir dado
   char *letter [99];
   char *output [99];
   int   count = 0;

   printf("Escreva a frase: \n");
      if(fgets(letter, sizeof(letter), stdin) == NULL){
         printf("ERRO: ao ler a entrada");
            return; getchar ( );
      }

      size_t lenth = strlen (letter);

      if (lenth > 0 && letter[lenth - 1] == '\n'){
         letter [ lenth - 1 ] = '\0';
      }

      count_chars_between_cp_another (letter, output, &count);

      printf("A quantidade de letras que sao maiores e menors que 'C', 'c', 'P', 'p' e [%d]: \n", count);

      printf("Letras filtradas (nao fazem parte da condicao): %s\n", output);

//
   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_06 ( )
//---------------------


//funcao de auxilio para contar e converter char em numero. 
//---------------------
int count_char_numbers(const char *letter, int *count) {
   IO_id("Funcao auxiliar count_char_numbers | method_07 - 3.5");

   if (letter == NULL) {
       printf("ERRO: Nada esta sendo apontado \n");
       return -1;  // Retorno de erro
   }

   // definindo dados 
   *count = 0;
   int number = 0;

   for (int i = 0; letter[i] != '\0'; i++) {
       bool char_numbers = letter[i] >= '0' && letter[i] <= '9';

       //caso seja diferente de numeros 
       if (!(char_numbers)) {
           printf("o caractere [%c] nao faz parte do conjunto numerico \n", letter[i]);
       } else { // condicao principal 
           // conversao de char para int
           int value = letter[i] - '0';
           number = (number * 10) + value;

           printf("O caracter [%c] e um numero! \n", letter[i]);
           (*count)++;
       }
   }

   printf("Numeros formados apartir de caracteres: %d\n", number);
   return *count;
}
//---------------------


//---------------------
/**
   Method_07 - Ler palavra, contar e mostrar numeros.
 */
void method_07()
{
   IO_id("EXEMPLO0407 - Method07 - v2.0");

    // definir dado
    char letter[99];
    int count = 0;

    printf("Escreva a frase: \n");
    if (fgets(letter, sizeof(letter), stdin) == NULL) {
        printf("ERRO: ao ler a entrada");
        return;
    }

    size_t lenth = strlen(letter);

    if (lenth > 0 && letter[lenth - 1] == '\n') {
        letter[lenth - 1] = '\0';
    }

    int result = count_char_numbers(letter, &count);

    if (result != NULL) {
        printf("Existem [%d] numeros na string: [%s] \n", count, letter);
    }

 // encerrar
 IO_pause("Apertar ENTER para continuar");
} // end method_07 ( )
//---------------------


//funcao de auxilio para verficar caracteres nao alfanumerico. 
//---------------------
int not_alphanumeric(const char *letter, char *output, int *count) {
   IO_id("Funcao auxiliar not_alphanumeric | method_08 - 2.0");

   if (letter == NULL) {
       printf("ERRO: Nada esta sendo apontado \n");
       return -1;  // Retorno de erro
   }

   int j = 0;
   for (int i = 0; letter[i] != '\0'; i++) {
       bool is_alphabetic = (letter[i] >= 'A' && letter[i] <= 'Z') || 
                            (letter[i] >= 'a' && letter[i] <= 'z');
       bool char_numbers = letter[i] >= '0' && letter[i] <= '9';

       // caso a string conter letras ou numeros, vai realizar a troca de string
       if (!(is_alphabetic || char_numbers)) { // condicao principal 
           output[j] = letter[i]; // -> vai fazer uma nova string e printar 
           j++;
       } else {
           printf("o caractere [%c] e alfanumerico  \n", letter[i]);
           (*count)++; // -> vai contar a quantidade de caracteres alfanumericos
       }
   }
   output[j] = '\0'; // -> terminador de string
   return *count;
}
//---------------------


//---------------------
/**
   Method_08 - Ler palavra, contar e mostrar caracteres nao alfanumericos 
 */
void method_08()
{
   // identificar
   IO_id("EXEMPLO0408 - Method08 - v2.0");
   // definir dado
   char *letter [99];
   char *output [99];
   int   count = 0;

   printf("Escreva a frase: \n");
      if(fgets(letter, sizeof(letter), stdin) == NULL){
         printf("ERRO: ao ler a entrada");
            return; getchar ( );
      }

      size_t lenth = strlen (letter);

      if (lenth > 0 && letter[lenth - 1] == '\n'){
         letter [ lenth - 1 ] = '\0';
      }

      not_alphanumeric (letter, output, &count);

      printf("Existem [%d] numeros que sao alfanumericos: \n", count);

      printf("Letras filtradas (nao sao alfanumericos): %s\n", output);

//

IO_pause("Apertar ENTER para continuar");
} // end method_08 ( )
//---------------------


//funcao de auxilio para verficar caracteres e alfanumerico. 
//---------------------
char is_aphanumeric (char * letter, char *output, int *count){
   IO_id("Funcao auxiliar is_aphanumeric | method_09 - 1.0");

   if (letter == NULL ){
      printf("ERRO: nada esta sendo apontado");
         return -1; getchar ( );
   }

   int j = 0;

   for (int i = 0; letter[i] != '\0'; i++){

      bool is_numbers =   letter[i] >= '0' && letter[i] <= '9';
      bool is_letters = (letter[i] >= 'a' && letter[i] <= 'z' ||
                         letter[i] >= 'A' && letter[i] <= 'Z');
   
         if (!(is_numbers || is_letters)){
            printf("O caracter [%c] nao e alfanumerico  \n", letter[i]);
            (*count)++;
         } else {
            printf("O caractere [%c] e alfanumerico  \n", letter[i]);
            output[j] = letter[i]; // -> vai fazer uma nova string e printar 

         }
   }
      output[j] = '\0';
      return output[j];
}
//---------------------


/**
   Method_09 - Ler palavra, contar e mostrar caracteres alfanumericos 
 */
void method_09()
{
    // identificar
    IO_id("EXEMPLO0409 - Method09 - v2.0");

   char *letter  [99];
   char *output  [99];
   int   count  =  0;

   printf("Digite a frase: \n");
      if (fgets(letter, sizeof(letter),stdin) == NULL){
         printf("Erro ao ler a entrada. \n");
            return;  getchar ( );
      }

      size_t lenth = strlen (letter); getchar ( );

      if (lenth > 0 && letter[lenth - 1] == '\n'){
         letter [ lenth - 1 ] = '\0';
      }
      
      is_aphanumeric(letter, output, &count);


      printf("Existem [%d] numeros que nao sao alfanumericos: \n", count);

      printf("Letras caracteres (sao alfanumericos): %s\n", output);


   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_09 ( )
//---------------------


// Função auxiliar para verificar caracteres alfanumericos
//---------------------
int more_than_one_and_alphanumeric(char *letter, char *output, int *count) {
   IO_id("Funcao auxiliar more_than_one_and_alphanumeric | method_10 - 1.0");

   printf("\nAnalisando a palavra: %s\n", letter);

   if (letter == NULL) {
       printf("ERRO: nada esta sendo apontado.\n");
       return;
   }

   int j = 0;
   int local_count = 0;

   for (int i = 0; letter[i] != '\0'; i++) {
       bool is_number = (letter[i] >= '0' && letter[i] <= '9');
       bool is_letter = (letter[i] >= 'a' && letter[i] <= 'z') || 
                        (letter[i] >= 'A' && letter[i] <= 'Z');

       if (!(is_number || is_letter)) {
           printf("O caractere [%c] nao e alfanumerico.\n", letter[i]);
       } else {
           printf("O caractere [%c] e alfanumerico.\n", letter[i]);
           output[j++] = letter[i]; // Adiciona à nova string
           local_count++; // Conta os caracteres alfanuméricos
       }
   }
   output[j] = '\0'; // Finaliza a string corretamente
   *count += local_count; // Acumula no total geral

   printf("Quantidade de caracteres alfanumericos nesta palavra: %d\n", local_count);

   return *count;
}
//---------------------


/**
   Method_10.
 */
void method_10()
{
   // identificar
   IO_id("EXEMPLO0409 - Method09 - v2.0");

  char *letter  [99];
  char *output  [99];
  int   total_count  =  0;

  printf("Digite a frase: \n");
     if (fgets(letter, sizeof(letter),stdin) == NULL){
        printf("Erro ao ler a entrada. \n");
           return;  getchar ( );
     }

     size_t lenth = strlen (letter); getchar ( );

     if (lenth > 0 && letter[lenth - 1] == '\n'){
        letter [ lenth - 1 ] = '\0';
     }
     
     more_than_one_and_alphanumeric(letter, output, &total_count);


     printf("\nTotal acumulado de caracteres alfanumericos: %d\n", total_count);
     printf("Letras caracteres (sao alfanumericos): %s\n", output);


   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_10 ( )
//---------------------


// Função auxiliar para verificar caracteres alfanumericos
//---------------------
int _less_than_three(char *letter, char *output, int *count) {
   IO_id("Funcao auxiliar less_than_three | method_11 - 4.0");

   printf("\nAnalisando a palavra: %s\n", letter);

   if (letter == NULL) {
       printf("ERRO: nada esta sendo apontado.\n");
       return - 1;
   }

   int j = 0;
   int local_count = 0;
   bool already_count = false; // -> vai servir como auxiliar, para o contador nao seja atuliaziado de forma desenssaria 

   for (int i = 0; letter[i] != '\0'; i++) {
       bool is_number = (letter[i] >= '0' && letter[i] <= '9');
       bool is_letter = (letter[i] >= 'a' && letter[i] <= 'z') || 
                        (letter[i] >= 'A' && letter[i] <= 'Z');

       if (!(is_number || is_letter)) {
           printf("O caractere [%c] nao e alfanumerico.\n", letter[i]); // -> nao e alfanumerico
               local_count = 0;// assim seu valor sempre vai reinicar caso o a condicao seja verdadeira (ser um nao alfanumerico )
               already_count = false;

       } else {
           printf("O caractere [%c] e alfanumerico.\n", letter[i]);// -> e alfanumerico 
           output[j++] = letter[i]; // Adiciona à nova string
           local_count++; // Conta os caracteres alfanuméricos
       }
       
       if (local_count > 3 && (!already_count) ){
            (*count)++;
            already_count = true;
       } 



   }
   output[j] = '\0'; // Finaliza a string corretamente

   return *count;
}
//---------------------


/**
   Method_11.
 */
void method_11()
{
   // identificar
   IO_id("EXEMPLO0412 - Method12 - v2.0");

  char *letter         [99];
  char *another_letter [99];
  char *output         [99];
  int   total_count  =   0;

  printf("Digite a frase: \n");
     if (fgets(letter, sizeof(letter),stdin) == NULL){
        printf("Erro ao ler a entrada. \n");
           return;  getchar ( );
     }

     size_t lenth = strlen (letter); getchar ( );

     if (lenth > 0 && letter[lenth - 1] == '\n'){
        letter [ lenth - 1 ] = '\0';
     }
     
     _less_than_three (letter, output, &total_count);


     printf("\nTotal acumulado de caracteres alfanumericos: %d\n", total_count);
     printf("Letras caracteres (sao alfanumericos): %s\n", output);

   // encerrar
   IO_pause("Apertar ENTER para continuar");
} // end method_11 ( )
//---------------------


//funcao de auxilio para contar digitos na string. 
//---------------------
int char_count (char const *string){
   IO_id("Funcao auxiliar char_count | method_12 - 2.0");

   int *count = 0;

   for (int i = 0; string[i] != '\0'; i++){
      bool is_number = (string[i] >= '0' && string[i] <= '9');

      if (!(is_number)){
         printf("O caracter [%c] nao e um digito. \n", string[i]);
      } else {
         printf("O caracter [%c] e um digito. \n", string[i]);
         (*count)++;
      }
   }
   return *count;
}
//---------------------


/**
   Method_12.
 */
void method_12()
{
   // identificar
   IO_id("EXEMPLO0412 - Method12 - v2.0");

  char letter         [99];
  char another_letter [99];
  int  count_one =       0;
  int  count_two =       0;



  printf("Digite a primeira string: ");
  fgets(letter, sizeof(letter), stdin);
  letter[strcspn(letter, "\n")] = 0; // Remove a nova linha

  printf("Digite a segunda string: ");
  fgets(another_letter, sizeof(another_letter), stdin);
  another_letter[strcspn(another_letter, "\n")] = 0; // Remove a nova linha


  count_one = char_count(letter);

  count_two = char_count(another_letter);

   if (count_one < count_two){
      printf("%s e a string com maior quantidade de digito", count_two);
   } else {
      printf("%s e a string com maior quantidade de digito", count_one);

   }


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
      IO_id("EXEMPLO0300 - Programa - v0.0");

      // ler do teclado
      IO_println("Opcoes");
      IO_println("0  - Method_00 parar");
      IO_println(" 1 - Method_01 mostrar as letrasmaiores que 'c' ou 'C' e menores que 'P' ou  'p' separadas por uma funcao");
      IO_println(" 2 - Method_02 contar e mostrar a quantidade de letras minusculas maiores que 'c' e menores que 'p'.");
      IO_println(" 3 - Method_03 mostrar a quantidade de letras minusculas maiores que 'c' e menores que 'p'.");
      IO_println(" 4 - Method_04 mostrar as letras minusculas maiores que 'c' e menores que 'p'(funcao).");
      IO_println(" 5 - Method_05 mostrar a quantidade de letras maiores que 'c' ou 'C' e menores que 'P' ou  'p').");
      IO_println(" 6 - Method_06 mostrar as letras maiores que 'c' ou 'C' e menores que 'P' ou  'p.");
      IO_println(" 7 - Method_07 mostrar a quantidade de digitos pares em uma cadeia de caracteres contados por uma funcao. ");
      IO_println(" 8 - Method_08 mostrar todos os simbolos nao alfanumericos em uma cadeia de caracteres separados por meio de uma funcao.");
      IO_println(" 9 - Method_09  mostrar todos os símbolos alfanumericos em uma cadeia de caracteres separados por meio de uma fucao ");
      IO_println("10 - Method_10  mostrar e contar a quantidade de simbolos alfanumericos em cada palavra, por meio de uma função, e calcular o total acumulado de todas as palavras.");
      IO_println("11 - Method_11  contar a quantidade de simbolos alfanumericos, incluindo espacos em branco, em cada palavra, e calcular o total de todas as palavras com mais de tres simbolos.");
      IO_println("10 - Method_10  calcular qual das duas sequencias possui a maior quantidade de digitos, por meio de uma funcao.");

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
