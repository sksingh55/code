#include <bits/stdc++.h>
#define vec vector< long long int>
#define vecp vector < pair< long long int ,long long int> > 
#define pb push_back
#define f(i,a,b) for(long long int i=a;i<b;i++)
#define tc long long int t; cin>>t; while(t--)
#define mp make_pair
#define map map <long long int, long long int>
using namespace std;
typedef  long long  int ll;


int main()
{
	tc
	{
		ll n;
		cin>>n;
		vector <ll> v;
		f(i,0,32)
		v.pb(pow(2,i));

		ll ans=INT_MAX;
		f(i,0,31)
		{
			f(j,0,31)
			{
				if(i!=j)
				{
					ll sum = v[i] + v[j];
					if(abs(sum - n) < ans)
						ans = abs(sum - n);
				}
			}
		}
		cout<<ans<<"\n";
	}
}