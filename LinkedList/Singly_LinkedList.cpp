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

    Node(T item) : val(item), next(nullptr) {};
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

        // Time Complexity : O(1)
        // Memory Complexity : O(1)
    }

    // -- Main functions -- //
    bool isempty()
    {
        return head == nullptr;

        // Time Complexity : O(1)
        // Memory Complexity : O(1)
    }

    void insertFront(T item)
    {
        Node<T> *node = new Node<T>(item);
        node->next = head;
        head = node;
        length++;

        // Time Complexity : O(1)
        // Memory Complexity : O(1)
    }

    void insertBack(T item)
    {
        Node<T> *node = new Node<T>(item);

        if (isempty())
        {
            head = node;
        }
        else
        {
            Node<T> *trav = head;
            while (trav->next != nullptr)
                trav = trav->next;

            trav->next = node;
        }
        length++;

        // Time Complexity : O(n)
        // Memory Complexity : O(1)
    }

    void insertAt(T item, int idx)
    {
        if (idx < 0 || idx > length) // ( > length ) because you might insert at last position
        {
            cout << "Invalid Index !" << nl;
            return;
        }

        Node<T> *node = new Node<T>(item);
        if (idx == 0)
        {
            node->next = head;
            head = node;
        }
        else
        {
            Node<T> *trav = head;
            for (int i = 0; i < idx - 1; i++)
                trav = trav->next;

            node->next = trav->next;
            trav->next = node;
        }
        length++;

        // Time Complexity : O(n)
        // Memory Complexity : O(1)
    }

    void updateAt(T item, int idx)
    {

        if (idx < 0 || idx >= length)
        {
            if (isempty())
                cout << "Your list is empty !" << nl;
            else
                cout << "Invalid Index !" << nl;

            return;
        }

        if (idx == 0)
        {
            head->val = item;
        }
        else
        {
            Node<T> *trav = head;
            for (int i = 0; i < idx; i++)
                trav = trav->next;

            trav->val = item;
        }

        // Time Complexity : O(n)
        // Memory Complexity : O(1)
    }

    void deleteFront()
    {
        if (isempty())
            return void(cout << "Your list is empty !" << nl);

        Node<T> *temp = head;
        head = head->next;
        delete temp;
        length--;

        // Time Complexity : O(1)
        // Memory Complexity : O(1)
    }

    void deleteBack()
    {
        if (isempty())
            return void(cout << "Your list is empty !" << nl);

        if (length == 1)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node<T> *trav = head;
            while (trav->next->next != nullptr)
                trav = trav->next;

            delete trav->next;
            trav->next = nullptr;
        }

        length--;

        // Time Complexity : O(n)
        // Memory Complexity : O(1)
    }

    void deleteAt(int idx)
    {
        if (idx < 0 || idx >= length)
        {
            if (isempty())
                cout << "Your list is empty !" << nl;
            else
                cout << "Invalid Index !" << nl;

            return;
        }

        if (idx == 0) // delete the first node
        {
            deleteFront();
        }
        else if (idx == length - 1) // delete the last node
        {
            deleteBack();
        }
        else
        {
            Node<T> *trav = head;
            for (int i = 0; i < idx - 1; i++)
                trav = trav->next;

            Node<T> *temp = trav->next;
            trav->next = trav->next->next;
            delete temp;
            length--;
        }

        // Time Complexity : O(n)
        // Memory Complexity : O(1)
    }

    void display()
    {
        if (isempty())
        {
            cout << "Your list is empty !" << nl;
            return;
        }

        Node<T> *trav = head;
        while (trav != nullptr)
        {
            cout << trav->val << " ";
            trav = trav->next;
        }
        cout << nl;

        // Time Complexity : O(n)
        // Memory Complexity : O(1)
    }

    // -- Additional functions -- //

    Node<T> *get_nth(int idx) // nodes is starting from 0....n - 1
    {
        if (isempty() || idx < 0 || idx >= length)
        {
            cout << (isempty() ? "Your list is empty !" : "Invalid Index !") << nl;

            exit(1);
        }

        Node<T> *trav = head;
        for (int i = 0; i < idx; i++)
            trav = trav->next;

        // Time Complexity : O(n)
        // Memory Complexity : O(1)
        return trav;
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
            cout << x.getMidd()->val << nl;
            trav = trav->next;
        }

        // Time Complexity : O(n)
        // Memory Complexity : O(1)
        return -1;
    }

    Node<T> *getMax()
    {
        if (isempty())
        {
            cout << "Your list is empty !" << nl;
            exit(1);
        }

        Node<T> *maxi = head, *trav = head->next;
        while (trav != nullptr)
        {
            if (trav->val > maxi->val)
                maxi = trav;
            trav = trav->next;
        }

        // Time Complexity : O(n)
        // Memory Complexity : O(1)
        return maxi;
    }

    Node<T> *getMin()
    {
        if (isempty())
        {
            cout << "Your list is empty !" << nl;
            exit(1);
        }

        Node<T> *mini = head, *trav = head->next;
        while (trav != nullptr)
        {
            if (trav->val < mini->val)
                mini = trav;

            trav = trav->next;
        }

        // Time Complexity : O(n)
        // Memory Complexity : O(1)
        return mini;
    }

    Node<T> *getMid()
    {
        if (isempty())
        {
            cout << "Your list is empty !" << nl;
            exit(1);
        }

        Node<T> *Mid = head, *fast = head;
        while (fast->next && fast->next->next)
            Mid = Mid->next, fast = fast->next->next;

        if (fast->next == nullptr)
            return Mid;

        // Time Complexity : O(n)
        // Memory Complexity : O(1)
        return Mid->next;
    }

    // -- save memory leak -- //
    LinkedList(const LinkedList &) = delete;
    LinkedList &operator=(const LinkedList &another) = delete;
    ~LinkedList()
    {
        Node<T> *trav = head;
        while (trav != nullptr)
        {
            Node<T> *temp = trav;
            trav = trav->next;
            delete temp;
        }

        head = nullptr;
        length = 0;

        // Time Complexity : O(n)
        // Memory Complexity : O(1)
    }
};

int main()
{
    return 0;
}
