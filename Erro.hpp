#ifndef _ERRO_H_
#define _ERRO_H_

#include <string>

class Erro
{
private:
    int erro;

public:
    static const std::string NO_ERROR;

    // Construtor padrão
    Erro() {
        erro = 0;
    }

    // Destrutor
    ~Erro() {
        // Nada a liberar por enquanto
    }

    // Obter o código de erro
    int getErro() {
        return erro;
    }

    // Testar se há erro
    bool hasError() {
        return (erro != 0);
    }

    // Obter mensagem de erro (versão base)
    virtual std::string getErroMsg() {
        return "";
    }

protected:
    // Definir o código de erro
    void setErro(int codigo) {
        erro = codigo;
    }
};

// Inicializar constante estática
const std::string Erro::NO_ERROR = "[ERRO] Nao ha' erro.";

#endif