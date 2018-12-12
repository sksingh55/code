// bubble sort
#include <bits/stdc++.h>
#define vec vector< long long int>
#define vecp vector < pair<long long int ,long long int> > 
#define pb push_back
#define f(i,a,b) for(long long int i=a;i<b;i++)
#define tc long long int t; cin>>t; while(t--)
#define mp make_pair
using namespace std;
typedef  long long int ll;

int main()
{
	int n;
	cin>>n;
	int arr[n+1];
	f(i,0,n)
	cin>>arr[i];

	f(i,0,n)
	{
		f(j,i+1,n)
		{
			if(arr[i]>arr[j])
			{
				int d=arr[i];
				arr[i]=arr[j];
				arr[j]=d;
			}
		}
	}

	f(i,0,n)
	{
		cout<<arr[i]<<" ";
	}
}