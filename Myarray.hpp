/* 
   myarray.hpp   - v0.0. - __ / __ / _____ 
   Author: ______________________ 
*/ 
 
// ----------------------------------------------- definicoes globais 
 
#ifndef  _MYARRAY_HPP_ 
#define  _MYARRAY_HPP_ 
 
// dependencias 
 
#include <iostream> 
   using std::cin  ;  // para entrada 
   using std::cout;  // para saida 
   using std::endl;  // para mudar de linha 
   
   #include <iomanip> 
   using std::setw;   // para definir espacamento 
   
   #include <string> 
   using std::string;   // para cadeia de caracteres 
   
   #include <fstream> 
   using std::ofstream;   // para gravar arquivo 
   using std::ifstream ;   // para ler       arquivo 
   #define null nullptr	

template < typename T > 
class Array 

{
//P_01 ---------------------

  private:   // area reservada 
   
    T   optional; 
    int   length; 
    T      *data; 
 

  public:   // area aberta 

//P_02 ---------------------
    Array ( int n, T initial ) 
    { 
     // definir valores iniciais 
        optional   = initial; 
        length     = 0; 
        data       = nullptr; 
 
     // reservar area 
        if ( n > 0 ) 
        { 
             length   = n; 
             data     = new T [ length ]; 
        } 
    } // end constructor 

//---------------------


//P_03 ---------------------
    void free ( ) 
    { 
       if ( data != nullptr ) 
       { 
          delete ( data ); 
           data = nullptr; 
       } // end if 
    } // end free ( ) 

//---------------------


//P_04 --------------------- 
   void set ( int position, T value ) 
    { 
      if ( 0 <= position && position < length ) 
      { 
         data [ position ] = value; 
      } // end if 
    } // end set ( ) 

//---------------------


//P_05 ---------------------
    T    get ( int position ) 
    { 
      T value = optional; 
 
      if ( 0 <= position && position < length ) 
      { 
        value = data [ position ]; 
      } // end if 
 
      return ( value ); 
    } // end get ( ) 
//---------------------


//P_06 ---------------------
    void print ( void ) 
    { 
       cout << endl; 
       for ( int x = 0; x < length; x=x+1 ) 
       { 
           cout << setw( 3 ) << x << " : " 
                    << setw( 9 ) << data[ x ] 
                    << endl; 
       } // end for 
       cout << endl; 
    } // end print ( ) 
//---------------------


//P_07 ---------------------
void read ( ) 
    { 
       cout << endl; 
       for ( int x = 0; x < length; x=x+1 ) 
       { 
           cout << setw( 3 ) << x << " : "; 
           cin   >> data[ x ]; 
       } // end for 
       cout << endl; 
    } // end read ( )
//---------------------


//P_08 ---------------------
void fprint ( string fileName ) 
    { 
       ofstream afile;  // output file 
 
       afile.open ( fileName ); 
       afile << length << endl; 
       for ( int x = 0; x < length; x=x+1 ) 
       { 
           afile << data[ x ] << endl; 
       } // end for 
       afile.close ( ); 
    } // end fprint ( )
//---------------------


//P_09 ---------------------
void fread ( string fileName ) 
    { 
       ifstream afile; // input file 
       int n = 0; 
       afile.open ( fileName ); 
       afile >> n; 
       if ( n <= 0 ) 
       { 
          cout << "\nERROR: Invalid length.\n" << endl; 
       } 
       else 
       { 
        // guardar a quantidade de dados 
           length  = n; 
        // reservar area 
           data    = new T [ n ]; 
        // ler dados 
           for ( int x = 0; x < length; x=x+1 ) 
           { 
              afile >> data[ x ]; 
           } // end for 
       } // end if 
       afile.close ( ); 
    } // end fread ( )
//---------------------


//P_10 ---------------------
    Array ( )    // construtor padrao 
    { 
     // definir valores iniciais 
        length  = 0; 
     // reservar area 
        data     = nullptr; 
    } // end constructor 
 
     
    // contrutor baseado em copia 
    Array ( int length, int other [ ] ) 
    { 
       if ( length <= 0 ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
        // criar copia 
           this->length = length; 
        // reservar area 
           data   = new T [ this->length ]; 
        // ler dados 
           for ( int x = 0; x < this->length; x=x+1 ) 
           { 
               data [ x ] = other [ x ]; 
           } // end for 
       } // end if 
    } // end constructor ( )
//---------------------


//P_11 ---------------------
Array ( const Array &other ) 
    { 
       if ( other.length <= 0 ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
        // criar copia 
           length = other.length; 
        // reservar area 
           data    = new T [ other.length ]; 
        // ler dados 
           for ( int x = 0; x < length; x=x+1 ) 
           { 
               data [ x ] = other.data [ x ]; 
           } // end for 
       } // end if 
    } // end constructor ( ) 
//---------------------


//P_12 ---------------------
Array &operator= ( const Array < T > other ) 
    { 
       if ( other.length <= 0 ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
           this->length  = other.length; 
           this->data    = new T [ other.length ]; 

           for ( int x = 0; x < this->length; x=x+1 ) 
           { 
               data [ x ] = other.data [ x ]; 
           } // end for 
       } // end if 
       return ( *this ); 
    } // end operator= ( ) 
//---------------------


//P_13 ---------------------
bool operator== ( const Array <T> other ) 
    { 
       bool result = false; 
       int  x           = 0; 
 
       if ( other.length == 0 || length != other.length ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
          x = 0;  
          result = true; 
          while ( x < this->length && result ) 
          { 
              result = result &&  (data [ x ] == other.data [ x ] ); 
              x = x + 1; 
          } // end while 
       } // end if 
       return ( result ); 
    } // end operator== ( ) 
//---------------------

//P_14 ---------------------
Array& operator+ ( const Array <T> other ) 
    { 
       static Array <T> result ( other ); 
 
       if ( other.length <= 0 ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
          for ( int x = 0; x < this->length; x=x+1 ) 
          { 
              result.data [ x ] = result.data [ x ] + this->data [ x ]; 
          } // end for 
       } // end if 
       return ( result ); 
    } // end operator+ ( ) 
//---------------------


//P_14 ---------------------
const int getLength ( ) 

