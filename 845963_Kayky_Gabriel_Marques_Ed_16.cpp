/* 
   Exemplo1600 - v0.0. - __ / __ / _____ 
   Author: _____________________________ 
 
 */ 
 
// ----------------------------------------------- preparacao 
 
// dependencias 
 
#include <iostream> 
using std::cin  ;  // para entrada 
using std::cout;   // para saida 
using std::endl;  // para mudar de linha 
 
#include <iomanip> 
using std::setw;  // para definir espacamento 
 
#include <string> 
using std::string;  // para cadeia de caracteres 
 
#include <fstream> 
using std::ofstream;  // para gravar arquivo 
using std::ifstream;   // para ler    arquivo 
#include <cstring>

#define Max 100
#define null nullptr
 
// outras dependencias 
 
void pause ( std::string text ) 
{ 
    std::string dummy; 
    std::cin.clear ( ); 
    std::cout << std::endl << text; 
    std::cin.ignore( ); 
    std::getline(std::cin, dummy); 
    std::cout << std::endl << std::endl; 
} // end pause ( ) 
 

 
// ----------------------------------------------- classes 
 
#include "Erro.hpp"     // classe para tratar erros 
#include "Myarray.hpp"  // classe auxiliar para craiacao de arranjos


// ----------------------------------------------- definicoes globais 
 
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
 * array_push_back - Acrescentar valor ao final do arranjo.
 * @param array - arranjo original
 * @param value - valor a ser inserido
 * @return novo arranjo com valor inserido, ou arranjo vazio em caso de erro
 */
Array<int> array_push_back(Array<int> array, int value)
{
// inicializando variavel
    Array<int> result(0, 0);  // arranjo resultado inicializado vazio

// tratamento de condicao logca (caso for difernte de 0 ou maior que 0 )
    if (array.getLength() != 0 && array.getLength() > 0)
    {
        int length = array.getLength();

// criar arranjo novo com tamanho +1
        result = Array<int>(length + 1, 0);

// copiar elementos antigos
        for (int i = 0; i < length; i = i + 1)
        {
            result.set ( i, array.get ( i ) );
        }

// inserir novo valor no final
        result.set(length, value);
    }
    else
    {
        cout << "Erro: arranjo vazio ou apontador aterrado."    << endl;
    }

    return (result);
}
//---------------------

//---------------------
/**
 * method_01 - Testar array_push_back
 */
