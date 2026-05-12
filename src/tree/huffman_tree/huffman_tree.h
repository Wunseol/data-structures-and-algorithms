#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <string>

struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode *left;
    HuffmanNode *right;
    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

class HuffmanTree {
public:
    HuffmanTree();
    ~HuffmanTree();

    void BuildHuffmanTree(const char chars[], const int freqs[], int n);
    void Encode();
    bool Decode(const std::string &bitstr);
    int CalculateWPL();

    bool IsBuilt() const { return root_ != nullptr; }

private:
    HuffmanNode *root_;
    std::string codes_[256];

    void Destroy(HuffmanNode *node);
    void GenerateCodes(HuffmanNode *node, const std::string &code);
    int CalculateWPL(HuffmanNode *node, int depth);
};

#endif