    { 
       return ( length ); 
    } // end getLength ( ) 
 

    T& operator[]( const int position ) 
    { 
       static T value = optional; 
 
       if ( position < 0 || length <= position ) 
       { 
          cout << endl << "\nERROR: Invalid position.\n" << endl; 
       } 
       else 
       { 
         value = data [ position ]; 
       } // end if 
       return ( value ); 
    } // end operator [ ]
//---------------------


//P_14 ---------------------
void  randomIntGenerate  (int N, T lower, T upper ) {

   //condicao de espaco fisico e logico
   if ( N <= 0 || lower < upper) {
      cout << "Erro, parametros invalidos."<< std::endl;
   }
   
   // atribuindo os valores 
   length = N; 
   data   = new T [ length ] ;

   // criando laco de repeticao 
      for (int i = 0; i < length; i = i + 1 ) {
      
      // prenechendo o indice com valores aleatorio 
      int value = ( lower + rand ( ) % ( upper - lower + 1 )) ;
      set ( i, value );
   } 

   // cria um novo arquivo 
      fprint ("DADOS1.TXT");  

}
//---------------------


//P_15 ---------------------
int searchFirstOdd ( ) {
   
   // iniciando variaveis
   int  biggest_number = 0; 
   bool find           = false;
   
   // laco de repeticao (vai de i a tamanho )
   for ( int i = 0;  i < length ; i = i + 1) {
   //condicao que preve se o valor e impar
      if ( data  [ i ] % 2 !=  0 ) {
   //condicao que preve a negacao do valor
         if ( ! find ) {
   // nova atribuicao de valor
            biggest_number = data [ i ];
            find           = true;

   // conficao de negacao ( caso nao passe da primeira )
         } else if ( data [ i ] > biggest_number  ) {
            biggest_number = data [ i ];
         }
      } 
   }

   // se find for verdade retorna o maior numero 
   if ( find ) {
      return ( biggest_number ) ; 
   // se nao
   } else { 
      cout << "Nao foi encontrado um valor impar"<< endl;
   }
}
//---------------------


//P_16 ---------------------
int searchFirstOddx3 ( ) {
  
   // iniciando variavel auxiliar 
      int target = 0; 
   // condicao de existencia e condicao de espaco do arranjo 
      if (data != null || length > 0 ) { 
   
   // laco de repeticao de 0 a lenght - 1 
      for (int i = 0; i < length; i = i + 1 ) {
   
   // condicao de valor impar  
      if ( data [ i ] % 2 != 0 ) {

   // verificao se o valor e multiplo de 3
         if ( data [ i ] % 3 == 0  ) {

   // atribuindo o valor 
            target = data [ i ] ; 

   // caso o valor de data i seja maior que "target"
         if ( target < data [ i ] ) {

            target = data [ i ]; 

         }    
      } 
   }             
}  // end for 

   // retorna alvo 
      return ( target );  

      } else {
         std::cout <<"Erro, o apontador esta aterrado ou seu tamanho e invalido"<< endl;
      }
}
//---------------------


//P_17 ---------------------
int readreadArrayFromFile ( string fileName ) { 
   //vai procurar o arquivo com o nome 
   ifstream file ( fileName ); 

   // condicao que verifica abertura
      if ( !file.is_open ( ) ) {
         
         cout << "Erro ao abrir arquivo"<< endl; 
         
         length = 0;
         
         data   = null;
      } 
   
   // tenta ler o tamanho
      if( ! ( file >> length  ) || length <= 0 ) { 
        
         std:: cout << "Erro, tamanho invalido";
                
         length = 0;
        
         data   = null;
   
   } 

   data = new T[ length ];

   for ( int i = 0; i < length; i = i + 1) {
      if (!(file >> data [ i ] )) {
         cout << "Erro ao tentar ler o elemento " << i << "do arquivo." <<endl;
            
         delete[] data;
         
         length = 0;
         
         data   = nullptr;
               
      }
   }

// Verifica se o arquivo terminou corretamente (sem lixo extra)
    if (!file.eof()) {
        string resto;
        file >> resto;
        if (!resto.empty()) {
            cout << "Aviso: há dados extras no arquivo que foram ignorados." << endl;
        }
    }

    file.close();
}
//---------------------


//P_18 ---------------------
int addInterval ( int first, int last ) {
   // iniciando var aux   
      int add = 0; 

   // condicao de existencia 
      if ( data != null ) {
   
   // condicao que previne que os valores seja maiores que o tamanho  ou seja 0 
      if (first <= 0 && last <= 0 && first < length && last < length ) 
      {
         cout<< "Erro, alguma das possicoes sao maiores que o proprio arranjo "<< endl;

      } else {

   // laco de repeticoa 
         for ( int i = first; i < last ; i = i + 1 ) { 
      
   // atribuindo o valor do intervalo  
            add += data [ i ]; 

         } // end for

      } // end else 

   // caso ponteiro esteja aterrado 
      } else {
         cout << "Erro, ponteiro aterrado." <<endl;
      }

   return ( add );
}
//---------------------


//P_19 ---------------------
int averageInterval ( int first, int last ) {
   // iniciando var aux   
      int add         = 0; 
      int count       = 0;
      int new_value   = 0;

   // condicao de existencia 
      if ( data != null ) {
   
   // condicao que previne que os valores seja maiores que o tamanho  ou seja 0 
      if (first <= 0 && last <= 0 && first < length && last < length ) 
      {
         cout<< "Erro, alguma das possicoes sao maiores que o proprio arranjo "<< endl;

      } else {

   // laco de repeticoa
         for ( int i = first; i < last ; i = i + 1 ) { 
      
   // atribuindo o valor do intervalo  
            add += data [ i ]; 
            cout << add <<endl;

   // incrementando o valor de i a cada "rodada"
            count = count + 1;
            cout << count <<endl;

      } // end for

   // operacao ( calcular a media )
       new_value = add / count ;

   } // end else 

   // caso ponteiro esteja aterrado 
      } else {
         cout << "Erro, ponteiro aterrado." <<endl;
      }

   return ( new_value );
}
//---------------------


//P_20 ---------------------
bool negatives ( ) {
  
   // iniciando variavel auxiliar 
      bool target = true; // -> variavel iniciada sendo verdade

   // condicao de existencia e condicao de espaco do arranjo 
      if (data != null && length > 0 ) { 
   
   // laco de repeticao de 0 a lenght - 1 
      for ( int  i  =  0 ;  i  <  length ;  i  =  i  +  1 ) {
            
      if ( data [ i ]  <=  0  ||  data [ i ]  <=  100 ) {
          target = false;  // Se algum for invalido, marca como falso

            }
        }

    } else {
        std::cout << "Erro: arranjo vazio ou ponteiro inválido." << std::endl;
        target = false;
    }

   // retorna alvo 
      return ( target );  
}
//---------------------

//P_21 ---------------------
bool isDecrescent ( ) {
  
   // iniciando variavel auxiliar 
      bool target = true; // -> variavel iniciada sendo verdade

   // condicao de existencia e condicao de espaco do arranjo ( precisa de ter um tamanho maior que um para sua comparacao
      if (data != null && length > 1 ) { 
   
   // primeiro laço de repeticao 
      for (int i = 0; i < length - 1 ; i = i + 1  ) { 
      
           int tempt = i + 1; // -> valor temporario que e sempreo valor de i mais 1

   // condicao que preve se o primeiro valor e menor que o segundo 
            if ( data [ i ] < data [ tempt ] ) {
               target = false; // -> caso passe na condicao, se tornarar falso

         }
      }

    } else {
        std::cout << "Erro: arranjo vazio ou ponteiro inválido." << std::endl;
        target = false;
    }

   // retorna alvo 
      return ( target );  
}
//---------------------

//P_22 ---------------------
int searchInterval ( int target, int start, int end ) {
   // inicinado valor  
      bool found = false; // -> found foi inicializado como falso 

   // condicao de existencia 
         if (length > 0 && data != null ) { // -> preve se o tamanho do arranjo e nulo e se o ponteiro e nulo 

   // verificao se dos tamanho de inicio, se sao maiores que 0 ou se o inicio maior que o fim  ou se o final e menor que o inicio (erro logico)
            if (start >= 0 && end >= 0
                && start <= end  && end < length) {

   // laço de repeticao i comeca no inicio e vai ate o end 
               for (int i = start; i <= end; i = i + 1) {

   // condicao que preve o o valor do indice do arranjo esta presente                
                  if (data[i] == target) {

   // caso estiver, found tem seu valor para verdade
                        found = true;
                  }
               }

            } else { // caso o intervalo nao seja invalido 
                  std::cout << "Erro: Intervalo invalido." << std::endl;
            } 
         } else {
            std::cout << "Erro: arranjo vazio ou ponteiro invalido." << std::endl;
         }

         return ( found );
         }
//---------------------


//P_23 ---------------------
Array <int> scalar(int constant, int start, int end) {
    Array<int> result(length);

    if (data != null && length > 0) {

        if (start >= 0 && end < length && start <= end) {
            for (int i = 0; i < length; i = i + 1) {
                if (i >= start && i <= end) {
                    result.set(i, data[i] * constant);  // multiplica dentro do intervalo
                } else {
                    result.set(i, data[i]);  // mantém fora do intervalo
                }
            }
        } else {
            std::cout << "Erro: intervalo invalido." << std::endl;
        }
    } else {
        std::cout << "Erro: ponteiro aterrado ou arranjo vazio." << std::endl;
    }

    return result;
}
//---------------------

//P_24 ---------------------
void sortDown() {
    if (data != nullptr && length > 1) {
        for (int i = 0; i < length - 1; i = i + 1) {
            for (int j = 0; j < length - i - 1; j = j + 1) {
                if (data[j] < data[j + 1]) {
                    // Troca os elementos para ordem decrescente
                    int temp     = data[j];
                    data[j]      = data[j + 1];
                    data[j + 1]  = temp;
                }
            }
        }
    } else {
        std::cout << "Erro: arranjo vazio ou com tamanho inválido." << std::endl;
    }
}
//---------------------


//P_24 ---------------------
bool isDifferent(const Array<int>& other) {
    // Verificar se os tamanhos são diferentes
    if (this->length != other.length) {
        return true;
    }

    // Verificar se há pelo menos uma posição com valores diferentes
    for (int i = 0; i < this->length; i++) {
        if (this->data[i] != other.data[i]) {
            return true;
        }
    }

    // Nenhuma diferença encontrada
    return false;
}
//---------------------


//P_25 ---------------------
bool operator!=(const Array<int>& other) const {
    if (this->length != other.length) {
        return true;
    }

    for (int i = 0; i < this->length; i++) {
        if (this->data[i] != other.data[i]) {
            return true;
        }
    }

    return false;
}
//---------------------


//P_26 ---------------------
Array<int> differences(Array<int> other) {
    Array<int> result(0, 0); // Initialize with a dummy size, will be reallocated if sizes match

    // Verificar se os tamanhos são iguais
    if (length == other.length && data != nullptr && other.data != nullptr) {
        // Criar novo arranjo com mesmo tamanho
        result = Array<int>(length, 0); // Corrected line: Use constructor to set length

        for (int i = 0; i < length; i = i + 1) {
            result.set(i, data[i] - other.data[i]);
        }
    } else {
        std::cout << "Erro: arranjos com tamanhos diferentes ou ponteiros inválidos." << std::endl;
    }

    return result;
}
//---------------------


}; // end class Array
 
#endif