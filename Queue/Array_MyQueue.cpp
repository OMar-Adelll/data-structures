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
class MyQueue
{
private:
    T *arr;
    int front;
    int rear;
    int size;
    int count;

public:
    MyQueue(int size)
    {
        this->size = size;
        front = count = 0, rear = -1;
        arr = new T[size];
    }

    ~MyQueue()
    {
        delete[] arr;
    }

    // -- Main Functions -- //

    bool empty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == size;
    }

    void enQueue(T item)
    {
        if (isFull())
            return void(cout << "Your Queue is full" << nl);

        rear = (rear + 1) % size;
        arr[rear] = item;

        count++;
    }

    void deQueue()
    {
        if (empty())
            return void(cout << "Your Queue is empty" << nl);

        front = (front + 1) % size;
        count--;
    }

    T Front()
    {
        if (empty())
        {
            cout << "Your queue is empty" << nl;
            exit(1);
        }

        return arr[front];
    }

    void display()
    {
        if (empty())
            return void(cout << "Your Stack is empty !" << nl);

        int i = front;
        int c = count;
        while (c--)
        {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }

        cout << nl;
    }

    // -- Additional Functions --//
    int getCount()
    {
        return this->count;
    }

    void enQueueN(vector<int> &nums)
    {
        int n = sz(nums);
        if (n + count >= size)
        {
            cout << "Sorry There is no enough Size" << nl;
            return;
        }
        for (auto &c : nums)
            enQueue(c);
    }

    void deQueueN_withDisplay(int n)
    {
        if (empty())
            return void(cout << "Your Queue is empty already" << nl);

        if (n >= count)
        {
            int rm = count;
            while (!empty())
            {
                cout << arr[front] << " ";
                front = (front + 1) % size;
                count--;
            }

            cout << nl;
        }
        else
        {
            while (n--)
            {
                cout << arr[front] << " ";
                front = (front + 1) % size;
                count--;
            }

            cout << nl;
        }
    }

    void deQueueN(int n)
    {
        if (empty())
            return void(cout << "Your Queue is empty already" << nl);

        if (n >= count)
        {
            int rm = count;
            while (!empty())
            {
                front = (front + 1) % size;
                count--;
            }

            cout << nl;
        }
        else
        {
            while (n--)
            {
                front = (front + 1) % size;
                count--;
            }

            cout << nl;
        }
    }

    int searchItem(T item)
    {
        if (empty())
            return -1;

        int pos = 0, i = front, c = count;

        while (c--)
        {
            if (arr[i] == item)
                return pos;

            i = (i + 1) % size;
            pos++;
        }
        return -1;
    }
};

signed main()
{
    return 0;
}
