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

    ll n,s;
    cin>>n>>s;
    ll a[n+1];
    ll sum=0;
    f(i,0,n)
    {
        cin>>a[i];
        sum += a[i];
    }
    if(sum<s)
    {
        cout<<-1;
        return 0;
    }

    ll low=0;
    ll high=1000000000;
    ll ans=0;
    while(high>=low)
    {
        ll mid=(low+high)/2;
        ll sum = 0;
       // cout<<"mid="<<mid<<"\n";
        f(i,0,n)
        {
            if(a[i]>=mid)
            {
                sum+=a[i]-mid;
            }
        }
        if(sum>=s)
            {ans=mid;}
        if(sum<s)
        {
            high = mid-1;
        }
        else
        {
            low=mid+1;
        }
                
    }
    f(i,0,n)
    {
        if(a[i]<ans)
            ans=a[i];
    }
    cout<<ans;
}
        