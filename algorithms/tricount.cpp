// counting triangle puzzle
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
		ll n;
		cin>>n;
		ll ans=n*(n+2)*(2*n+1);
		 ans=ans/8;
		 cout<<ans<<"\n";
	}
}