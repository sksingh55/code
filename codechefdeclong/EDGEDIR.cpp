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
        ll n,m;
        cin>>n>>m;
        vecp(ll,ll) g;
        ll degree[n+2]={0};
        ll intake[n+2]={0};
        ll ans[m+2];
        mem(ans,-1);
        f(i,0,m)
        {
            ll x,y;
            cin>>x>>y;
            g.pb(mp(x,y));
            degree[x]++;
            degree[y]++;
        }
        if(m%2!=0)
        {
            cout<<-1<<"\n";
            continue;
        }
        f(i,0,g.size())
        {
            ll x,y;
                    x=g[i].first;
                    y=g[i].second;
            if(degree[x]==1)
            {
                ans[i]=1;
                intake[y]++;
                m--;
            }
            else if(degree[y]==1)
            {
                ans[i]=0;
                intake[y]++;
                m--;
            }
        }

        ll val=2;
        while(m)
        {
            f(i,0,g.size())
            {

                if(ans[i]!=-1)
                    continue;
                ll x,y;
                x=g[i].first;
                y=g[i].second;
                if(intake[x]==val && intake[y]==val)
                    continue;
                else
                {
                    if(intake[x]!=val)
                    {
                        ans[i]=0;
                        intake[x]++;
                        m--;
                    }
                    else
                    {
                        ans[i]=1;
                        intake[y]++;
                        m--;
                    }
    
                }
    
    
            }
            f(i,1,g.size()+1)
            cout<<ans[i]<<" ";
            cout<<"\n";
        }
        

    }
    
   
    
}