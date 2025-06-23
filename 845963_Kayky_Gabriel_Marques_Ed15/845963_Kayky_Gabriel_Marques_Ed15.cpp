/* 
   Exemplo1400 - v0.0. - __ / __ / _____ 
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
 
#include "Erro.hpp"  // classe para tratar erros 
 
class MyString : public Erro 
{ 
//---------------------private
private : 
    std::string text;

//---------------------end private

//---------------------public
public: // -> atualizacao da Mystring do Ed14

  /** 
    * Funcao para obter mensagem 
    * relativa ao código de erro. 
    * @return mensagem sobre o erro 
    */ 
    std::string getErroMsg ( ) 
    { 
 
       return ( NO_ERROR ); // COMPLETAR A DEFINICAO 
 
    } // end getErroMsg ( ) 

//---------------------

     MyString(std::string value = "") {
        text = value;
        setErro(0);  // Sem erro por padrão
    }

    void setText(std::string value) {
    text = value;
}

//---------------------



//---------------------
int getInt() {
    int result = 0;
    bool valid = true;
    int index = 0;
    int signal = 1;

// condicao de tamanho (caso esteja vazio ou menor igual a 0 )
    if ( text.empty( ) ) {
        valid = false;
    } else {
// caso conter valores (se a posicao for igual a '-' o index andarar)
        if (text[0] == '-') {
            signal = -1;
            index = index + 1;
        }

// enquando o index for menor que o tamnho do texto 
    while (index < (int)text.length()) {

//variavel auxilicar
        char symbol = text[index];

// verificao se o simbolo e digito 

        if (symbol >= '0' && symbol <= '9') {

// caso for va converter de caractere a numero
            result = result * 10 + (symbol - '0');
        } else {

            valid = false;
            index = (int)text.length(); 
        }

            index = index + 1;
    }

    if ( valid ) {
        result = result * signal;
    } else {
         result = -1;
    }

    }

    if ( !valid ) {
        setErro( 1 );
    } else {
        setErro( 0 );
    }

    return (result);
}
//---------------------



//---------------------
double getDouble() {
    double result           = 0.0;
    bool   valid            = true;
    int    index            = 0;
    int    signal           = 1;
    int    pointPosition    = -1;
    int    digitsAfterPoint = 0;
    double multiplier       = 1.0;

// verificao de existencia
    if (text.empty()) {
        valid = false;
    } else {
        if (text[0] == '-') {
            signal = -1;
            index = index + 1;
        }

// enquanto o index for maior qu eo tamanho 
        while (index < (int)text.length()) {
            char symbol = text[index];

// verificao se o valor e um digito
            if (symbol >= '0' && symbol <= '9') {

// convercao para numero (deveria msm fazer uma funcao para isso)
                result = result * 10 + (symbol - '0');

// caso a posicap seja menor igual que 0 
            if (pointPosition >= 0) {
                digitsAfterPoint = digitsAfterPoint + 1;
            }
            } else {
// caso nao for verifica a posicao do . e se sua posicao e menos um (valores atras do ponto) 
                if (symbol == '.' && pointPosition == -1) {
                pointPosition = index;
                } else {
// caso contrario o loop sera abortado 
                valid = false;
                index = (int)text.length(); 
                }
            }

            index = index + 1;
        }

// verificao se o numero e valido e se a quantidade de valores apos o ponto
        if (valid && digitsAfterPoint > 0) {
            multiplier = 1.0;
            int count  = 0;

// multiplica os valores por 10.0 (transdormando em valores na)
    while (count < digitsAfterPoint) {
    multiplier = multiplier * 10.0;
    count = count + 1;
    }

    result = result / multiplier;
        }

    result = result * signal;

        if (!valid) {
            result = 0.0;
        }
    }

        if (!valid) {
            setErro(2); 
        } else {
            setErro(0);
        }

    return (result);
}
//---------------------


//---------------------
bool getBoolean() {
// variaveis logicas inicializadas com negacao
    bool result = false;
    bool valid  = false;


// verificacao de string para verdade
    if (text == "true" || text == "T" || text == "1") {
        result = true;
        valid  = true;
    }

// verificacao de string para falso
    if (text == "false" || text == "F" || text == "0") {
        result = false;
        valid = true;
    }

// caso contenha erro, chame seterro
    if (!valid) {
        setErro(3); // Erro para conteúdo inválido para booleano
    } else {
        setErro(0);
    }

    return result;
}
//---------------------


