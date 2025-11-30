// بسم الله الرحمن الرحيم
//  وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
//  Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(vec) (vec).begin(), (vec).end()
#define sz(x) (int)(x).size()
#define i(x) (x - 'a')
#define updmax(a, x) (a = max((a), (x)))
#define updmin(a, x) (a = min((a), (x)))
#define nl '\n'

class Node
{
public:
    int val;
    Node *next;
    Node(int v) : val(v), next(nullptr) {}
};

class MyLinkedList
{
    Node *head;
    int len;

public:
    MyLinkedList() { head = nullptr, len = 0; }

    int get(int index)
    {
        if (index < 0 || index >= len)
            return -1;

        Node *cur = head;
        for (int i = 0; i < index; i++)
            cur = cur->next;

        return cur->val;
    }

    void addAtHead(int val)
    {
        Node *node = new Node(val);
        if (!head)
            head = node;
        else
            node->next = head, head = node;

        len++;
    }

    void addAtTail(int val)
    {
        Node *node = new Node(val);

        if (!head)
        {
            head = node;
            len++;
            return;
        }
        Node *trav = head;
        while (trav->next)
            trav = trav->next;

        trav->next = node;
        len++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > len)
            return;
        if (index == 0)
        {
            addAtHead(val);
        }
        else if (index == len)
        {
            addAtTail(val);
        }
        else
        {
            Node *node = new Node(val);
            Node *trav = head;

            for (int i = 0; i < index - 1; i++)
                trav = trav->next;

            node->next = trav->next;
            trav->next = node;
            len++;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= len)
            return;

        if (index == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            len--;
            return;
        }

        Node *cur = head;
        for (int i = 0; i < index - 1; i++)
            cur = cur->next;
        Node *temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        len--;
    }
};
