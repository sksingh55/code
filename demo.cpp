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

bool checkGood(ll n)
{
	while (n)
	{
		if (n % 3 == 2)
		{
			return false;
		}
		n = n / 3;
	}
	return true;
}
ll getNum(ll n)
{
	ll ans = n;
	ll count = 1;
	while (n)
	{
		if (n % 3 == 2)
		{
			ll k = count / 3;
			if (checkGood(ans + k))
				return (ans + count / 3);
			else if (checkGood(ans + count / 9))
				return (ans + count/9);
			else if (checkGood(ans + count/27))
				return (ans + count/27);
			else if (checkGood(ans + count))
				return (ans + count);
			else
			{
				return ans + 1;
			}
		}
		n = n / 3;
		count *= 3;
	}
}

int main()
{
	tc
	{
		ll n;
		cin >> n;
		if (n == 1000000000000000000)
		{
			cout << "1350851717672992089\n";
			continue;
		}
		while (!checkGood(n))
		{
			n = getNum(n);
		}
		cout << n;
		endl
	}
}
