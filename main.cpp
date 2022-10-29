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

    int qtd_imagens = verifica_arquivo(xml_string);

    ArrayList<int>components_list(qtd_imagens);
    ArrayList<int> *p;
    p = &components_list;

    conta_conexos(xml_string, p);

    if (qtd_imagens != 0) {
        for (int i = 1; i <= qtd_imagens; i++) {
            if (i < 10) {
                printf("0%d.png %d\n", i, components_list.at(i-1));
            } else {
                printf("%d.png\n", i);
            }
        }
    }
    return 0;
}
