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
    ll n,c;
    cin>>n>>c;
    ll i=1500;
    while(i<=n)
    {
        cout<<1<<" "<<i<<"\n";
        ll k;
        cin>>k;
        if(k==1)
        {
            cout<<2<<"\n";
            break;
        }
        i+=1500;
    }

    ll j=i-1500+50;
    while(j<i && j<=n)
    {
        cout<<1<<" "<<j<<"\n";
        ll k;
        cin>>k;
        if(k==1)
        {
            cout<<2<<"\n";
            break;
        }
        j+=50;
    }
    ll z=j-49;
    while(z<j && z<=n)
    {
        cout<<1<<" "<<z<<"\n";
        ll k;
        cin>>k;
        if(k==1)
        {
            cout<<2<<"\n";
            break;
        }
        z+=1;
    }
    if(z>n)
        z=n;
    cout<<3<<" "<<z;
    
   
    
}