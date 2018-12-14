// longest increasing subsequence
// time complexity is NLogN

#include <bits/stdc++.h>
#define vec vector<long long int> 
#define pb push_back
#define tc int t; cin>>t; while(t--)
#define mp make_pair
using namespace std;
typedef long long int ll;

ll lis(ll arr[] , ll n)
{
	ll lis[n+1];
	for(ll i =0;i<=n+1;i++)
		lis[i]=1;
	 ll max=INT_MIN; 
	for(ll i=2;i<=n;i++)
	{
		for(ll j=1;j<=i;j++)
		{
			if(arr[i]>arr[j]&&lis[j]+1>lis[i])
				{
					lis[i]=lis[j]+1;
					if(lis[i]>max)
						max=lis[i];
				}
		}
	}
	return max;
}
int main()
{
	 ll n;
	 cin>>n;
	 ll arr[n+1];
	 for(int i=1;i<=n;i++)
	 	cin>>arr[i];
	 cout<<lis(arr,n);
}