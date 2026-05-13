#include "avl_tree.h"
#include <cstdio>
#include <algorithm>

AVLTree::AVLTree() : root_(nullptr) {}

AVLTree::~AVLTree()
{
    Destroy(root_);
}

void AVLTree::Destroy(AVLNode *node)
{
    if (node) {
        Destroy(node->left);
        Destroy(node->right);
        delete node;
    }
}

int AVLTree::GetHeight(AVLNode *node) const
{
    return node ? node->height : 0;
}

int AVLTree::GetBalanceFactor(AVLNode *node) const
{
    return node ? GetHeight(node->left) - GetHeight(node->right) : 0;
}

void AVLTree::UpdateHeight(AVLNode *node)
{
    if (node)
        node->height = 1 + std::max(GetHeight(node->left), GetHeight(node->right));
}

AVLNode *AVLTree::RotateLL(AVLNode *node)
{
    AVLNode *left_child = node->left;
    node->left = left_child->right;
    left_child->right = node;
    UpdateHeight(node);
    UpdateHeight(left_child);
    return left_child;
}

AVLNode *AVLTree::RotateRR(AVLNode *node)
{
    AVLNode *right_child = node->right;
    node->right = right_child->left;
    right_child->left = node;
    UpdateHeight(node);
    UpdateHeight(right_child);
    return right_child;
}

AVLNode *AVLTree::RotateLR(AVLNode *node)
{
    node->left = RotateRR(node->left);
    return RotateLL(node);
}

AVLNode *AVLTree::RotateRL(AVLNode *node)
{
    node->right = RotateLL(node->right);
    return RotateRR(node);
}

AVLNode *AVLTree::Insert(AVLNode *node, int key)
{
    if (!node) {
        node = new AVLNode{key, 1, nullptr, nullptr};
        return node;
    }
    if (key < node->key)
        node->left = Insert(node->left, key);
    else if (key > node->key)
        node->right = Insert(node->right, key);
    else
        return node;

    UpdateHeight(node);

    int bf = GetBalanceFactor(node);
    if (bf > 1 && key < node->left->key)
        return RotateLL(node);
    if (bf < -1 && key > node->right->key)
        return RotateRR(node);
    if (bf > 1 && key > node->left->key)
        return RotateLR(node);
    if (bf < -1 && key < node->right->key)
        return RotateRL(node);

    return node;
}

AVLNode *AVLTree::FindMin(AVLNode *node) const
{
    while (node && node->left)
        node = node->left;
    return node;
}

AVLNode *AVLTree::Delete(AVLNode *node, int key)
{
    if (!node)
        return nullptr;

    if (key < node->key)
        node->left = Delete(node->left, key);
    else if (key > node->key)
        node->right = Delete(node->right, key);
    else {
        if (!node->left || !node->right) {
            AVLNode *child = node->left ? node->left : node->right;
            delete node;
            return child;
        }
        AVLNode *successor = FindMin(node->right);
        node->key = successor->key;
        node->right = Delete(node->right, successor->key);
    }

    UpdateHeight(node);

    int bf = GetBalanceFactor(node);
    if (bf > 1 && GetBalanceFactor(node->left) >= 0)
        return RotateLL(node);
    if (bf > 1 && GetBalanceFactor(node->left) < 0)
        return RotateLR(node);
    if (bf < -1 && GetBalanceFactor(node->right) <= 0)
        return RotateRR(node);
    if (bf < -1 && GetBalanceFactor(node->right) > 0)
        return RotateRL(node);

    return node;
}

AVLNode *AVLTree::Search(AVLNode *node, int key) const
{
    if (!node || node->key == key)
        return node;
    if (key < node->key)
        return Search(node->left, key);
    return Search(node->right, key);
}

void AVLTree::InOrder(AVLNode *node) const
{
    if (node) {
        InOrder(node->left);
        printf("%d(bf=%d) ", node->key, GetBalanceFactor(node));
        InOrder(node->right);
    }
}

void AVLTree::PreOrder(AVLNode *node) const
{
    if (node) {
        printf("%d(bf=%d) ", node->key, GetBalanceFactor(node));
        PreOrder(node->left);
        PreOrder(node->right);
    }
}

void AVLTree::PostOrder(AVLNode *node) const
{
    if (node) {
        PostOrder(node->left);
        PostOrder(node->right);
        printf("%d(bf=%d) ", node->key, GetBalanceFactor(node));
    }
}

bool AVLTree::VerifyBalance(AVLNode *node) const
{
    if (!node)
        return true;
    int bf = GetBalanceFactor(node);
    if (bf < -1 || bf > 1)
        return false;
    return VerifyBalance(node->left) && VerifyBalance(node->right);
}

void AVLTree::Insert(int key)
{
    root_ = Insert(root_, key);
}

void AVLTree::Delete(int key)
{
    root_ = Delete(root_, key);
}

AVLNode *AVLTree::Search(int key)
{
    return Search(root_, key);
}

void AVLTree::InOrder() const
{
    if (!root_) {
        printf("AVL树为空\n");
        return;
    }
    printf("中序遍历: ");
    InOrder(root_);
    printf("\n");
}

void AVLTree::PreOrder() const
{
    if (!root_) {
        printf("AVL树为空\n");
        return;
    }
    printf("先序遍历: ");
    PreOrder(root_);
    printf("\n");
}

void AVLTree::PostOrder() const
{
    if (!root_) {
        printf("AVL树为空\n");
        return;
    }
    printf("后序遍历: ");
    PostOrder(root_);
    printf("\n");
}

bool AVLTree::VerifyBalance() const
{
    return VerifyBalance(root_);
}
