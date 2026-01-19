// بسم الله الرحمن الرحيم
// "وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define sz(x) (int)(x).size()
#define nl '\n'

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
    void insert(T item, Node<T> *node)
    {
        if (item < node->val)
        {
            if (!node->left)
                node->left = new Node<T>(item);
            else
                insert(val, node->left);
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
    ~MyBST() { clear(root) };

    // -- Main Functions -- //
    void insert(T item)
    {
    }
};

signed main()
{

    return 0;
}