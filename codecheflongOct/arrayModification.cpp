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

int main()
{
    tc
    {
        ll n, k;
        cin >> n >> k;
        ll a[n + 1];
        f(i,0,n)
        {
            cin >> a[i];
        }
        if(n%2!=0 && k>=n){
			a[n/2]=0;
		}
        k = k % (3 * n);
        f(i,0,k)
        {
            a[i % n] = a[i % n] ^ a[n - (i % n) - 1];
        }
        f(i,0,n)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
