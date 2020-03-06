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
	tc
	{
		int n;
		cin >> n;
		int a[n + 1], b[n + 1], c[n + 1];
		f(i, 0, n)
		{
			cin >> a[i];
		}
		f(i, 0, n)
		{
			cin >> b[i];
			c[i] = a[i] - b[i];
		}
		string ans = "YES\n";
		bool flag = true;
		int count = 0;
		int k;
		for (int i = 0; i < n; i++)
		{
			if(c[i]>0){
				flag = false;
				break;
			}
			if(c[i]==0){
				continue;
			}
			count++;
			int  k = c[i];
			while(k == c[i+1]){
				i++;
			}
			if(count == 2){
				flag = false;
				break;
			}

		}
		if(flag){
			cout<<ans;
		}
		else{
			cout<<"NO\n";
		}
	}
}
