// @ COPYRIGHT [2022] <Fernanda Müller e Pedro Nack>

#include "../classes/linked_stack.h"

using namespace std;
using namespace structures;

// CONTAR A QUANTIDADE DE IMG

int verifica_arquivo(string _xml_string, LinkedList<string> *q) {
    string xml_string = _xml_string;
    
    LinkedStack<std::string>pilha;
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
                string width = "";
                while (xml_string[i] != '<') {
                    width += xml_string[i];
                    i++;
                }
                i--;
            } else if (pilha.top() == "height") { 
                string height = "";
                while (xml_string[i] != '<') {
                    height += xml_string[i];
                    i++;
                }
                i--;
            } else if (pilha.top() == "name") {
                string name = "";
                while (xml_string[i] != '<') {
                    name += xml_string[i];
                    i++;
                }
                q->push_back(name);
                i--;
                resultado++;
                imagens[inicial] = name.c_str(); 
                inicial++;
            }
        }
    }
    if (!pilha.empty() || ERRO) {     // se nao estiver vazia no final, causa erro
        cout << "error" << endl;
        return 0;
    }
    return resultado;
}