void method_01()
{
// identificar
    cout << "\nMethod_01 - v1.0\n" << endl;

// definir dados
    int length = 0;
    cout << "Digite o tamanho do arranjo: ";
    cin >> length;
    getchar();

// iniciando nova variavel
    Array<int> array(length, 0);
    array.read();

    int value = 0;
    cout << "Digite o valor para inserir no final: ";
    cin >> value;
    getchar();

// teste
    Array<int> result = array_push_back(array, value);

// mostrar resultado
    cout << "Arranjo atualizado:" << endl;
    result.print();

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------

//---------------------
/**
 * array_pop_back - Remover valor do final do arranjo.
 * @param array - arranjo original
 * @return novo arranjo com último elemento removido, ou arranjo vazio
 */
Array<int> array_pop_back(Array<int> array)
{
// inicializando variavel
    Array<int> result(0, 0); // resultado inicial vazio

// condicao de tamanho 
    if ( array.getLength() != 0 )
    {
        int length = array.getLength();

// Criar arranjo novo com tamanho de n - 1
        result = Array<int>( length - 1, 0 );

// Copiar todos os elementos exceto o último
        for (int i = 0; i < length - 1; i = i + 1)
        {
            result.set(i, array.get(i));
        }
    }

// condicoes de exitencia 
    else if (array.getLength() == 1)
    {  cout << "arranjo ficara vazio, contem somente um valor" << endl; }

    else
    { cout << "Erro: arranjo vazio ou apontador aterrado."    << endl;  }

    return (result);
}
//---------------------


//---------------------
/**
 * method_02 - Testar array_pop_back
 */
void method_02()
{
// identificar
    cout << "\nMethod_02 - v1.0\n" << endl;

// definir dados
    int length = 0;
    cout << "Digite o tamanho do arranjo: ";
    cin >> length; getchar();

// iniciando variavel
    Array<int> array(length, 0);
    array.read();

// testar
    Array<int> result = array_pop_back(array);

// mostrar resultado
    cout << "Arranjo atualizado:" << endl;
    result.print();

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
/**
 * array_push_front - Acrescentar valor no início do arranjo.
 * @param value - valor a ser inserido
 * @param array - arranjo original
 * @return novo arranjo com valor inserido no início, ou arranjo vazio em caso de erro
 */
Array<int> array_push_front(int value, Array<int> array)
{
// inicializando variavel
    Array<int> result(0, 0);  // resultado inicial vazio

// condicao de tamanho necessario 
    if (array.getLength() != 0 && array.getLength() > 0)
    {

// iniciando variavel auxiliar 
        int length = array.getLength();

// criando novo arranjo com tamanho n + 1 
        result = Array<int>(length + 1, 0);

// inserindo o novo valor na posicao 0
        result.set(0, value);

// copiando os elementos antigos deslocando 1 posicao para frente
        for (int i = 0; i < length; i = i + 1)
        { result.set(i + 1, array.get(i)); }
    }
    else
    {  cout << "Erro: arranjo vazio ou apontador aterrado."    << endl; }

    return ( result );
}
//---------------------


//---------------------
/**
 * method_03 - Testar array_push_front
 */
void method_03()
{
// identificar
    cout << "\nMethod_03 - v1.0\n" << endl;

// definir dados
    int length = 0;
    cout << "Digite o tamanho do arranjo: ";
    cin >> length; getchar();

// definindo ararnjo 
    Array<int> array(length, 0);
    array.read();

    int value = 0;
    cout << "Digite o valor para inserir no inicio: ";
    cin >> value; getchar();

// testar
    Array<int> result = array_push_front(value, array);

// mostrar resultado
    cout << "Arranjo atualizado:" << endl;
    result.print();

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
/**
 * array_pop_front - Remover valor do início do arranjo.
 * @param array - arranjo original
 * @return novo arranjo com o primeiro elemento removido, ou arranjo vazio
 */
Array<int> array_pop_front(Array<int> array)
{
// inicializando variavel
    Array<int> result(0, 0); // resultado inicial vazio

// condicao de tamanho necessario 
    if (array.getLength() > 1) // -> ser no minimo maior que um 
    {
// variavel auxiliar para receber o tamanho 
        int length = array.getLength();

// criar novo arranjo com n  -1
        result = Array<int>(length - 1, 0);

// copiando todos os elementos exceto o primeiro 
        for (int i = 1; i < length; i = i + 1)
        {
            result.set(i - 1, array.get(i)); // - > deslocando para a posicao anterior
        }
    }
// condicao de tamanho miinimo necessario 
    else if (array.getLength() == 1)
    {  cout << "arranjo ficara vazio, contem somente um valor" << endl;  }
    
    else
    {
        cout << "Erro: arranjo vazio ou ponteiro invalido para remover valor do início." << endl;
    }

    return (result);
}
//---------------------


//---------------------
/**
 * method_04 - Testar array_pop_front
 */
void method_04()
{
// identificar
    cout << "\nMethod_04 - v1.0\n" << endl;

// definir dados
    int length = 0;
    cout << "Digite o tamanho do arranjo: ";
    cin >> length; getchar();

// criando arranjo 
    Array<int> array(length, 0);
    array.read();

// testar
    Array<int> result = array_pop_front(array);

// mostrar resultado
    cout << "Arranjo atualizado:" << endl;
    result.print();

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
/**
 * array_push_mid - Acrescentar valor no meio (aproximadamente) do arranjo.
 * @param array - arranjo original
 * @param value - valor a ser inserido
 * @return novo arranjo com valor inserido no meio, ou arranjo vazio em caso de erro
 */
Array<int> array_push_mid(Array<int> array, int value)
{
// inicializando variavel
    Array<int> result(0, 0);

// condicao de tamanho
    if (array.getLength() != 0)
    {
        int length = array.getLength(); // - > variavel aux, para receber o tamanho do arranjo 

        int mid = length / 2; // - > metade do tamanho do arranhjo 

// criar novo arranjo com n + 1
        result = Array<int>(length + 1, 0);

// copiar elementos antes do meio
        for (int i = 0; i < mid; i = i + 1)
        {
            result.set(i, array.get(i));
        }

 // inserir o valor no meio
        result.set(mid, value);

// copiar elementos depois do meio
        for (int i = mid; i < length; i = i + 1)
        {
            result.set(i + 1, array.get(i));
        }
    }
    else
    {
        cout << "Erro: arranjo vazio ou apontador aterrado." << endl;
    }

    return (result);
}
//---------------------


//---------------------
/**
 * method_05 - Testar array_push_mid
 */
void method_05()
{
// identificar
    cout << "\nMethod_05 - v1.0\n" << endl;

// definir dados
    int length = 0;
    cout << "Digite o tamanho do arranjo: ";
    cin >> length; getchar();

// criando arranjo
    Array<int> array(length, 0);
    array.read();

    int value = 0;
    cout << "Digite o valor para inserir no meio do arranjo: ";
    cin >> value; getchar();

// testar
    Array<int> result = array_push_mid(array, value);

// mostrar resultado
    cout << "Arranjo atualizado:" << endl;
    result.print();

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------

//---------------------
/**
 * array_pop_mid - Remover valor do meio (aproximadamente) do arranjo.
 * @param array - arranjo original
 * @return novo arranjo com elemento do meio removido, ou arranjo vazio
 */
Array<int> array_pop_mid(Array<int> array)
{
// inicializando variavel
    Array<int> result(0, 0);

// condicao de tamanho
    if (array.getLength() > 1)
    {
        int length = array.getLength();
        int mid = length / 2;

// criar novo arranjo com n - 1
        result = Array<int>(length - 1, 0);

// copiar elementos antes do meio
        for (int i = 0; i < mid; i = i + 1)
        {
            result.set(i, array.get(i));
        }

// copiar elementos depois do meio
        for (int i = mid + 1; i < length; i = i + 1)
        {
            result.set(i - 1, array.get(i));
        }
    }

    else if (array.getLength() == 1)
    {  cout << "arranjo ficara vazio, contem somente um valor" << endl; }
    else
    { cout << "Erro: arranjo vazio ou apontador aterrado." << endl;     }

    return ( result );
}
//---------------------


//---------------------
/**
 * method_06 - Testar array_pop_mid
 */
void method_06()
{
// identificar
    cout << "\nMethod_06 - v1.0\n" << endl;

// definir dados
    int length = 0;
    cout << "Digite o tamanho do arranjo: ";
    cin >> length; getchar();

// criando arranjo
    Array<int> array(length, 0);
    array.read();

// testar
    Array<int> result = array_pop_mid(array);

// mostrar resultado
    cout << "Arranjo atualizado:" << endl;
    result.print();

// encerrar
    pause("Apertar ENTER para continuar");
}
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
    cout << "11 - Questao_11." << endl;
    cout << "12 - Questao_12." << endl;

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
          /*case 5:   method_05 ( );   break; 
          case 6:   method_06 ( );   break; 
          case 7:   method_07 ( );   break; 
          case 8:   method_08 ( );   break; 
          case 9:   method_09 ( );   break; 
          case 10: method_10  ( );   break; 
          case 11: method_11  ( );   break; 
          case 12: method_12  ( );   break; */

          

          default: 
            cout << endl << "ERRO: Valor invalido." << endl; 
        } // end switch 
    } 
    while ( x != 0 ); 
 
 // encerrar 
    pause  ( "Apertar ENTER para terminar" ); 
    return ( 0 ); 
} // end main ( ) 