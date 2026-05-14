#ifndef AVL_TREE_H
#define AVL_TREE_H

struct AVLNode {
    int key;
    int height;
    AVLNode *left;
    AVLNode *right;
};

class AVLTree {
public:
    AVLTree();
    ~AVLTree();

    void Insert(int key);
    void Delete(int key);
    AVLNode *Search(int key);

    void InOrder() const;
    void PreOrder() const;
    void PostOrder() const;

    bool VerifyBalance() const;

private:
    AVLNode *root_;

    AVLNode *Insert(AVLNode *node, int key);
    AVLNode *Delete(AVLNode *node, int key);
    AVLNode *Search(AVLNode *node, int key) const;

    void InOrder(AVLNode *node) const;
    void PreOrder(AVLNode *node) const;
    void PostOrder(AVLNode *node) const;

    bool VerifyBalance(AVLNode *node) const;

    int GetHeight(AVLNode *node) const;
    int GetBalanceFactor(AVLNode *node) const;
    void UpdateHeight(AVLNode *node);

    AVLNode *RotateLL(AVLNode *node);
    AVLNode *RotateRR(AVLNode *node);
    AVLNode *RotateLR(AVLNode *node);
    AVLNode *RotateRL(AVLNode *node);

    AVLNode *FindMin(AVLNode *node) const;
    void Destroy(AVLNode *node);
};

#endif
