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
    Node *left;
    Node *right;

    Node(T v) : val(v), left(nullptr), right(nullptr) {}
};

template <typename T>
class MyBT
{
private:
    Node<T> *root;

    // -- Private Functions -- //

    // -- Display section -- //
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

    // // this type is Breadth First Search -> BFS
    // void display_LevelByLevel()
    // {
    //     if (!root)
    //         return;
    // }

    // -- Additional Private Helper Functions -- //
    void clear(Node<T> *node)
    {
        if (!node)
            return;
        clear(node->left);
        clear(node->right);
    }

    T TreeMax(Node<T> *root)
    {
        if (!root->left && !root->right)
            return root->val;

        T maxi = root->val;
        if (root->left)
            maxi = max(maxi, TreeMax(root->left));
        if (root->right)
            maxi = max(maxi, TreeMax(root->right));

        return maxi;
    }

    int TreeHeight(Node<T> *root)
    {
        if (!root)
            return 0;

        return 1 + max(TreeHeight(root->left), TreeHeight(root->right));
    }

    int TreeCount(Node<T> *root)
    {
        if (!root)
            return 0;

        return 1 + TreeCount(root->left) + TreeCount(root->right);
    }

    int LeavesCount(Node<T> *root)
    {
        int rs = !root->left && !root->right;

        if (root->left)
            rs += LeavesCount(root->left);

        if (root->right)
            rs += LeavesCount(root->right);

        return rs;
    }

    bool TreeSearch(Node<T> *root, T item)
    {
        bool rs = root->val = item;
        if (!rs && root->left)
            rs = TreeSearch(root->left, item);
        if (!rs && root->right)
            rs = TreeSearch(root->right, item);

        return rs;
    }

    bool isPerfect(Node<T> *root, int h = -1) // tree is perfect when all leaves are the same height so that we check with height
    {
        if (h == -1)
            h = TreeHeight(root);

        if (!root->left && !root->right)
            return 1;

        if ((!root->left && root->right) || (!root->right && root->left))
            return false; // your tree isn't perfect

        return isPerfect(root->left, h - 1) && isPerfect(root->right, h - 1);
    }

    void LeftBoundary(Node<T> *root) // display left boundary nodes only
    {
        if (!root)
            return;
        cout << root->val << " ";
        LeftBoundary(root->left);
    }

    void RightBoundary(Node<T> *root)
    {
        if (!root)
            return;

        cout << root->val << " ";
        RightBoundary(root->right);
    }

    pair<int, int> diameterOfTree(Node<T> *root) // the longest len between two nodes
    {
        if (!root)
            return {0, 0};

        auto l = diameterOfTree(root->left);
        auto r = diameterOfTree(root->right);

        int h = 1 + max(l.second, r.second);

        int diameterOfRoot = l.second + r.second;
        int diameter = max({diameterOfRoot, l.second, r.second});

        return {diameter, h};
    }

public:
    MyBT() : root(nullptr) {}                        // default constructor
    MyBT(T rootVal) { root = new Node<T>(rootVal); } // Parameterized constructor
    ~MyBT() { clear(root); }                         // save memory leak

    // -- Main Functions -- //
    void setRoot(T item) // this function to initialize root
    {
        if (root)
            return;
        root = new Node<T>(item);
    }

    void reSetRoot(T item) // this function to give new value to your root (root already exist)
    {
        if (!root)
            return;

        root->val = item;
    }

    void addByPath(vector<char> path, T item) // this function to add by path (you should give the path and the value)
    {
        if (!root)
        {
            assert(root != nullptr && "root should not be null");
        }

        Node<T> *trav = root;
        for (int i = 0; i < sz(path); i++)
        {
            char direction = tolower(path[i]);
            assert(direction == 'l' || direction == 'L' || direction == 'r' || direction == 'R');
            if (direction == 'l')
            {
                if (!trav->left)
                    trav->left = new Node<T>(item);

                trav = trav->left;
            }
            else
            {
                if (!trav->right)
                    trav->right = new Node<T>(item);
                trav = trav->right;
            }
        }
    }

    void display_inOrder()
    {
        inOrder(root);
        cout << nl;
    }

    void display_preOrder()
    {
        preOrder(root);
        cout << nl;
    }

    void display_postOrder()
    {
        postOrder(root);
        cout << nl;
    }

    void display_LevelByLevel()
    {
        display_LevelByLevel(root);
        cout << nl;
    }

    // -- Additional Functions -- //
    T TreeMax()
    {
        if (!root)
        {
            assert(root != nullptr && "root should not be null");
        }

        return TreeMax(root);
    }

    int TreeHeight()
    {
        if (!root)
            return 0;

        return TreeHeight(root);
    }

    int TreeCount()
    {
        if (!root)
            return 0;

        return TreeCount(root);
    }

    int LeavesCount()
    {
        if (!root)
            return 0;

        return LeavesCount(root);
    }

    bool TreeSearch(T item)
    {
        if (!root)
            assert(root != nullptr && "root should not be null");

        return TreeSearch(root, item);
    }

    bool isPerfect()
    {
        if (!root)
            return false;

        return isPerfect(root);
    }

    void LeftBoundary()
    {
        assert(root && "Your Tree is Empty !");

        LeftBoundary(root);
        cout << nl;
    }

    void RightBoundary()
    {
        assert(root && "Your Tree is Empty !");

        RightBoundary(root);
        cout << nl;
    }

    int diameterOfTree()
    {
        return diameterOfTree(root).first;
    }
};

signed main()
{
    MyBT<int> tree(1); // root

    tree.addByPath({'l'}, 2); // 1 -> left
    tree.addByPath({'r'}, 3); // 1 -> right

    tree.addByPath({'r', 'l'}, 4); // 3 -> left
    tree.addByPath({'r', 'r'}, 5); // 3 -> right

    cout << tree.diameterOfTree() << nl;

    return 0;
}

// Functions
/*
    1- set root
    2- reset root
    3- add by path
    4- dfs display (inorder - preorder - postorder)
    5- get Max node
    6- nodes count
    7- leaves count
    8- tree height (levels of tree)
    9- tree search
    10- is perfect tree (left equals right)
    11- boundaries (left - right)
    12- bfs display level by level
    13- get the diameter of the tree (the longest len between two nodes)
*/
