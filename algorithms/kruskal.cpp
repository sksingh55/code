//minimum spanning tree krushkal's algorithm

#include <bits/stdc++.h>
#define vec vector< long long int>
#define vecp vector < pair<long long int ,long long int> > 
#define pb push_back
#define f(i,a,b) for(long long int i=a;i<b;i++)
#define tc long long int t; cin>>t; while(t--)
#define mp make_pair
using namespace std;
typedef  long long int ll;


int main()
{
	vector < pair <ll,pair <ll,ll> > > v;
	ll n,m;
	cin>>n>>m;
	f(i,0,m)
	{
		
		ll x,y,p;
         cin>>x>>y>>p;
         if(p==0)
         v.pb(mp(p,mp(x,y)));
     	else
     	{
     		ll w;
     		cin>>w;
         v.pb(mp(w,mp(x,y)));
     	}
	}
	sort(v.begin(),v.end());
	ll a[n+2];
	f(i,0,n+2)
	a[i]=i;
	ll sum=0;
	
	f(i,0,v.size())
	{

		
		ll x,y;
		x=v[i].second.first;
		y=v[i].second.second;
		if(a[y] == y)
			{
				a[y]=a[x];
				sum+=v[i].first;
		         
		     }
	}
	cout<<sum;
}