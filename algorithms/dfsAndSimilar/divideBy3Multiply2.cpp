//URL https://codeforces.com/problemset/problem/977/D

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

map<ll, vector<ll>> graph;
map<ll, bool> visited;
ll freq = 0;
ll n;
void dfs(ll node)
{
    visited[node] = true;
    freq++;
    for (int i = 0; i < graph[node].size(); i++)
    {
        if (visited.find(graph[node][i]) != visited.end() && !visited[graph[node][i]])
        {
            dfs(graph[node][i]);
        }
    }
}
void print(ll node)
{
    visited[node] = true;
    cout << node << " ";
    for (int i = 0; i < graph[node].size(); i++)
    {
        if (visited.find(graph[node][i]) != visited.end() && !visited[graph[node][i]])
        {
            print(graph[node][i]);
        }
    }
}

int main()
{
    cin >> n;
    ll a[n + 1];
    f(i, 0, n)
    {
        ll x;
        cin >> x;
        a[i] = x;
        if (x % 3 == 0)
        {
            graph[x].pb(x / 3);
        }
        graph[x].pb(x * 2);
    }
    ll ans;
    f(i, 0, n)
    {
        freq = 0;
        f(j, 0, n)
        {
            visited[a[j]] = false;
        }
        dfs(a[i]);
        if (freq == n)
        {
            ans = a[i];
        }
    }
    f(j, 0, n)
    {
        visited[a[j]] = false;
    }
    print(ans);
}
