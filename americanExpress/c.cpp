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

int main()
{
	ll t, a, b, c;
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c;
		ll ans = 0;
		for (int i = 1; i <= b; i++)
		{
			ll ans1 = (a - 1 - i < 0 ? 0 : a - 1 - i);
			ll ans2 = (c - 1 - i < 0 ? 0 : c - 1 - i);

			ans = (ans + (ans1 + (ans2 + (ans1 * ans2) % mod) % mod) % mod) % mod;
		}
		cout << ans << "\n";
	}
}
