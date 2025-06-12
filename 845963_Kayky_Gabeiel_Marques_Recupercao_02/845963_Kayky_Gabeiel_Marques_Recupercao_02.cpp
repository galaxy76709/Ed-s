/* 
   Exemplo1100 - v0.0. - __ / __ / _____ 
   Author: ________________________ 
 
 */ 
// dependencias 
#include <iostream>  // std::cin, std::cout, std:endl 
#include <limits>   // std::numeric_limits 
#include <string>  // para cadeias de caracteres 
#include <cmath>
const int MAX = 100;
 
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
   Method_01 - Mostrar certa quantidade de valores. 
 */ 
void method_01 ( ) 
{ 
// definir dados 
    string fileName = "DADOS1.TXT"; 
    Array<int> array_1;

    array_1.readArrayFromFile ( fileName ); // correção aqui

    // identificar 
    cout << "\nMethod_01 - v1.0\n" << endl;

    if ( !array_1.isDecrescent ( )) {
          array_1.Decrescent   ( );  // método da própria classe, modificando o próprio array
          array_1.recordArrayToFile ("DECRESCENTE.TXT", array_1); 
    } else { 
      std::cout <<"O arranjo ja esta oredenado "<<endl;
      array_1.recordArrayToFile ("DECRESCENTE.TXT", array_1); 

    }

    array_1.print(); // deve imprimir o próprio array_1, que pode estar reordenado

    pause("Apertar ENTER para continuar");
}
//--------------------- 


//---------------------
// Funcao para inverter o conteuo de um array
void inverter_array(Array<int>& destino, Array<int>& origem)
{
    int tamanho = origem.getLength();
    destino.setLength(tamanho);
    
    for (int i = 0; i < tamanho; i = i + 1)
    {
        destino.set(i, origem.get(tamanho - 1 - i));
    }
}
//---------------------


//---------------------
/** 
   Method_02. 
 */ 
void method_02 ( ) 
{ 

    cout << "\nMethod_02 - Inverter array de arquivo\n" << endl;

    // Declarar os arranjos
    Array<int> array_original;
    Array<int> array_invertido;

    // Ler arranjo do arquivo
    array_original.readArrayFromFile("DECRESCENTE.TXT");

    // Inverter o arranjo
    inverter_array(array_invertido, array_original);

    // Gravar arranjo invertido em novo arquivo
    array_invertido.recordArrayToFile("INVERTIDOS.TXT", array_invertido);

    // Mostrar o arranjo invertido
    array_invertido.print();

    pause("Apertar ENTER para continuar");
} // end method_02 ( ) 
//---------------------


//---------------------
double median_array(Array<int> temp_array)
{
    int length = temp_array.getLength();

// Verificacao de tamanho 
    if (length <= 0) 
    {
       return(0.0);
    }
       

// bubble sort do array ( ordenar os valores )
    for (int i = 0; i < length - 1; i = i + 1)
    {
        for (int j = i + 1; j < length; j = j + 1 )
        {
// condicao que preve se o valor de i e maior que j ( se a primeira posicao e maior que a proxima )
            if ( temp_array.get(i)  >  temp_array.get(j) )
            {
               // a b c
                int temp = temp_array.get(i); // temp recebera o valor da posicao de i | a = b

                temp_array.set(i, temp_array.get(j)); // o valor de j sera adicionado a posicao de i ( swap ) b = c

                temp_array.set(j, temp); // j recebera o valor de temp  c = b 
            }
        }
    }

// condicao o numero de elementos for par
    if (length % 2 != 1)
    {
      // | 5 | | 6 | | 7 | | 8 | -> tamanho = 4
      int meio1 = temp_array.get(length / 2 - 1); // (4 / 2 - 1) = 1 -> | 6 |
      int meio2 = temp_array.get(length / 2);    //    ( 4 / 2 ) = 2 -> | 7 |
        return (meio1 + meio2) / 2.0;            //  (| 6 | + | 7 | / 2) = *6,5*
    }
// Se for par
    else {
      // | 5 | | 6 | | 7 |  -> tamanho = 3
        return temp_array.get(length / 2);  //    ( 4 / 2 ) = 2 -> | 6 |

    }
}
//---------------------


