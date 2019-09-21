//URL https://codeforces.com/problemset/problem/520/B

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
typedef long long int  ll;
ll max(ll a,ll b){
    return (a>b)?a:b;
}
ll bfs(ll m,ll n){
    queue<ll> bfs;
    bfs.push(n);
    ll count[MAX] = {0};
    while(!bfs.empty()){
        ll k = bfs.front();
        ll c = count[k];
        // cout<<k<<" "<<c<<"\n";
        if(k==m){
            return c;
        }
        bfs.pop();
        if(k>1 && count[k-1]==0){
            bfs.push(k-1);
            count[k-1] = c+1;
        }
        if(2*k < 2*m && count[2*k]==0 ){
            bfs.push(2*k);
            count[2*k] = c+1;
        }
        
    }
}

int main()
{
    
    ll n,m;
    cin>>n>>m;
    cout<<bfs(m,n);
    

}
