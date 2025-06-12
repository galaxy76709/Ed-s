/*
 * mymatrix.hpp - v1.1. - 12/06/2025
 * Author: _________________________
 *
 * Versão final corrigida e limpa.
 */

#ifndef _MYMATRIX_H_
#define _MYMATRIX_H_

// Dependências
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdexcept> // Para exceções como std::out_of_range
#include <utility>   // Para std::swap

template <typename T>
class Matrix
{
private:
    int rows;
    int columns;
    T **data;

    // Método auxiliar para alocar memória
    void allocate(int num_rows, int num_cols)
    {
        if (num_rows <= 0 || num_cols <= 0) {
            throw std::invalid_argument("Dimensões da matriz devem ser positivas.");
        }
        this->rows = num_rows;
        this->columns = num_cols;
        this->data = new T *[rows];
        for (int i = 0; i < rows; ++i)
        {
            this->data[i] = new T[columns](); // Inicializa com zeros/padrão
        }
    }

    // Método auxiliar para desalocar memória
    void deallocate()
    {
        if (data != nullptr)
        {
            for (int i = 0; i < rows; ++i)
            {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
            rows = 0;
            columns = 0;
        }
    }

public:
    // Construtor Padrão
    Matrix() : rows(0), columns(0), data(nullptr) {}

    // Construtor com dimensões
    Matrix(int num_rows, int num_cols)
    {
        allocate(num_rows, num_cols);
    }

    // Destrutor
    ~Matrix()
    {
        deallocate();
    }

    // --- A Regra dos Três/Cinco ---

    // 1. Construtor de Cópia (ESSENCIAL)
    Matrix(const Matrix<T> &other)
    {
        if (other.data == nullptr) { // Lida com a cópia de matrizes vazias
            rows = 0;
            columns = 0;
            data = nullptr;
            return;
        }
        allocate(other.rows, other.columns);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                this->data[i][j] = other.data[i][j];
            }
        }
    }

    // 2. Operador de Atribuição por Cópia (Copy-and-Swap Idiom)
    Matrix<T> &operator=(Matrix<T> other) // Passa por valor para criar uma cópia
    {
        std::swap(this->rows, other.rows);
        std::swap(this->columns, other.columns);
        std::swap(this->data, other.data);
        return *this; // A 'other' antiga será destruída, liberando a memória antiga de 'this'
    }

    // --- Métodos de Acesso e Modificação ---

    void set(int row, int col, T value)
    {
        if (row < 0 || row >= rows || col < 0 || col >= columns)
        {
            throw std::out_of_range("Erro: Posição inválida na matriz.");
        }
        data[row][col] = value;
    }

    T get(int row, int col) const
    {
        if (row < 0 || row >= rows || col < 0 || col >= columns)
        {
            throw std::out_of_range("Erro: Posição inválida na matriz.");
        }
        return data[row][col];
    }
    
    // Sobrecarga de operador () para acesso mais idiomático: matrix(row, col)
    T& operator()(int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= columns) {
            throw std::out_of_range("Erro: Posição inválida na matriz.");
        }
        return data[row][col];
    }

    const T& operator()(int row, int col) const {
        if (row < 0 || row >= rows || col < 0 || col >= columns) {
            throw std::out_of_range("Erro: Posição inválida na matriz.");
        }
        return data[row][col];
    }

    // --- Métodos de Leitura e Escrita ---

    void print() const
    {
        std::cout << std::endl;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                std::cout << data[i][j] << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void fprint(const std::string& fileName) const
    {
        std::ofstream afile(fileName);
        if (!afile.is_open()) {
            std::cerr << "Erro: Não foi possível abrir o arquivo " << fileName << std::endl;
            return;
        }
        afile << rows << std::endl;
        afile << columns << std::endl;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                afile << data[i][j] << std::endl;
            }
        }
        afile.close();
    }
    
    void fread(const std::string& fileName)
    {
        std::ifstream afile(fileName);
        if (!afile.is_open()) {
            std::cerr << "Erro: Nao foi possivel abrir o arquivo " << fileName << std::endl;
            return;
        }
        
        int file_rows, file_cols;
        afile >> file_rows >> file_cols;

        if (file_rows <= 0 || file_cols <= 0) {
            std::cerr << "Erro: Dimensões inválidas no arquivo." << std::endl;
            return;
        }

        // Libera a memória antiga antes de alocar nova
        deallocate();
        allocate(file_rows, file_cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (!(afile >> data[i][j])) {
                    std::cerr << "Erro: Faltam dados no arquivo." << std::endl;
                    deallocate(); // Limpa a matriz em caso de erro de leitura
                    return;
                }
            }
        }
        afile.close();
    }

    // --- Operadores ---

    bool operator==(const Matrix<T> &other) const
    {
        if (rows != other.rows || columns != other.columns)
        {
            return false;
        }

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (data[i][j] != other.data[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Matrix<T> &other) const
    {
        return !(*this == other);
    }
    
    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || columns != other.columns) {
            throw std::invalid_argument("As matrizes devem ter as mesmas dimensões para adição.");
        }
        Matrix<T> result(rows, columns);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    
    Matrix<T> operator-(const Matrix<T>& other) const {
        if (rows != other.rows || columns != other.columns) {
            throw std::invalid_argument("As matrizes devem ter as mesmas dimensões para subtração.");
        }
        Matrix<T> result(rows, columns);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                result.data[i][j] = this->data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator*(const Matrix<T> &other) const
    {
        if (this->columns != other.rows)
        {
            throw std::invalid_argument("O número de colunas da primeira matriz deve ser igual ao de linhas da segunda.");
        }

        Matrix<T> result(this->rows, other.columns);
        for (int i = 0; i < result.rows; ++i)
        {
            for (int j = 0; j < result.columns; ++j)
            {
                T sum = T(); // Inicializa com valor padrão (0 para tipos numéricos)
                for (int k = 0; k < this->columns; ++k)
                {
                    sum += this->data[i][k] * other.data[k][j];
                }
                result.data[i][j] = sum;
            }
        }
        return result;
    }
    
    Matrix<T> scalar(T constant) const
    {
        Matrix<T> result(rows, columns);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                result.data[i][j] = this->data[i][j] * constant;
            }
        }
        return result;
    }
    
    // --- Utilitários ---

    int getRows() const { return rows; }
    int getColumns() const { return columns; }

    bool isIdentity() const
    {
        if (rows <= 0 || rows != columns)
        {
            return false;
        }

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (i == j) // Diagonal principal
                {
                    if (data[i][j] != 1) return false;
                }
                else // Fora da diagonal
                {
                    if (data[i][j] != 0) return false;
                }
            }
        }
        return true;
    }

    void transpose() {
        if (rows == 0 || columns == 0) return;

        Matrix<T> temp(columns, rows);
        for (int i = 0; i < columns; ++i) {
            for (int j = 0; j < rows; ++j) {
                temp.data[i][j] = this->data[j][i];
            }
        }
        *this = temp; // Usa o operador de atribuição corrigido
    }
    
}; // end class

#endif