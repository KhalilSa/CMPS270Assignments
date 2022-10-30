#ifndef my_btree_h
#define my_btree_h

#define SPACE_BETWEEN_LEVELS 5
/*
    Binary TreeNode structure of generic type either character or integer
    stores generic data
    a pointer to the left child
    a pointer to the right child
*/
template <typename T> struct TreeNode {
    T data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// main functions
template<typename T> TreeNode<T>* createNode(T data);
template<typename T> TreeNode<T>* addNode(TreeNode<T> *root, T data);
template<typename T> TreeNode<T>* deleteNode(TreeNode<T> *root, T data);
template<typename T> int treeSize(TreeNode<T> *root);
template<typename T> int subtreeSize(TreeNode<T> *root, T data);

// helper functions
template<typename T> TreeNode<T>* findSubtree(TreeNode<T> *root, T data);
template<typename T> void print2DUtil(TreeNode<T> *root, int space);

// printing functions
template<typename T> void preOrderPrint(TreeNode<T> *root);
template<typename T> void inOrderPrint(TreeNode<T> *root);
template<typename T> void postOrderPrint(TreeNode<T> *root);
template<typename T> void printBFT(TreeNode<T> *root);
template<typename T> void print2D(TreeNode<T> *root);

#endif