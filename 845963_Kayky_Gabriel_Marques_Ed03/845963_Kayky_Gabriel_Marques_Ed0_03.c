/* 
   Exemplo0 300 - v0.0. - __ / __ / _____ 
   Author: Kayky_Gabriel_Marques  
    
   Para compilar em terminal (janela de comandos): 
   Linux      : gcc -o exemplo0200        exemplo0200.c 
   Windows: gcc -o exemplo0200        exemplo0200.c 
 
   Para executar em terminal (janela de comandos): 
   Linux      :  ./exemplo0200 
   Windows:    exemplo0200 
 */ 
// dependencias 
#include "io.h"  // para definicoes proprias 
#include <stdio.h> // biblioteca de apoio
#include <stdlib.h> // biblioteca de apoio 
#include <string.h>
#include <stdbool.h>

/** 
   Method_00 - nao faz nada. 
 */ 
void method_00 ( void ) 
{ 
 // nao faz nada 
} // end method_00 ( ) 


// iniciando o metodo auxiliar para method_01
//---------------------
void read_string(char *letter, bool one_call) {
   if (one_call) { 
   IO_id ( "read_string - v 6.0" ); 
}
   // Verifica se chegou ao final da string (caractere nulo '\0')
   if (*letter == '\0') {
       return; // Caso base: fim da recursão
   }

   // condicao para verificar se minha letra e maiuscula
   if (*letter <= 'A' && *letter >= 'Z') {

   // Compara cada caractere com 'K
   if (*letter >= 'K' ) {
       printf("A letra [%c] e maior ou igual a 'K' e maiuscula\n", *letter);

   } else {
       printf("A letra [%c] e menor que 'K' e minuscula \n", *letter);

   } 
} else { // caso a condicao seja falsa 
   printf("A letra [%c] nao e uma letra maiuscula \n", *letter);
}

   // Chamada recursiva para o proximo caractere
   read_string(letter + 1, false );
}
//---------------------


//---------------------
 
/** 
   Method_01 - Repeticao com teste no inicio. 
 */ 
