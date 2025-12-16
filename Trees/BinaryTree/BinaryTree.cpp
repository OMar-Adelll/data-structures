// بسم الله الرحمن الرحيم
// "وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define fixed(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) (int)(x).size()
#define Mod 1000000007
#define EPS 1e-9
#define updmax(a, b) a = max(a, b)
#define updmin(a, b) a = min(a, b)
#define nl '\n'
#define pi acos(-1.0)

template <typename T>
class Node
{
public:
    T val;
    Node *left;
    Node *right;

    Node(T v) : val(v), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree
{
private:
    Node<T> *root;

    // -- Private Functions -- //
    // All of these traversal styles belong to the same category: Depth-First Search (DFS)
    void inOrder(Node<T> *root) // LVR: left, current value, right
    {
        if (!root)
            return;
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }

    void preOrder(Node<T> *root) // VLR: current value, left, right
    {
        if (!root)
            return;
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(Node<T> *root) // LRV: left, right, current value
    {
        if (!root)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << " ";
    }

public:
    BinaryTree() { root = nullptr; }
};

signed main()
{
    return 0;
}
