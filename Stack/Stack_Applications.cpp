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
class Node
{
public:
    T val;
    Node *next;
    Node(T val) : val(val), next(nullptr) {};
};

template <typename T>
class Mystack
{
private:
    Node<T> *head;

    int precedence(char op)
    {
        if (op == '+' or op == '-')
            return 1;
        if (op == '*' or op == '/')
            return 2;
        if (op == '^')
            return 3;
        return 0;
    }

    int applyOp(int a, int b, char op)
    {
        if (op == '+')
            return a + b;
        if (op == '-')
            return a - b;
        if (op == '*')
            return a * b;
        if (op == '/')
            return a / b;
        return 0;
    }

public:
    Mystack() : head(nullptr) {};

    // -- Main Functions -- //
    bool isempty() { return head == nullptr; }
    void push(T item)
    {
        Node<T> *node = new Node(item);
        node->next = head;
        head = node;
    }
    void pop()
    {
        if (isempty())
            return;

        Node<T> *del = head;
        head = head->next;
        delete del;
    }

    T top()
    {
        if (isempty())
            return T();

        return head->val;
    }

    void display()
    {
        if (isempty())
            return;

        Node<T> *trav = head;
        while (trav != nullptr)
        {
            cout << trav->val << " ";
            trav = trav->next;
        }
        cout << nl;
    }

    int getSize()
    {
        if (isempty())
        {
            cout << "Your Stack is empty " << nl;
            exit(1);
        }

        int cnt = 0;
        Node<T> *trav = head;
        while (trav)
            cnt++, trav = trav->next;

        return cnt;
    }

    int searchItem(T item)
    {
        if (isempty())
        {
            cout << "Your Stack is empty !" << nl;
            exit(1);
        }

        if (head->val)
        {
            return 0;
        }

        int index = 0;
        Node<T> *cur = head;
        while (cur)
        {
            if (cur->val == item)
                return index;
            index++;
            cur = cur->next;
        }

        return -1; // not found
    }

    ~Mystack()
    {
        while (!isempty())
            pop();
    }

    // -- Applications of Stack (General functions) -- //
    string Infix_to_Postfix(string &infix)
    {
        Mystack<char> operators;
        string postfix = "";

        for (int i = 0; i < sz(infix); i++)
        {
            if (isspace(infix[i]))
                continue;
            if (isdigit(infix[i]))
            {
                while (i < sz(infix) && isdigit(infix[i]))
                    postfix += infix[i], i++;

                postfix += " ";
                i--;
            }
            else if (infix[i] == '(')
            {
                operators.push(infix[i]);
            }
            else if (infix[i] == ')')
            {
                while (!operators.isempty() && operators.top() != '(')
                    postfix += operators.top(), postfix += " ", operators.pop();

                operators.pop();
            }
            else
            {
                while (!operators.isempty() && precedence(operators.top()) >= precedence(infix[i]))
                    postfix += operators.top(), postfix += " ", operators.pop();

                operators.push(infix[i]);
            }
        }

        while (!operators.isempty())
            postfix += operators.top(), postfix += " ", operators.pop();

        return postfix;
    }

    int postfixEvaluation(string &postfix) // to evaluate the postfix
    {
        Mystack<int> res;

        for (int i = 0; i < postfix.size(); i++)
        {
            if (isspace(postfix[i]))
                continue;
            if (isdigit(postfix[i]))
            {
                int num = 0;
                while (i < postfix.size() && isdigit(postfix[i]))
                    num = num * 10 + (postfix[i] - '0'), i++;

                res.push(num);
                i--;
            }
            else
            {

                int f = res.top();
                res.pop();
                int s = res.top();
                res.pop();

                switch (postfix[i])
                {
                case '+':
                    res.push(s + f);
                    break;
                case '-':
                    res.push(s - f);
                    break;
                case '*':
                    res.push(s * f);
                    break;
                case '/':
                    res.push(s / f);
                    break;
                case '^':
                    res.push(pow(s, f));
                    break;

                default:
                    cout << "Invalid operator\n";
                    return -1;
                }
            }
        }

        return res.top();
    }

