// merge sort
#include <bits/stdc++.h>
#define vec vector< long long int>
#define vecp vector < pair<long long int ,long long int> > 
#define pb push_back
#define f(i,a,b) for(long long int i=a;i<b;i++)
#define tc long long int t; cin>>t; while(t--)
#define mp make_pair
using namespace std;
typedef  long long int ll;


ll partition(ll a[],ll low, ll high)
{
	ll pivot=a[high];
	ll i=low-1;
	f(j,low,high)
	{
		if(a[j]<=pivot)
		{
			i++;
			ll d=a[i];
			a[i]=a[j];
			a[j]=d;
		}
	}
	ll d=a[i+1];
	a[i+1]=a[high];
	a[high]=d;
	return i+1;
}

void quicksort(ll a[],ll start, ll end)
{
	if(start < end)
	{
		ll pi=partition(a,start,end);
		quicksort(a,start,pi-1);
		quicksort(a,pi,end);
	}
}

int main()
{
	ll n;
	cin>>n;
	ll arr[n+1];
	f(i,0,n)
	cin>>arr[i];

	quicksort(arr,0,n);
	f(i,1,n+1)
	cout<<arr[i]<<" ";
}