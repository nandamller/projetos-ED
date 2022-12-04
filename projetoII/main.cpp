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

    string word;
    
    while (1) {  // leitura das palavras ate' encontrar "0"
        cin >> word;
        if (word.compare("0") == 0) {
            break;
        }
        if (trie.check_prefix_amount(word) == 0) {
            cout << word << " is not prefix" << endl;
        } else {
            cout << word << " is prefix of " << trie.check_prefix_amount(word) << " words" << endl;
        }
    }
    // apagando da entrada os caracteres que correspondem ao dicionário
    // input_string.erase(0, 13);
}