    int InfixEvaluation(string &infix) // to evaluate the infix equation->  ( 1 + 2 ) * ( 6 - 4 )  -> 6
    {
        Mystack<int> vals;
        Mystack<char> op;
        for (int i = 0; i < sz(infix); i++)
        {
            if (isspace(infix[i]))
                continue;

            if (isdigit(infix[i]))
            {
                int num = 0;
                while (i < sz(infix) && isdigit(infix[i]))
                {
                    num = num * 10 + (infix[i] - '0');
                    i++;
                }

                vals.push(num);
                i--;
            }
            else if (infix[i] == '(')
            {
                op.push(infix[i]);
            }
            else if (infix[i] == ')')
            {
                while (!op.isempty() && op.top() != '(')
                {
                    int y = vals.top();
                    vals.pop();

                    int x = vals.top();
                    vals.pop();

                    char operation = op.top();
                    op.pop();

                    vals.push(applyOp(x, y, operation));
                }

                op.pop();
            }
            else
            {
                while (!op.isempty() && precedence(op.top()) >= precedence(infix[i]))
                {
                    int y = vals.top();
                    vals.pop();

                    int x = vals.top();
                    vals.pop();

                    char operation = op.top();
                    op.pop();

                    vals.push(applyOp(x, y, operation));
                }

                op.push(infix[i]);
            }
        }

        while (!op.isempty())
        {
            int y = vals.top();
            vals.pop();

            int x = vals.top();
            vals.pop();

            char operation = op.top();
            op.pop();

            vals.push(applyOp(x, y, operation));
        }

        return vals.top();
    }

    string Infix_to_Prefix(string &infix) // to convert the Infix to prefix
    {
        // TODO
        return "";
    }

    int prefixEvaluation(string &prefix) // to evaluate the prefix equation
    {
        // TODO
        return 0;
    }

    string reverseEachWord(string &word) // reverse each word : Omar Adel -> ledA ramO
    {
        Mystack<char> st;
        string res = "";

        for (int i = 0; i < sz(word); i++)
        {
            if (isspace(word[i]))
                st.push('#');
            else
                st.push(word[i]);
        }

        while (!st.isempty())
        {
            if (st.top() == '#')
                res += " ";
            else
                res += st.top();

            st.pop();
        }

        return res;
    }

    string reverseWord(string &word) // reverse sentence : OmarAdel -> ledAramO
    {
        Mystack<char> st;
        string res = "";

        for (int i = 0; i < sz(word); i++)
            st.push(word[i]);

        while (!st.isempty())
        {
            res += st.top();
            st.pop();
        }

        return res;
    }

    bool checkBalance(string &s)
    {
        Mystack<char> st;
        for (auto &c : s)
        {
            if (st.isempty() || c == '(' || c == '[' || c == '{')
                st.push(c);
            else if ((st.top() == '(' && c == ')') or (st.top() == '[' && c == ']') or (st.top() == '{' && c == '}'))
                st.pop();
        }
        return st.isempty();
    }

    bool isPalindrome(string &s) // chach if the word is palindrome or not
    {
        Mystack<char> st;
        for (auto &c : s)
            st.push(c);

        if (st.isempty())
            return false;

        for (int i = 0; i < sz(s); i++)
        {
            if (st.top() != s[i])
                return false;
            st.pop();
        }

        return true;
    }

    string decTobin(int x) // conver decimal to binary
    {
        Mystack<char> st;
        string s = "";
        while (x > 0)
        {
            st.push((x % 2) + '0');
            x /= 2;
        }

        while (!st.isempty())
            s += st.top(), st.pop();

        return s;
    }
};

signed main()
{

    return 0;
}
