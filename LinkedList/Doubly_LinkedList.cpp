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
    Node<T> *prv;

    Node(T item) : val(item), next(nullptr), prv(nullptr) {};
};
template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    int len;

public:
    LinkedList() : head(nullptr), len(0) {};
    LinkedList(T item)
    {
        Node<T> *node = new Node<T>(item);
        node->next = nullptr;
        node->prv = nullptr;
        head = node;
        len = 1;
    }

    // -- Main functions --//
    bool isempty() { return head == nullptr; }

    void insertFront(T item)
    {
        Node<T> *node = new Node<T>(item);
        node->prv = nullptr;
        node->next = head;

        if (head != nullptr)
            head->prv = node;

        head = node;
        len++;
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
            {
                trav = trav->next;
            }

            trav->next = node;
            node->prv = trav;
        }

        len++;
    }

    void insertAt(T item, int idx)
    {
        if (idx < 0 || idx > len)
        {
            cout << "Invalid Index !" << nl;
            return;
        }

        if (idx == 0)
        {
            insertFront(item);
        }
        else if (idx == len)
        {
            insertBack(item);
        }
        else
        {
            Node<T> *node = new Node<T>(item);
            Node<T> *trav = head;
            for (int i = 0; i < idx - 1; i++)
                trav = trav->next;

            node->next = trav->next;
            node->prv = trav;

            trav->next->prv = node;
            trav->next = node;

            len++;
        }
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
    }

    void deleteFront()
    {
        if (isempty())
            return void(cout << "Your list is empty !" << nl);

        Node<T> *temp = head;
        if (len == 1)
        {
            head = nullptr;
        }
        else
        {
            head = head->next;
            head->prv = nullptr;
        }
        delete temp;
        len--;
    }

    void deleteBack()
    {
        if (isempty())
            return void(cout << "Your list is empty !" << nl);

        if (len == 1)
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

        len--;
    }

    void deleteAt(int idx)
    {
        if (idx < 0 || idx >= len)
        {
            if (isempty())
                cout << "Your list is empty !" << nl;
            else
                cout << "Invalid Index !" << nl;

            return;
        }

        if (idx == 0)
        {
            deleteFront();
        }
        else if (idx == len - 1)
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
            trav->next->prv = trav;
            delete temp;
            len--;
        }
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
    }

    // -- Additional functions -- //

    void delete_all_nodes_with_key(T item)
    {
        if (isempty())
            return void(cout << "Your list is empty !" << nl);

        Node<T> *trav = head;
        while (trav != nullptr)
        {
            if (trav->val == item)
            {
                if (trav == head)
                {
                    deleteFront();
                    trav = head;
                }
                else if (trav->next == nullptr)
                {
                    deleteBack();
                    trav = nullptr;
                }
                else
                {

                    Node<T> *temp = trav;
                    trav->prv->next = trav->next;
                    trav->next->prv = trav->prv;

                    trav = trav->next;
                    delete temp;
                    len--;
                }
            }
            else
            {
                trav = trav->next;
            }
        }
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
        len = 0;
    }
};

int main()
{
    LinkedList<int> list;
    list.insertFront(10);
    list.insertFront(2);
    list.insertFront(10);
    list.insertFront(2);
    list.insertFront(2);

    list.display();
    list.delete_all_nodes_with_key(2);
    list.display();

    return 0;
}
