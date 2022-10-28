// @ COPYRIGHT [2022] <Fernanda Müller e Pedro Nack>

#ifndef MATRIX_IMAGE_H
#define MATRIX_IMAGE_H

#include <cstdint>

using namespace std;

namespace structures {

class Matrix_Image{
    public:
        /*
            Constrói uma classe para a criação das matrizes que irão conter
            as imagens lidas dos datasets.

            @param n_lines -> número de linhas da matriz
            @param n_columns -> número de linhas da matriz
        */

        // Construtor da classe
        Matrix_Image(int n_lines, int n_columns);

        // Destrutor da classe
        ~Matrix_Image();

        /*
            Método que conta a quantidade de componentes conexos presentes na matriz.
            Esse método retorna um inteiro com a quantidade de conexos.
        */ 
        int count_components();

        /*
            Método para setar os valores da matriz.
            
            @param line -> linha do elemento
            @param column -> coluna do elemento
            @param new_element -> elemento a ser setado
        */
        void set_element(int line, int column, int new_element);

        /*
            Método para pegar os valores da matriz.
            
            @param line -> linha do elemento
            @param column -> coluna do elemento
        */
        int get_element(int line, int column);

    private:
        // Matriz
        int** matrix;

        // Linhas
        int line;
    
        // Colunas
        int columns;

        // Componentes conexos
        int components;
};

} // namespace structures

#endif // MATRIX_IMAGE_H

structures::Matrix_Image::Matrix_Image(int line, int columns) {
    line = line;
    columns = columns;
    components = 0;

    matrix = new int*[line];

    // Criando a matriz com todos os elementos zeros
    for (int i = 0; i < line; i++) {
        matrix[i] = new int[columns];

        for (int j = 0; j < columns; j++) {
            matrix[i][j] = 0;
        }
    }
}

structures::Matrix_Image::~Matrix_Image() {
    for (int i = 0; i < line; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int structures::Matrix_Image::count_components() {
    
    
    return components;
}

void structures::Matrix_Image::set_element(int line, int column, int new_element) {
    matrix[line][column] = new_element;
}

int structures::Matrix_Image::get_element(int line, int column) {
    return matrix[line][column];
}