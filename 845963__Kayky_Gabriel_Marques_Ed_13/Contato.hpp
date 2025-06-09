#ifndef _CONTATO_H_
#define _CONTATO_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::setw;
using std::string;

#include "Erro.hpp"

// pausa
void pause(std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl << std::endl;
}

// ---------------------------------------------- definicao da classe
class Contato : public Erro
{
//---------------------
private:
    string nome;
    string fones[10]; // Suporta ate 10 telefones
    int quantidade;   // Quantidade de telefones armazenados

    // Novos atributos para endereços:
    string enderecoResidencial;
    string enderecoProfissional;
//---------------------


//---------------------
public:
    ~Contato() {}
//---------------------
    Contato()
    {
        setErro(0);
        nome = "";
        for (int i = 0; i < 10; i++) fones[i] = "";
        quantidade = 0;
        enderecoResidencial = "";
        enderecoProfissional = "";
    }
//---------------------


//---------------------
    Contato(std::string nome_inicial, std::string fone1, std::string fone2 = "")
    {
        setErro(0);
        setNome(nome_inicial);
        for (int i = 0; i < 10; i++) fones[i] = "";
        quantidade = 0;

        if (!fone1.empty())
        {
            fones[0] = fone1;
            quantidade++;
        }
        if (!fone2.empty())
        {
            fones[1] = fone2;
            quantidade++;
        }

        enderecoResidencial = "";
        enderecoProfissional = "";
    }
//---------------------


//---------------------
    Contato(const Contato &another)
    {
        setErro(0);
        setNome(another.nome);
        quantidade = another.quantidade;
        for (int i = 0; i < quantidade; i++)
        {
            fones[i] = another.fones[i];
        }
        enderecoResidencial = another.enderecoResidencial;
        enderecoProfissional = another.enderecoProfissional;
    }
//---------------------


//---------------------
    void setNome(string nome)
    {
        if (nome.empty())
            setErro(1);
        else
            this->nome = nome;
    }
//---------------------


//---------------------
    void setFone(string numero, int index = 0)
    {
        if (numero.empty() || index < 0 || index >= 10)
        {
            setErro(2);
        }
        else
        {
            fones[index] = numero;
            if (quantidade < index + 1)
                quantidade = index + 1;
        }
    }
//---------------------


//---------------------
    string getNome()
    {
        return nome;
    }
//---------------------


//---------------------
    string getFone(int i)
    {
        if (i >= 0 && i < quantidade)
            return fones[i];
        return "";
    }
//---------------------


//---------------------
    // Métodos para endereço residencial
    void setEnderecoResidencial(const string &endereco)
    {
        if (endereco.empty())
            setErro(12);
        else
            enderecoResidencial = endereco;
    }
//---------------------


//---------------------
    string getEnderecoResidencial() const
    {
        return enderecoResidencial;
    }
//---------------------


//---------------------
    void readEnderecoResidencial(const string &mensagem)
    {
        string entrada;
        cout << mensagem << endl;
        std::getline(std::cin >> std::ws, entrada);
        setEnderecoResidencial(entrada);
    }
//---------------------


//---------------------
    // Métodos para endereço profissional
    void setEnderecoProfissional(const string &endereco)
    {
        if (endereco.empty())
            setErro(13);
        else
            enderecoProfissional = endereco;
    }
//---------------------


//---------------------
    string getEnderecoProfissional() const
    {
        return enderecoProfissional;
    }
//---------------------


//---------------------
    void readEnderecoProfissional(const string &mensagem)
    {
        string entrada;
        cout << mensagem << endl;
        std::getline(std::cin >> std::ws, entrada);
        setEnderecoProfissional(entrada);
    }
//---------------------


//---------------------
    string toString()
    {
        string resultado = "{ " + getNome();
        for (int i = 0; i < quantidade; i++)
        {
            resultado += ", " + fones[i];
        }

        if (!enderecoResidencial.empty())
            resultado += ", Residencial: " + enderecoResidencial;

        if (!enderecoProfissional.empty())
            resultado += ", Profissional: " + enderecoProfissional;

        resultado += " }";
        return resultado;
    }
//---------------------


//---------------------
    bool hasErro()
    {
        return (getErro() != 0);
    }
//---------------------


//---------------------
    void readName(const std::string &mensagem)
    {
        std::string entrada;
        std::cout << mensagem << endl;
        std::getline(std::cin >> std::ws, entrada);
        if (entrada.empty())
            setErro(1);
        else
            setNome(entrada);
    }
//---------------------


//---------------------
    void readPhone(const std::string &mensagem, int index = 0)
    {
        std::string entrada;
        std::cout << mensagem << endl;
        std::getline(std::cin >> std::ws, entrada);
        if (entrada.empty())
            setErro(2);
        else
            setFone(entrada, index);
    }
//---------------------


//---------------------
    bool isValidPhone()
    {
        if (fones[0].empty())
        {
            setErro(2);
            return false;
        }
        for (char c : fones[0])
        {
            if (!((c >= '0' && c <= '9') || c == '-'))
            {
                setErro(3);
                return false;
            }
        }
        return true;
    }
//---------------------


//---------------------
    void readFromFile(const std::string &fileName)
{
    std::ifstream arquivo(fileName);
    if (!arquivo.is_open())
    {
        setErro(4);
        return;
    }

    std::getline(arquivo >> std::ws, nome);
    quantidade = 0;

    int i = 0;
    bool continuar = true;

    while (i < 10 && continuar)
    {
        if (!std::getline(arquivo >> std::ws, fones[i]))
        {
            continuar = false;
        }
        else if (fones[i].empty())
        {
            continuar = false;
        }
        else
        {
            quantidade = quantidade + 1 ;
            i = i + 1 ;
        }
    }

    std::getline(arquivo >> std::ws, enderecoResidencial);
    std::getline(arquivo >> std::ws, enderecoProfissional);

    if (nome.empty())
        setErro(5);

    arquivo.close();
}
//---------------------


//---------------------
    void writeToFile(const std::string &fileName)
    {
        std::ofstream arquivo(fileName);
        if (!arquivo.is_open())
        {
            setErro(6);
            return;
        }

        int tamanhoTotal = nome.length();
        for (int i = 0; i < quantidade; i++)
            tamanhoTotal += fones[i].length();

        tamanhoTotal += enderecoResidencial.length() + enderecoProfissional.length();

        arquivo << tamanhoTotal << std::endl;
        arquivo << nome << std::endl;
        for (int i = 0; i < quantidade; i = i + 1 )
            arquivo << fones[i] << std::endl;

        arquivo << enderecoResidencial << std::endl;
        arquivo << enderecoProfissional << std::endl;

        arquivo.close();
    }
//---------------------


//---------------------
    int phones() const
    {
        return quantidade;
    }
//---------------------


//---------------------
    void setPhone2a(const std::string &telefone)
    {
        if (!telefone.empty())
        {
            fones[1] = telefone;
            if (quantidade < 2)
                quantidade = quantidade + 1;
        }
        else
        {
            setErro(7);
        }
    }
//---------------------


//---------------------
    void setPhone2b(const std::string &telefone)
    {
        if (quantidade < 2)
        {
            setErro(8);
        }
        else if (!telefone.empty())
        {
            fones[1] = telefone;
        }
        else
        {
            setErro(7);
        }
    }
//---------------------


//---------------------
    void setPhone2c(const std::string &telefone)
    {
        if (quantidade < 2)
        {
            setErro(9);
            return;
        }

        if (telefone.empty())
        {
            fones[1] = "";
            quantidade = 1;
        }
        else
        {
            setErro(10);
        }
    }
//---------------------
};

using ref_Contato = Contato *;

#endif
