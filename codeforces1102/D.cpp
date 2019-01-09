#include <bits/stdc++.h>
#define vec(a) vector<a>
#define vecp(a,b) vector < pair< a, b > > 
#define pb push_back
#define minpq priority_queue <long long int, vector<long long int>, greater<long long int> > pq;
#define f(i,a,b) for(long long int i=a;i<b;i++)
#define fr(i,a,b) for(long long int i=a;i>=b;i--)
#define tc long long int t; cin>>t; while(t--)
#define mp make_pair
#define mapp(a,b) map<a, b>
#define umapp(a,b) unordered_map<a ,b> 
#define mem(d,val) memset(d,val,sizeof(d))
using namespace std;
#define mod 1000000007 
typedef long long int ll;

int main()
{
   int n;
   cin>>n;
   ll a[256]={0};
   string s;
   cin>>s;
   f(i,0,n)
   {
   	a[s[i]]++;
   }
   ll x=n/3;
   ll r0=a['0']-x;
   ll r1=a['1']-x;
   ll r2=a['2']-x;
   
   if(r2<0)
   {
   	for(int i=n-1;i>=0;i--)
	{
		if(r2>=0)
			break;
		if(s[i]=='1')
		{
			if(r1>0)
			{
				s[i]='2';
				r1--;
				r2++;
			}
		}
	}	
	for(int i=n-1;i>=0;i--)
	{
		if(r2>=0)
			break;
		if(s[i]=='0')
		{
			if(r0>0)
			{
				s[i]='2';
				r0--;
				r2++;
			}
		}
	}	
   }
   if(r1<0)
   {
   	ll count=0;
	for(int i=n-1;i>=0;i--)
	{
		if(r1>=0)
			break;
		if(s[i]=='2')
		{
			count++;
			if(r2>0 && count>x)
			{
				s[i]='1';
				r2--;
				r1++;
			}
		}
	}	
	for(int i=n-1;i>=0;i--)
	{
		if(r1>=0)
			break;
		if(s[i]=='0')
		{
			if(r0>0)
			{
				s[i]='1';
				r0--;
				r1++;
			}
		}
	}	
   }
   if(r0<0)
   {
   	f(i,0,n)
   	{
   		if(r0>=0)
   			break;
		if(s[i]=='2')
		{
			if(r2>0)
			{
				s[i]='0';
				r2--;
				r0++;
			}
		}
   	}
   	f(i,0,n)
   	{
   		if(r0>=0)
   			break;
		if(s[i]=='1')
		{
			if(r1>0)
			{
				s[i]='0';
				r1--;
				r0++;
			}
		}
   	}


   }
   
   cout<<s;
}