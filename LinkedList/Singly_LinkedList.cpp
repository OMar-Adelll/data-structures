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

struct Node
{
    int val;
    Node *next;

    Node(int item) : val(item) {};
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int len;

public:
    LinkedList() : head(NULL), tail(NULL), len(0) {}

    bool isempty()
    {
        return head == NULL;
    }
    void insertEnd(int item)
    {
        Node *node = new Node(item);

        if (isempty())
        {
            head = node;
            return;
        }

        Node *trav = head;
        while (trav->next != NULL)
            trav = trav->next;

        trav->next = node;
    }

    void display()
    {
        Node *trav = head;
        while (trav != NULL)
            cout << trav->val << " ", trav = trav->next;
        cout << nl;
    }
};

int main()
{
    return 0;
}
