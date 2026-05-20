//
// Created by Aya on 2026-05-20.
//

#ifndef LEARNING_DATA_STRUCTURE_BINARYTREE_H
#define LEARNING_DATA_STRUCTURE_BINARYTREE_H
template<typename T>
struct BTNode{
    T info;
    BTNode* right;
    BTNode* left;

    BTNode()
    {
        this->right= nullptr;
        this->left = nullptr;
    }
};
template<typename T>
class BinaryTree
{
protected:
    BTNode<T>* root;
public:
    const BinaryTree<T>& operator=(const BinaryTree<T>& BT);
    bool isEmpty() const;
    int heightOfTheTree() const;//height of the tree
    int numberOfNodes() const;// number of the nodes
    int numberOfLeaves()const; // number of leaves
    //traverse
    void printInOrder() const;//LNR
    void printPostOrder() const;//LRN
    void printPreOrder() const;//RNL
    void destroy();
    BinaryTree(const BinaryTree<T>& other);
    BinaryTree();
    ~BinaryTree();
private:
    void copyTree(BTNode<T>* & copiedTreeNode , BTNode<T>* & otherTreeRoot);
    void destroyTree(BTNode<T>* & node);
    void inorder(BTNode<T>* node) const;
    void preorder(BTNode<T>* node) const;
    void postOrder(BTNode<T>* node) const;
    int height(BTNode<T>* node) const;
    int countNode(BTNode<T>* node)const;
    int countLeaves(BTNode<T>* node) const;
};
#include "BinaryTree.tpp"

#endif //LEARNING_DATA_STRUCTURE_BINARYTREE_H