//---------------------
void method_03() {
// Identificação
    cout << "\nMethod_03 - v1.0\n" << endl;

// Criar array para armazenar os dados
    Array<int> array;

// Nome do arquivo
    string fileName = "DADOS1.TXT";

// Ler os dados do arquivo
    array.readArrayFromFile(fileName);

// Exibir o array lido
    cout << "Valores lidos do arquivo:" << endl;
    array.print();

    std::cout<<endl; 

// Calcular a mediana
    double mediana = median_array(array);

// Mostrar o resultado
    cout << "\nMediana: " << mediana << endl;

    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
Array<int> array_filter ( Array <int> array_1, Array <int> array_2, int* count) {
// iniciando variaveis com os tamanhos dos arranjos
    int tam_01   = array_1.getLength ( );
    int tam_02   = array_2.getLength ( );
    int tam_aux  = 0; // -> tamanho auxiliar, usar so na hora que descobrir o maior tamanho
    
    *count = 0;

 

// condicao que preve qual arranjo e maior que o outro 
    if (tam_01 <= tam_02) { // caso tam_02 seja maior 
        tam_aux = tam_02;
 
    } else {
        tam_aux = tam_01; 
    }

    Array <int> array_03; 
    array_03.setLength( tam_aux );

// previni que tam_aux seja menor ou igual a 0 
    if ( tam_aux >= 0 ) {

// iniciando operacao de filtro 
    for ( int i = 0; i < tam_01; i = i + 1 ){
        
// segundo laço de repeticao pata verificar outro arranjo inteiro (complelxidade de o^2)

        for ( int j = 0; j < tam_02; j = j + 1 ){

// verificao se contem valores iguais 

            if ( array_1.get( i ) == array_2.get ( j ) ) { // 1- | 5 | | 6 | | 7 | | 8 |  2- | 4 | | 6 | | 4 | | 2 |

                array_03.set(*count, array_2.get(j)); // ou array_2.get(j)
                *count = *count + 1; 
            cout<<"printando array_02.get(j): "<< array_1.get(j)<<endl;
            //array_03.print( );

            }

          }

        }

        array_03.setLength(*count);
        return ( array_03 );
    }
}
//---------------------


//---------------------
void method_04 ( void ) {
// Identificação
    cout << "\nMethod_04 - v1.0\n" << endl;

// Criar array para armazenar os dados
    Array <int> array_01;
    Array <int> array_02;
    Array <int> *array_03;
           int count = 0;

// Nome do arquivo
    string fileName_01 = "DADOS1.TXT";
    string fileName_02 = "DADOS2.TXT";

// Ler os dados do arquivo
    array_01.readArrayFromFile(fileName_01);
    array_02.readArrayFromFile(fileName_02);

// Exibir o array lido
    cout << "Valores lidos do primeiro arquivo:" << endl;
    array_01.print();
    std::cout<<endl; 

    cout << "Valores lidos do segundo arquivo:" << endl;
    array_02.print();
    std::cout<<endl; 

// Verificando o filto 
    Array<int> filter = array_filter( array_01, array_02, &count);

//enviando para o arquivo FILTRADOS.TXT
    filter.recordArrayToFile ("FILTRADOS.TXT", filter);
    
// Mostrar o resultado
    cout << "\nNos dois arquivos contem: " << count << " valores iguais"<<endl;

//end
    pause("Apertar ENTER para continuar");
}//end method_04 ( )
//---------------------


// Verifica se a string contém apenas '0' ou '1'
bool isBinari ( const string& string_ ) {
    for( char c : string_ ) {

        if (c != '0' && c != '1')
        { return false;}
    }

    return( !string_ .empty());
}


//---------------------
int array_toDecimal (const Array<int>& bin) {
// iniciando variaveis com valores 
    int lenght = bin.getLength();
    int decimal = 0;
    int pow_ = 1;

// laco de repeticao ao contrario 
    for (int i = lenght - 1; i >= 0; i = i - 1 ) {
        decimal += bin[i] * pow_;
        pow_ *= 2;
    }
    return (decimal);
}
//---------------------


//---------------------
void method_05 () {

    ifstream arquivo("BINARIOS1.TXT");
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo.\n";
    }

    Array<int> decimais;
    string linha;

    while (getline(arquivo, linha)) {
        // Etapa manual para remover final '\r' ou espaços:
        int fim = linha.length();
        while (fim > 0 && 
            (linha[fim - 1] == '\r' || 
            linha[fim - 1] == ' ' || 
            linha[fim - 1] == '\t'))
            fim = fim - 1 ;

        bool valido = true;

        // Verifica se todos os caracteres (até 'fim') são '0' ou '1'
        for (int i = 0; i < fim; i = i + 1 ) {
            if (linha[i] != '0' && linha[i] != '1') {
                valido = false;
                i = fim; // força saída do for
            }
        }

        if (valido && fim > 0) {
            Array<int> bits(fim, 0);
            for (int i = 0; i < fim; i = i + 1) {
                bits.set(i, linha[i] - '0');
            }

            int valor = array_toDecimal(bits);
            int pos = decimais.getLength();
            decimais.setLength(pos + 1);
            decimais.set(pos, valor);
        }
    }

    arquivo.close();

    cout << "\nValores decimais convertidos:\n";
    decimais.print();

    pause("Apertar ENTER para continuar");
}//end method_05 ( )
//---------------------


