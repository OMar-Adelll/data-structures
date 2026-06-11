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

    // [1] Display Functions
    // All of these traversal styles belong to the same category: Depth-First Search (DFS)
    void inOrder(Node<T> *root) // LVR: left, root, right
    {
        if (!root)
            return;
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }

    void preOrder(Node<T> *root) // VLR: root, left, right
    {
        if (!root)
            return;
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(Node<T> *root) // LRV: left, right, root
    {
        if (!root)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << " ";
    }

    // this type is Breadth First Search -> BFS
    void display_LevelByLevel(Node<T> *root)
    {
        if (!root)
            return;
        queue<Node<T> *> nodes;
        nodes.push(root);
        while (!nodes.empty())
        {
            Node<T> *fr = nodes.front();
            nodes.pop();
            cout << fr->val << " ";

            if (fr->left)
                nodes.push(fr->left);
            if (fr->right)
                nodes.push(fr->right);
        }
    }

    // [2] Additional Important Functions
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

    // tree is perfect when all leaves are the same height
    bool isPerfect(Node<T> *root, int h = -1)
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

    void RightBoundary(Node<T> *root) // display right boundary nodes only
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
        int diameter = max({diameterOfRoot, l.first, r.first});

        return {diameter, h};
        // this algorithm is based on the hight of the tree
    }

    // save memory leak
    void clear(Node<T> *node)
    {
        if (!node)
            return;
        clear(node->left);
        clear(node->right);

        delete node;
    }

public:
    MyBT() : root(nullptr) {}                        // default constructor
    MyBT(T rootVal) { root = new Node<T>(rootVal); } // Parameterized constructor
    ~MyBT() { clear(root); }                         // save memory leak

    // -- Main Functions -- //

    // customizing the root
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

    // Inserting Function (you should put the path of the item and the value like this ({'L','R',"R"}, 10))
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

    // [1] Display Functions
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

    void display_LevelByLevel() // bfs
    {
        display_LevelByLevel(root);
        cout << nl;
    }

    // [2] Additional Functions
    T TreeMax() // to get the max element from the tree
    {
        if (!root)
        {
            assert(root != nullptr && "root should not be null");
        }

        return TreeMax(root);
    }

    int TreeHeight() // to get number of the levels of your tree
    {
        if (!root)
            return 0;

        return TreeHeight(root);
    }

    int TreeCount() // to get the number of nodes of your tree
    {
        if (!root)
            return 0;

        return TreeCount(root);
    }

    int LeavesCount() // to get the number of leaves
    {
        if (!root)
            return 0;

        return LeavesCount(root);
    }

    bool TreeSearch(T item) // to search about specific element on your tree
    {
        if (!root)
            assert(root != nullptr && "root should not be null");

        return TreeSearch(root, item);
    }

    bool isPerfect() // to know you tree is perfect (have all nodes) or not
    {
        if (!root)
            return false;

        return isPerfect(root);
    }

    void LeftBoundary() // to print the whole left boundary
    {
        assert(root && "Your Tree is Empty !");

        LeftBoundary(root);
        cout << nl;
    }

    void RightBoundary() // to print the whole right boundary
    {
        assert(root && "Your Tree is Empty !");

        RightBoundary(root);
        cout << nl;
    }

    int diameterOfTree() // to know the make len between two nodes (diameter of the tree) :: this is popular problem (My "CP" skills)
    {
        return diameterOfTree(root).first;
    }
};

signed main()
{
    return 0;
}
