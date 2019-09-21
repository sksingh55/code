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
#define modd 1000000000000007
#define MAX 300005
#define SPEEDUP ios_base::sync_with_stdio(false);
using namespace std;
typedef long long int ll;

int main()
{
    SPEEDUP
    tc
    {
        ll n;
        scanf("%lld", &n);
        ll a[3][n + 1], b[n + 1];
        ll val[3][n + 1] = {{0}};
        f(i, 0, n)
        {
            scanf("%lld%lld",&a[0][i],&b[i]);
            a[1][i] = a[0][i] + 1;
            a[2][i] = a[1][i] + 1;
            val[0][i] = 0;
            val[1][i] = b[i];
            val[2][i] = 2 * b[i];
        }
        f(i, 1, n)
        {
            ll k = modd;
            if (a[0][i] != a[0][i - 1])
            {
                k = min(k, val[0][i - 1]);
            }
            if (a[0][i] != a[1][i - 1])
            {
                k = min(k, val[1][i - 1]);
            }
            if (a[0][i] != a[2][i - 1])
            {
                k = min(k, val[2][i - 1]);
            }
            if (k != modd)
            {
                val[0][i] += k;
            }

            k = modd;
            if (a[1][i] != a[0][i - 1])
            {
                k = min(k, val[0][i - 1]);
            }
            if (a[1][i] != a[1][i - 1])
            {
                k = min(k, val[1][i - 1]);
            }
            if (a[1][i] != a[2][i - 1])
            {
                k = min(k, val[2][i - 1]);
            }
            if (k != modd)
            {
                val[1][i] += k;
            }

            k = modd;
            if (a[2][i] != a[0][i - 1])
            {
                k = min(k, val[0][i - 1]);
            }
            if (a[2][i] != a[1][i - 1])
            {
                k = min(k, val[1][i - 1]);
            }
            if (a[2][i] != a[2][i - 1])
            {
                k = min(k, val[2][i - 1]);
            }
            if (k != modd)
            {
                val[2][i] += k;
            }
        }
        cout << min(val[0][n - 1], min(val[1][n - 1], val[2][n - 1])) << "\n";
    }
}