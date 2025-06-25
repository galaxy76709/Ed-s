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


// ----------------------------------------------- estrutua para uso de apontadores e refernciacao  
typedef struct s_intArray
{
    int length;
    int* data;
} intArray;

typedef intArray* ref_intArray;
// -----------------------------------------------


/**
 * intArray_free - Liberar memória de um intArray.
 * @param array - referência ao arranjo a ser desalocado
 */
void intArray_free(ref_intArray array)
{
    if (array != nullptr)
    {
        if (array->data != nullptr)
        {
            delete[] array->data;
            array->data = nullptr;
        }
        delete array;
        array = nullptr;
    }
}



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

// tratamento de condicao logica (caso for difernte de 0 ou maior que 0 )
    if (array.getLength() != 0 && array.getLength() > 0)
    {
        int length = array.getLength();

// criar arranjo novo com n + 1
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
Array<int> array_pop_back ( Array<int> array )
{
// inicializando variavel
    Array<int> result(0, 0); // resultado inicial vazio

// condicao de tamanho 
    if ( array.getLength() != 0 )
    {
        int length = array.getLength();

// Criar arranjo novo com tamanho de n - 1
        result = Array<int>( length - 1, 0 );

// Copiar todos os elementos exceto o ultimo
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
void method_02 (  )
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


//---------------------
/**
 * intArray_cmp - Comparar dois arranjos de inteiros.
 * @param p - primeiro arranjo
 * @param q - segundo arranjo
 * @return 0 se iguais; valor negativo se primeiro menor; valor positivo se primeiro maior
 */
int intArray_cmp(ref_intArray p, ref_intArray q)
{
// inicializando variavel aux
    int result      = 0;
    int minLength   = 0;
    int i           = 0;

// verificar existencia dos arranjos
    if ( p != null  && q != null  && p->data != null  &&  q->data != null )
    {

// condicao para encontrar o menor tamanho
        if ( p->length  < q->length )
           { minLength = p->length; }
           
        else
        { minLength = q->length; }

// comparar elemento por elemento
        i = 0;

        while ( i < minLength && result == 0 )
        {
            result = p->data[i] - q->data[i];
            i = i + 1;
        }

// se todos iguais ate aqui, comparar pelo tamanho final
        if (result == 0)
        { result = p->length - q->length; }
    }
    else
    {  cout << "Erro: Um dos arranjos esta nulo ou com ponteiro aterrado." << endl; }

    return ( result );
}
//---------------------


//---------------------
/**
 * method_07 - Testar intArray_cmp
 */
void method_07()
{
// identificar
    cout << "\nMethod_07 - v1.0\n" << endl;

// definir dados
    int length1 = 0;
    int length2 = 0;

    cout << "Digite o tamanho do primeiro arranjo: ";
    cin >> length1; getchar();

    cout << "Digite o tamanho do segundo arranjo: ";
    cin >> length2; getchar();

// variavel auxiliar passada como referenciacao 
    ref_intArray p = new intArray;
    ref_intArray q = new intArray;

// inicianado valores com tamanho de seus tamanhos
    p->length = length1;
    q->length = length2;

// criacao de referencia apartir dos tamanhos
    p->data = new int[length1];
    q->data = new int[length2];


    cout << "Digite os elementos do primeiro arranjo:" << endl;

    for (int i = 0; i < length1; i = i + 1)
    {
        cout << "p[" << i << "]: ";
        cin >> p->data[i]; getchar();
    }

    cout << "Digite os elementos do segundo arranjo:" << endl;

    for (int i = 0; i < length2; i = i + 1)
    {
        cout << "q[" << i << "]: ";
        cin >> q->data[i]; getchar();
    }

// testar
    int result = intArray_cmp(p, q);

// mostrar resultado
    cout << "Resultado da comparacao: " << result << endl;

// limpar memoria
    intArray_free( q );
    intArray_free( p );

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------

/**
 * intArray_cat - Concatenar dois arranjos de inteiros.
 * @param p - primeiro arranjo
 * @param q - segundo arranjo
 * @return novo arranjo com todos os elementos dos dois arranjos
 */
ref_intArray intArray_cat(ref_intArray p, ref_intArray q)
{
// inicializando ponteiro de resultado
    ref_intArray result = nullptr;

// verificar existencia dos arranjos
    if (p != null&& q != null && p->data != null && q->data != null)
    {
        int newLength = p->length + q->length;

        result         = new intArray;
        result->length = newLength;
        result->data   = new int[newLength];

// copiar elementos do primeiro arranjo
        for (int i = 0; i < p->length; i = i + 1)
            {   result->data[i] = p->data[i];   }

// copiar elementos do segundo arranjo
        for (int i = 0; i < q->length; i = i + 1)
        { result->data[p->length + i] = q->data[i]; }
    }
    else
    { cout << "Erro: Um dos arranjos esta invalido ou com ponteiro nulo." << endl; }

    return ( result );
}
//---------------------


//---------------------
/**
 * method_08 - Testar intArray_cat
 */
void method_08()
{
// identificar
    cout << "\nMethod_08 - v1.0\n" << endl;

// definir dados
    int length1 = 0;
    int length2 = 0;

    cout << "Digite o tamanho do primeiro arranjo: ";
    cin >> length1; getchar();

    cout << "Digite o tamanho do segundo arranjo: ";
    cin >> length2; getchar();

// criacao de referencia apartir dos tamanhos
    ref_intArray p = new intArray;
    ref_intArray q = new intArray;

    p->length = length1;
    q->length = length2;

    p->data = new int[length1];
    q->data = new int[length2];

    cout << "Digite os elementos do primeiro arranjo:" << endl;
    for (int i = 0; i < length1; i = i + 1)
    {
        cout << "p[" << i << "]: ";
        cin >> p->data[i]; getchar();
    }

    cout << "Digite os elementos do segundo arranjo:" << endl;
    for (int i = 0; i < length2; i = i + 1)
    {
        cout << "q[" << i << "]: ";
        cin >> q->data[i]; getchar();
    }

// testar
    ref_intArray result = intArray_cat(p, q);

// mostrar resultado
    if (result != null)
    {
        cout << "Arranjo concatenado:" << endl;
        for (int i = 0; i < result->length; i = i + 1)

        { cout << "result[" << i << "]: " << result->data[i] << endl; }
    }

// limpar memoria
    intArray_free(p);
    intArray_free(q);
    intArray_free(result);

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
/**
 * intArray_seek - Procurar primeira ocorrência de um valor em um arranjo.
 * @param a - arranjo de inteiros
 * @param x - valor a ser procurado
 * @return arranjo com um único elemento contendo a posição encontrada; NULL se não encontrar
 */
ref_intArray intArray_seek(ref_intArray a, int x)
{
// inicializar variavel de retorno
    ref_intArray result = null; // - > apontador aterrado

// validar existencia do arranjo
    if (a != null && a->data != null && a->length > 0)
    {
        for (int i = 0; i < a->length; i = i + 1)
        {
// condicao que preve se o X esta no arranjo 
            if ( a->data[i] == x )
            {
                result          = new intArray;
                result->length  = 1;
                result->data    = new int[1];
                result->data[0] = i;
                i = a->length; 
            }
        }
    }
    else
    { cout << "Erro: Arranjo invalido ou tamanho insuficiente (vazio)." << endl; }

    return (result);
}
//---------------------


//---------------------
/**
 * method_09 - Testar intArray_seek
 */
void method_09()
{
// identificar
    cout << "\nMethod_09 - v1.0\n" << endl;

// definir dados
    int length = 0;
    int value  = 0;

    cout << "Digite o tamanho do arranjo: ";
    cin >> length; getchar();

// criacao de apontadores apartir do tamanho
    ref_intArray a = new intArray;
    a->length      = length;
    a->data        = new int[length];

    cout << "Digite os elementos do arranjo:" << endl;
    for (int i = 0; i < length; i = i + 1)
    {
        cout << "a[" << i << "]: ";
        cin >> a->data[i]; getchar();
    }

    cout << "Digite o valor a procurar: ";
    cin >> value; getchar();

// testar
    ref_intArray result = intArray_seek(a, value);

// mostrar resultado
    if ( result != null )
    {
        cout << "Valor encontrado na posicao: " << result->data[0] << endl;
        intArray_free(result);
    }

    else
    { cout << "Valor nao encontrado no arranjo." << endl; }

// limpar memoria
    intArray_free(a);

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
/**
 * intArray_sub - Criar um novo arranjo com um segmento do arranjo original.
 * @param a - arranjo original
 * @param start - posição inicial
 * @param size - quantidade de elementos
 * @return novo arranjo com os elementos do intervalo; NULL em caso de erro
 */
ref_intArray intArray_sub(ref_intArray a, int start, int size)
{
// inicializar variavel de retorno
    ref_intArray result = null;

// validar existência e limites
    if ( a != null  && a->data != null  &&  a->length > 0 )
    {
// variavel auxiliar para melhor passagem de valor na hora 
        int another_lenght = start + size;

        if (start >= 0 && size > 0 && another_lenght <= a->length)
        {

// criacao de uma var aux
            result          = new intArray;
            result->length  = size;
            result->data    = new int[size];

            for (int i = 0; i < size; i = i + 1)
            {  result->data[i] = a->data[start + i]; }
        }
        else
        { cout << "Erro: Intervalo invalido." << endl; }
    }

    else
    { cout << "Erro: Arranjo invalido ou tamanho insuficiente (vazio)." << endl; }

    return (result);
}
//---------------------


//---------------------
/**
 * method_10 - Testar intArray_sub
 */
void method_10()
{
// identificar
    cout << "\nMethod_10 - v1.0\n" << endl;

// definir dados
    int length = 0;
    int start  = 0;
    int size   = 0;

    cout << "Digite o tamanho do arranjo: ";
    cin >> length; getchar();

// criacao de apontadores apartir do tamanho
    ref_intArray a = new intArray;
    a->length      = length;
    a->data        = new int[length];

    cout << "Digite os elementos do arranjo:" << endl;
    for (int i = 0; i < length; i = i + 1)
    {
        cout << "a[" << i << "]: ";
        cin >> a->data[i]; getchar();
    }

    cout << "Digite a posicao inicial: ";
    cin >> start; getchar();

    cout << "Digite o tamanho do subarranjo: ";
    cin >> size; getchar();

// testar
    ref_intArray result = intArray_sub(a, start, size);

// mostrar resultado
    if (result != null)
    {
        cout << "Subarranjo criado:" << endl;
        for (int i = 0; i < result->length; i = i + 1)
        { cout << "result[" << i << "]: " << result->data[i] << endl; }
        intArray_free(result);
    }
    else
    {
        cout << "Falha ao criar subarranjo." << endl;
    }

// limpar memoria
    intArray_free(a);

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
/**
 * intArray_merge - Intercalar dois arranjos, um valor de cada vez.
 * @param p - primeiro arranjo
 * @param q - segundo arranjo
 * @return novo arranjo intercalado; NULL em caso de erro
 */
ref_intArray intArray_merge(ref_intArray p, ref_intArray q)
{
// inicializar variavel para resultado
    ref_intArray result = null;

// condicao para validar existencia
    if (p != null && q != null &&
        p->data != null && q->data != null &&
        p->length >= 0  && q->length >= 0)
    {
// inicio de varaiveis passadas por referenciacao
        int total = p->length + q->length;
        result = new intArray;
        result->length = total;
        result->data = new int[total];

// variaveis de controle
        int index = 0;
        int i = 0;
        int j = 0;

// laco de repeticao enquanto i for menor que tamnho de p e j quando for menor que q
        while (i < p->length || j < q->length)
        {
// caso se i for menor q o tamanho do tamanho de p 
            if (i < p->length)
            {
                result->data[index] = p->data[i];
                index = index + 1;
                i = i + 1;
            }

// caso se j for menor q o tamanho do tamanho de q 
            if (j < q->length)
            {
                result->data[index] = q->data[j];
                index = index + 1;
                j = j + 1;
            }
        }
    }
    else
    {
        cout << "Erro: Arranjos invalido ou vazios." << endl;
    }

    return (result);
}
//---------------------


//---------------------
/**
 * method_11 - Testar intArray_merge
 */
void method_11()
{
// identificar
    cout << "\nMethod_11 - v1.0\n" << endl;

// definir dados
    int length1 = 0;
    int length2 = 0;

    cout << "Digite o tamanho do primeiro arranjo: ";
    cin >> length1; getchar();

    cout << "Digite o tamanho do segundo arranjo: ";
    cin >> length2; getchar();

// iniciando arranjos com passagem por referencia
    ref_intArray p = new intArray;
    ref_intArray q = new intArray;

    p->length = length1;
    q->length = length2;

    p->data = new int[length1];
    q->data = new int[length2];

    cout << "Digite os elementos do primeiro arranjo:" << endl;
    for (int i = 0; i < length1; i = i + 1)
    {
        cout << "p[" << i << "]: ";
        cin >> p->data[i]; getchar();
    }

    cout << "Digite os elementos do segundo arranjo:" << endl;
    for (int i = 0; i < length2; i = i + 1)
    {
        cout << "q[" << i << "]: ";
        cin >> q->data[i]; getchar();
    }

// testar
    ref_intArray result = intArray_merge(p, q);

// mostrar resultado
    if (result != nullptr)
    {
        cout << "Arranjo intercalado:" << endl;
        for (int i = 0; i < result->length; i = i + 1)
        {
            cout << "result[" << i << "]: " << result->data[i] << endl;
        }

    intArray_free(result);
    }

// limpar memoria
    intArray_free(p);
    intArray_free(q);

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
/**
 * intArray_mergeDown - Mesclar dois arranjos em ordem decrescente.
 * @param p - primeiro arranjo
 * @param q - segundo arranjo
 * @return novo arranjo mesclado e decrescente; NULL em caso de erro
 */
ref_intArray intArray_mergeDown(ref_intArray p, ref_intArray q)
{
// inicializar variavel para resultado
    ref_intArray result = null;

// conficao de verificao de existencia
    if (p != null && q != null &&
        p->data   != null && q->data   != null &&
        p->length >= 0    && q->length >= 0)
    {

// variavel auxilar 
        int total = p->length + q->length;
        result = new intArray;
        result->length = total;
        result->data = new int[total];

        int index = 0;

// copiar elementos de p
        for (int i = 0; i < p->length; i = i + 1)
        {
            result->data[index] = p->data[i];
            index = index + 1;
        }

// copiar elementos de q
        for (int i = 0; i < q->length; i = i + 1)
        {
            result->data[index] = q->data[i];
            index = index + 1;
        }

// ordenar de forma decrescente ((bubble sort)
        for (int i = 0; i < result->length - 1; i = i + 1)
        {
            for (int j = 0; j < result->length - i - 1; j = j + 1)
            {
                if (result->data[j] < result->data[j + 1])
                {
                    int temp = result->data[j];
                    result->data[j] = result->data[j + 1];
                    result->data[j + 1] = temp;
                }
            }
        }
    }
    else
    { cout << "Erro: Arranjos inválidos ou vazios." << endl; }

    return (result);
}
//---------------------


//---------------------
/**
 * method_12 - Testar intArray_mergeDown
 */
void method_12()
{
// identificar
    cout << "\nMethod_12 - v1.0\n" << endl;

// definir dados
    int length1 = 0;
    int length2 = 0;

    cout << "Digite o tamanho do primeiro arranjo: ";
    cin >> length1; getchar();

    cout << "Digite o tamanho do segundo arranjo: ";
    cin >> length2; getchar();

// iniciando arranjos com passagem por referencia
    ref_intArray p = new intArray;
    ref_intArray q = new intArray;

    p->length = length1;
    q->length = length2;

    p->data = new int[length1];
    q->data = new int[length2];

    cout << "Digite os elementos do primeiro arranjo:" << endl;
    for (int i = 0; i < length1; i = i + 1)
    {
        cout << "p[" << i << "]: ";
        cin >> p->data[i]; getchar();
    }

    cout << "Digite os elementos do segundo arranjo:" << endl;
    for (int i = 0; i < length2; i = i + 1)
    {
        cout << "q[" << i << "]: ";
        cin >> q->data[i]; getchar();
    }

// testar
    ref_intArray result = intArray_mergeDown(p, q);

// mostrar resultado
    if (result != null)
    {
        cout << "Arranjo mesclado em ordem decrescente:" << endl;
        for (int i = 0; i < result->length; i = i + 1)
        {
            cout << "result[" << i << "]: " << result->data[i] << endl;
        }
        intArray_free(result);
    }

// limpar memoria
    intArray_free(p);
    intArray_free(q);

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
          case 5:   method_05 ( );   break; 
          case 6:   method_06 ( );   break; 
          case 7:   method_07 ( );   break; 
          case 8:   method_08 ( );   break; 
          case 9:   method_09 ( );   break; 
          case 10:  method_10 ( );  break; 
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