// Problem Statemment : find closest pair


#include <bits/stdc++.h>
#define vec vector< int>
#define vecp vector < pair< int ,int> > 
#define pb push_back
#define f(i,a,b) for( int i=a;i<b;i++)
#define tc int t; cin>>t; while(t--)
#define mp make_pair
using namespace std;
typedef   int ll;


float find(vecp point,ll start, ll end)
{
	ll i=start;
	ll j=end;
	
	float dist= sqrt(pow(abs(point[i].first-point[j].first),2)+pow(abs(point[i].second-point[j].second),2));
			
	return dist;
}
ll sortest_distance(vecp point,ll start,ll end)
{
	ll mid=(start+end)/2;
	if(end-start<2)
	{

		return find(point,start,end);
	}


	float dl=sortest_distance(point,start,mid);
	float dr=sortest_distance(point,mid,end);
	float d=min(dl,dr);
}

int main ()
{

	ll n;
	cin>>n;
	vecp point;
	f(i,0,n)
	{
		ll x,y;
		cin>>x>>y;
		point.pb(mp(x,y));
	}
	sort(point.begin(),point.end());

	cout<< sortest_distance(point,0,n-1);
}