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
void debug() { cout << "[DEBUG]" << nl; }

template <typename T>
class Node
{
public:
    T val;
    Node *next;
    Node(T val) : val(val), next(nullptr) {};
};

template <typename T>
class Mystack
{
private:
    Node<T> *head;

public:
    // default constructor to initlize head pointer with null value
    Mystack() : head(nullptr) {};

    // -- Main Functions -- //
    bool isempty() { return head == nullptr; }

    void push(T item)
    {
        Node<T> *node = new Node(item);
        node->next = head;
        head = node;
    }

    void pop()
    {
        if (isempty())
            return void(cout << "Your stack is empty !" << nl);

        Node<T> *cur = head;
        if (cur->next == nullptr)
        {
            head = nullptr;
        }
        else
        {
            head = head->next;
        }

        delete cur;
    }

    T top()
    {
        if (isempty())
        {
            cout << "Your stack is empty !" << nl;
            return T();
        }

        return head->val;
    }

    void display()
    {
        if (isempty())
            return;

        Node<T> *trav = head;
        while (trav != nullptr)
        {
            cout << trav->val << " ";
            trav = trav->next;
        }
        cout << nl;
    }

    // this function is not optimal method (for practice only)
    int getSize()
    {
        if (isempty())
        {
            cout << "Your Stack is empty " << nl;
            exit(1);
        }

        int cnt = 0;
        Node<T> *trav = head;
        while (trav)
            cnt++, trav = trav->next;

        return cnt;
    }

    int searchItem(T item)
    {
        if (isempty())
        {
            cout << "Your Stack is empty !" << nl;
            exit(1);
        }

        if (head->val)
        {
            return 0;
        }

        int index = 0;
        Node<T> *cur = head;
        while (cur)
        {
            if (cur->val == item)
                return index;
            index++;
            cur = cur->next;
        }

        return -1; // not found
    }

    // save memory leak
    ~Mystack()
    {
        while (!isempty())
            pop();
    }
};

signed main()
{
    return 0;
}
