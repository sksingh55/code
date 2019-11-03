#include <bits/stdc++.h>
#define vec(a) vector<a>
#define vecp(a, b) vector<pair<a, b>>
#define pb push_back
#define minpq priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
#define f(i, a, b) for (  int i = a; i < b; i++)
#define fr(i, a, b) for (  int i = a; i >= b; i--)
#define tc           \
    int t; \
    scanf("%d",&t);        \
    while (t--)
#define mp make_pair
#define mapp(a, b) map<a, b>
#define umapp(a, b) unordered_map<a, b>
#define mem(d, val) memset(d, val, sizeof(d))
using namespace std;
#define mod 1000000007
#define speedup                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
typedef long int ll;

int main()
{
    std::ios::sync_with_stdio(false);
    ll A,C,previous,end,stop,k;
    int B;
    ll ans;
    tc
    {
        ans=0;
        scanf("%ld",&A);
        scanf("%d",&B);
        scanf("%ld",&C);
        f(b, 1, B + 1)
        {
            end = b * b;
            previous = A;
            stop = (b+1<A)?b+1:A;
            f(a, 1, stop)
            {
                k = (b * b / (a)) + 1;
                if (k < C)
                {
                    ans = (ans + (C - k) );
                    ans = ans%mod;
                }
                if (previous - k < 1 || (C - a) < 1)
                    continue;
                ans += (previous - k) * (C - a);
                ans = ans % mod;
                previous = k;
            }
        }
        printf("%lld\n",ans);
    }
}
