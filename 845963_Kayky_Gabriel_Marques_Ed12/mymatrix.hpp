/*
   mymatrix.hpp  - v0.0. - __ / __ / _____
   Author: _________________________

 */

// ----------------------------------------------- definicoes globais

#ifndef _MYMATRIX_H_
#define _MYMATRIX_H_
#define null nullptr
// dependencias

#include <iostream>
using std::cin;  // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha

#include <iomanip>
using std::setw; // para definir espacamento

#include <string>
using std::string; // para cadeia de caracteres

#include <fstream>
using std::ifstream; // para ler    arquivo
using std::ofstream; // para gravar arquivo

#include <ctime>     // para time()
#include <cstdlib>  // para rand() e srand()

//---------------------
template <typename T>
class Matrix
{
private: // area reservada
    T optional ;
    int rows   ;
    int columns;
    T **data   ;

public: // area aberta
    Matrix()
    {
        // definir valores iniciais
        this->rows    = 0;
        this->columns = 0;

        // sem reservar area
        data = nullptr;

    } // end constructor
//---------------------


//---------------------
Matrix(int rows, int columns, T initial)
    {
        // definir dado local
        bool OK = true;
        
        // definir valores iniciais
        this->optional = initial;
        this->rows     = rows;
        this->columns  = columns;

        // reservar area
        data      = new T *[rows];
        if (data != nullptr)
        {
            for (int x = 0; x < rows; x = x + 1)
            {
                data[x] = new T[columns];           // -> aloca memoria para as colunas 
                OK = OK && (data[x] != nullptr);    // -> ok so sera verdade se a ja for verdade e caso a posicao de x ser diferente de null
            } // end for
            if (!OK) // -> caso a condicao seja falsa, retornara um valor nulo 
            {
                data = nullptr;
            } // end if
        } // end if
    } // end constructor
//---------------------


//---------------------
~Matrix() // -> destrutor 
    {
        if (data != nullptr)
        {
            for (int x = 0; x < rows; x = x + 1)
            {
                delete (data[x]);
            } // end for
            delete (data);
            data = nullptr;
        } // end if
    } // end destructor ( )
//---------------------


//---------------------    
void set(int row, int column, T value)
    {
        if (row < 0 || row >= rows ||
            column < 0 || column >= columns)
        {
            cout << "\nERROR: Invalid position.\n";
        }
        else
        {
            data[row][column] = value;
        } // end if
    } // end set ( )
//---------------------


//---------------------
T get(int row, int column)
    {
        T value = optional;
        if (row < 0 || row >= rows ||
            column < 0 || column >= columns)
        {
            cout << "\nERROR: Invalid position.\n";
        }
        else
        {
            value = data[row][column];
        } // end if
        return (value);
    } // end get ( )
//---------------------


//---------------------   
void print()
    {
        cout << endl;
        for (int x = 0; x < rows; x = x + 1)
        {
            for (int y = 0; y < columns; y = y + 1)
            {
                cout << data[x][y] << "\t";
            } // end for
            cout << endl;
        } // end for
        cout << endl;
    } // end print ( )
//---------------------


//---------------------
void read ( ) 
    { 
       cout << endl; 
       for ( int x = 0; x < rows; x=x+1 ) 
       { 
           for ( int y = 0; y < columns; y=y+1 ) 
           { 
               cout << setw( 2 ) << x << ", " 
                        << setw( 2 ) << y << " : "; 
               cin    >> data[ x ][ y ]; 
           } // end for 
       } // end for 
       cout << endl; 
    } // end read ( )
//---------------------


//---------------------
void fprint ( string fileName ) 
    { 
       ofstream afile; 
 
       afile.open ( fileName ); 
       afile << rows       << endl; 
       afile << columns << endl; 
       for ( int x = 0; x < rows; x=x+1 ) 
       { 
           for ( int y = 0; y < columns; y=y+1 ) 
           { 
               afile << data[ x ][ y] << endl; 
           } // end for 
       } // end for 
       afile.close ( ); 
    } // end fprint ( )
//---------------------


//---------------------
void fread ( string fileName ) 
    { 
       ifstream afile; 
       int m  = 0; 
       int n  = 0; 
 
       afile.open ( fileName ); 
       afile >> m; 
       afile >> n; 
       if ( m <= 0 || n <= 0 ) 
       { 
          cout << "\nERROR: Invalid dimensions for matrix.\n" << endl; 
       } 
       else 
       { 
        // guardar a quantidade de dados 
           rows       = m; 
           columns    = n; 
        // reservar area 
           data       = new T* [ rows ]; 
           for ( int x = 0; x < rows; x=x+1 ) 
           { 
               data [x] = new T  [ columns ]; 
           } // end for 
        // ler dados 
           for ( int x = 0; x < rows; x=x+1 ) 
           { 
               for ( int y = 0; y < columns; y=y+1 ) 
               { 
                   afile >> data[ x ][ y ]; 
               } // end for 
           } // end for 
       } // end if 
       afile.close ( ); 
    } // end fread ( )
//---------------------


//---------------------
Matrix& operator= ( const Matrix <T> &other ) 
    { 
       if ( other.rows == 0 || other.columns == 0 ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
           this->rows        = other.rows  ; 
           this->columns = other.columns; 
           this->data         = new T* [ rows ]; 
           for ( int x = 0; x < rows; x=x+1 ) 
           { 
               this->data [ x ] = new T  [ columns ]; 
           } // end for 
           for ( int x = 0; x < this->rows; x=x+1 ) 
           { 
               for ( int y = 0; y < this->columns; y=y+1 ) 
               { 
                   data [ x ][ y ] = other.data [ x ][ y ]; 
               } // end for 
           } // end for 
       } // end if 
       return ( *this ); 
    } // end operator= ( ) 
//---------------------


//---------------------
bool isZeros ( ) 
    { 
       bool result = false; 
       int x = 0; 
       int y = 0; 
       if ( rows > 0 && columns > 0 ) 
       { 
          result = true; 
          while ( x < rows && result ) 
          { 
                y = 0; 
                while ( y < columns && result ) 
                { 
                      result = result && ( data [ x ][ y ] == 0 ); 
                      y = y + 1; 
                } // end while 
                x = x + 1; 
          } // end while 
       } // end if 
       return ( result ); 
    } // end isZeros ( )
//---------------------


//---------------------
bool operator!= ( const Matrix <T> &other ) 
    { 
       bool result = false; 
       int    x         = 0; 
       int    y         = 0; 
 
       if ( other.rows    == 0 || rows    != other.rows || 
            other.columns == 0 || columns != other.columns ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
          x = 0; 
          while ( x < rows && ! result ) 
          { 
                y = 0; 
                while ( y < columns && ! result ) 
                { 
                      result = ( data [ x ][ y ] != other.data [ x ][ y ] ); 
                      y = y + 1; 
                } // end while 
                x = x + 1; 
          } // end while 
       } // end if 
       return ( result ); 
    } // end operator!= ( )
//---------------------


//---------------------
Matrix& operator- ( const Matrix <T> &other ) 
    { 
       static Matrix <T> result ( 1, 1, 0 ); 
       int      x      = 0; 
       int      y      = 0; 
 
       if ( other.rows    == 0 || rows    != other.rows || 
            other.columns == 0 || columns != other.columns ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
          result.rows    = rows; 
          result.columns = other.columns; 
          result.data    = new T* [ result.rows ]; 
          for ( int x = 0; x < result.rows; x=x+1 ) 
          { 
              result.data [x] = new T  [ result.columns ]; 
          } // end for 
 
          for ( int x = 0; x < result.rows; x=x+1 ) 
          { 
              for ( int y = 0; y < result.columns; y=y+1 ) 
              { 
                  result.data [ x ][ y ] = data [ x ][ y ] - other.data [ x ][ y ]; 
              } // end for 
          } // end for 
       } // end if 
       return ( result ); 
    } // end operator- ( ) 
//---------------------


//---------------------
Matrix& operator* ( const Matrix <T> &other ) 
    { 
       static Matrix <T> result ( 1, 1, 0 ); 
       int x      = 0; 
       int y      = 0; 
       int z      = 0; 
       int sum = 0; 
 
       if (      rows  <= 0  ||       columns == 0 || 
            other.rows <= 0  || other.columns == 0 || 
                columns    != other.rows                ) 
       { 
          cout << endl << "ERROR: Invalid data." << endl; 
          result.data [ 0 ][ 0 ] = 0; 
       } 
       else 
       { 
          result.rows    = rows; 
          result.columns = other.columns; 
          result.data    = new T* [ result.rows ]; 
          for ( int x = 0; x < result.rows; x=x+1 ) 
          { 
              result.data [x] = new T  [ result.columns ]; 
          } // end for 
 
          for ( x = 0; x < result.rows; x = x + 1 ) 
          { 
              for ( y = 0; y < result.columns; y = y + 1 ) 
              { 
                 sum = 0; 
                 for ( z = 0; z < columns; z = z + 1 ) 
                 { 
                     sum = sum + data [ x ][ z ] *  other.data [ z ][ y ]; 
                 } // end for 
                 result.data [ x ][ y ] = sum; 
             } // end for 
          } // end for 
       } // end if 
       return ( result ); 
    } // end operator* ( )
//---------------------


//---------------------
const int getRows    ( ) 
    { 
       return ( rows ); 
    } // end getRows ( ) 
 
const int getColumns ( ) 
    { 
       return ( columns ); 
    } // end getColumns ( 
//---------------------


//---------------------
void randomIntGenerate (int upper, int lower ){

    // condicao de tamanho loogico e tamamnho fisico (requisitos da questao )
    if (data != null && upper >= 1 && lower <= 100 ) { 

    srand ( time ( 0 ) ) ; // -> seed de time 
    
    for (int i = 0; i < rows; i = i + 1  ) { // -> i vai de 0 a rows - 1 

        for (int j = 0; j < columns; j = j + 1  ) { // -> j vai de 0 a columns - 1 

            int aux_value = ( rand ( ) % ( upper - lower + 1 ) + lower );
            data  [ i ] [ j ] = aux_value; 

        }
    }
 }
}
//---------------------


//---------------------
void saveFlatToFile(std::string fileName) {
    std::ofstream outfile(fileName);

    if (!outfile.is_open()) {
        std::cout << "Erro: não foi possível abrir o arquivo '" << fileName << "' para escrita." << std::endl;
        return;
    }

    // Primeira linha com a quantidade total de elementos
    outfile << (rows * columns) << std::endl;

    // Escrevendo os dados, um por linha
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            outfile << data[i][j] << std::endl;
        }
    }

    outfile.close();
    std::cout << "Matriz salva com sucesso no arquivo '" << fileName << "'." << std::endl;
}
 


