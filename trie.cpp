#include <iostream>
#include <string>
#include <vector>

#include "trie.hpp"

#define charToInt(ch) ((ch) - 'a');

Trie::Trie() {
    isLeaf = false;
    this->create_children();
}

void Trie::create_children() {
    for (int i = 0; i < NUM_LETTERS; i++) {
        children[i] = NULL;
    }
}

void Trie::insert(std::string word) {    
    Trie * currNode = this;
    for (int i = 0; i < word.length(); i++) {
        int idx = charToInt(word[i]);
        if (currNode->children[idx] == NULL) {
            currNode->children[idx] = new Trie();
        }
        currNode = currNode->children[idx];
    }

    currNode->isLeaf = true;
}

bool Trie::search(std::string word) {
    Trie * currNode = this;
    for (int i = 0; i < word.length(); i++) {
        int idx = charToInt(word[i]);
        if (currNode->children[idx] == NULL) {
            return false;
        }

        currNode = currNode->children[idx];
    }

    if (currNode->isLeaf) {
        return true;
    }

    return false;
}

void _search_children_for_words( 
    std::vector<char> & letters, 
    Trie * currNode, 
    std::vector<std::string> & valid_words, 
    char current_letter,
    std::string current_string = "")
{
    std::string next_string;
    char pivot = letters[0];

    if (currNode == NULL) {
        return;
    }

    next_string = current_string += current_letter;

    if (currNode->isLeaf) {
        valid_words.push_back(next_string);
    }

    for (char letter : letters) {
        int idx = charToInt(letter)
        _search_children_for_words(letters, currNode->children[idx], valid_words, letter, next_string);
    }
}

std::vector<std::string> Trie::gather_words(std::vector<char> & letters, std::vector<std::string> & valid_words) {
    for (char letter : letters) {
        int idx = charToInt(letter);
        _search_children_for_words(letters, this->children[idx], valid_words, letter);
    }

    return valid_words;
}


