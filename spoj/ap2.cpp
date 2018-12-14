
#include <bits/stdc++.h>
#define vec vector< long long int>
#define vecp vector < pair<long long int ,long long int> > 
#define pb push_back
#define tc int t; cin>>t; while(t--)
#define mp make_pair
using namespace std;
typedef long long int ll;

int main()
{
	tc
	{
		ll x,y,s;
		cin>>x>>y>>s;
		ll n=2*s/(x+y);
		cout<<n<<"\n";
		ll d=2*(s-x*n);
		
		d=d/(n*(n-1)-4*n);
	
		ll a=x-2*d;
         
		for(int i=0;i<n;i++)
		{
			cout<<a<<" ";
			a+=d;
		}
		cout<<"\n";
	}
}