//---------------------
Matrix scalar( int  constant) 
{
    Matrix result(rows, columns, optional);
    
    if (data != null && result.data != null) 
    {
        for (int x = 0; x < rows; x++) 
        {
            for (int y = 0; y < columns; y++) 
            {
                result.data[x][y] = data[x][y] * constant;
            }
        }
    }
    return result;
}
//---------------------


//---------------------
static Matrix<T> readMatrixFromFile(string fileName)
{
    std::ifstream file(fileName);
    int rows = 0, cols = 0;

    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return Matrix<T>();
    }

    if (!(file >> rows >> cols) || rows <= 0 || cols <= 0) {
        std::cout << "Erro: tamanhos inválidos para a matriz." << std::endl;
        return Matrix<T>();
    }

    Matrix<T> result(rows, cols, 0);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            file >> result.data[i][j];
        }
    }

    return result;
}
//---------------------


//---------------------
bool identidade ( ) const // 'const' indica que o método não altera o estado do objeto
{
    // Condição 1: A matriz deve ser quadrada e ter dimensões positivas.
    if ( rows <= 0 || rows != columns )
    {
        // Se não for quadrada ou não tiver dimensões válidas, não pode ser identidade.
        return ( false );
    }

    // Condição 2: Verificar os elementos da matriz.
    for ( int x = 0; x < rows; x = x + 1 )
    {
        for ( int y = 0; y < columns; y = y + 1 )
        {
            if ( x == y ) // Elemento na diagonal principal
            {
                // Compara diretamente com o literal inteiro 1.
                // Isso funciona bem para tipos T numéricos padrão.
                if ( data[x][y] != 1 ) 
                {
                    // Se um elemento da diagonal principal não for 1, não é identidade.
                    return ( false ); 
                }
            }
            else // Elemento fora da diagonal principal
            {
                // Compara diretamente com o literal inteiro 0.
                // Isso funciona bem para tipos T numéricos padrão.
                if ( data[x][y] != 0 )
                {
                    // Se um elemento fora da diagonal principal não for 0, não é identidade.
                    return ( false );
                }
            }
        } // end for y
    } // end for x

    // Se passou por todas as verificações, a matriz é identidade.
    return ( true );
} // end identidade ( )
//---------------------


