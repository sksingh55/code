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
    n = n%60;
    ll a=0,b=1,c=1;
    if(n==0)
    {
        cout<<0;
        return 0;
    }
    f(i,2,n+1)
    {
        c= (a*a)%10 + (b*b)%10;
        a= (b)%10;
        b= (c)%10;
    }
    cout<<c%10;
    return 0;
}