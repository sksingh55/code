//disjoint set

#include <bits/stdc++.h>
#define vec vector<long long int> 
#define pb push_back
#define tc int t; cin>>t; while(t--)
#define mp make_pair
using namespace std;
typedef long long int ll;


int main()
{
	ll n, m;
	cin>>n>>m;
	ll a[n+5];
	for(int i=0;i<n+5;i++)
		a[i]=i;
     ll cyclic=0;
	while(m--)
	{
		ll x,y;
		cin>>x>>y;
		
		if(a[y]==a[x])
			cyclic=1;
		else
			a[y]=a[x];

	}
	if(cyclic==1)
		cout<<"NO\n";
	else
		cout<<"YES\n";

}