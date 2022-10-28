
#include <iostream>
#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions
#include <string>
#include <fstream>
#include <unistd.h>


#include "./classes/array_list.h"
#include "./src/verifica_arquivo.h"
#include "./src/conta_conexos.h"

int main() {
    char xmlfilename[100];
    structures::ArrayList<std::string>fila(500);
    // std::cin >> xmlfilename;
    std::ifstream arquivo;
    std::string conteudos;
    
    // Lendo o arquivo
    arquivo.open("./datasets/dataset01.xml");
    arquivo >> conteudos;

    conta_conexos(conteudos, xmlfilename);

    struct imagens retorno;
    retorno = verifica_arquivo(conteudos, xmlfilename);
    
    if (retorno.quantidade != 0) {
        for (int i = 1; i <= retorno.quantidade; i++) {
            printf("0%d.png\n", i);
        }
    }
    const char* imagens[100];
    return 0;
}

