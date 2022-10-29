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
    ifstream xml_file("./datasets/dataset01.xml");
    string xml_string;
    string line;

    if (xml_file.is_open()) {
        while (getline(xml_file, line)) {
            xml_string += line;
        }
        xml_file.close();
    } else {
        cout << "error" << endl;
    }

    struct imagens retorno;
    retorno = verifica_arquivo(xml_string);
    int qtd_imagens = retorno.quantidade;

    if (qtd_imagens != 0) {
        for (int i = 1; i <= qtd_imagens; i++) {
            printf("0%d.png\n", i);

        }
        if (ERRO) {
            break;
        }
}
if (!pilha.empty() || (ERRO)) {     // se nao estiver vazia no final, causa erro
    printf("error\n");
    arquivo.close();
    return 1;
} else {
    for (int i = 0; i < posicao; i++) {
        printf("altura: %d, largura: %d\n", altura, largura);
        printf("%s\n", nomes[i].c_str());
        printf("%s\n", imagens[i].c_str());
    }

    const char* imagens[100];

    conta_conexos(xml_string, qtd_imagens);

    return 0;
}
