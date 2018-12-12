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

int main()
{
   ll n;
   cin>>n;
   vec (ll) a;
   f(i,0,n)
   {
    ll k;
    cin>>k;
    a.pb(k);
   }
   reverse(a.begin(),a.end());
   ll t[n+1];
   vec(ll) tval;
   ll r[n+1];
   ll len=0;
   mem(r,-1);
   t[0]=0;
   tval.pb(a[0]);

   f(i,1,n)
   {
        if(a[i]>tval[len])
        {
            t[len+1]=i;
            tval.pb(a[i]);
            len++;
            r[i]=t[len-1];
        }
        else if(a[i]<tval[0])
        {
            t[0]=i;
            tval[0]=a[i];
        }
        else
        {
            ll index=lower_bound(tval.begin(),tval.end(),a[i])-tval.begin();
            tval[index]=a[i];
            t[index]=i;
            r[i]=t[index-1];
        }

   }
   ll mark[n+1]={0};
   ll index=t[len];
   while(1)
   {
    if(index == -1)
        break;
    mark[index]=1;;
    index=r[index];
   }
   ll ans = len+1;
   ll min = INT_MAX;
   ll i=n-1;
   while(mark[i]==1 && i>=0)
    i--;
    min=a[i];
   for(;i>=0;i--)
   {

    if(mark[i]== 0 && a[i]<=min)
    {
        ans++;
        min=a[i];
    }
   }
   cout<<ans<<"\n";
}