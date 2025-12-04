// بسم الله الرحمن الرحيم
// "وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"
// Free Palestine

#ifndef PRIORITYQUEUE_LINKEDLIST_STRUCTURE_H
#define PRIORITYQUEUE_LINKEDLIST_STRUCTURE_H

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

    void insertFront(T item)
    {
        Node<T> *node = new Node<T>(item);
        node->next = head;
        head = node;
        length++;
    }

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

    void insert(T item) // the list should be sorted
    {
        if (isempty() || head->val >= item)
        {
            insertFront(item);
            return;
        }

        Node<T> *node = new Node<T>(item);
        Node<T> *trav = head;
        while (trav->next && trav->next->val < item)
            trav = trav->next;

        node->next = trav->next;
        trav->next = node;
        length++;

        // Time Complexity : O(n)
        // Memory Complexity : O(1)
    }

    T getFront()
    {
        if (isempty())
        {
            cout << "Your Queue is Empty !" << nl;
            return T();
        }

        return head->val;

        // Time Complexity : O(1)
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

        // Time Complexity : O(n)
        // Memory Complexity : O(1)
        return -1;
    }

    void GreaterToSmaller()
    {
        if (isempty())
        {
            cout << "Your list is empty !" << nl;
            return;
        }

        Node<T> *prv = nullptr, *nxt = nullptr, *cur = head;
        while (cur)
        {
            nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
        }

        head = prv;
        // Time Complexity : O(n)
        // Memory Complexity : O(1)
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

#endif