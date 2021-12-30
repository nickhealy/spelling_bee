#ifndef TRIE
#define TRIE

#include <string>
#include <vector>

const int NUM_LETTERS = 26;
#define charToInt(ch) ((ch) - 'a');
#define intToChar

class Trie {
    public:
        Trie();
        bool isLeaf;
        Trie * children[NUM_LETTERS];
        void insert(std::string word);
        bool search(std::string word);
        std::vector<std::string> gather_words(std::vector<char> & letters, std::vector<std::string> & valid_words);
    private: 
        void create_children();
};

#endif