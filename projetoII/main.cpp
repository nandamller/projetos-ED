// @ COPYRIGHT [2022] <Fernanda Müller e Pedro Nack>

/* EXEMPLOS DE SAÍDA
bear is prefix of 1 words
bear is at (0,149)
bu is prefix of 2 words
but is not prefix
stop is prefix of 1 words
*/

#include <fstream>
#include <iostream>

#include "./classes/Trie.h"

using namespace structures;

int main() {
    string input_string, file_name;

    getline(cin, input_string);

    for (int i = 0; i < 15; i++) {
        file_name += input_string[i];
    }    

    // Criando a árvore
    Trie trie = Trie(file_name);

    // apagando da entrada os caracteres que correspondem ao dicionário
    // input_string.erase(0, 13);
}