// divide and conquer to find minimum




//finding minimun using divide and conquer

#include <bits/stdc++.h>
#define vec vector< long long int>
#define vecp vector < pair<long long int ,long long int> > 
#define pb push_back
#define f(i,a,b) for(long long int i=a;i<b;i++)
#define tc long long int t; cin>>t; while(t--)
#define mp make_pair
using namespace std;
typedef  long long int ll;

ll find(vec v,ll start, ll end)
{
    ll min;
	if(start==end)
		return v[end];

	ll mid=(start+end)/2;
	ll minleft=find(v,start,mid);
	ll minright=find(v,mid+1,end);
	if(minleft<minright) 
		min=minleft;
	else
		min=minright;
	return min;
}

int main()
{
    int n;
    cin>>n;
    vec v;
    f(i,0,n)
    {
    	ll k;
    	cin>>k;
    	v.pb(k);
    }
    ll min=find(v,0,n-1);
    cout<<min;
}