// بسم الله الرحمن الرحيم
// "وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define sz(x) (int)(x).size()
#define nl '\n'

// the first thing you should to know this version will not include any duplicates
template <typename T>
class Node
{
public:
    T val;
    Node *left, *right;

    Node(T item) : val(item), left(nullptr), right(nullptr) {};
};

template <typename T>
class MyBST
{
private:
    Node<T> *root; // this is the root of the tree (the first pointer of the first node)

    // -- Main functions (private implementation) -- //

    // [1] insertion
    void insert(T item, Node<T> *node)
    {
        if (item < node->val)
        {
            if (!node->left)
                node->left = new Node<T>(item);
            else
                insert(item, node->left);
        }
        else if (item > node->val)
        {
            if (!node->right)
                node->right = new Node<T>(item);
            else
                insert(item, node->right);
        }

        // else -> this node is already exsit
    }

    // [2] display BST
    void PreOrder(Node<T> *node)
    {
        if (!node)
            return;
        cout << node->val << " ";
        PreOrder(node->left); PreOrder(node->right);
    }

    void InOrder(Node<T> *node)
    {
        if (!node)
            return;
        InOrder(node->left);
        cout << node->val << " ";
        InOrder(node->right);
    }

    void PostOrder(Node<T> *node)
    {
        if (!node)
            return;
        PostOrder(node->left); PostOrder(node->right);
        cout << node->val << " ";
    }

    

    // -- clean the memory -- //
    void clear(Node<T> *node)
    {
        if (!node)
            return;

        clear(node->left);
        clear(node->right);

        delete node;
    }

public:
    MyBST() = default;
    MyBST(T rootvale) { root = new Node<T>(rootvale); }
    ~MyBST() { clear(root); }

    // -- Main Functions -- //

    // [1] insertion
    void insert(T item) { if (!root) return; insert(item, root); }

    // [2] display BST
    void PreOrder() {if(!root) return; PreOrder(root); cout << nl;}
    void InOrder() {if(!root) return; InOrder(root); cout << nl;}
    void PostOrder() {if(!root) return; PostOrder(root); cout << nl;}
};

signed main()
{
    // MyBST tree(10);
    // tree.insert(20);
    // tree.insert(5);
    // tree.insert(3);
    // tree.insert(4);
    // tree.insert(2);
    // tree.InOrder();
    return 0;
}