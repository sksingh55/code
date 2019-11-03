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
    ll a[n+1];
    ll diff[n+1]={0};
    f(i,0,n)
    {
        cin>>a[i];
    }
    f(i,0,n-1)
    {
        diff[i]=abs(a[i]-a[i+1]);
    }
    ll flag=0;
    f(i,0,n-1)
    {
        if(diff[i]%2==0)
        {
            flag=1;
        }
    }
    if(flag)
        cout<<"YES";
    else
        cout<<"NO";
}