// funcao para verificar se um numero e par e m de 3
//---------------------
bool ispair_mult_3(int valor) {
    return (valor % 2 == 0 && valor % 3 == 0);
}
//---------------------


// funcao para procurar o maior valor par e mult de 3 na matriz
//---------------------
int searchLargestMultiplePair3 (Matrix<int>& matrix, int& rows, int& columns) {
// iniciando as variaveis
    int large  = 0;
    bool finde = false;

//laço de repeticao para leitura de matriz
    for (int i = 0; i < matrix.getRows(); i = i + 1 ) {

        for (int j = 0; j < matrix.getColumns(); j = j + 1 )  {
// recebera o valor da posicao (i, j) ca matriz
            int value = matrix.get(i, j);
// verificacarao se e par e multiplo de 3 ( 6, 12, 16, 24... )
            if ( ispair_mult_3 ( value ) ) {

//condicao que verifica se achou e se o valor e maior que o "maior valor" (large)
                if ( !finde || value > large ) {
                    large   = value;
                    rows    = i;
                    columns = j;
                    finde   = true;

                }
            }
        }
    }

    if ( !finde ) {
        return ( -1 );

    } else {
        return ( large );

    }

}
//---------------------

void method_06 ( void ) {
// criando nova matrix
    Matrix<int> matriz;

    string fileName;
    cout << "Digite o nome do arquivo com a matriz: ";
    cin >> fileName;

// Ler matriz do arquivo
    matriz.fread ( fileName );

    int rows    = -1;
    int columns = -1;
    int large   = searchLargestMultiplePair3(matriz, rows, columns);

// verificando se o valor foi achado 
    if (large != -1) {
        cout << "\nMaior valor par e multiplo de 3 encontrado: " << large << endl;

        cout << "Posicao: linha " << rows << ", coluna " << columns << endl;

    } else {

        cout << "\nNao ha nenhum valor par multiplo de 3 na matriz." << endl;
    }

    pause("Apertar ENTER para continuar");
}//end method_06 ( )
//---------------------


//---------------------
void montarTridiagonalSecundaria(Matrix<int> &matriz, int N) {
    int valor = 0;

    for (int i = 0; i < N; i = i + 1 ) {
        for (int j = 0; j < N; j = j + 1 ) {
            if (i + j == N - 1 || i + j == N - 2 || i + j == N) {
                valor = valor + 1;
                matriz.set(i, j, valor);
            } else {
                matriz.set(i, j, 0);
            }
        }
    }
}
//---------------------


//---------------------
void mostrarMatriz(Matrix<int> &matriz, int N) {
    cout << "\nMatriz tridiagonal secundaria decrescente (" << N << "x" << N << "):\n";
    for (int i = 0; i < N; i = i + 1 ) {

        for (int j = 0; j < N; j = j + 1 ) {

            cout << matriz.get(i, j) << "\t";
        }
        cout << endl;
    }
}
//---------------------


//---------------------
void gravarMatrizEmArquivo(Matrix<int> &matriz, int N, const string &nomeArquivo) {
    ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo " << nomeArquivo << endl;
        return;
    }

    arquivo << N << endl;
    for (int i = 0; i < N; i = i + 1) {

        for (int j = 0; j < N; j = j + 1 ) {

            arquivo << matriz.get(i, j) << " ";
        }
        arquivo << endl;
    }

    arquivo.close();
}
//---------------------


//---------------------
void method_07 ( void ) {

    int N = 0;
    ifstream file ("MATRIZ1.TXT");


    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo MATRIZ1.TXT." << endl;

    } else {

    std::cout<<"\nDigite o valor da matriz"<<endl; 
    cin >> N; 


    Matrix<int> matriz(N, N); // Cria matriz N x N

    montarTridiagonalSecundaria(matriz, N);
    mostrarMatriz(matriz, N);
    gravarMatrizEmArquivo(matriz, N, "MATRIZ2.TXT");

    cout << "\nMatriz gravada no arquivo MATRIZ2.TXT com sucesso.\n";
}
    pause("Apertar ENTER para continuar");
}//end method_07 ( )
//---------------------


//---------------------
bool verificarPotenciasPorColuna(Matrix<int> &matriz) {
    int linhas  = matriz.getRows    ( );
    int colunas = matriz.getColumns ( );

    for (int j = 0; j < colunas; j = j + 1 ) {

        int base = matriz.get(1, j); // Segunda linha (indice 1) como base

        for (int i = 0; i < linhas; i = i + 1) {

            int esperado = pow(base, i);

            if (matriz.get(i, j) != esperado) {

                return false;

            }
        }
    }
    return true;
}
//---------------------


