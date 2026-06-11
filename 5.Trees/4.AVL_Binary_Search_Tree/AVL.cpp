// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define nl '\n'

// this tree is log(n) into search

template <typename T>
struct Node
{
    T val;
    Node<T> *left;
    Node<T> *right;
    int height;

    Node(T _v = 0)
    {
        val = _v, height = 1;
        left = right = nullptr;
    }
};

template <typename T>
class AVL
{
private:
    Node<T> *root;

    // helper functions
    int getHeight(Node<T> *node)
    {
        if (!node)
            return 0;

        return node->height;
    }

    int getBalancedFactor(Node<T> *node) // should be between [-1 : 1]
    {
        if (!node)
            return 0;

        return getHeight(node->left) - getHeight(node->right);
    }

    void updateHeight(Node<T> *node)
    {
        if (!node)
            return;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    // main functions

    /*
    Right Rotation

    Before:
            A
           /
          B
         /
        C

    After:
            B
           / \
          C   A

    A = unbalanced node
    B = left child of A
    C = left child of B
    */

    Node<T> *rightRotate(Node<T> *A)
    {
        Node<T> *B = A->left;
        Node<T> *x = B->right;

        B->right = A;
        A->left = x;

        updateHeight(A);
        updateHeight(B);

        return B;
    }

    /*
    Left Rotation

    Before:
        A
         \
          B
           \
            C

    After:
            B
           / \
          A   C

    A = unbalanced node
    B = right child of A
    C = right child of B
    */

    Node<T> *leftRotate(Node<T> *A)
    {
        Node<T> *B = A->right;
        Node<T> *x = B->left;

        B->left = A;
        A->right = x;

        updateHeight(A);
        updateHeight(B);

        return B;
    }

    // insert node && fix immediately (RR,LL,RL,LR)
    Node<T> *insert(Node<T> *node, T item)
    {
        if (!node)
            return new Node<T>(item);

        if (item < node->val)
            node->left = insert(node->left, item);
        else if (item > node->val)
            node->right = insert(node->right, item);
        else
            return node;

        updateHeight(node);
        int balance = getBalancedFactor(node);

        // LL
        if (balance > 1 && item < node->left->val)
            return rightRotate(node);

        // RR
        if (balance < -1 && item > node->right->val)
            return leftRotate(node);

        // LR
        if (balance > 1 && item > node->left->val)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL
        if (balance < -1 && item < node->right->val)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // trav
    void inorder(Node<T> *node)
    {
        if (!node)
            return;

        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

public:
    AVL() : root(nullptr) {}

    void insert(T item)
    {
        if (!root)
            root = new Node(item);
        else
            root = insert(root, item);
    }

    void display() // inOrder traversal
    {
        inorder(root);
        cout << nl;
    }
};

int main()
{
}