// Question 2 of week 3


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
    double m;
    cin>>n>>m;
    double v[n+1];
    double w[n+1];
    vector< pair< double,long long int > > ratio;
    double ans=0;
    f(i,0,n)
    {
        cin>>v[i]>>w[i];
        ratio.pb(mp(double(v[i]/w[i]),i));
    }
    sort(ratio.begin(),ratio.end());
    fr(i,n-1,0)
    {
        if(m==0)
            break;

        if(m>=w[ratio[i].second])
            {
                //cout<<w[ratio[i].second]<<"\n";
                ans+=ratio[i].first * w[ratio[i].second];
                m -= w[ratio[i].second];
            }
        else
        {
            ans+=ratio[i].first*m;
            break;
        }

    }
    cout<<setprecision(10)<<ans;

    

}