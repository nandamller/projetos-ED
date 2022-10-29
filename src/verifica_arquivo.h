//#include <cstdint>  // std::size_t
//#include <stdexcept>  // C++ exceptions
//#include <string>
//#include <fstream>
//#include <unistd.h>
//#include <stdio.h>

#include "../classes/array_stack.h"

using namespace std;

// CONTAR A QUANTIDADE DE IMG

int verifica_arquivo(string _xml_string) {
    string xml_string = _xml_string;
    
    structures::ArrayStack<std::string>pilha(500);
    bool ERRO = false;
    const char* imagens[100];
 
    int inicial = 0;
    int resultado = 0;

    for (int i = 0; i < xml_string.size(); i++) {  // checando cada caracter
        if (xml_string[i] == '<') {
            if (xml_string[i+1] != '/') {          // se nao for '/', esta empilhando
                string tag("");
                i++;
                while (xml_string[i] != '>') {
                    tag += xml_string[i];
                    i++;
                }
                pilha.push(tag);
            } else {                             // se for '/', esta desempilhando
                string tag;
                i++;
                i++;
                while (xml_string[i] != '>') {
                    tag += xml_string[i];
                    i++;
                }
                try {
                    string topo = pilha.top(); // checar se fila esta vazia, causa erro
                } catch (out_of_range& e) {
                    ERRO = true;
                    break;
                }
                if (!tag.compare(pilha.top())) {    // verifica se esta fechando corretamente
                    pilha.pop();
                } else {
                    ERRO = true;
                    break;
                }
            }
        } else {  
            try {
                string topo = pilha.top();
            } catch (out_of_range& e) {
                ERRO = true;
                break;
            }
            if (pilha.top() == "width") {
                std::string width = "";
                while (xml_string[i] != '<') {
                    width += xml_string[i];
                    i++;
                }
                i--;
            } else if (pilha.top() == "height") { 
                std::string height = "";
                while (xml_string[i] != '<') {
                    height += xml_string[i];
                    i++;
                }
                i--;
            } else if (pilha.top() == "name") {
                std::string name = "";
                while (xml_string[i] != '<') {
                    name += xml_string[i];
                    i++;
                }
                i--;
                resultado++;
                imagens[inicial] = name.c_str(); 
                inicial++;
            }
        }
    }
    if (!pilha.empty() || ERRO) {     // se nao estiver vazia no final, causa erro
        printf("error--\n");
        return 0;
    }
    return resultado;
}
