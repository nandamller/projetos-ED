// @ COPYRIGHT [2022] <Fernanda Müller e Pedro Nack>

#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <cstdint>
#include <tuple>
#include <string.h>

#include "TrieNode.h"

using namespace std;

const int ALPHABET_SIZE = 26;

namespace structures {

class Trie{
    public:
        /*
            Construtor da classe árvore de prefixos. O construtor será responsável
            por abrir o arquivo de dicionário e montar a árvore.

            @param dict -> nome do arquivo de dicionário a ser lido. 
        */
        Trie(string dict);

        // Destrutor da classe
        ~Trie();

        /*
            Método que adiciona uma palavra à árvore.

            @param word -> palavra a ser adicionada na árvore.
            @param position -> posição inicial da palavra.
            @param length -> comprimento da palavra.
        */ 
        void add(string word, int position, int length);

        /*
            Método que confere e retorna:
                1. Se a palavra é prefixo de outras palavras.
                2. Se for, retorna a quantidade de palavras que possuem a palavra
                passada por parâmetro como prefixo.
            
            @param  -> .
        */
        int check_prefix(string word);

        /*
            Método que retorna uma tupla com dois inteiros correspondentes ao
            index e o comprimento da palavra no dicionário, respectivamente.
            
            @param  word -> palavra a ser encontrada.
        */
        tuple<int, int> find_index(string word);

    private:
        // Nome do arquivo
        string dictionary;

        // Nó raiz
        TrieNode* root{nullptr};
};

} // namespace structures

#endif // MATRIX_H

structures::Trie::Trie(string dict) {
    root = new TrieNode(' ', 0, 0);

    dictionary = "./dictionaries/" + dict;
    ifstream file_dict(dictionary);

    string line;

    // criação da árvore a partir do dicionário
    if (file_dict.is_open()) {
        int pos = 0;
        while (getline(file_dict, line)) {
            
            string word;

            // loop p/ encontrar a palavra
            for (int i = 1; i < line.length(); i++) {
                if (line[i] == ']')
                    break;

                word += line[i];
            }

            int len = line.length() + pos;
            // inserindo a palavra na árvore
            add(word, pos, len);

            // atribuido a posição dentro do dicionário p/ saber para as próximas palavras
            pos += line.length() + 1;
        }
        file_dict.close();
    } else {
        cout << "error" << endl;
    }
}

structures::Trie::~Trie() {}

void structures::Trie::add(string word, int position, int length) {
    TrieNode* current_node = root;

    for (int i = 0; i < word.length(); i++) {
        int index = word[i]-'a';

        current_node->contains(index);

        // se o nó atual não possui esse char como filho
        if (!current_node->contains(index)) {
            TrieNode* new_node;

            // se for a última letra
            if (i == word.length()-1) {
                new_node = new TrieNode(word[i], position, length);
            }
            else {
                new_node = new TrieNode(word[i], 0, 0);
            }
            current_node->add_child(index, new_node);
        }
        current_node = current_node->get_children(index);
    }
}

int structures::Trie::check_prefix(string word) {
    TrieNode* current_node = root;

    int prefix;

    for (int i = 0; i < word.length(); i++) {
        /* se o nó atual não possui esse char como filho retorna 0 que vai ser
        tratado de alguma forma lá na frente */
        if (!current_node->contains(word[i])) {
            prefix = 0;
            break;
        }
        current_node = current_node->get_children(word[i]-'a');
        prefix = current_node->get_children_amount();
    }
    return prefix;
}

tuple<int, int> structures::Trie::find_index(string word) {
    TrieNode* current_node = root;

    tuple <int, int> index;
    for (int i = 0; i < word.length(); i++) {
        /* se o nó atual não possui esse char como filho retorna 0,0 que vai ser
        tratado de alguma forma lá na frente */
        if (!current_node->contains(word[i])) {
            index = make_tuple(0,0);
            break;
        }
        current_node = current_node->get_children(word[i]-'a');
        index = make_tuple(current_node->get_position(), current_node->get_length());
    }
    return index;
}