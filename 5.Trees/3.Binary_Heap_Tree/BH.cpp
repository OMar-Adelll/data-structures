// بسم الله الرحمن الرحيم
// "وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define sz(x) (int)(x).size()
#define nl '\n'

/*
    ## why heap is useful data structure
    - If you have sorted data and you want to add a new element into it's correct postion is difficult if you will use array
    - It more easy if you will use linked list but it's not optimal solution cuz you should travers into linked-list each time
    solution :
    - you will use the heap it will be faster than linked list
*/

/*
    ## Heap main idea (MIN heap) :
    - the root of each sub tree is min than or equal to the subtree childrens
    - it fill left side first to right side and the tree should be ballanced all the time
    - if you delete the top (root) you will replace it value with another one and make heapfiy down
    - indcies based on array (left : i * 2 + 1 , right r * 2 + 2)
*/

// This Heap is dyanmic but it min heap by defualt and you can select if you want it max heap
template <typename T, bool MIN = true>
class Heap
{
private:
    vector<T> nums;

    // this formula is to find the left child from index
    int left(int idx)
    {
        return (2 * idx + 1 >= sz(nums) ? -1 : 2 * idx + 1);
    }

    // this formula is to find the right child from index
    int right(int idx)
    {
        return (2 * idx + 2 >= sz(nums) ? -1 : 2 * idx + 2);
    }

    // this formula is to find the parent from index
    int parent(int idx)
    {
        return (idx == 0 ? -1 : floor((idx - 1) / 2));
    }

    bool better(const T &x, const T &y)
    {
        if (MIN)
            return x < y; // this for Min Heap
        return x > y;     // this for Max Heap
    }

    void HeapfiyUp(int idx) // compare the curr with it's parent to put the new node in correct position
    {
        while (idx > 0 && better(nums[idx], nums[parent(idx)]))
        {
            swap(nums[idx], nums[parent(idx)]);
            idx = parent(idx);
        }
    }

    void HeapfiyDown(int idx) // important to put root into correct position and you will use it into (constructor, delete element)
    {
        while (true)
        {
            int l = left(idx);
            int r = right(idx);
            int best = idx;

            if (l != -1 && better(nums[l], nums[best]))
                best = l;
            if (r != -1 && better(nums[r], nums[best]))
                best = r;

            if (idx == best) // best not changed
                break;
            swap(nums[idx], nums[best]);
            idx = best;
        }
    }

public:
    // this constructor to push a vector into Heap
    Heap(const vector<T> &v)
    {
        nums = v;
        for (int i = parent(sz(nums)); i >= 0; i--)
            HeapfiyDown(i);
    }

    // this function to insert new element
    void push(const T &node)
    {
        nums.push_back(node);
        int idx = sz(nums) - 1;
        HeapfiyUp(idx);
    }

    // this function to pop element
    void pop()
    {
        if (nums.empty())
            return;

        /*
            always we want to delete the root element and if you make this your binary heap tree will be not complete
            solution:
            1- we will assign the root with the last node you have added it (leaf)
            2- after the first step (now finally you deleted the top by assigning anothe value)
            3- now will appear new problem and it's the heap is not ballanced cuz the last element is at incorrect postion now (root)
            4- you will make heapfiydown to put it into it's correct place
        */
        nums[0] = nums.back();
        nums.pop_back();

        HeapfiyDown(0);
    }

    // this function to check your data structure is empty or not ?
    bool empty()
    {
        return nums.empty();
    }

    // this function to return the count of elements into heap
    int size()
    {
        return sz(nums);
    }

    // return always root but it will be (the minimum element -> Min Heap && the maximum element -> Max Heap)
    T top()
    {
        if (nums.empty())
            return T();

        return nums[0];
    }
};

signed main()
{

    return 0;
}