//---------------------
bool operator==(const Matrix<T>& other) const {
    if (rows != other.rows || cols != other.cols) {
        return false;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }

    return true;
}
//---------------------


//---------------------
Matrix<T> add(const Matrix<T>& other) const {
    if (rows != other.rows || cols != other.cols) {
        std::cerr << "Erro: matrizes com dimensões diferentes." << std::endl;
        return Matrix<T>(); // matriz vazia
    }
//---------------------


//---------------------
    Matrix<T> result(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.set(i, j, data[i][j] + other.data[i][j]);
        }
    }

    return result;
}
//---------------------


//---------------------
void addRows(int row1, int row2, T constante) {
    if (row1 < 0 || row1 >= rows || row2 < 0 || row2 >= rows) {
        std::cout << "Erro: índices de linha inválidos.\n";
        return;
    }

    for (int j = 0; j < cols; ++j) {
        data[row1][j] = data[row1][j] + constante * data[row2][j];
    }
}
//---------------------


//---------------------
void addRows(int row1, int row2, T constante) {
    if (row1 < 0 || row1 >= rows || row2 < 0 || row2 >= rows) {
        std::cerr << "Erro: índices de linha inválidos.\n";
        return;
    }

    for (int j = 0; j < cols; j = j + 1 ) {
        data[row1][j] = data[row1][j] + constante * data[row2][j];
    }
}
//---------------------


