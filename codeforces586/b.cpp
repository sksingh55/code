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
#define MAX 300005
using namespace std;
typedef long long int ll;

int main()
{
    ll n;
    cin >> n;
    ll a[n + 5][n + 5];
    f(i, 1, n + 1)
    {
        f(j, 1, n + 1)
        {
            cin >> a[i][j];
        }
    }
    ll a1 = sqrt(a[1][2] * a[1][3] / a[2][3]);
    cout<<a1<<" ";
    for(int i=2;i<=n;i++){
        ll k = a[1][i]/a1;
        cout<<k<<" ";
    }
}
