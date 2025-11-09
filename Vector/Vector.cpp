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
class MyVector
{
private:
    T *arr = nullptr;
    int size;
    int capacity;

    void expand_capacity()
    {
        capacity *= 2;
        T *temp = new T[capacity];
        for (int i = 0; i < size; i++)
            temp[i] = arr[i];

        T *old = arr;
        arr = temp;

        delete[] old;
        // Amortized Time Complexity: O(1) -> O(n)
    }

    void shrink_capacity()
    {
        capacity /= 2;
        T *temp = new T[capacity];
        for (int i = 0; i < size; i++)
            temp[i] = arr[i];

        T *old = arr;
        arr = temp;
        delete[] old;
        // Amortized Time Complexity: O(1) -> O(n)
    }

public:
    MyVector() // Empty constructor
    {
        size = 0;
        capacity = 10;
        arr = new T[capacity];
    }

    MyVector(int size) // parametrized constructor
    {
        this->size = size < 0 ? 1 : size;
        this->capacity = this->size + 10;
        arr = new T[capacity];
    }

    MyVector(const MyVector &other) // copy constructor
    {
        size = other.size;
        capacity = other.capacity;
        arr = new T[capacity];
        for (int i = 0; i < size; i++)
            arr[i] = other.arr[i];
    }

    ~MyVector() // frees the allocated memory
    {
        delete[] arr;
        arr = nullptr;
    }

    void set(T val, int idx)
    {
        assert(0 <= idx && idx < size); // Check that index is valid; program stops if not
        arr[idx] = val;
    }

    T get(int idx)
    {
        assert(0 <= idx && idx < size);
        return arr[idx];
    }

    T getFront()
    {
        assert(size > 0);
        return arr[0];
    }

    T getBack()
    {
        assert(size > 0);
        return arr[size - 1];
    }

    void pushFront(T val)
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

    void pushBack(T val)
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

    void popFront()
    {
        assert(size > 0);
        if (size - 1 <= (capacity / 2))
            shrink_capacity();

        for (int i = 0; i < size - 1; i++)
            arr[i] = arr[i + 1];

        size--;
    }

    void PopBack()
    {
        assert(size > 0);
        if (size - 1 <= (capacity / 2))
            shrink_capacity();

        size--;
    }

    void insertAt(T item, int idx)
    {
        assert(idx >= 0 && idx < size);
        if (size == capacity)
            expand_capacity();

        for (int i = size - 1; i >= idx; i--)
            arr[i + 1] = arr[i];
        arr[idx] = item;

        size++;
    }

    void deleteAt(int idx)
    {
        assert(size > 0 && idx >= 0 && idx < size);
        if (size - 1 < (capacity / 2))
            shrink_capacity(); // to shrink capacity from memory

        for (int i = idx; i < size - 1; i++)
            arr[i] = arr[i + 1];

        size--;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << (i == size - 1 ? "\n" : " ");
    }

    int find(T val)
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

    T getMax()
    {
        T mx = arr[0];
        for (int i = 0; i < size; i++)
            updmax(mx, arr[i]);
        return mx;
    }

    T getMin()
    {
        T mn = arr[0];
        for (int i = 0; i < size; i++)
            updmin(mn, arr[i]);
        return mn;
    }

    void Sooort()
    {
        sort(arr, arr + size);
    }

    void Reverse()
    {
        T *temp = new T[capacity];
        for (int i = 0; i < size; i++)
            temp[i] = arr[size - i - 1];

        swap(temp, arr);
        delete[] temp;
    }

    void Clear()
    {
        size = 0;
    }

    bool isempty()
    {
        return size == 0;
    }

    void shiftRight()
    {
        if (size == 0)
            return;

        int val = arr[size - 1];
        for (int i = size - 1; i > 0; i--)
            arr[i] = arr[i - 1];

        arr[0] = val;
    }

    void shiftLeft()
    {
        if (size == 0)
            return;

        int val = arr[0];
        for (int i = 0; i < size - 1; i++)
            arr[i] = arr[i + 1];

        arr[size - 1] = val;
    }

    void shiftLeft_times(int n)
    {
        if (size == 0)
            return;
        n %= size;
        if (n == 0)
            return;

        T *temp = new T[size];
        for (int i = 0; i < size; i++)
            temp[i] = arr[(i + n) % size];

        for (int i = 0; i < size; i++)
            arr[i] = temp[i];

        delete[] temp;
    }

    void shiftRight_times(int n)
    {
        if (size == 0)
            return;
        n %= size;
        if (n == 0)
            return;

        T *temp = new T[size];
        for (int i = 0; i < size; i++)
            temp[i] = arr[(i - n + size) % size];

        for (int i = 0; i < size; i++)
            arr[i] = temp[i];

        delete[] temp;
    }

    // -- Operators -- //

    MyVector &operator=(const MyVector<T> &other)
    {
        if (this != &other)
        {
            delete[] arr;
            size = other.size;
            capacity = other.capacity;
            arr = new T[capacity];
            for (int i = 0; i < size; i++)
                arr[i] = other.arr[i];
        }

        return *this;
    }

    T &operator[](int idx)
    {
        assert(idx >= 0 && idx < size);
        return arr[idx]; // for normal vectors
    }

    const T &operator[](int idx) const
    {
        assert(idx >= 0 && idx < size);
        return arr[idx]; // for const vectors
    }

    // -- Iterators -- //
    T *begin()
    {
        return arr;
    }

    T *end()
    {
        return arr + size;
    }
};

int main()
{

    return 0;
}
