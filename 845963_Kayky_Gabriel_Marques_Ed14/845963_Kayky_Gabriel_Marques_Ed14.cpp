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
public: 

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
/** 
   Method_01 - Testar definicoes da classe. 
 */ 
void method_01 ( ) 
{ 
 // definir dados 
    MyString *s = new MyString ( ); 
 
 // identificar 
    cout << "\nMethod_01 - v0.0\n" << endl; 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_01 ( ) 
//---------------------


//---------------------
void method_02 ( void ) {
    cout << "\nMethod_02 - v0.0\n" << endl;

    string input = "";
    cout << "Digite um texto numerico: ";
    cin.ignore();
    getline(cin, input);

    MyString* s = new MyString(input);

    int value = s->getInt();

    cout << "Valor inteiro: " << value << endl;
    cout << "Codigo de erro: " << s->getErro() << endl;

    delete ( s );

    pause("Apertar ENTER para continuar");
}
//---------------------
 

//--------------------- 
void method_03( void ) {
// identificar
    cout << "\nMethod_03 - v0.0\n" << endl;

// definir dados
    MyString *s = new MyString();

// ler valor
    cout << "Digite um texto (true, false, T, F, 1, 0): ";
    string input;
    cin.ignore(); // limpar buffer
    getline(cin, input);

    s->setText (input);

// testar
    bool result = s->getBoolean();

// mostrar resultado
    cout << "Valor booleano: " << (result ? "true" : "false") << endl;
    cout << "Codigo de erro: " << s->getErro() << endl;
    cout << "Mensagem: " << s->getErroMsg() << endl;

    // encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
void method_04( void ) {
// identificar
    cout << "\nMethod_04 - v0.0\n" << endl;

// definir dados
    MyString *s = new MyString();

// ler texto principal
    cout << "Digite o texto principal: ";
    string input;
    cin.ignore(); // limpar buffer

    getline(cin, input);
    s->setText(input);

// ler subtexto
    cout << "Digite o subtexto: ";
    string subtext;
    getline(cin, subtext);

// testar
    bool result = s->contains(subtext);

// mostrar resultado
    cout << "Subtexto encontrado? " << (result ? "Sim" : "Nao") << endl;
    cout << "Codigo de erro: "      << s->getErro( )            << endl;
    cout << "Mensagem: "            << s->getErroMsg( )         << endl;

    // encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
void method_05( void ) {
// identificar
    cout << "\nMethod_05 - v0.0\n" << endl;

// definir dados
    MyString *s = new MyString();

// ler valor
    cout << "Digite um texto: ";
    string input;
    cin.ignore(); // limpar buffer
    getline(cin, input);

    s->setText(input);

// converter
    string result = s->toUpperCase();

// mostrar resultado
    cout << "Texto em maiusculas: " << result                   << endl;
    cout << "Codigo de erro: "      << s->getErro( )            << endl;
    cout << "Mensagem: "            << s->getErroMsg( )         << endl;

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
void method_06( void ) {
// identificar
    cout << "\nMethod_06 - v0.0\n" << endl;

// definir dados
    MyString *s = new MyString();

// ler valor
    cout << "Digite um texto: ";
    string input;

    cin.ignore(); // limpar buffer
    getline(cin, input);

    s->setText(input);

// converter
    string result = s->toLowerCase();

// mostrar resultado
    cout << "Texto em minusculas: " << result                   << endl;
    cout << "Codigo de erro: "      << s->getErro( )            << endl;
    cout << "Mensagem: "            << s->getErroMsg( )         << endl;

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
void method_07( void ) {
// identificar
    cout << "\nMethod_07 - v0.0\n" << endl;

// definir dados
    MyString *s = new MyString( );
    string input;
    char original = ' ';
    char new_     = ' ';

// ler valor
    cout << "Digite um texto: ";
    cin.ignore();
    getline(cin, input);

    s->setText(input);

// atribuindo valor
    cout << "Digite o caractere a ser substituido: ";
    cin >> original;

    cout << "Digite o novo caractere: ";
    cin >> new_;

 // converter   
    string result = s->replace ( original, new_ );

// mostrar resultado
    cout << "Texto resultante: "    << result                   << endl;
    cout << "Codigo de erro: "      << s->getErro( )            << endl;
    cout << "Mensagem: "            << s->getErroMsg( )         << endl;

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
void method_08( void ) {
// identificar
    cout << "\nMethod_08 - v0.0\n" << endl;

// definir dados
    MyString *s = new MyString();
    string input;

// ler valor
    cout << "Digite um texto: ";
    cin.ignore();
    getline(cin, input);

    s->setText(input);

 // converter   
    string result = s->encrypt();

// mostrar resultado
    cout << "Texto codificado (Cifra de Cesar): "   << result                   << endl;
    cout << "Codigo de erro: "                      << s->getErro( )            << endl;
    cout << "Mensagem: "                            << s->getErroMsg( )         << endl;

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
void method_09( void ) {
// identificar
    cout << "\nMethod_09 - v0.0\n" << endl;

// definir dados
    MyString *s = new MyString();
    string input;

// ler valor
    cout << "Digite um texto codificado (Cifra de Cesar): ";
    cin.ignore();
    getline(cin, input);

    s->setText(input);

// converter   
    string result = s->decrypt();

// mostrar resultado
    cout << "Texto decodificado: "                  << result                   << endl;
    cout << "Codigo de erro: "                      << s->getErro( )            << endl;
    cout << "Mensagem: "                            << s->getErroMsg( )         << endl;

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
void method_10( void ) {
// identificar  
    cout << "\nMethod_10 - v0.0\n" << endl;

// definir dados
    MyString *s = new MyString();
    string input;
    string palavras[100];  // - >  limite max  100 palavras
    int quantidade = 0;
    int index      = 0;

// ler valor
    cout << "Digite um texto: ";
    cin.ignore();
    getline(cin, input);

    s->setText(input);

// converter   
    quantidade = s->split(palavras);

// mostrar resultado
    cout << "Quantidade de palavras encontradas: " << quantidade << endl;

    index = 0;
    while (index < quantidade) {
        cout << "Palavra [" << index << "]: "       << palavras[index]          << endl;
        index = index + 1;
    }

    cout << "Codigo de erro: "                      << s->getErro( )            << endl;
    cout << "Mensagem: "                            << s->getErroMsg( )         << endl;

// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
void method_11( void ) {
// identificar  
    cout << "\nMethod_11 - v0.0\n" << endl;

// definir dados
    MyString *s = new MyString();
    std::string input;
    std::string palavras[100];
    int quantidade = 0;
    int index = 0;
    char delimiter;

// ler valor
    cout << "Digite um texto: ";
    cin.ignore();
    getline(cin, input);

    s->setText(input);

    cout << "Digite o delimitador: ";
    cin >> delimiter;

// converter   
    quantidade = s->splitByDelimiter(delimiter, palavras);

// mostrar resultado
    cout << "Quantidade de sequencia encontradas: " << quantidade << endl;

    index = 0;
    while (index < quantidade) {
        cout << "Sequencia [" << index << "]: "     << palavras[index]          << endl;
        index = index + 1;
    }

    cout << "Codigo de erro: "                      << s->getErro( )            << endl;
    cout << "Mensagem: "                            << s->getErroMsg( )         << endl;
 
// encerrar
    pause("Apertar ENTER para continuar");
}
//---------------------


//---------------------
void method_12() {
// identificar  
    cout << "\nMethod_12 - v0.0\n" << endl;

// definir dados
    MyString *s = new MyString();
    std::string input;

// ler valor
    cout << "Digite um texto: ";
    cin.ignore();
    getline(cin, input);

    s->setText(input);

// converter   
    std::string result = s->reverse();

// mostrar resultado
    cout << "Texto invertido: "                     << result                   << endl;
    cout << "Codigo de erro: "                      << s->getErro( )            << endl;
    cout << "Mensagem: "                            << s->getErroMsg( )         << endl;
 
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
