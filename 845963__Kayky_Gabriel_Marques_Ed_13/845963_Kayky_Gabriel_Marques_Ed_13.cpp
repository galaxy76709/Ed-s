// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits>   // std::numeric_limits
#include <string>   // para cadeias de caracteres

// ----------------------------------------------- definicoes globais

// ----------------------------------------------- classes

#include "Contato.hpp" // classe para tratar dados de pessoas

// ----------------------------------------------- definicoes globais

//---------------------
/**
   Method_00 - nao faz nada.
 */
void method_00()
{
   // nao faz nada
} // end method_00 ( )
//---------------------

//---------------------
/**
   Method_01 - Testar definicoes da classe.
 */
void method_01()
{
   // definir dados
   
   ref_Contato pessoa1 = new Contato(); 

      // identificar
        cout << "\nMethod_01 - v1.0\n"<< endl;
   std::cout <<"Digite o nome da pessoa"<< endl; 

   pessoa1 -> readName ("Digite o nome da pessoa: "); 

   if ( pessoa1 -> hasErro () ) {
        std::cout << "Nome invalido. Erro " << pessoa1->getErro() << std::endl;
   } else {
        std::cout << "Contato: " << pessoa1->toString() << std::endl;   }


   // encerrar
   pause("Apertar ENTER para continuar");
} // end method_01 ()
//---------------------

//---------------------
/**
   Method_02 - Testar atribuicoes.
 */
void method_02()
{
   // definir dados
   
   ref_Contato pessoa1 = new Contato(); 

      // identificar
        cout << "\nMethod_01 - v1.0\n"<< endl;
      //std::cout <<"Digite o nome da pessoa"<< endl; 

   pessoa1 -> readName ("Digite o nome da pessoa: ");

      //std::cout <<"Digite o numero da pessoa"<< endl; 
   pessoa1 -> readPhone ("Digite o numero da pessoa: ");


   if ( pessoa1 -> hasErro () ) {
        std::cout << "Nome invalido e/ou numero errado. Erro " << pessoa1->getErro() << std::endl;
   } else {
        std::cout << "Contato: " << pessoa1->toString() << std::endl;   }


   // encerrar
   pause("Apertar ENTER para continuar");
} // end method_01 ()
//---------------------

//---------------------
/**
   Method_03 - Testar recuperacao de dados.
 */
void method_03()
{
   ref_Contato pessoa1 = new Contato();

    cout << "\nMethod_03 - Validar telefone\n" << endl;



     pessoa1 -> readName ("Digite o nome da pessoa: ");

      //std::cout <<"Digite o numero da pessoa"<< endl; 
     pessoa1 -> readPhone ("Digite o numero da pessoa: ");


    if (pessoa1->isValidPhone()) {

        cout << "Telefone valido: " << pessoa1->getFone(0) << endl;
    } else {

        cout << "Telefone invalido. Erro: " << pessoa1->getErro() << endl;
    }

    // encerrar
   pause("Apertar ENTER para continuar");
} // end method_03 ( )
//---------------------

//---------------------
/**
   Method_04 - Testar construtor alternativo.
 */
void method_04()
{
    cout << "\nMethod_04 - v1.0\n" << endl;

    ref_Contato contato1 = new Contato();

    contato1->readFromFile("Pessoa1.txt");

    if (contato1->hasErro())
    {
        std::cout << "Erro ao ler contato. Codigo: " << contato1->getErro() << std::endl;
    }
    else
    {
        std::cout << "Contato lido do arquivo: " << contato1->toString() << std::endl;
    }
   // encerrar
   pause("Apertar ENTER para continuar");
} // end method_04 ( )
//---------------------

//---------------------
/**
   Method_05 - Testar construtor alternativo.
 */
void method_05()
{
   cout << "\nMethod_05 - v1.0\n" << endl;

    ref_Contato contato1 = new Contato("Carlos Silva", "98888-7766");

    contato1->writeToFile("Pessoa1.txt");

    if (contato1->hasErro())
    {
        std::cout << "Erro ao gravar contato. Código: " << contato1->getErro() << std::endl;
    }
    else
    {
        std::cout << "Contato gravado com sucesso em arquivo." << std::endl;
    }

   // encerrar
   pause("Apertar ENTER para continuar");
} // end method_05 ( )
//---------------------

//---------------------
/**
   Method_06 - Testar construtor alternativo.
 */
void method_06()
{
     cout << "\nMethod_06 - v1.0\n" << endl;

    ref_Contato contato1 = new Contato("Mariana", "9999-1111", "98888-2222");

    std::cout << "Contato criado: " << contato1->toString() << std::endl;

   // encerrar
   pause("Apertar ENTER para continuar");
} // end method_06 ( )
//---------------------

//---------------------
/**
   Method_07 - Testar atribuicoes e tratamento de erro.
 */
void method_07()
{
   cout << "\nMethod_07 - Verificar quantidade de telefones\n" << endl;

    ref_Contato contato1 = new Contato();

    contato1->readName("Digite o nome da pessoa: ");
    contato1->readPhone("Digite o 1o numero da pessoa: ");

    // Perguntar se deseja inserir um segundo telefone
    string resposta;
    cout << "Deseja adicionar outro telefone? (s/n): ";
    getline(cin >> std::ws, resposta);

    if (resposta == "s" || resposta == "S")
    {
        string telefone2;
        cout << "Digite o 2o numero da pessoa: ";
        getline(cin >> std::ws, telefone2);
        if (!telefone2.empty())
        {
            contato1->setFone(telefone2); // Aqui você pode adaptar para lidar com o segundo número
        }
    }

    cout << "Quantidade de telefones cadastrados: " << contato1->phones() << endl;

   // encerrar
   pause("Apertar ENTER para continuar");
} // end method_07 ( )
//---------------------

