// count number of inversion in  an array
// PRoblem statement : TO find all pair where a[i]<a[j] && i<j 


#include <bits/stdc++.h>
#define vec vector< long long int>
#define vecp vector < pair<long long int ,long long int> > 
#define pb push_back
#define f(i,a,b) for(long long int i=a;i<b;i++)
#define tc long long int t; cin>>t; while(t--)
#define mp make_pair
using namespace std;
typedef  long long int ll;

ll merge(vec v,ll start, ll mid, ll end)
{
	vec temp;
	ll inv=0;
	
	ll i=start,j=mid;

	//cout<<i<<" "<<j<<"\n";
	while	(i<mid && j<=end)
	{
		if(v[i]<v[j])
			temp.pb(v[i++]);
		else
		{
			temp.pb(v[j++]);
			inv+=mid-i;;
		}
	}

	while(i<mid)
		temp.pb(v[i++]);
	while(j<=end)
		temp.pb(v[j++]);

	v=temp;
	return inv;


}

ll count_inversion(vec v,ll start, ll end  )
{
	ll inv=0;
	ll mid;
	if(start<end)
	{
		mid=start+end;
		mid=mid/2;
		inv += count_inversion(v,start,mid);
		inv +=count_inversion(v,mid+1,end);
		inv +=merge(v,start,mid+1,end);
	}
	return inv;
}

int main()
{
    ll n;
    cin>> n;
    vec v;
    f(i,0,n)
    {
    	ll k;
    	cin>>k;
    	v.pb(k);
    }

    cout<< count_inversion(v,0	,n-1)<<"\n";
}