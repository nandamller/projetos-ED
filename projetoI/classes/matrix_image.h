// @ COPYRIGHT [2022] <Fernanda Müller e Pedro Nack>

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdint>
#include <string.h>

#include "linked_queue.h"

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

            @param data -> string contendo a imagem
        */ 
        int count_components(int height, int width);

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
        // int components;
};

} // namespace structures

#endif // MATRIX_H

structures::Matrix_Image::Matrix_Image(int _line, int _columns) {
    line = _line;
    columns = _columns;

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

int structures::Matrix_Image::count_components(int height, int width) {
    // fila para adicionar a posição (x, y) da vizinhança
    using pos = pair<int, int>;
    LinkedQueue<pos> queue;

    // cria a matriz 0
    Matrix_Image matrix_zero = Matrix_Image(height, width);
    
    int components = 1;
    // loop que vai de linha em linha
    for (int k = 0; k < height; k++) {
        //loop que vai pelas colunas
        for (int j = 0; j < width; j++) {
            if (!matrix_zero.get_element(k, j) && matrix[k][j]) {
                matrix_zero.set_element(k, j, components);

                // adicionando na fila
                queue.enqueue({k, j});

                // enquanto não estiver vazia vai adicionando a vizinhança
                while (!queue.empty()) {
                    pos pos_atual = queue.dequeue();

                    const int x = pos_atual.first;
                    const int y = pos_atual.second;

                    // x, y-1
                    if (y-1 >= 0 && matrix_zero.get_element(x, y-1) == 0 && matrix[x][y-1]) {
                        matrix_zero.set_element(x, y-1, components);
                        queue.enqueue({x, y-1});
                    }

                    // x, y+1
                    if (y+1 < width && matrix_zero.get_element(x, y+1) == 0 && matrix[x][y+1]) {
                        matrix_zero.set_element(x, y+1, components);
                        queue.enqueue({x, y+1});
                    }

                    // x-1, y
                    if (x-1 >= 0 && matrix_zero.get_element(x-1, y) == 0 && matrix[x-1][y]) {
                        matrix_zero.set_element(x-1, y, components);
                        queue.enqueue({x-1, y});
                    }

                    // x+1, y
                    if (x+1 < height && matrix_zero.get_element(x+1, y) == 0 && matrix[x+1][y]) {
                        matrix_zero.set_element(x+1, y, components);
                        queue.enqueue({x+1, y});
                    }
                }
                components++;

            } 
        }
    } 
    return components-1;
}

void structures::Matrix_Image::set_element(int line, int column, int new_element) {
    matrix[line][column] = new_element;
}

int structures::Matrix_Image::get_element(int line, int column) {
    return matrix[line][column];
}