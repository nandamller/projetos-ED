#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions
#include <string>
#include <fstream>
#include <unistd.h>
#include "../classes/array_stack.h"

using namespace std;

struct imagens {
    int quantidade = 0;
};

// CONTAR A QUANTIDADE DE IMG

struct imagens verifica_arquivo(string _xml_string) {
    string xml_string = _xml_string;
    
    structures::ArrayStack<std::string>pilha(500);
    bool ERRO = false;
    const char* imagens[100];
 
    int inicial = 0;
    struct imagens resultado;

    for (int i = 0; i < xml_string.size(); i++) {  // checando cada caracter
        if (xml_string[i] == '<') {
            if (xml_string[i+1] != '/') {          // se nao for '/', esta empilhando
                std::string tag("");
                i++;
                while (xml_string[i] != '>') {
                    tag += xml_string[i];
                    i++;
                }
                pilha.push(tag);
            } else {                             // se for '/', esta desempilhando
                std::string tag("");
                i++;
                i++;
                while (xml_string[i] != '>') {
                    tag += xml_string[i];
                    i++;
                }
                try {
                    std::string topo = pilha.top(); // checar se fila esta vazia, causa erro
                } catch (std::out_of_range& e) {
                    ERRO = true;
                    break;
                }

                if (pilha.top() == "width") {
                    std::string width = "";
                    while (conteudos[i] != '<') {
                        width += conteudos[i];
                        i++;
                    }
                    i--;
                    std::stoi(width);
                } else if (pilha.top() == "height") { 
                    std::string height = "";
                    while (conteudos[i] != '<') {
                        height += conteudos[i];
                        i++;
                    }
                    i--;
                    std::stoi(height);
                } else if (pilha.top() == "name") {
                    std::string name = "";
                    while (conteudos[i] != '<') {
                        name += conteudos[i];
                        i++;
                    }
                    i--;
                    resultado.quantidade++;
                    imagens[inicial] = name.c_str(); 
                    inicial++;
                } if (!tag.compare(pilha.top())) {    // verifica se esta fechando corretamente
                    pilha.pop();
                } else {
                    ERRO = true;
                    break;

                }
            }
        } else {
            try {
                std::string topo = pilha.top();
            } catch (std::out_of_range& e) {
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
                std::stoi(width);
            } else if (pilha.top() == "height") { 
                std::string height = "";
                while (xml_string[i] != '<') {
                    height += xml_string[i];
                    i++;
                }
                i--;
                std::stoi(height);
            } else if (pilha.top() == "name") {
                std::string name = "";
                while (xml_string[i] != '<') {
                    name += xml_string[i];
                    i++;
                }
                i--;
                resultado.quantidade++;
                imagens[inicial] = name.c_str(); 
                inicial++;
            }
        }
    }
    if (!pilha.empty()) {     // se nao estiver vazia no final, causa erro
        printf("error\n");
        resultado.quantidade = 0;
        return resultado;
    }
    return resultado;
}
