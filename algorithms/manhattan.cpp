#include <bits/stdc++.h>
#define vec(a) vector<a>
#define vecp(a,b) vector < pair< a, b > > 
#define pb push_back
#define minpq priority_queue <long long int, vector<long long int>, greater<long long int> > pq;
#define f(i,a,b) for(long long int i=a;i<b;i++)
#define fr(i,a,b) for(long long int i=a;i>=b;i--)
#define tc long long int t; cin>>t; while(t--)
#define mp make_pair
#define mapp(a,b) map<a, b>
#define umapp(a,b) unordered_map<a ,b> 
#define mem(d,val) memset(d,val,sizeof(d))
using namespace std;
#define mod 1000000007 
typedef long long int ll;

ll distancesum(ll arr[], ll n) 
{  
    sort(arr, arr + n); 
    ll res = 0, sum = 0; 
    for (ll i = 0; i < n; i++) { 
        res += (arr[i] * i - sum)%  mod; 
        sum += arr[i]; 
    } 
  
    return res%mod; 
} 
  
ll totaldistancesum(ll x[], ll y[], ll n) 
{ 
    return distancesum(x, n) + distancesum(y, n); 
} 
  
 
 

int main()
{
  
  ll n;
  cin>>n;
  ll x[n+1];
  ll y[n+1];
  f(i,0,n)
  {
    cin>>x[i]>>y[i];
  }
  cout<<totaldistancesum(x,y,n)%mod;


}