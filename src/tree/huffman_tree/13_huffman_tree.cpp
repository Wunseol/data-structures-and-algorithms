#include "13_huffman_tree.h"
#include <cstdio>
#include <cstring>
#include <queue>
#include <functional>
#include <string>

struct CompareNode {
    bool operator()(HuffmanNode *a, HuffmanNode *b) const
    {
        return a->freq > b->freq;
    }
};

HuffmanTree::HuffmanTree() : root_(nullptr) {}

HuffmanTree::~HuffmanTree()
{
    Destroy(root_);
}

void HuffmanTree::Destroy(HuffmanNode *node)
{
    if (node) {
        Destroy(node->left);
        Destroy(node->right);
        delete node;
    }
}

void HuffmanTree::BuildHuffmanTree(const char chars[], const int freqs[], int n)
{
    Destroy(root_);
    root_ = nullptr;
    for (int i = 0; i < 256; i++)
        codes_[i].clear();

    std::priority_queue<HuffmanNode *, std::vector<HuffmanNode *>, CompareNode> pq;
    for (int i = 0; i < n; i++)
        pq.push(new HuffmanNode(chars[i], freqs[i]));

    while (pq.size() > 1) {
        HuffmanNode *left = pq.top();
        pq.pop();
        HuffmanNode *right = pq.top();
        pq.pop();
        HuffmanNode *parent = new HuffmanNode('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    if (!pq.empty())
        root_ = pq.top();

    GenerateCodes(root_, "");
}

void HuffmanTree::GenerateCodes(HuffmanNode *node, const std::string &code)
{
    if (!node)
        return;
    if (!node->left && !node->right) {
        codes_[(unsigned char)node->ch] = code;
        return;
    }
    GenerateCodes(node->left, code + "0");
    GenerateCodes(node->right, code + "1");
}

void HuffmanTree::Encode()
{
    if (!root_) {
        printf("哈夫曼树尚未构建\n");
        return;
    }
    printf("哈夫曼编码:\n");
    bool has_leaf = false;
    for (int i = 0; i < 256; i++) {
        if (!codes_[i].empty()) {
            if (i >= 32 && i < 127)
                printf("  '%c': %s\n", (char)i, codes_[i].c_str());
            else
                printf("  (ASCII %d): %s\n", i, codes_[i].c_str());
            has_leaf = true;
        }
    }
    if (!has_leaf && root_) {
        printf("  (单节点树，无编码)\n");
    }
}

bool HuffmanTree::Decode(const std::string &bitstr)
{
    if (!root_) {
        printf("哈夫曼树尚未构建\n");
        return false;
    }
    if (bitstr.empty()) {
        printf("解码结果: (空)\n");
        return true;
    }
    printf("解码结果: ");
    HuffmanNode *cur = root_;
    bool decoded = false;
    for (size_t i = 0; i < bitstr.size(); i++) {
        if (bitstr[i] == '0')
            cur = cur->left;
        else if (bitstr[i] == '1')
            cur = cur->right;
        else {
            printf("\n无效字符 '%c'，仅接受0和1\n", bitstr[i]);
            return false;
        }
        if (!cur) {
            printf("\n解码失败，比特串无效\n");
            return false;
        }
        if (!cur->left && !cur->right) {
            printf("%c", cur->ch);
            cur = root_;
            decoded = true;
        }
    }
    if (cur != root_) {
        printf("\n警告: 比特串末尾不完整\n");
    }
    printf("\n");
    return decoded || (root_ && !root_->left && !root_->right);
}

int HuffmanTree::CalculateWPL()
{
    if (!root_)
        return 0;
    return CalculateWPL(root_, 0);
}

int HuffmanTree::CalculateWPL(HuffmanNode *node, int depth)
{
    if (!node)
        return 0;
    if (!node->left && !node->right)
        return node->freq * depth;
    return CalculateWPL(node->left, depth + 1) + CalculateWPL(node->right, depth + 1);
}
