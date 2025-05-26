/* 
   Exemplo1100 - v0.0. - __ / __ / _____ 
   Author: ________________________ 
 
 */ 
// dependencias 
#include <iostream>  // std::cin, std::cout, std:endl 
#include <limits>   // std::numeric_limits 
#include <string>  // para cadeias de caracteres 
 
// ----------------------------------------------- definicoes globais 
 
void pause ( std::string text ) //P_00
{ 
    std::string dummy; 
    std::cin.clear ( ); 
    std::cout << std::endl << text; 
    std::cin.ignore( ); 
    std::getline(std::cin, dummy); 
    std::cout << std::endl << std::endl; 
} // end pause ( ) 
 
 
// ----------------------------------------------- classes / pacotes 
 
#include "myarray.hpp" 
 
using namespace std; 
 
// ----------------------------------------------- metodos 


//---------------------
/** 
   Method_00 - nao faz nada. 
 */ 
void method_00 ( ) 
{ 
 // nao faz nada 
} // end method_00 ( ) 
//---------------------


//--------------------- 
/** 
   Method_01 - Mostrar certa quantidade de valores. 
 */ 
void method_01 ( ) 
{ 
 // definir dados 
   // chamado do contrutor
    Array < int > array_1; 

    int N      = 0;
    int lower  = 0;
    int upper  = 0; 
    int answer = 0;

    //decalrando valores para a variavel
      std:: cout << "Digite o valor de N" << endl; 
      std:: cin >> N;  std:: cin.get ();

      //decalrando valores para a variavel
      
    std::cout << "Digite o valor inferior do intervalo: ";
    std::cin >> lower; std:: cin.get ();

    std::cout << "Digite o valor superior do intervalo: ";
    std::cin >> upper; std:: cin.get ();


   // identificar 
      cout << "\nMethod_01 - v1.0\n" << endl; 

    if ( upper >=  lower ) {  

    //chamada da funcao principal 
      array_1.randomIntGenerate ( N, upper, lower ); 

    // mostrar dados 
      array_1.print ( ); 
    
    // reciclar espaco 
      array_1.free ( );  


        } else {
            cout << "Erro: o valor do intervalo esta errado. " << endl;

        }

// encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_01 ( ) 
//--------------------- 


//---------------------
/** 
   Method_02. 
 */ 
void method_02 ( ) 
{ 
   // definir dados
      Array <int> array_1;
      string fileName;

      cout << "\nMethod_02 - Procurar o maior ímpar\n" << endl;

   // entrada do usuário
      cout << "Digite o nome do arquivo: ";
      cin >> fileName; std::cin.get ( ); 

   // ler arranjo do arquivo
      array_1.readreadArrayFromFile ( fileName ) ;

   // verificar se dados foram lidos
      if ( array_1.getLength() > 0 ) { // -> caso o tamanho seja maior que 0 
     
   // mostrar os dados
      array_1.print();

   // procurar o maior impar
      int maior = array_1.searchFirstOdd();
      cout << "Maior valor impar encontrado: " << maior << endl;

   // reciclar a memoria
      array_1.free();
    }
   // encerrar 
      pause ( "Apertar ENTER para continuar" ); 
} // end method_02 ( ) 
//---------------------


//---------------------
/** 
   Method_03. 
 */ 
void method_03 ( ) 
{ 
   // definir dados
      Array <int> array_1;
      string fileName;
      
      cout << "\nMethod_03 - somar um intervalo no arranjo\n" << endl;

   // entrada do usuário
      cout << "Digite o nome do arquivo: ";
      cin >> fileName; std::cin.get ( ); 

   // ler arranjo do arquivo
      array_1.readreadArrayFromFile ( fileName ) ;

   // verificar se dados foram lidos
      if ( array_1.getLength() > 0 ) { // -> caso o tamanho seja maior que 0 
     
   // mostrar os dados
      array_1.print();

   // procurar o maior impar
      int target = array_1.searchFirstOddx3 (  );
         cout <<"O maior valor impar multiplo de 3 e :"<< target << endl;

   // reciclar a memoria
      array_1.free();
    }
   // encerrar 
      pause ( "Apertar ENTER para continuar" ); 
} // end method_03 ( )
//---------------------


//--------------------- 
/** 
   Method_04. 
 */ 
void method_04 ( ) 
{ 
   // definir dados
      Array <int> array_1;
      string fileName;

      int first   = 0; 
      int second  = 0;
      
      cout << "\nMethod_03 - somar um intervalo no arranjo\n" << endl;

   // entrada do usuário
      cout << "Digite o nome do arquivo: ";
      cin >> fileName; std::cin.get ( ); 

      std::cout << "Digite o primeiro valor do intervalo: ";
      std::cin >> first; std:: cin.get ();

      std::cout << "Digite o segundo valor do intervalo: ";
      std::cin >> second; std:: cin.get ();


   // ler arranjo do arquivo
      array_1.readreadArrayFromFile ( fileName ) ;

   // verificar se dados foram lidos
      if ( array_1.getLength() > 0 ) { // -> caso o tamanho seja maior que 0 
     
   // mostrar os dados
      array_1.print();

   // procurar o maior impar
      int value = array_1.addInterval( first, second );
            cout << "A soma no intervalo [" << first 
                 << ", " << second << "] e: " 
                 << value << endl;

   // reciclar a memoria
      array_1.free();
    }
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_04 ( ) 
//---------------------


//---------------------
/** 
   Method_05. 
 */ 
void method_05 ( ) 
{ 
   // definir dados
      Array <int> array_1;
      string fileName;

      int first   = 0; 
      int second  = 0;
      
      cout << "\nMethod_03 - somar um intervalo no arranjo\n" << endl;

   // entrada do usuário
      cout << "Digite o nome do arquivo: ";
      cin >> fileName; std::cin.get ( ); 

      std::cout << "Digite o primeiro valor do intervalo: ";
      std::cin >> first; std:: cin.get ();

      std::cout << "Digite o segundo valor do intervalo: ";
      std::cin >> second; std:: cin.get ();


   // ler arranjo do arquivo
      array_1.readreadArrayFromFile ( fileName ) ;

   // verificar se dados foram lidos
      if ( array_1.getLength() > 0 ) { // -> caso o tamanho seja maior que 0 
     
   // mostrar os dados
      array_1.print();

   // recebe os valores da fubcao averageInterval
      int value = array_1.averageInterval( first, second );
            cout << "A media  intervalo [" << first 
                 << ", " << second << "] e: " 
                 << value << endl;

   // reciclar a memoria
      array_1.free();
    }
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_05 ( ) 
//---------------------


//---------------------

/** 
   Method_06. 
 */ 
void method_06 ( ) 
{ 
// definir dados
      Array <int> array_1;
      string fileName;
      
      cout << "\nMethod_06 - verifica se o arranjo so contem valores positivos e maiores que 100\n" << endl;

   // entrada do usuário
      cout << "Digite o nome do arquivo: ";
      cin >> fileName; std::cin.get ( ); 

   // ler arranjo do arquivo
      array_1.readreadArrayFromFile ( fileName ) ;

   // verificar se dados foram lidos
      if ( array_1.getLength() > 0 ) { // -> caso o tamanho seja maior que 0 
     
   // mostrar os dados
      array_1.print();

   // procurar o maior impar
      bool target = array_1.negatives (  );
   // condicao de verdade 
      if ( target ) { // caso target retorne como verdade
         std:: cout << "O arranjo contem valores positivos e maiores que 100 " <<endl; 

      } else {       // caso contrario 
         std:: cout << "O arranjo contem valores negativos e/ou menores que 100 " <<endl; 

      }
   // reciclar a memoria
      array_1.free();
    }
   // encerrar 
      pause ( "Apertar ENTER para continuar" ); 
} // end method_06 ( )
//---------------------


//---------------------
/** 
   Method_07. 
 */ 
void method_07 ( ) 
{ 
// definir dados
      Array <int> array_1;
      string fileName;
      
      cout << "\nMethod_06 - verifica se o arranjo esta ordenado ou nao ( de formar decresente )\n" << endl;

   // entrada do usuário
      cout << "Digite o nome do arquivo: ";
      cin >> fileName; std::cin.get ( ); 

   // ler arranjo do arquivo
      array_1.readreadArrayFromFile ( fileName ) ;

   // verificar se dados foram lidos
      if ( array_1.getLength() > 0 ) { // -> caso o tamanho seja maior que 0 
     
   // mostrar os dados
      array_1.print();

   // procurar o maior impar
      bool target = array_1.isDecrescent (  );
   // condicao de verdade 
      if ( target ) { // caso target retorne como verdade
         std:: cout << "O arranjo esta ordenado de forma decresente" <<endl; 

      } else {       // caso contrario 
         std:: cout << "O arranjo esta desordenado" <<endl; 

      }
   // reciclar a memoria
      array_1.free();
    }
   // encerrar 
      pause ( "Apertar ENTER para continuar" ); 
} // end method_07 ( ) 
//---------------------


//---------------------
/** 
   Method_08. 
 */ 
void method_08 ( ) 
{ 
   // definir dados
      Array <int> array_1  ;

      string fileName;

      int first   = 0; 
      int second  = 0;
      int target  = 0;
      
      cout << "\nMethod_08 - verificar se o um determinado valor esta no em um intervalo\n" << endl;

   // entrada do usuário
      cout << "Digite o nome do arquivo: ";
      cin >> fileName; std::cin.get ( ); 


      std::cout << "Digite o valor que procura: "<<endl;
      std::cin >> target; std:: cin.get ();

      std::cout << "Digite o primeiro valor do intervalo: ";
      std::cin >> first; std:: cin.get ();

      std::cout << "Digite o segundo valor do intervalo: ";
      std::cin >> second; std:: cin.get ();


   // ler arranjo do arquivo
      array_1.readreadArrayFromFile ( fileName ) ;


   // verificar se dados foram lidos
      if ( array_1.getLength() > 0 ) { // -> caso o tamanho seja maior que 0 
     
   // mostrar os dados
      array_1.print();

    // Verificar presença no intervalo
        if (array_1.searchInterval (target, first, second)) {
            std::cout << "Valor " << target << " encontrado no intervalo [" << first << ", " << second << "]." << std::endl;
        } else {
            std::cout << "Valor " << target << " NAO encontrado no intervalo." << std::endl;
        }
      }
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )
//---------------------


//---------------------
/** 
   Method_09. 
 */ 
void method_09() {
    Array<int> array_1;
    Array<int> novo;

    std::string fileName = "DADOS.TXT";
    int constante = 0, inicio = 0, fim = 0;

    std::cout << "\nMethod_09 - Escalar dados no intervalo do arranjo\n" << std::endl;

    // Entrada do usuário
    std::cout << "Digite a constante para multiplicar: ";
    std::cin >> constante; std::cin.get();

    std::cout << "Digite a posicao inicial: ";
    std::cin >> inicio; std::cin.get();

    std::cout << "Digite a posicao final: ";
    std::cin >> fim; std::cin.get();

    // Ler do arquivo
    array_1.readreadArrayFromFile(fileName);

    if (array_1.getLength() > 0) {
        std::cout << "\nArranjo original:\n";
        array_1.print();

        // Aplicar escalonamento
        novo = array_1.scalar(constante, inicio, fim);

        std::cout << "\nArranjo escalado:\n";
        novo.print();

        // Liberar memória
        array_1.free();
        novo.free();
    }

    pause("Apertar ENTER para continuar");
}

//---------------------



//--------------------- 
/** 
   Method_10. 
 */ 
void method_10() {
    
   Array<int> array;
    std::string fileName;

    std::cout << "\nMethod_10 - Ordenar arranjo em ordem decrescente\n" << std::endl;

    // entrada do usuário
      cout << "Digite o nome do arquivo: ";
      cin >> fileName; std::cin.get ( ); 

    // Ler do arquivo
    array.readreadArrayFromFile(fileName);

    if (array.getLength() > 0) {
        std::cout << "\nArranjo original:\n";
        array.print();

        // Ordenar em ordem decrescente
        array.sortDown();

        std::cout << "\nArranjo ordenado em ordem decrescente:\n";
        array.print();

        // Liberar memória
        array.free();
    }

    pause("Apertar ENTER para continuar");
} // end method_10 ( )
//---------------------



//--------------------- 
/** 
   Method_11. 
 */ 
void method_11() {
      
   // definir dados
   Array<int> array1, array2;
   std::string file1, file2;

   std::cout << "Digite o nome do primeiro arquivo: ";
   std::cin >> file1; std::cin.get();

   std::cout << "Digite o nome do segundo arquivo: ";
   std::cin >> file2; std::cin.get();

   // ler os arranjos dos arquivos
   array1.readreadArrayFromFile ( file1 );
   array2.readreadArrayFromFile ( file2 );

   // verificar se são diferentes
   if (array1.isDifferent(array2)) {
      std::cout << "Os arranjos sao diferentes em pelo menos uma posicao." << std::endl;
   } else {
      std::cout << "Os arranjos sao iguais em todas as posicao." << std::endl;
   }

    pause("Apertar ENTER para continuar");
} // end method_11 ( )
//---------------------


//--------------------- 
/** 
   Method_12. 
 */ 
void method_12() {
   
   Array<int> array1, array2, diff;
   std::string file1, file2;

   std::cout << "Digite o nome do primeiro arquivo: ";
   std::cin >> file1; std::cin.get();

   std::cout << "Digite o nome do segundo arquivo: ";
   std::cin >> file2; std::cin.get();

   // Ler arranjos dos arquivos
   array1.readreadArrayFromFile(file1);
   array2.readreadArrayFromFile(file2);

   // Calcular diferenças
   diff = array1.differences(array2);

   // Mostrar resultado, se aplicável
   if (diff.getLength() > 0) {
      std::cout << "Diferencas entre os arranjos (posicao por posicao):" << std::endl;
      diff.print();
   }

    pause("Apertar ENTER para continuar");
} // end method_12 ( )'
//---------------------


// ----------------------------------------------- acao principal ----------------------------------------------- \\
 
/* 
  Funcao principal. 
  @return codigo de encerramento 
*/ 
int main ( int argc, char** argv ) 
{ 
 // definir dado 
    int x = 0;   // definir variavel com valor inicial 
 
 // repetir até desejar parar 
    do 
    { 
     // identificar 
        cout << "EXEMPLO1101 - Programa - v0.0\n    " << endl; 
 
     // mostrar opcoes 
        cout << "Opcoes        " << endl; 
        cout << " 0 - parar       " << endl; 
        cout << " 1 - gerar valores aleatorios dentro de um intervalo  " << endl; 
        cout << " 2 - le os dados de um arquivo e verificar o maior impar " << endl; 
        cout << " 3 - cria um arquivo TXT de um arranjo  " << endl; 
        cout << " 4 -  " << endl; 
        cout << " 5 -        " << endl; 
        cout << " 6 -        " << endl; 
        cout << " 7 -        " << endl; 
        cout << " 8 -        " << endl; 
        cout << " 9 -        " << endl; 
        cout << "10 -        " << endl;
        cout << "11 -        " << endl; 
        cout << "12 -        " << endl; 

 
     // ler do teclado 
        cout << endl << "Entrar com uma opcao: "; 
        cin  >> x; 
 
 
     // escolher acao 
        switch ( x ) 
        { 
          case 0:   method_00 ( );   break; 
          case 1:   method_01 ( );   break; 
          case 2:   method_02 ( );   break; 
          case 3:   method_03 ( );   break; 
          case 4:   method_04 ( );   break; 
          case 5:   method_05 ( );   break; 
          case 6:   method_06 ( );   break; 
          case 7:   method_07 ( );   break; 
          case 8:   method_08 ( );   break; 
          case 9:   method_09 ( );   break; 
          case 10: method_10  ( );   break; 
          case 11: method_11  ( );   break; 
          case 12: method_12  ( );   break; 

          default: 
            cout << endl << "ERRO: Valor invalido." << endl; 
        } // end switch 
    } 
    while ( x != 0 ); 
 
 // encerrar 
    pause  ( "Apertar ENTER para terminar" ); 
    return ( 0 ); 
} // end main ( ) 