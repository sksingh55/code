//URL https://codeforces.com/problemset/problem/546/C

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
#define modd 1000000007
#define MAX 100005
#define speedup std::ios::sync_with_stdio(false);
using namespace std;
typedef long long int ll;
ll max(ll a, ll b)
{
    return (a > b) ? a : b;
}

ll freq = 0;
ll winner, numberoffight;
queue<int> first;
queue<int> second;
void solve()
{
    while(1)
    {
        if (freq == MAX)
        {
            winner = -1;
            break;
        }
        if (first.empty())
        {
            winner = 2;
            numberoffight = freq;
            break;
        }
        if (second.empty())
        {
            winner = 1;
            numberoffight = freq;
            break;
        }
        ll a = first.front();
        first.pop();
        ll b = second.front();
        second.pop();
        if (a > b)
        {
            first.push(b);
            first.push(a);
        }
        else
        {
            second.push(a);
            second.push(b);
        }
        freq++;
    }
}

int main()
{
    int n;
    cin >> n;
    int k1;
    cin >> k1;
    f(i, 0, k1)
    {
        int x;
        cin >> x;
        first.push(x);
    }
    int k2;
    cin >> k2;
    f(i, 0, k2)
    {
        int x;
        cin >> x;
        second.push(x);
    }
    solve();
    if (winner == -1)
    {
        cout << winner;
    }
    else
    {
        cout << numberoffight << " " << winner;
    }
}
