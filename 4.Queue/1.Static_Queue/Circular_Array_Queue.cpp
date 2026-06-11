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

// Circula Queue is more efficient to save leak of memory but normal array is bad approach
// Global idea if you want to push element you should use rear and if you want to pop it you should use front
// The main idea of queue is play with the index of front and rear
// We might see rear before front because it a circular Queue

template <typename T>
class MyQueue
{
private:
    T *arr;
    int front;
    int rear;
    int size;  // this size cuz it static queue
    int count; // count the current elements in queue

public:
    MyQueue(int size)
    {
        this->size = size;
        front = count = 0, rear = -1;
        arr = new T[size];
    }

    // save memory leak
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

    // this cuz this queue is circular queue
    int next(int x)
    {
        x = (x + 1) % size;
        return x;
    }

    void enQueue(T item)
    {
        if (isFull())
            return void(cout << "Your Queue is full" << nl);

        rear = next(rear);
        arr[rear] = item;

        count++;
    }

    void deQueue()
    {
        if (empty())
            return void(cout << "Your Queue is empty" << nl);

        front = next(front);
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
            i = next(i);
        }

        cout << nl;
    }

    // -- Additional Functions --//
    int Size()
    {
        return this->count;
    }

    // this to enQueue n elements
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

    // this to deQueue n elements with store them into vector to display them later
    vector<int> dequeueN_elements(int n)
    {
        if (empty())
        {
            cout << "Sorry Your Queue is empty !" << nl;
            return {};
        }

        if (n > count)
        {
            cout << "Sory your Queue size now is : " << Size() << nl;
            return {};
        }

        int idx = 0;
        vector<int> elements(n);
        while (n--)
        {
            elements[idx++] = arr[front];
            front = next(front);
            count--;
        }

        return elements;
    }

    // this to deQueue n elements without store them
    void deQueueN(int n)
    {
        if (empty())
            return void(cout << "Your Queue is empty already" << nl);

        if (n >= count)
        {
            int rm = count;
            while (!empty())
            {
                front = next(front);
                count--;
            }

            cout << nl;
        }
        else
        {
            while (n--)
            {
                front = next(front);
                count--;
            }

            cout << nl;
        }
    }

    // 0-based indexing like normal array
    int searchItem(T item)
    {
        if (empty())
            return -1;

        int pos = 0, i = front, c = count;

        while (c--)
        {
            if (arr[i] == item)
                return pos;

            i = next(i);
            pos++;
        }
        return -1;
    }
};

signed main()
{
    return 0;
}
