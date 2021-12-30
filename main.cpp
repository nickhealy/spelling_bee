#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iterator>

#include "trie.hpp"

const std::string WORD_BANK_PATH = "words.txt";
const int LETTER_SAMPLE_SIZE = 7;

void load_word_list(Trie &root) {
    std::string word;

    std::ifstream Word_list(WORD_BANK_PATH);
    std::string test;

    while(Word_list >> word) {
        root.insert(word);
    }
    Word_list.close();
}

int main() {
    Trie root;
    std::string test;
    std::vector<std::string> words;
    std::vector<char> letters = {'y', 'r', 'b', 'l', 'a', 'o', 'd'};

    load_word_list(root);
    root.gather_words(letters, words);

    std::cout << "Here are the words " << std::endl;
    for (std::string word : words) {
        std::cout << word << std::endl;
    }

    return 0;
}