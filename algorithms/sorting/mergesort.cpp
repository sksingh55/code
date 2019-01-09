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
ll b[100000];
void merge(ll arr[],ll low,ll mid, ll high)
{
	ll l1,l2,i;
	

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) 
   {
      if(arr[l1] <= arr[l2])
         b[i] = arr[l1++];
      else
         b[i] = arr[l2++];
 	}

 	while(l1<=mid)
 		b[i++]=arr[l1++];
 	while(l2<=high)
 		b[i++]=arr[l2++];

 	for(i = low; i <= high; i++)
      arr[i] = b[i];


}

void mergesort(ll arr[],ll start,ll end)
{
	if(start<end)
	{
		ll mid=start+end;
		mid=mid/2;
		mergesort(arr,start,mid);
		mergesort(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
	
}

int main()
{
	ll n;
	cin>>n;
	ll arr[n+1];
	f(i,0,n)
	cin>>arr[i];

	mergesort(arr,0,n);
	f(i,1,n+1)
	cout<<arr[i]<<" ";
}
