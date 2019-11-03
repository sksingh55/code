//URL https://codeforces.com/problemset/problem/217/A

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
vecp(ll,ll) point;
ll n;
bool visited[MAX] = {false};
void solve(int node){
   visited[node]=true;
   f(i,0,n){
       if(!visited[i] && (point[node].first == point[i].first || point[node].second == point[i].second)){
           solve(i);
       }
   }
}

int main()
{
    cin>>n;
    f(i,0,n){
        ll x,y;
        cin>>x>>y;
        point.pb(mp(x,y));
    }
    ll ans =0;
    f(i,0,n){
        if(!visited[i]){
            ans++;
            solve(i);
        }
    }
    cout<<ans-1;

}
