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

    Node(T val) : val(val), next(nullptr) {}
};

template <typename T>
class LinkedList
{
    Node<T> *head;
    int len;

public:
    LinkedList() : head(nullptr), len(0) {};
    LinkedList(T item)
    {
        Node<T> *node = new Node<T>(item);
        head = node;
        len = 1;
    }

    // -- Main Functions -- //
    bool isempty() { return head == nullptr; }

    void insertFront(int item)
    {
        Node<T> *node = new Node<T>(item);
        if (isempty())
        {
            head = node;
            node->next = head;
        }
        else
        {
            Node<T> *trav = head;
            while (trav->next != head)
                trav = trav->next;

            trav->next = node;
            node->next = head;
            head = node;
        }

        len++;
    }

    void insertBack(T item)
    {
        Node<T> *node = new Node<T>(item);
        if (isempty())
        {
            head = node;
            node->next = head;
        }
        else
        {
            Node<T> *trav = head;
            while (trav->next != head)
                trav = trav->next;

            trav->next = node;
            node->next = head;
        }
        len++;
    }

    void insertAt(T item, int idx)
    {
        if (idx < 0 || idx > len)
        {
            cout << "Invalid Index!" << nl;
            return;
        }

        if (idx == 0)
        {
            insertFront(item);
            return;
        }

        Node<T> *node = new Node<T>(item);
        Node<T> *trav = head;
        for (int i = 1; i < idx; i++)
            trav = trav->next;

        node->next = trav->next;
        trav->next = node;
        len++;
    }

    void updateAt(T item, int idx)
    {

        if (idx < 0 || idx >= len)
        {
            if (isempty())
                cout << "Your list is empty !" << nl;
            else
                cout << "Invalid Index !" << nl;

            return;
        }

        Node<T> *trav = head;
        for (int i = 0; i < idx; i++)
            trav = trav->next;

        trav->val = item;
    }

    void deleteFront()
    {
        if (isempty())
        {
            cout << "Your Circule is empty !" << nl;
            return;
        }

        Node<T> *del = head;
        if (head->next == head)
        {
            head = nullptr;
        }
        else
        {
            Node<T> *trav = head;
            while (trav->next != head)
                trav = trav->next;

            head = head->next;
            trav->next = head;
        }

        delete del;
        len--;
    }

    void deleteBack()
    {
        if (isempty())
            return void(cout << "Your circle is empty !" << nl);

        if (head->next == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node<T> *trav = head;
            while (trav->next->next != head)
                trav = trav->next;

            delete trav->next;
            trav->next = head;
        }

        len--;
    }

    void deleteAt(int idx)
    {
        if (idx < 0 || idx >= len)
        {
            cout << "Invalid Index !" << nl;
            return;
        }

        if (idx == 0)
        {
            deleteFront();
            return;
        }

        Node<T> *trav = head;
        for (int i = 1; i < idx; i++)
            trav = trav->next;

        Node<T> *del = trav->next;
        trav->next = trav->next->next;
        delete del;
        len--;
    }

    void display()
    {
        if (isempty())
            return void(cout << "Your circule is empty !" << nl);
        Node<T> *trav = head;
        do
        {
            cout << trav->val << " ";
            trav = trav->next;
        } while (trav != head);

        cout << nl;
    }

    ~LinkedList()
    {
        if (isempty())
            return;

        Node<T> *trav = head;
        Node<T> *nextNode;

        do
        {
            nextNode = trav->next;
            delete trav;
            trav = nextNode;
        } while (trav != head);

        head = nullptr;
        len = 0;
    }
};

signed main()
{
    return 0;
}