//---------------------
bool contains(std::string subtext) {
// varaiveis auxiliares 
    bool found      = false;
    int mainLength  = (int)   text.length( ); // -> recebe tamanho do texto "principal"
    int subLength   = (int)subtext.length( ); // -> recebe tamanho do sub texto
    int i = 0;

// verificao de tamanho se for maior que zero e se o subtexto dor menor ou igual ao tamanho do texto principal
    if (subLength > 0 && subLength <= mainLength) {

// enquanto i for menor ou igual ao tamanh do principaç e do subtexto 
        while (i <= mainLength - subLength) {

// variaveis auxiliares
            int      j = 0;
            bool match = true;


// verificao de existencia (caso o sub texto esteja contido no texto principaç)
    while (j < subLength) {
        if (text[i + j] != subtext[j]) {
             match = false;
            }

        j = j + 1;

    }

        if (match) {
        found = true;
        }

        i = i + 1;
        }
    }

    if (!found) {
        setErro(4); // Erro para: subtexto nao encontrado
    } else {
        setErro(0);
    }

    return found;
}
//---------------------


//---------------------
std::string toUpperCase() {
// varaiveis auxiliares 
    std::string result = "";
    int index = 0;
    int lengh = text.length ( ); 

// enquanto o index seja menor que o tamanho 
    while ( index < lengh ) {
        char current = text[index];

// verificao se em current contem caracteres minusculos
        if (current >= 'a' && current <= 'z') {

// caso tiver, houverar conversao para maiusculo 
            current = current - 32;  
        }

        result = result + current;
        index = index + 1;
    }

    return (result);
}
//---------------------


//---------------------
std::string toLowerCase() {
// varaiveis auxiliares 
  int index = 0;
  int lengh = text.length ( ); 
  std::string result = "";


// enquanto o index seja menor que o tamanho 
    while ( index < lengh ) {
        char current = text[index];

// verificao se em current contem caracteres maiusculas 
        if (current >= 'A' && current <= 'Z') {

//   Converter para minuscula
            current = current + 32;
        }

        result = result + current;
        index = index + 1;
    }

    return result;
}
//---------------------


//---------------------
std::string replace(char original, char novo) {
// variaveis auxiliares
    std::string result = "";
    int  index   = 0;
    bool changed = false;
    int lenght   = text.length( );


// enquanto index for menor que o tamanho 
    while (index < lenght ) {
        char current = text[index];

// verificao se current e igual ao caracter de original 
        if (current == original) {
// atibuicao de valores
            current = novo;
            changed = true;
        }

        result = result + current;
        index = index + 1;
    }

    if (!changed) {
        setErro(2);  // código de erro para "nenhuma ocorrencia encontrada"
    }

    return result;
}
//---------------------



//---------------------
std::string encrypt() {
// variaveis auxiliares
    std::string result = "";
    int index    = 0;
    int lenght   = text.length( );


// enquanto index for menor que o tamanho 
    while (index < lenght ) {
        char current = text[index];

// verificando se current e uma letra maiusucla 
        if (current >= 'A' && current <= 'Z') {

// " andando " com as palavras
            current = ((current - 'A' + 3) % 26) + 'A';

        } else {

// verificando se current e uma letra maiusucla 
            if (current >= 'a' && current <= 'z') {

// " andando " com as palavras
                current = ((current - 'a' + 3) % 26) + 'a';
            }
        }

        result = result + current;
        index = index + 1;
    }

    return result;
}
//---------------------


//---------------------
std::string decrypt() {
// variaveis auxiliares
    std::string result = "";
    int index    = 0;
    int lenght   = text.length( );


// enquanto index for menor que o tamanho 
    while (index < lenght ) {
        char current = text[index];

// verificando se current e uma letra maiusucla 
        if (current >= 'A' && current <= 'Z') {

// " voltando " com as palavras
            current = ((current - 'A' - 3 + 26) % 26) + 'A';
        } else {

// verificando se current e uma letra minuscula 
            if (current >= 'a' && current <= 'z') {

// " voltando " com as palavras            
                current = ((current - 'a' - 3 + 26) % 26) + 'a';
            }
        }

        result = result + current;
        index = index + 1;
    }

    return (result);
}
//---------------------


