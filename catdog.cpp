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
    
    tc
    {
    	ll a,b,c;
        cin>>a>>b>>c;
        if(c%4!=0)
        {
            cout<<"no\n";
            continue;
        }
        ll min=0;
        ll max=0;
        ll p=2*b;
        if(a<=p)
        {
            min = b*4;
        }
        else
        {
            min = b*4 + (a-2*b)*4;
        }
        max = (a+b)*4;
        if(c >= min && c<=max)
        {
            cout<<"yes"<<"\n";
        }
        else
        {
            cout<<"no\n";
        }
    	
    }
}

dfdfn
    
