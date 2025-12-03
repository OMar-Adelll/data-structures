// بسم الله الرحمن الرحيم
// "وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"
// Free Palestine
#include <bits/stdc++.h>
#include "Queue_LinkedList_Structure.h"
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
class Queue
{
private:
    LinkedList<T> list;

public:
    Queue() : LinkedList() {}

    // -- Main functions -- //
    void enQueue(T item)
    {
        list.insertBack();
    }

    void deQueue()
    {
        list.deleteFront();
    }

    T front()
    {
        return list.getFront();
    }

    bool empty()
    {
        return list.isempty();
    }

    void display()
    {
        list.display();
    }
};

signed main()
{

    return 0;
}