//---------------------
int split(std::string sequencia[]) {
// variaveis auxiliares
    int quantidade   = 0;
    int index        = 0;
    std::string temp = "";
    int lenght       = text.length( );


// enquanto index for menor que o tamanho 
    while (index < lenght ) {
        char current = text[index];

// verificao de espaco em branco
        if (current != ' ') {

            temp = temp + current;

        } else {
// vairiavel auxiliar para o tamanho temp 
        int temp_lenght = temp.length();

// condicao caso o tamnho seja valido
            if (temp_lenght > 0) {

// adicina a letra de temp na string "sequeincia"
                sequencia[quantidade] = temp;
                quantidade = quantidade + 1;
                temp = "";
            }
        }

        index = index + 1;
    }

// vairiavel auxiliar para o tamanho temp 
    int temp_lenght = temp.length();

    if (temp_lenght > 0) {
// adiciona o valor de sequencia para temp
        sequencia[quantidade] = temp;
        quantidade = quantidade + 1;
    }

    if (quantidade == 0) {
        setErro(3);  // código de erro para "nenhuma sequencia encontrada"
    }

    return quantidade;
}
//---------------------


//---------------------
int splitByDelimiter(char delimiter, std::string sequencia[]) {
// variaveis auxiliares
    int quantidade   = 0;
    int index        = 0;
    std::string temp = "";
    int lenght       = text.length( );


// enquanto index for menor que o tamanho 
    while (index < lenght ) {
        char current = text[index];

// condicao caso current e delimiter nao sejam iguais
        if (current != delimiter) {
            temp = temp + current;
        } else {
// vairiavel auxiliar para o tamanho temp 
    int temp_lenght = temp.length();

            if (temp_lenght > 0) {
// sequencia vai receber os valores de temp
                sequencia[quantidade] = temp;
                quantidade = quantidade + 1;
// temp sera "zerado"
                temp = "";
            }
        }

        index = index + 1;
    }

// vairiavel auxiliar para o tamanho temp 
    int temp_lenght = temp.length();

    if (temp_lenght > 0) {

// sequencia vai receber os valores de temp
        sequencia[quantidade] = temp;
        quantidade = quantidade + 1;
    }

    if (quantidade == 0) {
        setErro(4);  // Erro: Nenhuma sequencia encontrada com o delimitador
    }

    return quantidade;
}
//---------------------


//---------------------
std::string reverse() {
    std::string result = "";
    int index = text.length() - 1;

// enquanto index for menor ou igual a 0
    while (index >= 0) {
// atribui o valor para result
        result = result + text[index];
        index = index - 1;
    }

    return result;
}
// ----------------------------------------------- atualizacoes propostos pelo Ed_15 


//---------------------
/**
 * Function to calculate the length of a character array (C-string)
 * without using libraries.
 * @param text - pointer to character array
 * @return number of characters before null terminator
 */
int getLength() {
    int length = 0;
    while (text[length] != '\0' && text[length] != 0) {
        length = length + 1;
    }
    return length;
}


/**
 * Método para obter o conteúdo atual da cadeia de caracteres.
 * @return texto armazenado
 */
string getText() {
    return text;
}


//---------------------


//--------------------- end public
}; // end classe MyString 


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
char* str_push_back(char *s, char c) {
// vairiaveis auxiliareis 
    int length = 0;
    int index  = 0;


// calcular o tamanho da string manualmente
    while (s[length] != '\0') {
        length = length + 1;
    }

// adicionar caractere ao final
    s[length] = c;
    s[length + 1] = '\0';

    return s;
}
//---------------------


//---------------------
/** 
   Method_01 - Testar definicoes da classe. 
 */ 
void method_01 ( ) 
{
// identificar
    cout << "\nMethod_01 - v1.0\n" << endl;

// definir dados
    char text[Max] = "";// -> tamanho maximo 100 
    char letter;

// ler valor
    cout << "Digite uma cadeia de caracteres (sem espaços): ";
    cin >> text;

    cout << "Digite um caractere para acrescentar: ";
    cin >> letter;

// testar
    str_push_back(text, letter);

// mostrar resultado
    cout << "Resultado: " << text << endl;

// encerrar
    pause("Apertar ENTER para continuar");
} // end method_01 ( ) 
//---------------------


