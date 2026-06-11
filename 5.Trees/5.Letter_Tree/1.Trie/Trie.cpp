// بسم الله الرحمن الرحيم
// وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define nl '\n'

class TRIE
{
private:
    // Trie's node
    struct Node
    {
        Node *ch[26];
        int prefix, cnt;

        Node()
        {
            prefix = cnt = 0;
            memset(ch, 0, sizeof(ch));
        }
    };

    Node *root = new Node();

public:
    void insert(const string &s)
    {
        Node *curr = root;
        for (auto &c : s)
        {
            int idx = c - 'a';
            if (curr->ch[idx] == 0)
            {
                curr->ch[idx] = new Node();
            }
            curr->prefix++;
            curr = curr->ch[idx];
        }

        curr->cnt++;
    }

    void erase(const string &s)
    {
        if (!word_count(s))
            return;

        Node *curr = root;
        for (auto &c : s)
        {
            int idx = c - 'a';
            curr->prefix--;
            curr = curr->ch[idx];
        }
        curr->cnt--;
    }

    // count frequency of word
    int word_count(const string &s)
    {
        Node *curr = root;
        for (auto &c : s)
        {
            int idx = c - 'a';
            if (curr->ch[idx] == 0)
            {
                return 0;
            }
            curr = curr->ch[idx];
        }

        return curr->cnt;
    }

    // count number of prefixes such start with this string
    int prefix_count(const string &s)
    {
        Node *curr = root;
        for (auto &c : s)
        {
            int idx = c - 'a';
            if (curr->ch[idx] == 0)
                return 0;

            curr = curr->ch[idx];
        }

        return curr->prefix;
    }
};

int main()
{

    return 0;
}