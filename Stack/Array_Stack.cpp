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
class MyStack
{
private:
    int size;
    int top;
    T *arr;

public:
    MyStack(int size)
    {
        this->size = size;
        this->top = -1;
        arr = new T[size];
        // Time Complexity : O(n)
        // Memory Complexity : O(n)
    }
    ~MyStack()
    {
        delete[] arr; // save memory leak
    }

    // -- Main Functions --//
    bool isfull()
    {
        return top == size - 1;
    }

    bool isempty()
    {
        return top == -1;
    }
    void push(T item)
    {
        if (isfull())
            return void(cout << "Sorry! your Stack is full now" << nl);

        arr[++top] = item;
    }

    void pop()
    {
        if (isempty())
            return void(cout << "Your stack is empty !" << nl);

        top--;
    }

    T peek()
    {
        if (isempty())
        {
            cout << "Your Stack is empty !" << nl;
            return T();
        }

        return arr[top];
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << nl;
    }

    // -- Additional Functions -- //
    void reversed_display()
    {
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << nl;
    }
    T print_and_pop()
    {
        if (isempty())
        {
            cout << "Your Stack is empty !" << nl;
            return T();
        }

        return arr[top--];
    }

    void pop_and_push(T item)
    {
        arr[top] = item;
    }
};

signed main()
{

    return 0;
}