#ifndef TRIE_H
#define TRIE_H

#include <string>

struct TrieNode {
    TrieNode *children[26];
    bool is_end;
    int word_count;

    TrieNode();
};

class Trie {
public:
    Trie();
    ~Trie();

    void Insert(const std::string &word);
    bool Search(const std::string &word) const;
    bool StartsWith(const std::string &prefix) const;
    bool Delete(const std::string &word);
    int CountWords() const;

private:
    TrieNode *root_;

    bool Delete(TrieNode *node, const std::string &word, int depth);
    void Destroy(TrieNode *node);
    int CountWords(TrieNode *node) const;
};

#endif