//---------------------
int searchRows(T value) const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (data[i][j] == value) {
                return i; // linha onde foi encontrado
            }
        }
    }
    return -1; // não encontrado
}
//---------------------


//---------------------
int searchColumns(T value) const {
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            if (data[i][j] == value) {
                return j; // coluna onde foi encontrado
            }
        }
    }
    return -1; // não encontrado
}
//---------------------


//---------------------
void transpose() {
    T** temp = new T*[cols];
    for (int i = 0; i < cols; ++i) {
        temp[i] = new T[rows];
    }

    // Copiar os dados transpostos
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            temp[j][i] = data[i][j];
        }
    }

    // Deletar a matriz antiga
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;

    // Atualizar para nova matriz
    data = temp;
    std::swap(rows, cols); // inverter dimensões
}

//---------------------


//---------------------
bool hasDiagonalRightPattern(const Matrix<int>& mat) {
    int rows = mat.getRows();
    int cols = mat.getCols();
    int expected = mat.get(0, 0);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (mat.get(i, j) != expected++) {
                return false;
            }
        }
    }

    return true;
}
//---------------------


//---------------------
Matrix<int> buildDiagonalRightPattern(int rows, int cols) {
    Matrix<int> mat(rows, cols);
    int value = 1;

    for (int i = rows - 1; i >= 0; --i) {
        for (int j = 0; j < cols; ++j) {
            mat.set(i, j, value++);
        }
    }

    return mat;
}
//---------------------


//---------------------
}; // end class

#endif