//---------------------
void method_08 ( void ) {

    Matrix<int> matriz;

// Leitura direta usando a função da biblioteca
    matriz.fread("MATRIZ3.TXT");

// Exibir a matriz lida
    cout << "Matriz lida:\n";
    matriz.print( ); 

// Verificar a característica
    if (verificarPotenciasPorColuna(matriz)) {
        cout << "\nA matriz apresenta a caracteristica de potencia por colunas.\n";
    } else {
        cout << "\nA matriz NAO apresenta a característica de potencia por colunas.\n";
    }

    pause("Apertar ENTER para continuar");
}//end method_08 ( )
//---------------------


// Verificar potências decrescentes por colunas
//---------------------
bool verificarPotenciasDecrescentesPorColuna(Matrix<int> &matriz) {
    int linhas  = matriz.getRows   ();
    int colunas = matriz.getColumns();

    for (int j = 0; j < colunas; j = j + 1 ) {
        int base = matriz.get(linhas - 2, j); // penúltima linha é a base

        for (int i = 0; i < linhas; i = i + 1 ) {
            int expoente = linhas - 1 - i; // expoente decrescente
            int esperado = pow(base, expoente);

            if (matriz.get(i, j) != esperado) {
                return false;
            }
        }
    }

    return true;
}
//---------------------


//---------------------
void method_09 ( void ) {

   Matrix<int> matriz;

    // Ler matriz de arquivo
    matriz.fread("MATRIZ4.TXT");

    // Mostrar matriz
    cout << "Matriz lida:\n";
    matriz.print( );

    // Verificar característica
    if (verificarPotenciasDecrescentesPorColuna(matriz)) {
        cout << "\nA matriz apresenta potencia decrescentes por colunas.\n";
    } else {
        cout << "\nA matriz NAO apresenta potencia decrescentes por colunas.\n";
    }

    pause("Apertar ENTER para continuar");
}//end method_09 ( )
//---------------------


//---------------------
void method_10 ( void ) {

    int n = 0 ; //  -> numero de supermercados
    string  nomes[MAX];
    int   codigos[MAX];
    double precos[MAX];

    ifstream arquivo("DADOS3.TXT");

    if (!arquivo) {
        std::cout<< "Erro ao abrir o arquivo DADOS3.TXT\n"<<endl;
    } else {

// Lendo o numero de supermercados
    arquivo >> n;

// Validando o número
    if (n <= 0 || n > MAX) {
        cout << "Quantidade invalida de supermercados\n"<<endl; 
    }

// Lendo nomes e codigos
    for (int i = 0; i < n; i = i + 1 ) {
        arquivo >> nomes[i] >> codigos[i];
    }

// Lendo precos
    for (int i = 0; i < n; i = i + 1 ) {
        arquivo >> precos[i];
    }

    arquivo.close();

// Calculando a media dos preços
    double soma = 0.0;
    for (int i = 0; i < n; i = i + 1 ) {
        soma += precos[i];
    }
    double media = soma / n;

// Mostrando dados e resultado
    cout << fixed << setprecision(2);
    cout << "\nPreco medio do produto: R$ " << media << "\n" <<endl; 
    cout << "\nSupermercados com preco abaixo da media:\n"   <<endl; 

    int abaixoMedia = 0;
    for (int i = 0; i < n; i++) {
        if (precos[i] < media) {
            cout << "- " << nomes[i] << " (Codigo: " << codigos[i] << ") - R$ " << precos[i] << "\n";
            abaixoMedia = abaixoMedia + 1 ;
        }
    }

    if (abaixoMedia < 2) {
        cout << "\n[Atenção] Menos de dois supermercados com preço abaixo da média.\n";
    }
}
    pause("Apertar ENTER para continuar");
}//end method_10 ( )
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
    cout << "Opcoes" << endl;
    cout << " 0 - Method_00 parar" << endl;
    cout << " 1 - Questao_01." << endl;
    cout << " 2 - Questao_02." << endl;
    cout << " 3 - Questao_03." << endl;
    cout << " 4 - Questao_04." << endl;
    cout << " 5 - Questao_05." << endl;
    cout << " 6 - Questao_06." << endl;
    cout << " 7 - Questao_07." << endl;
    cout << " 8 - Questao_08." << endl;
    cout << " 9 - Questao_09." << endl;
    cout << "10 - Questao_10." << endl;

    cout << "" << endl; 

 
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
          

          default: 
            cout << endl << "ERRO: Valor invalido." << endl; 
        } // end switch 
    } 
    while ( x != 0 ); 
 
 // encerrar 
    pause  ( "Apertar ENTER para terminar" ); 
    return ( 0 ); 
} // end main ( ) 