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
typedef double ll;

int main()
{
    tc{
        ll m,c,x;
        cin>>m>>c>>x;
        ll y = min(m,c);
        ll a = m-y;
        ll b = c-y;
        ll k = a+b+x;
        if(k >= y ){
            long long int ns= y;
            cout<<ns<<"\n";
        }else{
            ll p = ceil((y-k)/3);
            long long int ans = y-p;
            cout<<max(0ll,ans)<<"\n";
        }
    }
}
