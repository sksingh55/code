//longest common subsequence nlogn
#include <bits/stdc++.h>
#define vec vector< long long int>
#define vecp vector < pair<long long int ,long long int> > 
#define pb push_back
#define f(i,a,b) for(long long int i=a;i<b;i++)
#define tc long long int t; cin>>t; while(t--)
#define mp make_pair
using namespace std;
typedef long long int ll;




int main()
{
	ll n;
	cin>>n;
	vec v;
	ll r[n+1];
    memset(r,-1,sizeof(r));
    
	f(i,0,n)
	{
		ll k;
		cin>>k;
		v.pb(k);
	}
	ll len=0;

	vec t[2];
	

	for(int i=0;i<n;i++)
	{
		if(t[0].empty())
		{
			t[0].pb(i);
			t[1].pb(v[i]);
		}
		else
		{
			ll k=lower_bound(t[1].begin(),t[1].end(),v[i])-t[1].begin();
		     
			
			if(k==len+1)
			{
				t[0].pb(i);
				t[1].pb(v[i]);
				len++;
				if(k!=0)
				r[i]=t[0][k-1];
			}
			else
			{
				t[0][k]=i;
				t[1][k]=v[i];
				if(k!=0)
				{
				    //cout<<"i="<<i<<"\n";
					r[i]=t[0][k-1];
				}

			}
			
		}
	}
	
	ll pos=t[0][len];
	cout<<len+1<<"\n";
	while(pos!=-1)
	{
	    cout<<v[pos]<<" ";
	    pos=r[pos];
	}
    
 }
