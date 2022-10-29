// @ COPYRIGHT [2022] <Fernanda Müller e Pedro Nack>

#include "../classes/matrix_image.h"

using namespace std;
using namespace structures;

void conta_conexos(string _xml_string, ArrayList<int> *p) {   
    string xml_string = _xml_string;

    int height = 0;
    int width = 0;

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
                string _height;
                while (xml_string[i] != '<') {
                    _height += xml_string[i];
                    i++;
                }
                height = stoi(_height);

            } else if (tag == "width") {
                i++; // pula o >
                string _width;
                while (xml_string[i] != '<') {
                    _width += xml_string[i];
                    i++;
                }
                width = stoi(_width);

            } else if (tag == "data") {
                i++; // pula o >
                string data;
                while (xml_string[i] != '<') {
                    data += xml_string[i];
                    i++;
                } 

                // cria a matriz que vai representar a imagem
                Matrix_Image matrix_image = Matrix_Image(height, width);

                int line = 0;
                int column = 0;

                // c percorre os valores de data
                for (const char& c:data) {
                    if (std::isspace(c)) {
                        continue;
                    }
                    
                    matrix_image.set_element(line, column, c - '0');

                    if (++column >= width) {
                        column = 0;
                        if (++line >= height) {
                            break;
                        }
                    }
                }
                p->push_back((matrix_image.count_components(height, width)));          
            }
        }
    }
}
