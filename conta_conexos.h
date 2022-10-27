// @ COPYRIGHT [2022] <Fernanda Müller e Pedro Nack>

#include <cstdint>      // std::size_t
#include <stdexcept>    // C++ exceptions
#include <string>
#include <fstream>
#include <unistd.h>
#include <iostream>
#include <fstream>      // Biblioteca para escrita/leitura de arquivos

#include "linked_list.h"

using namespace std;
using namespace structures;


int calcula_qtd(string imagem, int altura, int largura) {
    int quantidade_conexos = 0;

    structures::LinkedList<std::string> matriz;

    for (int i = 0; i < altura; i++) {
        structures::LinkedList<std::string> linha;
        for (int j = 0; j < largura; j++) {
            linha.push_front('0');
        }
        matriz.push_front(linha);
    }

    cout << matriz.empty() <<  endl;

    return quantidade_conexos;
}

void conta_conexos(string conteudos, string xmlfilename) {
    ifstream xml_file("dataset01.xml");
    string xml_string;
    string line;

    if (xml_file.is_open()) {
        while (getline(xml_file, line)) {
            xml_string += line;
        }
        xml_file.close();
    } else {
        cout << "Arquivo não pode ser lido" << endl;
    }

    string height;
    string width;
    string data;    

    for (int i = 0; i < xml_string.size(); i++) {
        if (xml_string[i] == '<' && xml_string[i+1] != '/') {
            string tag;
            i++; // para pular <

            while (xml_string[i] != '>') {
                tag += xml_string[i];
                i++;
            }

            cout << tag << endl;

            if (tag == "height") {
                i++; // pula o >
                while (xml_string[i] != '<') {
                    height += xml_string[i];
                    i++;
                }
                cout << "Saiu do loop." << height <<  endl;
            } else if (tag == "width") {
                i++; // pula o >
                while (xml_string[i] != '<') {
                    width += xml_string[i];
                    i++;
                }
                cout << "Saiu do loop." << width <<  endl;
            } else if (tag == "data") {
                i++; // pula o >
                while (xml_string[i] != '<') {
                    data += xml_string[i];
                    i++;
                } 
                
                int u = calcula_qtd(data, stoi(height), stoi(width));
            }
        }
        
    }
}
