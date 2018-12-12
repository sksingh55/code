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

int main() {

    ll n;
    cin>>n;
    ll a[n+2];
    f(i,1,n+1)
    {
        cin>>a[i];
    }
    ll ans=INT_MAX;
    f(i,1,n+1)
    {
        ll sum=0;
        f(j,1,n+1)
        {
            ll k=abs(i-j)+j-1+abs(i-1);
            k = k*2;
            k = a[j]*k;
            sum+=k;
            
        }
        if(sum<ans)
            ans=sum;
    }
    cout<<ans;
   
}