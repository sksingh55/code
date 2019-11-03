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
#define endl cout << "\n"
using namespace std;
typedef long long int ll;

class Solution
{
public:
	void solve(int a[], int n)
	{
		int ans = INT_MIN;
		map<int, int> freq;
		f(i, 0, n)
		{
			ans = max(ans, freq[a[i]]);
			for (int j = 1; j <= sqrt(a[i]); j++)
			{
				if (a[i] % j == 0)
				{
					if (a[i] / j == j)
						freq[j]++;

					else
					{
						freq[j]++;
						freq[a[i] / j]++;
					}
				}
			}
		}
		cout << ans;
		endl;
	}
};

int main()
{
	tc
	{
		int n;
		cin >> n;
		int a[n + 1];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		Solution().solve(a,n);
	}
}