//---------------------
char* str_pop_back( char *s ) {
    int length = 0;

// calcular tamanho da string
    while (s[length] != '\0') {
        length = length + 1;
    }

// condicao que preve caso o valor seja maior que 0
    if (length > 0) {
        s[length - 1] = '\0';
    } else {
        std::cout<<"Valor indisponivel, menor que 0."<<endl;
    }

    return ( s );
}
//---------------------



//---------------------
void method_02 ( void ) {
// identificar
   cout << "\nMethod_02 - v0.0\n" << endl;

// definir dados
    char text[Max] = "";// - > tamanho maximo 100

// ler valor
    cout << "Digite uma cadeia de caracteres (sem espaços): ";
    cin >> text;

// testar
    str_pop_back(text);

// mostrar resultado
    cout << "Resultado: " << text << endl;

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
char* str_push_front(char c, char* s) {
//varivaies axuliares 
    int size = 0;

// lendo ate encontrar o \0 
    while ( s[ size ] != '\0' &&  s[ size ] != 0) {
        size = size + 1;
    }

// deslocar para direita (de tras para frente)
    int i = size;
    while (i > 0) {
        s[i] = s[i - 1];
        i = i - 1;
    }

// inserir novo caractere
    s[0] = c;
    s[size + 1] = '\0'; // novo final

    return ( s );
}
//---------------------
 

// ---------------------
void method_03(void) {
// identificar
    cout << "\nMethod_03 - v0.0\n" << endl;

// definir dados
    MyString *s = new MyString(); // -> reserva o tamanho para de uma string com o tamanho do objeto da classe 

// ler valor
    cout << "Digite um texto: ";
    string input;
    cin.ignore(); // limpar buffer
    getline(cin, input);

    s->setText(input);

// obter texto como vetor de caracteres
    std::string str = s->getText();
    char* pointer   = &str[0]; 

// ler caractere a ser adicionado
    char symbol = ' ';
    cout << "Digite um caractere para colocar no início: ";
    cin >> symbol;

// inserir caractere na frente
    pointer = str_push_front(symbol, pointer);

// atualizar texto na classe
    s->setText(pointer);

// mostrar resultado
    cout << "Texto atualizado: " << s->getText() << endl;

// encerrar
    pause("Apertar ENTER para continuar");
}
// ---------------------


// ---------------------
/**
 * Function to remove the first character from a string using a pointer.
 * @return pointer to the updated string (or empty string)
 * @param s - pointer to the character string
 */
char* str_pop_front(char* s) {
    // auxiliary variables
    int length = 0;

    // calculate length of the string (physical check for end)
    while (s[length] != '\0' && s[length] != 0) {
        length = length + 1;
    }

    // shift characters to the left, starting from index 1
    int index = 0;
    while (index < length) {
        s[index] = s[index + 1];
        index = index + 1;
    }

    return s;
}
// ---------------------


// ---------------------
void method_04(void) {
// identificar
    cout << "\nMethod_04 - v0.0\n" << endl;

// definir dados
    MyString* s = new MyString();

// ler valor
    cout << "Escreva o texto: ";
    string input;
    cin.ignore(); // limpar buffer

    getline(cin, input);

// armazenar texto
    s->setText(input);

// converter o conteudo para um array de char
    char array[ Max ]; 
    strcpy(array, s->getText().c_str());

// remover o primeiro caractere
    char* result = str_pop_front(array);

// atualizar texto na classe
    s->setText(result);

// mostrar resultado
    cout << "novo texto: " << s->getText() << endl;

// encerrar
    pause("Apertar ENTER para continuar");
}
// ---------------------


// ---------------------
/**
 * Funcao para inserir caractere no meio (aproximadamente)
 * de uma cadeia de caracteres, por meio de apontador,
 * se houver pelo menos dois caracteres.
 * @return apontador para a cadeia atualizada
 * @param s - apontador para cadeia de caracteres
 * @param c - caractere a ser inserido
 */
char* str_push_mid(char* s, char c) {
// varaivel auxiliares
    int length = 0;

// Contar o tamanho da string
    while (s[length] != '\0') {
        length = length + 1 ;
    }

// condicao caso tiver  pelo menos dois caracteres
    if (length >= 2) {
        int mid = length / 2; // a posicao aproximada do meio

// mover os caracteres para a direita para abrir espaço
        for (int i = length; i > mid; i = i - 1 ) {
            s[i] = s[i - 1];
        }

// inserir o caractere no meio
        s[mid] = c;

// finalizar a string
        s[length + 1] = '\0';
    }

    return ( s );
}

//---------------------


void method_05(void) {
// identificar
    cout << "\nMethod_05 - v0.0\n" << endl;

// definir dados
    MyString* s = new MyString();

// ler valor
    cout << "Enter a text: ";
    string input;
    cin.ignore();

    getline(cin, input);

// armazenar texto
    s->setText(input);

// ler caractere a ser inserido
    char c;
    cout << "Escreva o texto: "<<endl;
    cin >> c;

// converter string para char* (com espaço extra caso precise inserir caractere)
    string temp = s->getText();
    char* pointer = new char[temp.length() + 2];  // +2 por segurança (1 para o novo char e 1 para o '\0')
    strcpy(pointer, temp.c_str());

// chamada da funcao de insercao no meio 

    char* result = str_push_mid(pointer, c);

// atualizar texto na classe
    s->setText(result);

// liberar memoria
    delete[] pointer;

// mostrar resultado
    cout << "Texto atualizado: " << s->getText() << endl;

// encerrar
    pause("Apertar ENTER para continuar");
}



//---------------------
/**
 * Funcao para remover caractere do meio (aproximadamente)
 * de uma cadeia de caracteres, por meio de apontador.
 * Se houver ao menos dois caracteres, remover o primeiro.
 * @return apontador para a cadeia atualizada
 * @param s - apontador para cadeia de caracteres
 */
char* str_pop_mid(char* s) {
// inicializando auxiliares
    int length = 0;

// adicionando o tamanho da string
   while (s[length] != '\0' && s[length] != 0) {
        length = length + 1 ;
    }

// se houver pelo menos dois caracteres
    if (length >= 2) {
        int mid = length / 2; // a posicao aproximada do meio

// deslocar os caracteres para a esquerda
        for (int i = mid; i < length; i = i + 1 ) {
            s[i] = s[i + 1];
        }
    }

    return (s);
}
//---------------------




//---------------------
void method_06(void) {
// identificar
    cout << "\nMethod_06 - v0.0\n" << endl;

// definir dados
    MyString* s = new MyString();

// ler valor
    cout << "Escreva o texto: "<<endl;

    string input;
    cin.ignore(); // limpar o buffer de entrada

    getline(cin, input);

// armazenar texto
    s->setText(input);

// converter string para char* (com espaço suficiente)
    string temp = s->getText();
    char* pointer = new char[temp.length() + 1];  // +1 para o '\0'
    strcpy(pointer, temp.c_str());

// remover o caractere do meio
    char* result = str_pop_mid(pointer);

// atualizar o texto na classe
    s->setText(result);

// liberar meoria
    delete[] pointer;

// mostrar resultado
    cout << "Texto atualizado: " << s->getText() << endl;

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
/**
 * Funcao para inserir caractere em certa posição válida
 * de uma cadeia de caracteres, por meio de apontador.
 * @return  apontador para a cadeia atualizada
 * @param s - apontador para cadeia de caracteres
 * @param c - caractere a ser inserido
 * @param index - posição onde inserir
 */
char* str_insert(char* s, char c, int index) {
// calcular tamanho da string
    int length = 0;
    while (s[length] != '\0' && s[length] != 0) {
        length = length + 1 ;
    }

// verificar se o índice é válido
    if (index < 0 || index > length) {
        return s; // posição inválida, retornar string original
    }

// deslocar os caracteres para a direita
    for (int i = length; i >= index; i = i - 1 ) {
        s[i + 1] = s[i];
    }

    // inserir o caractere
    s[index] = c;

    return (s);
}
//---------------------


//---------------------
void method_07(void) {
// identificar
    cout << "\nMethod_07 - v0.0\n" << endl;

// definir dados
    MyString* s = new MyString();

// ler valor
    cout << "Escreva o texto: "<<endl;
    string input;
    cin.ignore(); // limpar o buffer de entrada

    getline(cin, input);

// armazenar texto
    s->setText(input);

// ler caractere a ser inserido
    char c;
    cout << "Digite o caracter para achar-lo: ";
    cin >> c;

// ler posição de inserção
    int index;
    cout << "Digite a posicao: ";
    cin >> index;

// converter string para char*
    string temp = s->getText();
    char* pointer = new char[temp.length() + 2];  // +2 para o novo char e o '\0'
    strcpy(pointer, temp.c_str());

// chamar a função de inserção
    char* result = str_insert(pointer, c, index);

// atualizar o texto na classe
    s->setText(result);

// liberar memoria
    delete[] pointer;

// mostrar resultado
    cout << "Texto atualizado: " << s->getText() << endl;

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
/**
 * Funcao para remover caractere de certa posição válida
 * de uma cadeia de caracteres, por meio de apontador.
 * @return  apontador para a cadeia atualizada
 * @param s - apontador para cadeia de caracteres
 * @param index - posição de onde remover
 */
char* str_remove(char* s, int index) {
// calcular tamanho da string
    int length = 0;
    while (s[length] != '\0') {
        length = length + 1;
    }

// verificar se o índice é válido
    if (index < 0 || index >= length) {
        return s; 
    }

    // deslocar os caracteres para a esquerda, sobrescrevendo o que vai ser removido
    for (int i = index; i < length; i++) {
        s[i] = s[i + 1];
    }

    return s;
}
//---------------------




//---------------------
void method_08(void) {
// identificar
    cout << "\nMethod_08 - v0.0\n" << endl;

// definir dados
    MyString* s = new MyString();

// ler valor
    cout << "Escreva o texto: "<<endl;
    string input;
    cin.ignore(); // limpar o buffer de entrada
    getline(cin, input);

// armazenar texto
    s->setText(input);

// ler posicao para remocao
    int index;
    cout << "Digite a posicao para retirar: ";
    cin >> index;

// converter string para char*
    string temp = s->getText();
    char* pointer = new char[temp.length() + 1];  // +1 para o '\0'
    strcpy(pointer, temp.c_str());

// chamar a funcao de remocao
    char* result = str_remove(pointer, index);

// atualizar o texto na classe
    s->setText(result);

// liberar meoria
    delete[] pointer;

// mostrar resultado
    cout << "Texto atualizado: " << s->getText() << endl;

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
char* str_chr(char* s, char c) {
// iniciando variavel aux
    int i = 0;

// laco de repeticao ( verificao logica e fisica )
    while (s[i] != '\0' && s[i] != 0) {

// condicao que preve se c esta no arranjo de s
        if (s[i] == c) {
            return &s[i];  // retorna ponteiro para a ocorrência
        }

// incrementacao do i 
        i = i + 1 ;
    }

    return null; // caso nao tiver achado 
}
//---------------------


//---------------------
void method_09(void) {
// identificar
    cout << "\nMethod_09 - str_chr - v0.0\n" << endl;

// definir dados
    MyString* s = new MyString();

// ler valor
    cout << "Escreva o texto: "<<endl;
    string input;
    cin.ignore();

    getline(cin, input);

// armazenar texto
    s->setText(input);

// ler posicao para achar
    cout << "Digite o caractere para encontrar ele no arranjo: ";
    char c;
    cin >> c;

// obter ponteiro para texto
    char* pointer = (char*) s->getText().c_str();

    char* found = str_chr(pointer, c);

    if (found != null) {
        cout << "Caractere '" << c << "' encontrada na posiacao: "       << (found - pointer) << endl;
    } else {
        cout << "Caractere '" << c << "' a palavra nao foi encontrada." << endl;
    }

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
char* str_tok(char* s, char delimiter) {
// iniciando var aux
    int i = 0;

// laco de repeticao ( verificao logica e fisica )
    while ( s [ i ]  !=  '\0'  &&  s [ i ]  !=  0 ) {

// condicao que preve caso delimiter esteja no arranjo 
        if (s[i] == delimiter) {
            s[i] = '\0';    // substitui delimitador por fim de string
            return (s);     // retorna início da string modificada
        }

        i = i + 1 ;
    }
// caso delimitador nao tenha sido encontrado
    return null; 
}
//---------------------


//---------------------
void method_10(void) {
// identificar
    cout << "\nMethod_10 - str_tok - v0.0\n" << endl;

// definir dados
    MyString* s = new MyString();

// ler valor
    cout << "Escreva o texto: "<<endl;
    string input;
    cin.ignore();

    getline(cin, input);

// adicionando o texto a s
    s->setText(input);

// ler posicao para achar
    cout << "Escreva o delimitador: ";
    char delimiter;
    cin >> delimiter;

// obter ponteiro para texto
    char* pointer = (char*) s->getText().c_str();
    
// chamada da funcao e atribuicao para token
    char* token = str_tok(pointer, delimiter);

// condicao que preve existencia 
    if (token != null) {
        cout << "Texto antes do delimitador: " << token                           << endl;
    } else {
        cout << "Delimitado '"                << delimiter << "' nao foi achado." << endl;
    }
// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
char* str_prefix(char* prefix, char* s) {
// iniciando var aux
    int i = 0;

// laco de repeticao ( verificao logica e fisica )
    while (prefix[i] != '\0' && prefix[i] != 0 && s[i] != '\0' && s[i] != 0) {

// se algum caractere for diferente, nao prefixo
        if (prefix[i] != s[i]) {

            return null; 

        }

        i = i + 1 ;
    }

// Se percorreu todo o prefixo sem erro, entao e prefixo
    if ( prefix[ i ]  ==  '\0'  ||  prefix[ i ]  ==  0 ) {

// retorna o ponteiro para o inicio da string onde encontrou o prefixo
        return (s);  
    }
    
// caso contrario
    return null; 
}
//---------------------



//---------------------
void method_11(void) {
// identificar
    cout << "\nMetodo_11 - str_prefix - v1.0\n" << endl;

// definir dados
    MyString* s = new MyString();

    cout << "Digite o texto: ";
    string input;
    cin.ignore();
    getline(cin, input);

    s->setText(input);

    cout << "Escreva  o prefixo: ";
    string prefixInput;
    getline(cin, prefixInput);

// Preparar buffers char[]
    char text[100];
    char prefix[100];
    
//chamada da funcao
    strcpy(text, s->getText().c_str());
    strcpy(prefix, prefixInput.c_str());


    char* result = str_prefix(prefix, text);

    if (result != nullptr) {
        cout << "prefixo encontrando!"   << endl;
    } else {
        cout << "prefixo nao encontrar." << endl;
    }

    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
char* str_suffix(char* s, char* suffix) {
    // calcular tamanho das duas strings
    int lenS      = 0;
    int lenSuffix = 0;

    while (s[lenS] != '\0' && s[lenS] != 0) lenS++;
    while (suffix[lenSuffix] != '\0' && suffix[lenSuffix] != 0) lenSuffix++;

    // se o sufixo for maior que a string, não tem como
    if (lenSuffix > lenS) {
        return nullptr;
    }

    int start = lenS - lenSuffix;
    int i = 0;

    while (suffix[i] != '\0' && suffix[i] != 0) {
        if (s[start + i] != suffix[i]) {
            return nullptr;  // se um caractere for diferente, não é sufixo
        }
        i++;
    }

    return &s[start];  // retorna ponteiro para onde começa o sufixo
}
//---------------------


//---------------------
void method_12(void) {
    cout << "\nMethod_12 - str_suffix - v0.0\n" << endl;

    MyString* s = new MyString();

    cout << "Digite o texto: ";
    string input;
    cin.ignore();
    getline(cin, input);
    s->setText(input);

    cout << "Escreva o sufixo: ";
    string suffixInput;
    getline(cin, suffixInput);

    // Preparar buffers char[]
    char text[100];
    char suffix[100];
    strcpy(text, s->getText().c_str());
    strcpy(suffix, suffixInput.c_str());

    char* result = str_suffix(text, suffix);

    if (result != nullptr) {
        cout << "Sufixo na posicao: " << (result - text) << endl;
    } else {
        cout << "Sufixo nao encontrado." << endl;
    }

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