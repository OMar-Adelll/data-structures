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

class MyVector
{
private:
    int *arr = nullptr;
    int size;
    int capacity;

public:
    MyVector()
    {
        size = 0;
        capacity = 10;
        arr = new int[capacity];
    }
    MyVector(int size)
    {
        this->size = size < 0 ? 1 : size;
        this->capacity = this->size + 10;
        arr = new int[capacity]; // Allocate contiguous block of memory
    }

    ~MyVector() // frees the allocated memory
    {
        delete[] arr;
        arr = nullptr;
    }

    void expand_capacity() // this important to avoid long time in push back
    {
        capacity *= 2;
        int *temp = new int[capacity];
        for (int i = 0; i < size; i++)
            temp[i] = arr[i];

        swap(arr, temp);

        delete[] temp;
        // Amortized Time Complexity: O(1)
    }

    // -- setters & getters -- //

    void set(int val, int idx)
    {
        assert(0 <= idx && idx < size); // Check that index is valid; program stops if not
        arr[idx] = val;
    }

    int get(int idx)
    {
        assert(0 <= idx && idx < size);

        return arr[idx];
    }

    int getFront()
    {
        assert(size > 0);
        return arr[0];
    }

    int getBack()
    {
        assert(size > 0);
        return arr[size - 1];
    }

    void pushBack(int val)
    {
        if (size == capacity)
            expand_capacity();

        arr[size++] = val;

        /*
            1- Time Complexity: O(1)
            2- Time Complexity (when expanding): O(n)
            3- Space Complexity: O(1)
            -> Amortized Time Complexity: O(1)
        */
    }

    void pushFront(int val)
    {
        if (size == capacity)
            expand_capacity();

        for (int i = size; i >= 1; i--)
            arr[i] = arr[i - 1];
        arr[0] = val;
        size++;

        /*
            1- Time Complexity: O(1)
            2- Time Complexity (when expanding): O(n)
            3- Space Complexity: O(1)
            -> Amortized Time Complexity: O(1)
        */
    }

    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << (i == size - 1 ? "\n" : " ");
    }

    // -- another features --//

    int find(int val)
    {
        for (int i = 0; i < size; i++)
            if (arr[i] == val)
                return i;

        return -1;
    }

    int getSize()
    {
        return this->size;
    }
    int getCapacity()
    {
        return this->capacity;
    }
};

int main()
{
    MyVector x(10);
    for (int i = 1; i <= 10; i++)
        x.pushBack(i);

    x.print();
    x.pushBack(100);
    cout << x.getCapacity() << nl;

    return 0;
}