//---------------------
/**
   Method_08 - Testar atribuicoes e segundo telefone.
 */
void method_08()
{
    cout << "\nMethod_08 - Atribuir segundo telefone\n" << endl;

    ref_Contato contato1 = new Contato();

    contato1->readName("Digite o nome da pessoa: ");
    contato1->readPhone("Digite o 1o telefone da pessoa: ");

    cout << "\nTelefone atual: " << contato1->getFone(0) << endl;
    cout << "Quantidade atual de telefones: " << contato1->phones() << endl;

    string resposta;
    cout << "Deseja adicionar outro telefone? (s/n): ";
    getline(cin >> std::ws, resposta);

    if (resposta == "s" || resposta == "S")
    {
        string tel2;
        cout << "Digite o 2o telefone: ";
        getline(cin >> std::ws, tel2);

        contato1->setPhone2a(tel2);
    }

    // Mostrar resultado final
    cout << "\nResumo do Contato:\n" << contato1->toString() << endl;
    cout << "Quantidade final de telefones: " << contato1->phones() << endl;

   // encerrar
   pause("Apertar ENTER para continuar");
} // end method_08 ( )
//---------------------

//---------------------
/** 
   Method_09 - Testar arranjo de objetos (1). 
 */ 
void method_09 ( ) 
{ 
 cout << "\nMethod_09 - Alterar segundo telefone\n" << endl;

    // Criar contato com dois telefones
    Contato* contato = new Contato("Joao", "9999-1111", "9888-2222");

    cout << "Contato atual: " << contato->toString() << endl;
    cout << "Quantidade de telefones: " << contato->phones() << endl;

    string novoFone;
    cout << "Digite o novo segundo telefone: ";
    getline(cin >> std::ws, novoFone);

    contato->setPhone2b(novoFone);

    if (contato->hasErro())
    {
        cout << "Erro ao alterar segundo telefone. Codigo: " << contato->getErro() << endl;
    }
    else
    {
        cout << "Telefone alterado com sucesso!" << endl;
        cout << "Contato atualizado: " << contato->toString() << endl;
    }
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_09 ( )
//---------------------


//---------------------
/** 
   Method_10 - Testar arranjo de referencias para objetos (2). 
 */ 
void method_10 ( ) 
{ 
   cout << "\nMethod_1320 - Remover segundo telefone\n" << endl;

    Contato* contato = new Contato("Maria", "9999-1111", "9888-2222");

    cout << "Contato atual: " << contato->toString() << endl;
    cout << "Quantidade de telefones: " << contato->phones() << endl;

    string entrada = "";
    contato->setPhone2c(entrada); // chama com string vazia

    if (contato->hasErro())
    {
        cout << "Erro ao remover segundo telefone. Codigo: " << contato->getErro() << endl;
    
     } else
    {
        cout << "Segundo telefone removido com sucesso!" << endl;
        cout << "Contato atualizado: " << contato->toString() << endl;
        cout << "Quantidade atual de telefones: " << contato->phones() << endl;
    }

 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_10 ( )
//---------------------


//---------------------
/** 
   Method_11 - Testar arranjo de referencias para objetos (2). 
 */ 
void method_11 ( ) 
{ 
   cout << "\nMethod_11 - Remover segundo telefone\n" << endl;

     ref_Contato contato = new Contato();
    cout << "Method_13E1 - Adicionar ate 10 telefones" << endl;

    contato->readName("Digite o nome:");
    contato->readPhone(0);

    cout << "Contato cadastrado: " << contato->toString() << endl;
    cout << "Total de telefones: " << contato->phones() << endl;


 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_10 ( )
//---------------------


//---------------------
void method_12()
{
    ref_Contato contato = new Contato();
   cout << "\nMethod_12 - Remover segundo telefone\n" << endl;

    contato->readName("Digite o nome do contato:");
    contato->readPhone("Digite o telefone principal:", -1);

    contato->readEnderecoResidencial("Digite o endereco residencial:");
    contato->readEnderecoProfissional("Digite o endereco profissional:");

    cout << "\nDados do contato:" << endl;
    cout << contato->toString() << endl;

 // encerrar 
    pause("Aperte ENTER para continuar");
} // end method_10 ( )
//---------------------
// ----------------------------------------------- acao principal ----------------------------------------------- \\

/*
  Funcao principal.
  @return codigo de encerramento
*/
int main(int argc, char **argv)
{
   // definir dado
   int x = 0; // definir variavel com valor inicial

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
      cout << " 11 - EX 11  " << endl;
      cout << " 12 - EX 12  " << endl;


      // ler do teclado
      cout << endl
           << "Entrar com uma opcao: ";
      cin >> x;

      // escolher acao
      switch (x)
      {
      case 0:
         method_00();
         break;
      case 1:
         method_01();
         break;
      case 2:
         method_02();
         break;
      case 3:
         method_03();
         break;
      case 4:
         method_04();
         break;
      case 5:
         method_05();
         break;
      case 6:
         method_06();
         break;
      case 7:
         method_07();
         break;
      case 8:
         method_08();
         break;
      case 9:
         method_09();
         break;
      case 10:
         method_10();
         break;
      case 11:
         method_11();
         break;
      case 12:
         method_12();
         break;
      default:
         cout << endl
              << "ERRO: Valor invalido." << endl;
      } // end switch
   } while (x != 0);

   // encerrar
   pause("Apertar ENTER para terminar");
   return (0);
} // end main ( )