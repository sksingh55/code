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

int main()
{
    ll n,k;
    cin>>n>>k;
    ll a[n+1];
    vecp(ll,ll) b;
    f(i,0,n){
        cin>>a[i];
        b.pb(mp(a[i],i));
    }
    vecp(ll,ll) ans;
    sort(b.begin(),b.end());
    
}
