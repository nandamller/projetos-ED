// @ COPYRIGHT [2022] <Fernanda Müller e Pedro Nack>

#include <fstream>
#include <iostream>
#include <tuple>

#include "./classes/LinkedList.h"
#include "./classes/Trie.h"

using namespace structures;

int main() {
    std::string input_string, file_name, to_search;

    getline(cin, input_string);

    
    int start = 0;

    for (int i = 0; i < input_string.length(); i++) {
        if (input_string[i] == ' ') {
            start = i + 1;
            break;
        }
        file_name += input_string[i];
    }

    LinkedList<string> words_to_search;

    to_search = "";

    for (int i = start; i < input_string.length(); i++) {
        if (input_string[i] != ' ') {
            to_search += input_string[i];
        }
        else {
            words_to_search.push_back(to_search);
            to_search = "";
        }
    }

    // Criando a árvore
    Trie trie = Trie(file_name);

    string word;
    
    while (1) {  // leitura das palavras ate' encontrar "0"
        word = words_to_search.pop_front();
        if (trie.check_prefix_amount(word) == 0) {
            cout << word << " is not prefix" << endl;
        } else {
            cout << word << " is prefix of " << trie.check_prefix_amount(word) << " words" << endl;
            tuple<int, int> values;
            
            values = trie.find_index(word);

            if (get<0>(values) != 0 || get<1>(values) != 0) {
                cout << word << " is at (" << get<0>(values) << "," << get<1>(values) << ")" << endl;
            }
        }
        if (words_to_search.empty()) {
            break;
        }
    }
    
}