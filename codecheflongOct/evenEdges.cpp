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

	tc
	{
		int n, m;
		cin >> n >> m;
		int deg[n + 1]={0};
		int res[n + 1]={0};
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		res[a] = 3;
		res[b] = 4;
		deg[a]++;
		deg[b]++;
		f(i,1,m)
		{
			cin >> a >> b;
			a--;
			b--;
			deg[a]++;
			deg[b]++;
		}
		if (m % 2 == 0)
		{
			cout << "1\n";
			f(i,0,n)
			{
				cout << "1 ";
			}
		}
		else
		{
			bool flag = false;
			f(i,0,n)
			{
				if (deg[i] % 2 == 1)
				{
					res[i] = 2;
					flag = true;
					break;
				}
			}
			if (flag)
			{
				cout << "2\n";
				f(i,0,n)
					if (res[i] != 2)
						res[i] = 1;
			}
			else
			{
				cout << "3\n";
				f(i,0,n)
				{
					if (res[i] == 3)
						res[i]--;
					else if (res[i] == 4)
						res[i]--;
					else
						res[i] = 1;
				}
			}
			f(i,0,n)
				cout << res[i] << " ";
		}
		endl;
	}
}
