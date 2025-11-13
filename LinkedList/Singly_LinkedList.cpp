// بسم الله الرحمن الرحيم
// "وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define fixed(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) (int)(x).size()
#define updmax(a, b) a = max(a, b)
#define updmin(a, b) a = min(a, b)
#define nl '\n'
#define pi acos(-1.0)

template <typename T>
struct Node
{
    T val;
    Node<T> *next;

    Node(T item) : val(item) {};
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    int length;

public:
    LinkedList() : head(nullptr), length(0) {}
    LinkedList(T item)
    {
        Node<T> *node = new Node<T>(item);
        node->next = nullptr;
        head = node;
        length = 1;
    }

    // -- Main functions -- //
    bool isempty() { return head == nullptr; }

    void insertFront(T item)
    {
        Node<T> *node = new Node(item);
        node->next = head;
        head = node;
        length++;
    }

    void insertBack(T item)
    {
        Node<T> *node = new Node<T>(item);

        if (isempty())
        {
            head = node;
            length++;
            return;
        }

        Node<T> *trav = head;
        while (trav->next != nullptr)
            trav = trav->next;

        trav->next = node;
        length++;
    }

    void display()
    {
        Node<T> *trav = head;
        while (trav != nullptr)
        {
            cout << trav->val << " ";
            trav = trav->next;
        }
        cout << nl;
    }

    // -- Additional funcitons -- //

    Node<T> *get_nth(int num) // nodes is starting from 0....n - 1
    {
        if (isempty() || num < 0 || num >= length)
        {
            cout << (isempty() ? "Your list is empty !" : "Invalid Index !") << nl;
            ;
            exit(1);
        }

        int cur = 0;
        Node<T> *trav = head;
        while (trav != nullptr)
        {
            if (cur++ == num)
                return trav;

            trav = trav->next;
        }

        return nullptr;
    }

    int searchItem(T item)
    {
        if (isempty())
        {
            cout << "Your list is empty !" << nl;
            exit(1);
        }
        int Index = 0;
        Node<T> *trav = head;
        while (trav != nullptr)
        {
            if (trav->val == item)
                return Index;

            Index++;
            trav = trav->next;
        }

        return -1;
    }
};

int main()
{
    LinkedList<int> list(8);

    int idx = list.searchItem(7);

    cout << idx << nl;
    return 0;
}
