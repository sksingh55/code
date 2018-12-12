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
ll a[100005];

ll find(ll node)
{
  while(a[node]!=node)
    {a[node]=a[a[node]];
      node=a[node];}
  return node;
}


int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   ll n,k;
   cin>>n>>k;

   f(i,0,n)
   a[i]=i;

   while(k--)
   {
    ll x,y;
    cin>>x>>y;
    ll xset=find(x);
    ll yset=find(y);
    a[yset]=a[xset];
   }

   mapp(ll,ll) m;
   f(i,0,n)
   {

    a[i]=find(i);
    m[a[i]]++;
  }

  mapp(ll,ll)::iterator it;
  ll ans=1;
  for(it=m.begin();it!=m.end();it++)
  {
    ll z=1;
    f(i,1,it->second+1)
    {
      z*=i;
      z = z%mod;
    }
    ans = ans*z;
    ans = ans %mod;
  }
  cout<<ans;



}