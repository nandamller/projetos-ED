// @ COPYRIGHT [2022] <Fernanda Müller e Pedro Nack>

#ifndef TRIENODE_H
#define TRIENODE_H

#include <iostream>
#include <cstdint>
#include <string.h>

#include "LinkedList.h"

using namespace std;

namespace structures {

class TrieNode{
    public:
        /*
            Constrói uma classe para um nó da árvore.

            @param character -> catacter correspondente ao nó.
            @param position -> a posição do caracter inicial.
            @param length -> comprimento da linha.
        */

        // Construtor da classe
        TrieNode(char character, int position, int length);

        // Destrutor da classe
        ~TrieNode();

        /*
            Método que adiciona novos filhos ao nó. A quantidade máxima de filhos é o
            tamanho do dicionário.
    
            @param node -> nó que será adicionado como filho.
        */
        void add_child(int index, TrieNode* node);

        /*
            Método para setar a posição do nó.
    
            @param new_position -> nova posição.
        */
        void set_position(int new_position);
        
        /*
            Método para setar o comprimento do nó.
    
            @param new_length -> novo comprimento.
        */
        void set_length(int new_length);

        void increase_prefix_of();

        // Método que retorna a posição
        int get_position();

        // Método que retorna o comprimento
        int get_length();

        // Método que retorna o char correspondente ao nó.
        char get_char();

        int get_prefix_of();

        /*
            Método para verificar se determinado caracter é filho ou não desse nó.
            
            @param child_character -> caracter a ser encontrado (ou não).
        */
        bool contains(int index);

        /*
            Método que retorna o nó de determinado filho (caso possua este filho).
            
            @param child_character -> caracter a ser encontrado (ou não).
        */
        TrieNode* get_children(int index);

        /*
            Método que retorna a quantidade de filhos que o TrieNode possui
         */
        int get_children_amount();

    private:
        // Caracter correspondente ao nó
        char character;

        int prefix_of;

        // Lista de filhos do nó
        TrieNode* children[26];

        // Posição inicial da palavra e significado
        int position;

        // Comprimento da palavra e significado
        int length;

        // Quantidade de filhos
        int children_amount;
};

} // namespace structures

#endif

structures::TrieNode::TrieNode(char charac, int position1, int length1) {
    character = charac;
    position = position1;
    length = length1;
    children_amount = 0;
    prefix_of = 0;

    for (int i = 0; i < 26; i++) {
        children[i] = 0;
    }
}

structures::TrieNode::~TrieNode() {}

void structures::TrieNode::add_child(int index, TrieNode* node){
    children[index] = node;
    children_amount++;
}

void structures::TrieNode::set_position(int new_position) {
    position = new_position;
}

void structures::TrieNode::set_length(int new_length) {
    length = new_length;
}

int structures::TrieNode::get_position() {
    return position;
}

int structures::TrieNode::get_length() {
    return length;
}

int structures::TrieNode::get_prefix_of() {
    return prefix_of;
}

void structures::TrieNode::increase_prefix_of() {
    prefix_of++;
}

char structures::TrieNode::get_char() {
    return character;
}

structures::TrieNode* structures::TrieNode::get_children(int index) {
    return children[index];
}

bool structures::TrieNode::contains(int index) {
    if (children[index] != 0) {
        return true;
    }
    else {
        return false;
    }
}

int structures::TrieNode::get_children_amount() {
    return children_amount;
}
