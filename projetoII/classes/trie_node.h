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
            Constrói uma classe .
        */

        // Construtor da classe
        TrieNode(char character, int position, int length);

        // Destrutor da classe
        ~TrieNode();

        //
        add_child(TrieNode node);

        //
        set_position(int new_position);
        
        //
        set_length(int new_length);

        //
        get_char();

        //
        contains(char child_character);

    private:
        // 
        char character;

        // 
        LinkedList<TrieNode> children;

        // 
        int position;

        //
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

bool structures::TrieNode::contains(char child_character) {
    for (int i = 0; i < children.size(); i++) {
        if (children.at(i).get_char() == child_character)
            return true;
    }

    return false;
}

