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
        ll n;
        cin>>n;
        ll ans[n+1]={0};
       	
        if(n%2==0)
        {
        	ll a,b;
        	cout<<1<<" "<<1<<" "<<2<<" "<<3<<"\n";
        	cin>>a;
        	cout<<1<<" "<<2<<" "<<3<<" "<<4<<"\n";
        	cin>>b;
        	ll x=a^b;
        	ll p=1,q=4;
        	ll count=0;
        	for(ll i=5;i<=n;i++)
        	{
        		ll k=0;
        		cout<<1<<" "<<p<<" "<<q<<" "<<i<<"\n";
        		cin>>k;
        		ans[i]=x^k;
        		count++;
        		if(count==2)
        		{
        			//cout<<"change\n";
        			count=0;
        			p=i-1;
        			q=i;
        			x = ans[p]^ans[q];
        		}

        	}
        	ll k=0;
    		cout<<1<<" "<<n-1<<" "<<n<<" "<<2<<"\n";
    		cin>>k;
    		ans[2]=ans[n-1]^ans[n]^k;
    		cout<<1<<" "<<n-1<<" "<<n<<" "<<3<<"\n";
    		cin>>k;
    		ans[3]=ans[n-1]^ans[n]^k;
    		ans[1]=a^ans[2]^ans[3];
    		ans[4]=b^ans[2]^ans[3];


        }
        else
        {
        	ll a,b;
        	cout<<1<<" "<<1<<" "<<2<<" "<<3<<"\n";
        	cin>>a;
        	cout<<1<<" "<<2<<" "<<3<<" "<<4<<"\n";
        	cin>>b;
        	ll x=a^b;
        	ll p=1,q=4;
        	ll count=0;
        	for(ll i=5;i<=n;i++)
        	{
        		ll k=0;
        		cout<<1<<" "<<p<<" "<<q<<" "<<i<<"\n";
        		cin>>k;
        		ans[i]=x^k;
        		count++;
        		if(count==2)
        		{
        			//cout<<"change\n";
        			count=0;
        			p=i-1;
        			q=i;
        			x = ans[p]^ans[q];
        		}

        	}
        	ll k=0;
    		cout<<1<<" "<<n-1<<" "<<n<<" "<<2<<"\n";
    		cin>>k;
    		ans[2]=ans[n-1]^ans[n]^k;
    		cout<<1<<" "<<n-2<<" "<<n<<" "<<3<<"\n";
    		cin>>k;
    		ans[3]=ans[n-2]^ans[n]^k;
    		ans[1]=a^ans[2]^ans[3];
    		ans[4]=b^ans[2]^ans[3];



        }





        cout<<2<<" ";
        for(int i=1;i<=n;i++)
        	cout<<ans[i]<<" ";
        cout<<"\n";
        ll b;
        cin>>b;
        if(b!=1)
        	break;


    }
   
    
}