// بسم الله الرحمن الرحيم
// "وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define sz(x) (int)(x).size()
#define nl '\n'

// IMPORTANT : this version will not include any dublicates
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

        // else -> this node is already exsit and this version don't support dublicates
    }

    // [2] display BST
    void PreOrder(Node<T> *node)
    {
        if (!node)
            return;
        cout << node->val << " ";
        PreOrder(node->left);
        PreOrder(node->right);
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
        PostOrder(node->left);
        PostOrder(node->right);
        cout << node->val << " ";
    }

    // [3] Delete Node
    void DeleteNode(T item, Node<T> *&node)
    {
        if (!node)
            return;
        if (item < node->val)
        {
            DeleteNode(item, node->left);
        }
        else if (item > node->val)
        {
            DeleteNode(item, node->right);
        }
        else
        {
            if (!node->left && node->right) // if yor target is a leaf node
            {
                delete node;
                node = nullptr;
            }

            if (!node->left) // if you don't have left then your target in right place (leaf node)
            {
                Node<T> *temp = node;
                node = node->right;
                delete temp;
            }
            else if (!node->right) // if you don't have right then your target in left place (leaf node)
            {
                Node<T> *temp = node;
                node = node->left;
                delete temp;
            }
            else // this if your target isn't a leaf node so that you should resort the subtree after delete you target
            {
                Node<T> *suc = node->right;
                while (suc->left)
                    suc = suc->left;

                node->val = suc->val;
                DeleteNode(suc->val, node->right);
            }
        }
    }

    // -- Additional Funcions -- //
    T getMin(Node<T> *node)
    {
        if (node && node->left)
            return getMin(node->left);

        return node->val;
    }

    T getMax(Node<T> *node)
    {
        if (node && node->right)
            return getMax(node->right);
        return node->val;
    }

    bool SearchNode(T item, Node<T> *node)
    {
        if (!node)
            return 0;

        if (node->val == item)
            return 1;

        if (node->left)
            SearchNode(item, node->left);
        if (node->right)
            SearchNode(item, node->right);

        return 0;
    }

    // -- clean the memory -- //
    void clear(Node<T> *node) // save memory leak
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
    void insert(T item)
    {
        if (!root)
            return;
        insert(item, root);
    }

    // [2] display BST
    void PreOrder()
    {
        if (!root)
            return;
        PreOrder(root);
        cout << nl;
    }

    void InOrder()
    {
        if (!root)
            return;
        InOrder(root);
        cout << nl;
    }

    void PostOrder()
    {
        if (!root)
            return;
        PostOrder(root);
        cout << nl;
    }

    // [3] Deleting Node
    void DeleteNode(T item)
    {
        if (!root)
            return;

        if (SearchNode(item)) // this to know if value is found or not to can delte it if exist
            DeleteNode(item, root);
        else
            cout << "This Element is not found!" << nl;
    }

    // -- Additional General Functions --//
    T getMin()
    {
        if (!root)
            exit(1);
        return getMin(root);
    }

    T getMax()
    {
        if (!root)
            exit(1);
        return getMax(root);
    }

    bool SearchNode(T item)
    {
        if (!root)
            return 0;

        return SearchNode(item, root);
    }
};

signed main()
{

    return 0;
}
