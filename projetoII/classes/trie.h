// @ COPYRIGHT [2022] <Fernanda Müller e Pedro Nack>

#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <cstdint>
#include <string.h>

using namespace std;

const int ALPHABET_SIZE = 26;

namespace structures {

class Trie{
    public:
        /*
            Constrói uma classe para a uma árvore de prefixos.
        */

        // Construtor da classe
        Trie(string dict);

        // Destrutor da classe
        ~Trie();

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
