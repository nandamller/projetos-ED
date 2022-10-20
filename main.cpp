#include <iostream>
#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions
#include <string>
#include <fstream>
#include <unistd.h>
//#include "array_stack.h"

#include "array_list.h"
#include "verifica_arquivo.h"

int main() {
    char xmlfilename[100];
    structures::ArrayList<std::string>fila(500);
    std::cin >> xmlfilename;
    std::ifstream arquivo;
    std::string conteudos;
    struct imagens retorno;
    retorno = verifica_arquivo(conteudos, xmlfilename);
    if (retorno.quantidade != 0) {
        printf("%d\n", retorno.quantidade);
    }
    const char* imagens[100];
    return 0;
}

