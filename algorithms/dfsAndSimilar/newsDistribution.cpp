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
bool visited[MAX] = {false};
ll freq = 0;
ll n,m;
void dfs(ll node)
{
    
}


int main()
{
    cin>>n>>m;
    vector<ll> group[m+10];
    f(i,1,m+1){
        ll k;
        cin>>k;
        f(j,0,k){
            ll x;
            cin>>x;
            group[x].pb(i);
            graph[i].pb(x);
        }
    }
    f(i,1,n+1){
        if(!visited[i]){
            freq=0;
            for(int j=0;j<group[i].size();j++){
                dfs(group[i][j]);
            }
        }
    }
    
    
}
