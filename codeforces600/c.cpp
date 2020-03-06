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
#define MAX 300005
#define SPEEDUP ios_base::sync_with_stdio(false);
#define endl cout << "\n";
using namespace std;
typedef long long int ll;

int main()
{
	ll n,m;
	cin>>n>>m;
	ll a[n+1];
	a[0]=0;
	f(i,1,n+1){
		cin>>a[i];
	}
	sort(a,a+n+1);
	f(i,1,n+1){
		a[i] += a[i-1];
	}
	f(i,m+1,n+1){
		a[i] += a[i-m];
	}
	f(i,1,n+1){
		cout<<a[i] <<" ";
	}
}
