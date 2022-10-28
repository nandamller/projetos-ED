// @ COPYRIGHT [2022] <Fernanda Müller e Pedro Nack>

#ifndef MATRIX_IMAGE_H
#define MATRIX_IMAGE_H

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

        // talvez precise colocar get e set p/ os elementos

    private:
        // Matriz
        int** M;

        // Linhas
        int line;
    
        // Colunas
        int columns;

};

#endif // MATRIX_IMAGE_H