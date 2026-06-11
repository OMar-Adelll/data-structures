// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define nl '\n'

class BinaryTRIE
{
private:
    // node's data
    struct Node
    {
        Node *ch[2];
        int freq[2];

        Node()
        {
            ch[0] = ch[1] = 0;
            freq[0] = freq[1] = 0;
        }
    };

    Node *root = new Node();

    void erase(int n, int bit, Node *curr)
    {
        if (bit == -1)
            return;

        int idx = (n >> bit) & 1;
        erase(n, bit - 1, curr->ch[idx]);
        curr->freq[idx]--;
        if (curr->freq[idx] == 0)
        {
            delete curr->ch[idx];
            curr->ch[idx] = 0;
        }
    }

public:
    void insert(int n)
    {
        Node *curr = root;
        for (int bit = 31; bit >= 0; bit--)
        {
            bool idx = (n >> bit) & 1;
            if (curr->ch[idx] == 0)
            {
                curr->ch[idx] = new Node();
            }

            curr->freq[idx]++;
            curr = curr->ch[idx];
        }
    }

    void erase(int n, int bit = 31)
    {
        erase(n, bit, root);
    }

    int mxXor(int n)
    {
        Node *curr = root;
        int ret = 0;
        for (int bit = 31; bit >= 0; bit--)
        {
            bool idx = (n >> bit) & 1;
            if (curr->ch[idx ^ 1] == 0)
            {
                curr = curr->ch[idx];
            }
            else
            {
                curr = curr->ch[idx ^ 1];
                ret |= (1 << bit);
            }
        }

        return ret;
    }
};

int main()
{

    return 0;
}