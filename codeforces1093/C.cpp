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
    ll n;
    cin>>n;
    ll b[n/2 + 1];
    f(i,1,n/2+1)
    {
        cin>>b[i];
    }

   

    ll a[n+1];
    a[1]=0;
    a[n]=b[1];
    f(i,2,n/2+1)
    {
        if(b[i]>(a[n+2-i]+a[i-1]))
        {
            a[n+1-i]=a[n+2-i];
            a[i]=b[i]-a[n+1-i];
        }
        else
        {
            a[i]=a[i-1];
            a[n+1-i]=b[i]-a[i];
        }
    }
    f(i,1,n+1)
    cout<<a[i]<<" ";
}