// @ COPYRIGHT [2022] <Fernanda Müller e Pedro Nack>

#ifndef TRIE_NODE_H
#define TRIE_NODE_H

#include <iostream>
#include <cstdint>
#include <string.h>

#include "linked_list.h"

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
        add_child(TrieNode node);

        /*
            Método para setar a posição do nó.
    
            @param new_position -> nova posição.
        */
        set_position(int new_position);
        
        /*
            Método para setar o comprimento do nó.
    
            @param new_length -> novo comprimento.
        */
        set_length(int new_length);

        // Método retorna o char correspondente ao nó.
        get_char();

        /*
            Método para verificar se determinado caracter é filho ou não desse nó.
            
            @param child_character -> caracter a ser encontrado (ou não).
        */
        contains(char child_character);

        /*
            Método que retorna o nó de determinado filho (caso possua este filho).
            
            @param child_character -> caracter a ser encontrado (ou não).
        */
        get_children(char child_character);

    private:
        // Caracter correspondente ao nó
        char character;

        // Lista de filhos do nó
        LinkedList<TrieNode> children;

        // Posição inicial da palavra e significado
        int position;

        // Comprimento da palavra e significado
        int length;
};

} // namespace structures

#endif

structures::TrieNode::TrieNode(char character, int position, int length) {
    character = character;
    position = position;
    length = length;
}

structures::TrieNode::~TrieNode() {}

void structures::TrieNode::add_child(TrieNode node){
    children.push_back(node);
}

void structures::TrieNode::set_position(int new_position) {
    position = new_position;
}

void structures::TrieNode::set_length(int new_length) {
    length = new_length;
}

char structures::TrieNode::get_char() {
    return character;
}

TrieNode* structures::TrieNode::get_children(char child_character) {
    for (int i = 0; i < children.size(); i++) {
        if (children.at(i).get_char() == child_character)
            return children.at(i);
    }
}

bool structures::TrieNode::contains(char child_character) {
    for (int i = 0; i < children.size(); i++) {
        if (children.at(i).get_char() == child_character)
            return true;
    }

    return false;
}

