
#include <iostream>
#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions
#include <string>
#include <fstream>
#include <unistd.h>
//#include "array_stack.h"

#include "array_list.h"
#include "verifica_arquivo.h"
#include "conta_conexos.h"

int main() {
    char xmlfilename[100];
    structures::ArrayList<std::string>fila(500);
    std::cin >> xmlfilename;
    std::ifstream arquivo;
    std::string conteudos;
    
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

