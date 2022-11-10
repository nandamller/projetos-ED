// @ COPYRIGHT [2022] <Fernanda Müller e Pedro Nack>

#include <iostream>
#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions
#include <string>
#include <fstream>
#include <unistd.h>

#include "./classes/array_list.h"
#include "./classes/linked_list.h"
#include "./src/verifica_arquivo.h"
#include "./src/conta_conexos.h"

int main() {
    string xmlfilename;
    cin >> xmlfilename;

    xmlfilename = "./datasets/" + xmlfilename;
    ifstream xml_file(xmlfilename);
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

    // lista com os nomes dos arquivos
    LinkedList<string>files_list;
    LinkedList<string> *q;
    q = &files_list;

    int qtd_imagens = verifica_arquivo(xml_string, q);

    if (qtd_imagens != 0) {
        ArrayList<int>components_list(qtd_imagens);
        ArrayList<int> *p;
        p = &components_list;

        conta_conexos(xml_string, p);

        for (int i = 0; i < qtd_imagens; i++) {
            cout << files_list.at(i) << " " << components_list.at(i) << endl;
        }
    }
    return 0;
}
