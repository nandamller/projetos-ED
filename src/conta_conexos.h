// @ COPYRIGHT [2022] <Fernanda Müller e Pedro Nack>

#include "../classes/matrix_image.h"

using namespace std;
using namespace structures;

void conta_conexos(string conteudos, string xmlfilename) {    
    ifstream xml_file("./datasets/dataset01.xml");
    string xml_string;
    string line;

    if (xml_file.is_open()) {
        while (getline(xml_file, line)) {
            xml_string += line;
        }
        xml_file.close();
    } else {
        cout << "Erro na leitura do arquivo" << endl;
        return;
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
            if (tag == "height") {
                i++; // pula o >
                while (xml_string[i] != '<') {
                    height += xml_string[i];
                    i++;
                }
            } else if (tag == "width") {
                i++; // pula o >
                while (xml_string[i] != '<') {
                    width += xml_string[i];
                    i++;
                }
            } else if (tag == "data") {
                i++; // pula o >

                while (xml_string[i] != '<') {
                    data += xml_string[i];
                    i++;
                } 

                cout << data[127] << "isso" << endl;
                // cria a matriz que vai representar a imagem
                Matrix_Image matrix_image = Matrix_Image(stoi(height), stoi(width));

                for (int lines = 0; lines < stoi(height)-1; lines++) {
                    for (int columns = 0; columns < stoi(width)-1; columns++) {
                        int element = data[stoi(width)*lines + columns];
                        matrix_image.set_element(lines, columns, element);
                    }
                }

                
                
            }
        }
        
    }
}
