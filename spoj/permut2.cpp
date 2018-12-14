
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
	int n;
	cin>>n;

	while(n!=0)
	{
		ll a[n+1];
		a[0]=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int i=1;
		for(;i<=n;i++)
		{
			if(a[a[i]]!=i)
				break;
		}	
		if(i<=n)
			cout<<"not ambiguous\n";
		else
			cout<<"ambiguous\n";
		cin>>n;
	}
}