void method_01 ( void ) 
{ 
 // definir dado 
   
 char letter[100]; // Array para armazenar a string (tamanho máximo: 99 caracteres)

 // identificar 
 IO_id ( "Method_01 - v 7.0" ); 

 //iniciando os valores 

   printf("Escreva a frase: ");
      scanf("%99[^\n]", letter); // Le a linha inteira ate a quebra de linha
         getchar(); // Limpa o buffer de entrada

 read_string(letter,true); // Passa a string para o metodo recursivo


 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_01 ( ) 
//---------------------


// iniciando o metodo auxiliar para method_02
//---------------------
void read_last_string(char *letter, bool one_call, int count) {
 // condicao de somente uma chamada para o "io_id"
 if (one_call) {
   IO_id("read_last_string - v 5.0");
}

    // Caso base
    if (*letter == '\0') {
      printf("Houveram [%d] letras menores que 'k'\n", count);
      return;
  }

  // Verifica se a letra e minuscula
  if (*letter >= 'a' && *letter <= 'z') {
      // Compara cada caractere com 'k'
      if (*letter <= 'k') { // condicao de objetivo 
          count = count + 1;
          printf("A letra [%c] e menor ou igual a 'k' e minuscula\n", *letter);
      } else {
          printf("A letra [%c] e maior que 'k' e minuscula\n", *letter);
      }
  } else { 
      printf("A letra [%c] nao e uma letra minuscula\n", *letter);
  }

  // Chamada recursiva para o próximo caractere
  read_last_string(letter + 1, false, count);
}
//---------------------

 
/** 
   Method_02 - 
 */ 
void method_02 ( void ) 
{ 
 // definir dado 
   
 char letter[100]; // Array para armazenar a string (tamanho máximo: 99 caracteres)

 // identificar 
 IO_id ( "Method_02 - v 1.0" ); 

 //iniciando os valores 

   printf("Escreva a frase: ");
      scanf("%99[^\n]", letter); // Le a linha inteira ate a quebra de linha
         getchar(); // Limpa o buffer de entrada

 read_last_string(letter, true, 0); // Passa a string para o metodo recursivo


 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_02 ( ) 
//---------------------


// iniciando o metodo auxiliar para method_03
//---------------------
void reverse_greater (char *letter, bool one_call, int *count) { 
   // condicao de somente uma chamada para o "io_id"
   if (one_call) {
     IO_id("reverse_greater - v 2 .0");
  }
  
      // Caso base
      if (*letter == '\0') {
      // como count tem que começar pelo final, sendo um ponteiro, seu valor vai conseguir 
      //percorrer a string sem perder seu valor 
        printf("Houveram [%d] letras menores que 'K'\n", *count);
        return;
    }
      // Chamada recursiva para o proximo caractere do final para o inicio 
      reverse_greater (letter + 1 , false, count); 

    // Verifica se a letra e minuscula
    if (*letter >= 'A' && *letter <= 'Z') {
        // Compara cada caractere com 'k'
        if (*letter > 'K') { // condicao de objetivo 
            (*count)++;
            printf("A letra [%c] e maior que 'K'\n", *letter);
        }
    } else { 
        printf("A letra [%c] nao e uma letra minuscula\n", *letter);
    }
  

  }
//---------------------


/** 
   Method_03 - 
 */ 
void method_03 ( void ) 
{ 
 // definir dado 
   
 char letter[100]; // Array para armazenar a string (tamanho máximo: 99 caracteres)

 // identificar 
 IO_id ( "Method_03 - v 1.0" ); 

 //iniciando os valores 

   printf("Escreva a frase: ");
      scanf("%99[^\n]", letter); // Le a linha inteira ate a quebra de linha
         getchar(); // Limpa o buffer de entrada

         reverse_greater(letter, true, 0); // Passa a string para o metodo recursivo
 

 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_03 ( ) 
 //---------------------


// iniciando o metodo auxiliar para method_04
//---------------------
void another_char (char *letter, bool one_call, int *count) {
   // condicao de somente uma chamada para o "io_id"
   if (one_call) {
      IO_id("anothers_char - v 5.0");
   }
   
// passo base
if (*letter == '\0') {
   printf("\nHouve [%d] letras.\n", *count);
   return;
}

// Verifica se e uma letra do alfabeto (maiuscula ou minuscula)
if ((*letter >= 'a' && *letter <= 'z') || (*letter >= 'A' && *letter <= 'Z')) {
   printf("O caracter [%c] faz parte do alfabeto.\n", *letter);
   (*count)++;
} else {
   printf("O caracter [%c] nao faz parte do alfabeto.\n", *letter);
}

// Chamada recursiva para o proximo caractere
another_char(letter + 1, false, count);
}


/** 
   Method_04 - 
 */ 
void method_04 ( void ) 
{ 
 // definir dado 
   
 char letter[100]; // Array para armazenar a string (tamanho máximo: 99 caracteres)
 int  count = 0; 
 // identificar 
 IO_id ( "Method_04 - v 1.0" ); 

 //iniciando os valores 

   printf("Escreva a frase: ");
      scanf("%99[^\n]", letter); // Le a linha inteira ate a quebra de linha
         getchar(); // Limpa o buffer de entrada

         another_char (letter, true, &count); // Passa a string para o metodo recursivo
 

 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_04 ( ) 
//---------------------


// iniciando o metodo auxiliar para method_05
//---------------------
void reverse_pair (char *letter, bool one_call, int *count, int *number) { 


   // condicao de somente uma chamada para o "io_id"
   if (one_call) {
     IO_id("reverse_pair - v 7.0");
  }
  
      // Caso base
      if (*letter == '\0') {
         // vai somar a quantidade de numeros pares e mostrar quantas vezes eles apareceram 
        printf("\nHouveram [%d] numeros pares.\n", *count);
        return;
    }
      // Chamada recursiva para o proximo caractere do final para o inicio 
      reverse_pair (letter + 1 , false, count, number); 
      // -> adicionando number, o valor sempre sera mandado de volta para a funcao

    // Verifica se a existencia de digitos 
    if (*letter >= '0' && *letter <= '9') {
         //realizar a conversao de char para inteiro 
         int value =  *letter - '0'; // -> uma das formar de conversao de char para int 

         // atualizando valor acumulado
          *number = (*number * 10) + value; // nao tem necessidade de number ser atualizado com um inteiro toda hora

        // Compara cada caractere com o resto da divisao por 2
        if (value  % 2 == 0) { // condicao de objetivo 
         printf("O numero [%c] e par \n", *letter);
         (*count)++;


        } else {
         printf("O numero [%c] nao e par \n", *letter);

        }

      } else {
         printf("O caracter [%c] nao faz parte do sistema numerico \n", *letter);
      }
      
}  
//---------------------


/** 
   Method_05 - 
 */ 
void method_05 ( void ) 
{ 
 // definir dados
   
 char letter[100]; // Array para armazenar a string (tamanho máximo: 99 caracteres)
 int  count    = 0; 
 int number    = 0;
 // identificar 
 IO_id ( "Method_05 - v 2.0" ); 

 //iniciando os valores 

   printf("Escreva a frase: ");
      scanf("%99[^\n]", letter); // Le a linha inteira ate a quebra de linha
         getchar(); // Limpa o buffer de entrada

         reverse_pair (letter, true, &count, &number); // Passa a string para o metodo recursivo
 

 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_05 ( ) 
//--------------------- 


// iniciando o metodo auxiliar para method_06
//---------------------
void betwen_numbers (char *letter, bool one_call, int *count, int *number) { 
   // condicao de somente uma chamada para o "io_id"
   if (one_call) {
     IO_id("betwen_numbers - v 2.0");
  }
  
      // Caso base
      if (*letter == '\0') { // corrigido para verificar o final da string corretamente
         // vai somar a quantidade de numeros pares e mostrar quantas vezes eles apareceram 
        printf("\nHouveram [%d] caracteres que nao sao impares.\n", *count);
        return;
      }

    // Verifica se a existencia de digitos 
    if (*letter >= '0' && *letter <= '9') {
         //realizar a conversao de char para inteiro 
         int value =  *letter - '0'; // -> uma das formar de conversao de char para int 

         // atualizando valor acumulado
          *number = (*number * 10) + value; // nao tem necessidade de number ser atualizado com um inteiro toda hora

        // Compara cada caractere com o resto da divisao por 2
        if (value  % 2 != 0) { // condicao de objetivo 
         printf("O numero [%c] e impar \n", *letter);

        } else {
         printf("O numero [%c] e par \n", *letter);
         (*count)++;

        }

      } else {
         printf("O caracter [%c] e uma letra ou caractere especial \n", *letter);
         (*count)++;

      }
       // Chamada recursiva para o proximo caractere do final para o inicio 
       betwen_numbers (letter + 1 , false, count, number); 
}
//---------------------


/** 
   Method_06 - 
 */ 
void method_06 ( void ) 
{ 
 // definir dados
   
 char letter[100]; // Array para armazenar a string (tamanho máximo: 99 caracteres)
 int  count     = 0; 
 int  number    = 0;
 // identificar 
 IO_id ( "Method_06 - v 2.0" ); 

 //iniciando os valores 

   printf("Escreva a frase: ");
      scanf("%99[^\n]", letter); // Le a linha inteira ate a quebra de linha
         getchar(); // Limpa o buffer de entrada

         betwen_numbers (letter, true, &count, &number); // Passa a string para o metodo recursivo
 

 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_06 ( ) 
//---------------------


// iniciando o metodo auxiliar para method_07
//---------------------
void betwen_mult_of_three (int *numbers, int first_interval    , int second_interval, int index, int size, int *count, bool one_call) { 
   // condicao de somente uma chamada para o "io_id"
   if (one_call) {
     IO_id("\nbetwen_mult_of_three - v 5.0\n");
  }
// index posicao atual a ser comparada
  if (index >= size ){ //-> quantidade total de nuemros
   return;
  }
  
  if (numbers[index] % 3 == 0  ){ // -> verificar se o numero multiplo de 3
   
   if (numbers[index] >= first_interval && 
      numbers[index] <= second_interval){ 
      printf("O numero [%d] e multiplo de 3 e faz parte do intervalo de [%d : %d] \n", numbers[index], first_interval, second_interval);
      (*count)++ ;
   
   } 
} else {
      printf("o numero [%d], nao faz e multiplo de 3\n", numbers[index]);
}

  betwen_mult_of_three (numbers, first_interval, second_interval, index + 1, size, count, false);
  // a funcao vai chamar numeros (meu array) o primeiro intervalo e o segundo
  // vai andar andar com a posicao dentro do array para ser comparado e quando chegar no passo base vai parar
}    
//---------------------


/** 
   Method_07 - 
 */ 
void method_07 ( void ) 
{ 
 // definir dados
int first_interval   = 0;
int second_interval  = 0;
int n_numbers        = 0;
int count            = 0;

 // identificar 
 IO_id ( "Method_07 - v 3.0" ); 

 //iniciando os valores 
    // Entrada dos valores do intervalo
    printf("Digite os valores dos intervalos: \n");
    scanf("%d %d", &first_interval, &second_interval);


    // Entrada do valor do array
    printf("Digite a quantidade de valores: \n");
    scanf("%d ",&n_numbers);

    int numbers[n_numbers];

        // Entrada dos valores do array
        printf("Digite os valores:\n");
        for (int i = 0; i < n_numbers; i++) {
            scanf("%d", &numbers[i]);
            getchar();
        }

   betwen_mult_of_three(numbers, first_interval, second_interval, 0, n_numbers, &count, true);


 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_07 ( ) 
//---------------------


// iniciando o metodo auxiliar para method_08
//---------------------
void btw_mult_of_three_not_four (int *numbers, int first_interval, int second_interval, int index, int size, int *count, bool one_call) { 
   // condicao de somente uma chamada para o "io_id"
   if (one_call) {
     IO_id("\nbetwen_mult_of_three - v 4.0\n");
  }

// index posicao atual a ser comparada
  if (index >= size ){ //-> quantidade total de nuemros
   return;
  }
  
// adicionando variaveis temporarias 
  int    current_number      =  numbers[index];
  bool   mult_of_three       =  numbers[index] % 3 == 0;
  bool   mult_of_four        =  numbers[index] % 4 == 0;
  bool   in_interval         = (current_number >= first_interval && current_number <= second_interval);


  if ( mult_of_three ){ // -> verificar se o numero multiplo de 3

   if (mult_of_four) {  // -> verificar se o numero e multiplo de 4
      printf("O numero [%d] e multiplo de 3 e de 4 (NAO conta). \n", numbers[index]);

   } else if (in_interval){
      printf("O numero [%d] e multiplo de 3 e faz parte do intervalo de [%d : %d] \n", numbers[index], first_interval, second_interval);
      (*count)++ ;
   } else {
      printf("O numero [%d] nao e multiplo de 3 (NAO conta). \n", numbers[index]);
   }
}
btw_mult_of_three_not_four (numbers, first_interval, second_interval, index + 1, size, count, false);
  // a funcao vai chamar numeros (meu array) o primeiro intervalo e o segundo
  // vai andar andar com a posicao dentro do array para ser comparado e quando chegar no passo base vai parar
} 
//---------------------


/** 
   Method_08 - 
 */ 
void method_08 ( void ) 
{ 
 // definir dados
int first_interval   = 0;
int second_interval  = 0;
int n_numbers        = 0;
int count            = 0;

 // identificar 
 IO_id ( "Method_08 - v 1.0" ); 

 //iniciando os valores 
    // Entrada dos valores do intervalo
    printf("Digite os valores dos intervalos: \n");
    scanf("%d %d", &first_interval, &second_interval);


    // Entrada do valor do array
    printf("Digite a quantidade de valores: \n");
    scanf("%d ",&n_numbers);

   // iniciando valores do meu array
    int numbers[n_numbers];

        // Entrada dos valores do array
        printf("Digite os valores:\n");
        for (int i = 0; i < n_numbers; i++) {
            scanf("%d", &numbers[i]); //-> declarando os valores do meu array 
            getchar();
        }

   btw_mult_of_three_not_four(numbers, first_interval, second_interval, 0, n_numbers, &count, true);


 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_08 ( ) 
//---------------------


// iniciando o metodo auxiliar para method_09
//---------------------
void count_int_pair_less_than_five (double *numbers, double first_interval, double second_interval, int index, double size, int *count, bool one_call) { 
   // condicao de somente uma chamada para o "io_id"
   if (one_call) {
     IO_id("\nount_int_pair_less_than_five - v 4.0\n");
  }
// index posicao atual a ser comparada
  if (index >= size ){ //-> quantidade total de nuemros
   return;
  }
  
// adicionando variaveis temporarias 
double current_number  =    numbers[index];
int    int_part        =   (int)current_number; //  transforma o valor double para int (isolando o valor)
bool   in_interval     =   (current_number > first_interval && current_number < second_interval);
bool   is_even         =   (int_part % 2 == 0); // -> verifica se o valor e divisivel por 2 (par)
bool   less_than_five  =   (int_part < 5);      // -> verifica se o valor e menor que 5

if (in_interval && is_even && less_than_five) {
   printf("Valor %.2lf com parte inteira %d esta no intervalo e atende aos criterios.\n", current_number, int_part);
   (*count)++;
} else {
   printf("Valor %.2lf com parte inteira %d nao atende aos criterios.\n", current_number, int_part);

}

count_int_pair_less_than_five(numbers, first_interval, second_interval, index + 1, size, count, false);
}
//---------------------


/** 
   Method_09 - 
 */ 
void method_09(void) 
{ 
    // Definir dados
 // definir dados
 bool repeat              = true;
 int n_numbers            = 0;
 double first_interval    = 0;
 double second_interval   = 0;
 int count                = 0;
    // Identificar 
    IO_id("Method_09 - v 5.0"); 

    // Iniciando loop para checagem do valor
    do { 
        printf("Digite os valores dos intervalos (a b): ");
        scanf("%lf %lf", &first_interval, &second_interval);
        getchar();

        if (first_interval < second_interval) {
            printf("Valor aceito: [%.2lf : %.2lf]\n", first_interval, second_interval);
            repeat = false; // Sai do loop validando os valores
        } else {
            printf("ERRO: O primeiro valor deve ser menor que o segundo.\n");
        }
    } while (repeat);
   
    // Perguntar se deseja continuar
    repeat = true;
    do {
        char response = ' ';
        printf("Deseja continuar? (S/N): ");
        scanf(" %c", &response); 
        getchar(); 

        if (response == 'N' || response == 'n') {
            return; // Encerrando 
        } 

        if (response == 'S' || response == 's') {
            repeat = false; // Continua o programa
        } else {
            printf("Resposta invalida. Digite 'S' para continuar ou 'N' para sair.\n");
        }
    } while (repeat);

    // Entrada do valor do array
    printf("Digite a quantidade de valores: \n");
    scanf("%d", &n_numbers); 
    getchar();

    // Alocar memoria dinamicamente para o array
    double *numbers = (double *)malloc(n_numbers * sizeof(double));
    if (numbers == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    // Entrada dos valores do array
    printf("Digite os valores:\n");
    for (int i = 0; i < n_numbers; i++) {
        scanf("%lf", &numbers[i]);
        getchar();
    }

    // Chamada do metodo 
    count_int_pair_less_than_five(numbers, first_interval, second_interval, 0, n_numbers, &count, true);

    // Encerrar
    free(numbers); // Liberar a memoria alocada
    IO_pause("Apertar ENTER para continuar"); 
} // end method_09
//---------------------


// implementacao de uma funcao ja existene chamada floor para pegar o numero e 
double My_floor (int value ) {
   // caso o numero foi ja for inteiro
   if ((int) value == value ) {
      return value;
   }
   // caso ele for maior que 0
   if(value > 0){
      return (int)value; // -> retornar o valor inteiro 
   }

   return (int) value - 1; // caso for negativo, arredonda para o menor inteiro
}


// Método recursivo para contar partes fracionárias dentro do intervalo aberto
void count_fractional_in_range(double *numbers, double first_interval, double second_interval, int index, int size, int *count, bool one_call) {
    if (one_call) {
        IO_id("\ncount_fractional_in_range - v 4.0\n");
    }

    if (index < size) { // Passo base
        double fractional = numbers[index] - My_floor(numbers[index]); // Parte fracionaria

        if (fractional > first_interval && fractional < second_interval) { // -> ver se esta dentro do intervalo aberto 
            printf("%.2lf tem parte fracionaria %.2lf dentro do intervalo ]%.2lf : %.2lf[\n",numbers[index], fractional, first_interval, second_interval);
            (*count)++;

        } else {
            printf("[%.2lf] nao contem parte fracionaria [%.2lf] dentro do intervalo ]%.2lf : %.2lf[\n",
                   numbers[index], fractional, first_interval, second_interval);
        }
        // Chamada recursiva correta
        count_fractional_in_range(numbers, first_interval, second_interval, index + 1, size, count, false);
    }
}


/** 
   Method_10 - 
 */ 
void method_10(void) 
{ 
    // Definir dados
 // definir dados
 bool repeat              = true;
 int n_numbers            = 0;
 double first_interval    = 0;
 double second_interval   = 0;
 int count                = 0;
    // Identificar 
    IO_id("Method_10 - v 0.0"); 


    // adicionando  
    do {
        printf("Digite dois valores reais (a b) maiores que 0 e menores que 1: ");
        scanf("%lf %lf", &first_interval, &second_interval);
        getchar();

        if (first_interval > 0 && first_interval < 1 
         && second_interval > 0 && second_interval < 1 
         && first_interval < second_interval) {
            printf("Intervalo aceito: ]%.2lf : %.2lf[\n", first_interval, second_interval);
        } else {
            printf("ERRO: Os valores devem ser maiores que 0, menores que 1 e a < b.\n");
        }
    } while (!(first_interval > 0 && first_interval < 1 
      && second_interval > 0 && second_interval < 1 
      && first_interval < second_interval)); // -> ate nao ser igual 

    // Get number of values
    printf("Digite a quantidade de valores a serem testados: ");
    scanf("%d", &n_numbers);
    getchar();

    // fazendo alocao de memoria para *numbers(array)
    double *numbers = (double *)malloc(n_numbers * sizeof(double));
    if (numbers == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    // dicionando os valores para dentro do array
    printf("Digite os valores reais:\n");
    for (int i = 0; i < n_numbers; i++) {
        scanf("%lf", &numbers[i]);
        getchar();
    }

    // chamada da recursao 
    count_fractional_in_range(numbers, first_interval, second_interval, 0, n_numbers, &count, repeat);
    printf("Total de valores com partes fracionarias no intervalo: %d\n", count);

    // Encerrar
    free(numbers); // Liberar a memoria alocada
    IO_pause("Apertar ENTER para continuar"); 
} // end method_10
//---------------------


bool My_insalum ( char * string ){
   char try = *string; // Pega o caractere apontado pelo ponteiro

   bool comparation_a   =  (try >= 'a' && try <= 'z');
   bool compaeration_A  =  (try >= 'A' && try <= 'Z');
   bool compation_Num   =  (try >= '0' && try <= '9');

   if  ( compaeration_A ||
         comparation_a  || 
         compation_Num){
      //printf("O caracter [%c] e um alfanumerico. \n", *string);
      return true;
   } else {
      //printf("O caracter [%c] nao e alfanumerico. \n", *string );
      return true;
   }
}


/** 
   Method_11 - 
*/ 
void method_11 ( void ) 
{ 
 // definir dados
   
 char letter[100]; // Array para armazenar a string (tamanho máximo: 99 caracteres)
 char non_alphanumeric [100];
 int j = 0; // indicie da nova string 
 // identificar 
 IO_id ( "Method_11 - v 3.0" );

 //iniciando os valores 

   printf("Escreva uma frase: ");
      fgets(letter, 100, stdin);
         getchar(); // Limpa o buffer de entrada

   letter[strcspn(letter,"\n") ] = '\0';

   for(int i = 0;  letter [i] != '\0'; i++){
      if(!My_insalum(&letter[i])){ // -> lembrar de colocar o & na hora de mandar o ponteiro 
         non_alphanumeric[j++] = letter[i]; // caso a condicao seja falsa, os nao alfanumericos vao receberem a posicao do caractere de letter
      }
   
   non_alphanumeric [j] = '\0'; 

   }


 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
   // end method_11 ( ) 

}
//--------------------- 

/** 
   Method_12 - 
*/ 
void method_12 ( void ) 
{ 
 // definir dados
   
 char letter[100]; // Array para armazenar a string (tamanho máximo: 99 caracteres)
 char non_alphanumeric [100];
 int i = 0;
 bool only_non_alphanumeric = true; // Assume que só há não-alfanuméricos

 // identificar 
 IO_id ( "Method_12 - v 3.0" );

 //iniciando os valores 

   printf("Escreva uma frase: ");
      fgets(letter, 100, stdin);
         getchar(); // Limpa o buffer de entrada

   letter[strcspn(letter,"\n") ] = '\0'; // vai tirar o \n assim, vai ler os espacos em branco (ideia proposta pelo professor)

 while ( letter[i] !=  '\0' )
 {
   // vai ver se o valor e igual a cada passagem se um for 0 (false) vai trocar retornar como 0 o valor de only_non_alphanumeric
   only_non_alphanumeric = only_non_alphanumeric && !My_insalum(&letter[i]); // esqueci de passar mais uma vez o endereco 
   i = i + 1; 
 }
 
   


   if (non_alphanumeric == letter){
      printf("na string so contem simbolos alfanumericos. \n");
   } else {
      printf("na string contem ao menos um simbolos alfanumericos. \n");
   }


 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
   // end method_12 ( ) 

}
//--------------------- 

//------------------------------------------
/* 
  Funcao principal. 
  @return codigo de encerramento 
*/ 
int main ( ) 
{ 
 // definir dado 
    int x = 0; 
 
 // repetir até desejar parar 
    do 
    { 
     // identificar 
        IO_id ( "EXEMPLO0300 - Programa - v0.0" ); 
 
     // ler do teclado 
        IO_println ( "Opcoes"  ); 
        IO_println ( "0 - parar" ); 
        IO_println ( " 1 - letras maiusculas maiores que 'K. " );
        IO_println ( " 2 - letras minusculas menores que 'k.'" ); 
        IO_println ( " 3 - letars miusculas maiores que 'K', do fim para o inicio da palavra. ");
        IO_println ( " 4 - contar e mostrar todos simbolos que forem letras. ");
        IO_println ( " 5 - contar e mostrar todos os digitos pares, percorrendo do fim ao inicio. ");
        IO_println ( " 6 - contar e mostrar tudo o que nao for digito impar e tambem nao for letra. ");
        IO_println ( " 7 - contar e mostrar quantos dentre esses valores lidos (x) os que forem multiplos de 3, e pertençam ao intervalo [a:b]. ");
        IO_println ( " 8 - contar e mostrar quantos dentre esses valores lidos (x) os que forem multiplos de 3 menos multiplos de 4, e pertençam ao intervalo [a:b]. ");
        IO_println ( " 9 - contar e mostrar todos os valores lidos, pertencentes ao do intervalo, cujas partes inteiras forem pares e menores que 5.  ");
        IO_println ( "10 - contar e mostrar todos os valores lidos que tenham suas partes fracionarias dentro do intervalo ]a:b[.  ");
        IO_println ( "11 - separar em outra cadeia de caracteres e mostrar todos os simbolos nao alfanumericos (letras ou digitos) na cadeia de caracteres.  ");
        IO_println ( "12 - dizer se a sequencia contem apenas símbolos que NAO sao digitos ou letras.  ");



        IO_println ( "" ); 
 
        x = IO_readint ( "Entrar com uma opcao: " ); 
 
     // testar valor 
        switch ( x ) 
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
            IO_pause ( IO_concat ( "Valor diferente das opcoes [0 a 12] (", 
                                IO_concat ( IO_toString_d ( x ), ")" ) ) ); 
        } // end switch 
    } 
    while ( x != 0 ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para terminar" ); 
    return ( 0 ); 
} // end main ( )
 
 
 
 
