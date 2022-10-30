#include <iostream>
#include <queue>
#include <assert.h>
#include "my_btree.hpp"

using namespace std;

// driver code
int main()
{
    TreeNode<char> *charTree = new TreeNode<char>();
    TreeNode<int> *intTree = new TreeNode<int>();

    charTree->data = 'a';
    addNode(charTree, 'b');
    addNode(charTree, 'c');
    charTree->right->left = createNode('e');
    addNode(charTree, 'd');
    print2D(charTree);
    printBFT(charTree);
    cout << "Char Tree Size: " << treeSize(charTree) << endl;
    cout << "Int Sub Tree 'b' Size: " << subtreeSize(charTree, 'b') << endl;
    cout << "Int Sub Tree 'k' Size: " << subtreeSize(charTree, 'k') << endl;

    cout << "Deleting Node 'd'" << endl;
    charTree = deleteNode(charTree, 'd');
    print2D(charTree);
    cout << "print preoder:" << endl;
    preOrderPrint(charTree);
    cout << endl;
    cout << "print inoder:" << endl;
    inOrderPrint(charTree);
    cout << endl;
    cout << "print postoder:" << endl;
    postOrderPrint(charTree);
    cout << endl;

    cout << endl;

    cout << "Creating new int tree ..." << endl;
    intTree->data = 100;
    addNode(intTree, 123);
    addNode(intTree, 34);
    intTree->right->left = createNode(45);
    addNode(intTree, 76);
    print2D(intTree);
    printBFT(intTree);

    cout << "Deleting Node 76 ..." << endl;
    intTree = deleteNode(intTree, 76);
    print2D(intTree);
    cout << "Int Tree Size: " << treeSize(intTree) << endl;
    addNode(intTree, 65);
    addNode(intTree, -45);
    addNode(intTree, 12); 
    addNode(intTree, -34);
    print2D(intTree);

    assert(subtreeSize(intTree, intTree->data) == treeSize(intTree));
    assert(subtreeSize(intTree, 0) == 0);
    assert(subtreeSize(intTree, 45) == 1);
    cout << "Int Sub Tree 34 Size: " << subtreeSize(intTree, 34) << endl;
    cout << "Int Sub Tree 123 Size: " << subtreeSize(intTree, 123) << endl << endl;

    cout << "print preoder:" << endl;
    preOrderPrint(intTree);
    cout << endl;
    cout << "print inoder:" << endl;
    inOrderPrint(intTree);
    cout << endl;
    cout << "print postoder:" << endl;
    postOrderPrint(intTree);
    cout << endl;


    return 0;
}

