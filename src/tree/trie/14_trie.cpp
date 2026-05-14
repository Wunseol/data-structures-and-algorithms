#include "14_trie.h"
#include <cstring>

TrieNode::TrieNode() : is_end(false), word_count(0)
{
    memset(children, 0, sizeof(children));
}

Trie::Trie()
{
    root_ = new TrieNode();
}

Trie::~Trie()
{
    Destroy(root_);
}

void Trie::Destroy(TrieNode *node)
{
    if (node) {
        for (int i = 0; i < 26; i++)
            Destroy(node->children[i]);
        delete node;
    }
}

void Trie::Insert(const std::string &word)
{
    TrieNode *cur = root_;
    for (char c : word) {
        int idx = c - 'a';
        if (idx < 0 || idx >= 26)
            return;
        if (!cur->children[idx])
            cur->children[idx] = new TrieNode();
        cur = cur->children[idx];
    }
    cur->is_end = true;
    cur->word_count++;
}

bool Trie::Search(const std::string &word) const
{
    TrieNode *cur = root_;
    for (char c : word) {
        int idx = c - 'a';
        if (idx < 0 || idx >= 26)
            return false;
        if (!cur->children[idx])
            return false;
        cur = cur->children[idx];
    }
    return cur->is_end;
}

bool Trie::StartsWith(const std::string &prefix) const
{
    TrieNode *cur = root_;
    for (char c : prefix) {
        int idx = c - 'a';
        if (idx < 0 || idx >= 26)
            return false;
        if (!cur->children[idx])
            return false;
        cur = cur->children[idx];
    }
    return true;
}

bool Trie::Delete(TrieNode *node, const std::string &word, int depth)
{
    if (!node)
        return false;

    if (depth == (int)word.size()) {
        if (!node->is_end)
            return false;
        node->word_count--;
        if (node->word_count == 0)
            node->is_end = false;
        for (int i = 0; i < 26; i++)
            if (node->children[i])
                return false;
        return node->word_count == 0;
    }

    int idx = word[depth] - 'a';
    if (idx < 0 || idx >= 26)
        return false;
    if (!node->children[idx])
        return false;

    bool should_delete_child = Delete(node->children[idx], word, depth + 1);
    if (should_delete_child) {
        delete node->children[idx];
        node->children[idx] = nullptr;
        if (!node->is_end) {
            for (int i = 0; i < 26; i++)
                if (node->children[i])
                    return false;
            return true;
        }
    }
    return false;
}

bool Trie::Delete(const std::string &word)
{
    if (!Search(word))
        return false;
    Delete(root_, word, 0);
    return true;
}

int Trie::CountWords(TrieNode *node) const
{
    if (!node)
        return 0;
    int count = node->word_count;
    for (int i = 0; i < 26; i++)
        count += CountWords(node->children[i]);
    return count;
}

int Trie::CountWords() const
{
    return CountWords(root_);
}
