// بسم الله الرحمن الرحيم
// "وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define sz(x) (int)(x).size()
#define nl '\n'

// you should pass the data type of your heap array
// you should know that it Min heap by defualt you can change it type ( < T , false > ) this mean Max Heap
template <typename T, bool MIN = true>
class Heap
{
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

    void HeapfiyUp(int idx) // we will use this into insertion to put an element into its correct location
    {
        while (idx > 0 && better(nums[idx], nums[parent(idx)]))
        {
            swap(nums[idx], nums[parent(idx)]);
            idx = parent(idx);
        }
    }

    void HeapfiyDown(int idx)
    {
        while (ture)
        {
            int l = left(idx);
            int r = right(idx);
            int best = idx;

            if (l != -1 && better(nums[l], nums[best]))
                best = l;
            if (r != -1 && better(nums[r], nums[best]))
                best = r;

            if (iex == best) // best not changed
                break;
            swap(nums[idx], nums[best]);
            idx = best;
        }
    }

public:
    void push(const T &node)
    {
        nums.push_back(node);
        int idx = sz(nums) - 1;
        HeapfiyUp(idx);
    }

    void pop()
    {
        if (nums.empty())
            return;

        /*
            always we want to delet the root element and if you make this your binary will be not complete
            -> solution :
                1- we will assign the last elemnt to the first (when you make this you finaly deleted the root element value)
                2- we will make Heapfiy down to the root to put it into its correct location
        */
        nums[0] = nums.back();
        nums.pop_back();

        HeapfiyDown(0); // you will make heapify down to the root like this
    }
};

signed main()
{

    return 0;
}
