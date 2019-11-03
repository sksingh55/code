#include <bits/stdc++.h>
#define vec(a) vector<a>
#define vecp(a, b) vector<pair<a, b>>
#define pb push_back
#define minpq priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
#define f(i, a, b) for (long long int i = a; i < b; i++)
#define fr(i, a, b) for (long long int i = a; i >= b; i--)
#define tc             \
    long long int t;   \
    scanf("%lld", &t); \
    while (t--)
#define mp make_pair
#define mapp(a, b) map<a, b>
#define umapp(a, b) unordered_map<a, b>
#define mem(d, val) memset(d, val, sizeof(d))
#define modd 1000000007
#define MAX 9000025
#define SPEEDUP ios_base::sync_with_stdio(false);
#define endl cout << "\n"
using namespace std;
typedef long long int ll;

vector<ll> graph[MAX];
vecp(ll, ll) query[MAX];
ll t[MAX], res[MAX], arr[MAX];
ll n, q;

ll query_func(ll l, ll r)
{
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}

void modify(ll p, ll val){
    for (t[p += n] += val; p > 1; p >>= 1)
        t[p >> 1] = t[p] + t[p ^ 1];
}

void dfs(ll u, ll p, ll depth)
{
    modify(q + depth, arr[u]);
    if (graph[u].size() == 0 || graph[u].size() == 1 && u != 0)
    {
        for (pair<ll, ll> curq : query[u])
        {
            if (curq.first == -1)
            {
                res[curq.second] = query_func(q + depth - curq.second, q + depth + 1);
            }
            else
            {
                modify(q + depth - curq.second, curq.first);
            }
        }
        for (pair<ll, ll> curq : query[u])
        {
            if (curq.first != -1)
            {
                modify(q + depth - curq.second, -1 * curq.first);
            }
        }
        modify(q + depth, -1 * arr[u]);
        return;
    }

    for (pair<ll, ll> curq : query[u])
    {
        if (curq.first == -1)
        {
            res[curq.second] = t[n + q + depth - curq.second];
        }
        else
        {
            modify(q + depth - curq.second, curq.first);
        }
    }

    for (int v : graph[u])
    {
        if (v != p)
            dfs(v, u, depth + 1);
    }

    for (pair<ll, ll> curq : query[u])
    {
        if (curq.first != -1)
        {
            modify(q + depth - curq.second, -1 * curq.first);
        }
    }

    modify(q + depth, -1 * arr[u]);
    return;
}

int main()
{
    ll nn;
    cin >> nn;
    cin >> q;
    n = (nn + q);
    mem(graph, 0);
    mem(query, 0);
    mem(res, 0);
    mem(t, 0);
    mem(arr, 0);
    
    for (ll i = 0; i < nn - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        graph[a - 1].pb(b - 1);
        graph[b - 1].pb(a - 1);
    }

    for (ll i = 0; i < nn; i++)
    {
        cin >> arr[i];
    }
    
    for (ll i = 1; i <= q; i++)
    {
        char c;
        cin >> c;
        if (c == '?')
        {
            ll a;
            cin >> a;
            query[a - 1].pb(mp(-1, i));
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            query[a - 1].pb(mp(b, i));
        }
    }
    f(i, 0, q + 1)
    {
        res[i] = -1;
    }
    dfs(0, -1, 0);

    for (ll i = 1; i <= q; i++)
    {
        if (res[i] != -1)
            cout << res[i] << "\n";
    }
}
