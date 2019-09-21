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
    tc{
        ll n;
        cin>>n;
        ll a[n+1];
        map<ll,ll> count;
        f(i,0,n){
            cin>>a[i];
            count[a[i]]++;
        }
        for(int i=1;i<=2048;i=i*2){
            ll k = count[i]/2;
            count[2*i] += k;
        }
        if(count[2048]>0){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}
