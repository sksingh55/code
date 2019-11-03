// Question 5 of week 3


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
    vec(ll) ans;
    ll i=1;
    while(1)
    {
        if(n==0)
            break;  
        n -= i;
        if(n<0)
        {
            
            ans[ans.size()-1]+=abs(n+i);
            break;
        }
        else
            ans.pb(i);
        i++;
    }
    cout<<ans.size()<<"\n";
    f(i,0,ans.size())
    cout<<ans[i]<<" ";

}