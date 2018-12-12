#include <bits/stdc++.h>
#define vec(a) vector<a>
#define vecp(a,b) vector < pair< a, b > > 
#define pb push_back
#define minpq priority_queue <long long int, vector<long long int>, greater<long long int> > pq;
#define f(i,a,b) for(long long int i=a;i<b;i++)
#define fr(i,a,b) for(long long int i=b;i>a;i--)
#define tc long long int t; cin>>t; while(t--)
#define mp make_pair
#define mapp(a,b) map<a, b>
#define umapp(a,b) unordered_map<a ,b> 
using namespace std;
typedef long long int ll;



int main()
{
    //ios_base::sync_with_stdio(0);
    vec(ll) v[10000];
    ll n,q;
    cin>>n>>q;
    ll k=1;
    ll i=0;
    ll level=1;
    while(i<n)
    {

        f(j,0,k)
        {
            ll num;
            i++;
            cin>>num;
            v[level].pb(num);
            if(i>n)
                break;
            cout<<v[level][j]<<" ";

        }
        cout<<"\n";
        level++;
        k=k*2;  
    }
    

}