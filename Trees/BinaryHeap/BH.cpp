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

public:
    void push(const T &node)
    {
        nums.push_back(node);
        int idx = sz(nums) - 1;

        while (i > 0 && better(nums[idx], nums[parent(idx)])) // Heapfiy up to put an elemement on the correct location
        {
            swap(nums[idx], [parent(idx)]);
            idx = parent(idx);
        }
    }
};

signed main()
{

    return 0;
}
