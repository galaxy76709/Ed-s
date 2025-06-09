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
 
#include "mymatrix.hpp" 
 
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
   Method_01 -gera valores aleatorios e printa eles em um arquivo 
 */ 
void method_01 ( ) 
{ 
 // definindo variaveis aux
 int rows     = 0; // -> M
 int columns  = 0; // -> N
 int upper    = 0;
 int lower    = 0;


 // definir dados 

    std::cout << "\ndigite o valor das linhas: " << endl;
    std::cin >> rows; std:: cin.get ();

    
    std::cout << "\ndigite o valor das colunas: " << endl;
    std::cin >> columns; std:: cin.get ();

    Matrix <int> int_matrix ( rows, columns, 0 ); 
 
 // identificar 
    cout << "\nMethod_01 - v1.0\n" << endl; 


// acoes 
    int_matrix.randomIntGenerate ( 1 , 100 ); 
    int_matrix.saveFlatToFile    ("DADOS1.TXT");

 
 // mostrar dados 
    int_matrix.print ( ); 
 
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
 
    std::string fileName;
    int N_const;

    std::cout << "\nDigite o nome do arquivo: ";
    std::cin >> fileName;

    std::cout << "\nDigite a constante para multiplicação: ";
    std::cin >> N_const;

    Matrix<int> matrix    = Matrix<int>::readMatrixFromFile  (fileName);
    Matrix<int> matrix_02 = matrix.scalar               ( N_const);

    std::cout << "\nMatriz original:\n";
    matrix.print();

    std::cout << "\nMatriz escalada:\n";
    matrix_02.print();


    // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_02 ( )
//---------------------


//---------------------
void method_03 ( ) 
{ 
    // Identificar 
    std::cout << std::endl << "Method_03 - v0.0" << std::endl; 
 
    std::string fileName;
    Matrix<int> matrix1; // Matriz que será lida do arquivo.

    std::cout << "Digite o nome do arquivo com a matriz: ";


    std::getline(std::cin >> std::ws, fileName); 

    if (matrix1.getRows() > 0 && matrix1.getColumns() > 0) {

        std::cout << "Matriz lida do arquivo '" << fileName << "':" << std::endl;

        matrix1.print(); // Exibe a matriz que foi lida.

  
        bool teste = matrix1.identidade( ); 

        if ( teste ) {
            std::cout << "A matriz E uma matriz identidade. " << std::endl;
        } else {
            std::cout << "A matriz NAO E uma matriz identidade. " << std::endl;
        }
    } else {
        std::cout << "Erro: Nao foi possivel ler uma matriz valida do arquivo '" << fileName 
                  << "'." << std::endl;
    }

    // Encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_03 ( ) 



//---------------------
/** 
   Method_04. 
 */ 
void method_04 ( ) 
{ 
 // definir dados 
    Matrix <int> matrix ( 1, 1, 0 ); 
 
 // identificar 
    cout <<  endl << "Method_04 - v0.0" << endl; 
 
  string filename1, filename2;

    cout << "Digite o nome do primeiro arquivo: ";
    getline(cin, filename1);

    cout << "Digite o nome do segundo arquivo: ";
    getline(cin, filename2);

    Matrix<int> matrix1;
    Matrix<int> matrix2;

    matrix1.readMatrixFromFile(filename1);
    matrix2.readMatrixFromFile(filename2);

    if (matrix1 == matrix2) {
        cout << "As matrizes SAO iguais." << endl;
    } else {
        cout << "As matrizes NAO são iguais." << endl;
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
 // identificar 
    cout << endl << "Method_05 - v0.0" << endl; 
 
  string filename1, filename2;

    cout << "Digite o nome do primeiro arquivo: ";
    getline(cin, filename1);

    cout << "Digite o nome do segundo arquivo: ";
    getline(cin, filename2);

    Matrix<int> matrix1;
    Matrix<int> matrix2;

    matrix1.readMatrixFromFile(filename1);
    matrix2.readMatrixFromFile(filename2);

    Matrix<int> soma = matrix1.add(matrix2);

    cout << "Resultado da soma das matrizes:" << endl;
    soma.print(); // ou soma.printMatrix() dependendo da sua classe

 
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

 // identificar 
    cout << endl << "Method_06 - v0.0" << endl; 
 
    string filename;
    cout << "Digite o nome do arquivo com a matriz: ";
    getline(cin, filename);

    Matrix<int> matrix1;
    matrix1.readMatrixFromFile(filename);

    int linha1    = 0;
    int linha2    = 0;
    int constante = 0;

    cout << "Digite o indice da linha a ser modificada (ex: 0): ";
    cin >> linha1;

    cout << "Digite o indice da linha usada como base (ex: 1): ";
    cin >> linha2;

    cout << "Digite a constante multiplicadora: ";
    cin >> constante;
    cin.ignore(); // para limpar o buffer do ENTER

    matrix1.addRows(linha1, linha2, constante);

    cout << "Matriz resultante apos a operacao:" << endl;
    matrix1.print();

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

   string filename;
    cout << "Digite o nome do arquivo com a matriz: ";
    getline(cin, filename);

    Matrix<int> matrix1;
    matrix1.readMatrixFromFile(filename);

    int linha1    = 0 ;
    int linha2    = 0 ;
    int constante = 0 ;

     // identificar 
    cout << endl << "Method_07 - v0.0" << endl; 
 
    cout << "Digite o indice da linha a ser modificada (ex: 0): ";
    cin >> linha1;

    cout << "Digite o indice da linha usada como base (ex: 1): ";
    cin >> linha2;

    cout << "Digite a constante multiplicadora: ";
    cin >> constante;
    cin.ignore(); // limpa o ENTER pendente

    matrix1.addRows(linha1, linha2, constante);

    cout << "Matriz resultante apos a operacao:" << endl;
    matrix1.print();

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

 // identificar 
    cout << endl << "Method_08 - v0.0" << endl; 
 
    string filename;
    cout << "Digite o nome do arquivo com a matriz: ";
    getline(cin, filename);

    Matrix<int> matrix1;
    matrix1.readMatrixFromFile(filename);

    int procurado = 0 ;
    cout << "Digite o valor a ser procurado na matriz: ";
    cin >> procurado;
    cin.ignore(); // limpa o ENTER

    int linhaEncontrada = matrix1.searchRows(procurado);

    if (linhaEncontrada != -1) {
        cout << "O valor foi encontrado na linha: " << linhaEncontrada << endl;
    } else {
        cout << "O valor NAO foi encontrado na matriz." << endl;
    }
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_08 ( )
//---------------------


//---------------------
/** 
   Method_09. 
 */ 
void method_09 ( ) 
{ 
   
 // identificar 
    cout << endl << "Method_09 - v0.0" << endl; 

    string filename;
    cout << "Digite o nome do arquivo com a matriz: ";
    getline(cin, filename);

    Matrix<int> matrix1;
    matrix1.readMatrixFromFile(filename);

    int procurado = 0 ;
    cout << "Digite o valor a ser procurado na matriz: ";
    cin >> procurado;
    cin.ignore(); // limpa o ENTER

    int colunaEncontrada = matrix1.searchColumns(procurado);

    if (colunaEncontrada != -1) {
        cout << "O valor foi encontrado na coluna: " << colunaEncontrada << endl;
    } else {
        cout << "O valor NAO foi encontrado na matriz." << endl;
    }


 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_09 ( )
//---------------------


//---------------------
/** 
   Method_10. 
 */ 
void method_10 ( ) 
{ 
    cout << endl << "Method_10 - v0.0" << endl; 


   string filename;
    cout << "Digite o nome do arquivo com a matriz: ";
    getline(cin, filename);

    Matrix<int> matrix1;
    matrix1.readMatrixFromFile(filename);

    cout << "Matriz original:" << endl;
    matrix1.print();

    matrix1.transpose();

    cout << "Matriz transposta:" << endl;
    matrix1.print();
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_10 ( )
//---------------------


//---------------------
/** 
   Method_11. 
 */ 
void method_11 ( ) 
{ 
   cout << endl << "Method_11 - v0.0" << endl; 
   string filename;
    cout << "Digite o nome do arquivo com a matriz: ";
    getline(cin, filename);

    Matrix<int> matrix;
    matrix.readMatrixFromFile(filename);

    if ( hasDiagonalRightPattern ( matrix ) ) {
        cout << "A matriz segue o padrão esperado." << endl;
    } else {
        cout << "A matriz NÃO segue o padrão esperado." << endl;
    }

 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_11 ( )
//---------------------



//---------------------
/** 
   Method_12. 
 */ 
void method_12 ( ) 
{ 

   cout << endl << "Method_12 - v0.0" << endl; 


    int rows = 0;
    int cols = 0;
    cout << "Digite o número de linhas: ";
    cin >> rows;

    cout << "Digite o número de colunas: ";
    cin >> cols;
    cin.ignore();

    Matrix<int> matrix = buildDiagonalRightPattern (rows, cols);

    cout << "Matriz construída:" << endl;
    matrix.print();

 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_12 ( )
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
        cout << "  0 - parar       " << endl; 
        cout << "  1 - EX 01  " << endl; 
        cout << "  2 - EX 02  " << endl; 
        cout << "  3 - EX 03  " << endl; 
        cout << "  4 - EX 04  " << endl; 
        cout << "  5 - EX 05  " << endl; 
        cout << "  6 - EX 06  " << endl; 
        cout << "  7 - EX 07  " << endl; 
        cout << "  8 - EX 08  " << endl; 
        cout << "  9 - EX 09  " << endl; 
        cout << " 10 - EX 10  " << endl; 
 
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
          case 10:  method_10 ( );   break; 
          default: 
            cout << endl << "ERRO: Valor invalido." << endl; 
        } // end switch 
    } 
    while ( x != 0 ); 
 
 // encerrar 
    pause  ( "Apertar ENTER para terminar" ); 
    return ( 0 ); 
} // end main ( ) 