#include <bits/stdc++.h>
#define vec(a) vector<a>
#define vecp(a, b) vector<pair<a, b>>
#define pb push_back
#define minpq priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
#define f(i, a, b) for (long long int i = a; i < b; i++)
#define fr(i, a, b) for (long long int i = a; i >= b; i--)
#define tc           \
    long long int t; \
    cin >> t;        \
    while (t--)
#define mp make_pair
#define mapp(a, b) map<a, b>
#define umapp(a, b) unordered_map<a, b>
#define mem(d, val) memset(d, val, sizeof(d))
using namespace std;
#define mod 1000000007
typedef long long int ll;

struct stacks
{
    char data;
    struct stacks *next;
};

struct stacks *newNode(char data)
{
    struct stacks *pt = (struct stacks *)malloc(sizeof(struct stacks));
    if (!pt)
    {
        cout << "Heap Overflow\n";
        return NULL;
    }
    pt->data = data;
    pt->next = NULL;
    return pt;
}

void push(struct stacks **pt, char x)
{
    struct stacks *point = newNode(x);
    point->next = *pt;
    *pt = point;
}

void pop(struct stacks **pt)
{
    if (*pt == NULL)
    {
        cout << "Stack is empty\n";
        return;
    }
    struct stacks *node = *pt;
    *pt = (*pt)->next;
    free(node);
}

char peek(struct stacks *pt)
{
    if (pt == NULL)
    {
        return -1;
    }
    return pt->data;
}

bool solver(string s)
{
    struct stacks *pt = NULL;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            if (s[i] == '(')
            {
                push(&pt, '(');
            }
            if (s[i] == '[')
            {
                push(&pt, '[');
            }
            if (s[i] == '{')
            {
                push(&pt, '{');
            }
        }
        else
        {

            if (s[i] == ')' && peek(pt) == '(')
            {
                pop(&pt);
            }
            else if (s[i] == '}' && peek(pt) == '{')
            {
               pop(&pt);
            }
            else if (s[i] == ']' && peek(pt) == '[')
            {
                pop(&pt);
            }
            else
            {
                return false;
            }
        }
    }
    if(peek(pt) == -1){
        return true;
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    cout << solver(s);
}