/*
    description:
        creates new tree node in the heap, returns pointer to the node
    precondtion: non-null data
    returns: a pointer to the new created node
*/
template<typename T> TreeNode<T>* createNode(T data) {
    TreeNode<T> *node = new TreeNode<T>();
    if (!node) {
        cout << "Memory Error" << endl;
        return NULL;
    }
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

/*
    description: 
        adds new node to the tree
    precondition:
        non null data (char or int)
    returns: 
        a pointer to the new created node
*/
template<typename T> TreeNode<T>* addNode(TreeNode<T> *root, T data) {
    // the idea is to do a bfs traversal using a queue
    // add the node to the first node that doesn't have two children

    // if the tree is empty create the first node as root
    if (root == nullptr) {
        root = createNode(data);
        return root;
    }

    // else traverse the tree using queue
    // looking for first node with zero or only one child
    queue<TreeNode<T>*> queue;
    queue.push(root);
    while (!queue.empty()) {
        TreeNode<T> *curr = queue.front();
        queue.pop();
        // if the current node doesn't have a left child 
        // add a left child and return
        // otherwise push left child to the queue
        if (curr->left == nullptr) {
            curr->left = createNode(data);
            return root;
        } else {
            queue.push(curr->left);
        }

        // similarly, if the current node doesn't have a right child 
        // add a right child and return
        // otherwise push right child to the queue
        if (curr->right == nullptr) {
            curr->right = createNode(data);
            return root;
        } else {
            queue.push(curr->right);
        }
    }

    cout << "Unexpected Error" << endl;
    return nullptr;
}

/*
    Description: 
        delete node if it has no children
    precondition:
        non empty (null) tree, non null data (char or int)
    returns: 
        a pointer to the new modified tree
*/
template<typename T> TreeNode<T>* deleteNode(TreeNode<T> *root, T data) {
    // return nullptr if the root is null
    if (root == nullptr) {
        return nullptr;
    }

    // traverse left and right subtrees
    // updating any changes
    root->left = deleteNode(root->left, data);
    root->right = deleteNode(root->right, data);

    // if has the specefied key 
    if (root->data == data) {
        // but has no children, return nullptr
        // thus setting the parent pointer to nullptr
        // efectiverly deleting the node
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // otherwise (non-leaf), print cannot delete node
        cout << "CANNOT DELETE NODE" << endl;
    }
    return root;
}

/*
    description:
        calculates the size of a given tree
    returns:
        the size of the tree
*/
template<typename T> int treeSize(TreeNode<T> *root) {
    // tree size = size of the left subtree + size of the right subtree + 1
    if (root) {
        return treeSize(root->left) + treeSize(root->right) + 1;
    }
    return 0;
}

/*
    description:
        calculate the size of a subtree
    preconditions:
        valid data 
    returns:
        size of the subtree if found, 0 otherwise
*/
template<typename T> int subtreeSize(TreeNode<T> *root, T data) {
    TreeNode<T> *subtreeRoot = findSubtree(root, data);
    if (subtreeRoot == nullptr) return 0;
    return treeSize(subtreeRoot);
}

/*
    description:
        returns a pointer to the node that has the specified key
        returns null if key isn't found
*/
template<typename T> TreeNode<T>* findSubtree(TreeNode<T> *root, T data) {
    if (root == nullptr) return nullptr;
    if (root->data == data) return root;

    TreeNode<T> *left = findSubtree(root->left, data);
    TreeNode<T> *right = findSubtree(root->right, data);
    if (left != nullptr)
        return left;
    if (right != nullptr)
        return right;
    return nullptr;
}

/*
    description:
        traverse the tree preoder while printing nodes' data
*/
template<typename T> void preOrderPrint(TreeNode<T> *root) {
    if (root) {
        cout << root->data << " ";
        preOrderPrint(root->left);
        preOrderPrint(root->right);
    }
}

/*
    description:
        printing the nodes' data inorder
*/
template<typename T> void inOrderPrint(TreeNode<T> *root) {
    if (root) {
        inOrderPrint(root->left);
        cout << root->data << " ";
        inOrderPrint(root->right);
    }
}

/*
    description:
        traverse the tree postorder while printing nodes' data
*/
template<typename T> void postOrderPrint(TreeNode<T> *root) {
    if (root) {
        postOrderPrint(root->left);
        postOrderPrint(root->right);
        cout << root->data << " ";
    }
}

/*
    description: 
        print nodes' data while doing a breadth first traversal (BFT) to the tree
*/
template<typename T> void printBFT(TreeNode<T> *root) {
    if (root == nullptr) {
        cout << "Nothing to print" << endl;
        return;
    }

    queue<TreeNode<T>*> queue;
    queue.push(root);
    while (!queue.empty()) {
        TreeNode<T> *curr = queue.front();
        queue.pop();

        cout << curr->data << " ";
        
        if (curr->left != nullptr) {
            queue.push(curr->left);
        }

        if (curr->right != nullptr) {
            queue.push(curr->right);
        }
    }
    cout << endl;
}


// Source: https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
// Function to print binary tree in 2D
// It does reverse inorder traversal
template<typename T> void print2DUtil(TreeNode<T> *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += SPACE_BETWEEN_LEVELS;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    cout << endl;
    for (int i = SPACE_BETWEEN_LEVELS; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
template<typename T> void print2D(TreeNode<T> *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

