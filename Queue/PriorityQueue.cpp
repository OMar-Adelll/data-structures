// بسم الله الرحمن الرحيم
// "وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"
// Free Palestine
#include <bits/stdc++.h>
#include "PriorityQueue_LinkedLIst_Structure.h"
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
class priority_Queue
{
private:
    LinkedList<T> list;

public:
    priority_Queue() {}

    void insert(T item)
    {
        list.insert(item);
    }

    void deQueue()
    {
        list.deleteFront();
    }
    T front()
    {
        return list.getFront();
    }

    void display()
    {
        list.display();
    }

    int searchItem(T item)
    {
        return list.searchItem(item);
    }

    bool isempty()
    {
        return list.isempty();
    }

    void greater()
    {
        list.GreaterToSmaller();
    }
};

signed main()
{
    priority_Queue<int> pq;


    return 0;
}