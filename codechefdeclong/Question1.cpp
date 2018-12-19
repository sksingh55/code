#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll k,x,n,p,y;
		cin>>k>>x>>n>>p>>y;
		ll ans =-1;
		
		ll each = n/x;// unit of each ingredient he will have if he take exactly one ball from each box
		if(each>k)
		{
			ans=-1;
		}
		else
		{
			if(k%each==0)
			{
				ll out = k/each; // number of ball he must take out from each box to get K unit of X ingredient
				if(out>p)
				{
					ans=-1;
				}
				else
				{
					ans = out;
				}
			}
			else
			{
				ans=-1;
			}

		}


		cout<<ans<<"\n";
	}
}