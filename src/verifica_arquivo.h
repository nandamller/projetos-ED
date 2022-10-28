#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions
#include <string>
#include <fstream>
#include <unistd.h>
#include "array_stack.h"

//#include "array_list.h"

struct imagens {
    int quantidade = 0;
};

// CONTAR A QUANTIDADE DE IMG
struct imagens verifica_arquivo(std::string conteudos, std::string xmlfilename) {
    std::ifstream arquivo;
    arquivo.open(xmlfilename);
    structures::ArrayStack<std::string>pilha(500);
    int linha = 0;
    const char* imagens[100];
    bool ERRO = false;
    int inicial = 0;
    struct imagens resultado;
    while (ERRO == false) {
        linha++;
        arquivo >> conteudos;
        if (arquivo.eof()) {
            break;
        }
        for (int i = 0; i < conteudos.size(); i++) {  // checando cada caracter
            if (conteudos[i] == '<') {
                if (conteudos[i+1] != '/') {          // se nao for '/', esta empilhando
                    std::string tag("");
                    i++;
                    while (conteudos[i] != '>') {
                        tag += conteudos[i];
                        i++;
                    }
                    pilha.push(tag);
                } else {                             // se for '/', esta desempilhando
                    std::string tag("");
                    i++;
                    i++;
                    while (conteudos[i] != '>') {
                        tag += conteudos[i];
                        i++;
                    }
                    try {
                        std::string topo = pilha.top(); // checar se fila esta vazia, causa erro
                    } catch (std::out_of_range& e) {
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
                    std::string topo = pilha.top();
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
                }
            }
        }
        if (ERRO) {
            break;
        }
    }
    if (!pilha.empty() || (ERRO)) {     // se nao estiver vazia no final, causa erro
        printf("error\n");
        arquivo.close();
        resultado.quantidade = 0;
        return resultado;
    }
    return resultado;
}
