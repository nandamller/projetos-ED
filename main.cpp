#include <iostream>
#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions
#include <string>
#include <fstream>
#include <unistd.h>


namespace structures {

template<typename T>
//! CLASSE PILHA
class ArrayStack {
 public:
    //! construtor simples
    ArrayStack();
    //! construtor com parametro tamanho
    explicit ArrayStack(std::size_t max);
    //! destrutor
    ~ArrayStack();
    //! metodo empilha
    void push(std::string data);
    //! metodo desempilha
    std::string pop();
    //! metodo retorna o topo
    std::string& top();
    //! metodo limpa pilha
    void clear();
    //! metodo retorna tamanho
    std::size_t size();
    //! metodo retorna capacidade maxima
    std::size_t max_size();
    //! verifica se esta vazia
    bool empty();
    //! verifica se esta cheia
    bool full();

 private:
    std::string* contents;
    int top_;
    std::size_t max_size_;

    static const auto DEFAULT_SIZE = 10u;
};

}  // namespace structures

template<typename T>
structures::ArrayStack<T>::ArrayStack() {
    max_size_ = DEFAULT_SIZE;
    contents = new std::string[max_size_];
    top_ = -1;
}

template<typename T>
structures::ArrayStack<T>::ArrayStack(std::size_t max) {
    max_size_ = max;
    contents = new std::string[max_size_];
    top_ = -1;
}

template<typename T>
structures::ArrayStack<T>::~ArrayStack() {
    delete [] contents;
}

template<typename T>
void structures::ArrayStack<T>::push(std::string data) {
    if (full()) {
        throw std::out_of_range("pilha cheia");
    } else {
        top_++;
        contents[top_] = data;
    }
}

template<typename T>
std::string structures::ArrayStack<T>::pop() {
    if (empty())
        throw std::out_of_range("pilha vazia");
    T aux;
    aux = contents[top_];
    top_--;
    return aux;
}

template<typename T>
std::string& structures::ArrayStack<T>::top() {
    if (empty())
        throw std::out_of_range("pilha vazia");
    return contents[top_];
}

template<typename T>
void structures::ArrayStack<T>::clear() {
    top_ = -1;
}

template<typename T>
std::size_t structures::ArrayStack<T>::size() {
    return top_ + 1;
}

template<typename T>
std::size_t structures::ArrayStack<T>::max_size() {
    return max_size_;
}

template<typename T>
bool structures::ArrayStack<T>::empty() {
    return (top_ +1 == 0);
}

template<typename T>
bool structures::ArrayStack<T>::full() {
    return (top_ == static_cast<int>(max_size()-1));
}

int main() {
    std::string nomes[100];
    std::string imagens[100];
    int alturas[100];
    int larguras[100];
    bool ERRO = false;
    char xmlfilename[100];
    int altura;
    int largura;
    structures::ArrayStack<std::string> pilha(500);

    std::cin >> xmlfilename;
    std::ifstream arquivo;
    arquivo.open(xmlfilename);
    std::string conteudos;
    std::string linha;
    int posicao = 0;
    while (getline(arquivo, linha)) {
        if (arquivo.eof()) {
            break;
        }
        for (int i = 0; i < linha.size(); i++) {  // checando cada caracter
            if (linha[i] == '<') {
                if (linha[i+1] != '/') {          // se nao for '/', esta empilhando
                    std::string tag("");
                    i++;
                    while (linha[i] != '>') {
                        tag += linha[i];
                        i++;
                    }
                    pilha.push(tag);
                } else {                             // se for '/', esta desempilhando
                    std::string tag("");
                    i++;
                    i++;
                    while (linha[i] != '>') {
                        tag += linha[i];
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
                    while (linha[i] != '<') {
                        width += linha[i];
                        i++;
                    }
                    largura = stoi(width);
                    larguras[posicao] = largura;
                    i--;
                } else if (pilha.top() == "height") { 
                    std::string height = "";
                    while (linha[i] != '<') {
                        height += linha[i];
                        i++;
                    }
                    i--;
                    altura = stoi(height);
                    alturas[posicao] = altura;
                } else if (pilha.top() == "name") {
                    std::string name = "";
                    while (linha[i] != '<') {
                        name += linha[i];
                        i++;
                    }
                    i--;
                    nomes[posicao] = name; 
                } else if (pilha.top() == "data") {
                    std::string data = "";
                    for (int p = 0; p < altura-1; p++) {
                        printf("%d\n", p);
                        for (int q = 0; q < largura; q++) {
                            data += linha[q];
                            i++;
                        }
                        getline(arquivo, linha);
                    }
                    imagens[posicao] = data;
                    i--;
                    posicao++;
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
    return 1;
} else {
    for (int i = 0; i < posicao; i++) {
        printf("altura: %d, largura: %d\n", altura, largura);
        printf("%s\n", nomes[i].c_str());
        printf("%s\n", imagens[i].c_str());
    }
}  
    arquivo.close();
    return 0;
}