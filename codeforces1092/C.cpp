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
    string p[2*n];
    vec(string) s;
    vecp(ll,ll) pair;
    f(i,0,2*n-2)
    {
        string k;
        cin>>k;
        p[i]=k;
        pair.pb(mp(k.length(),i));
        if(k.length()==(n-1))
            s.pb(k);
        
    }
    sort(pair.begin(),pair.end());



    string a,b;
    a=s[0];
    b=s[1];
    string ans1=a+b[n-2];
    string ans2=b+a[n-2];


    ll flag=0;
    vec(char) ans;
    f(i,0,2*n-2)
    {
        string k=p[i];
        ll pref=1;
        f(i,0,k.length())
        {
            if(ans1[i]!=k[i])
            {
                pref=0;
                break;
            }
        }
        ll suf=1;
        f(i,0,k.length())
        {
            if(ans1[n-i-1]!=k[k.length()-1-i])
            {
                suf=0;
                break;
            }
        }
        if(suf==0 && pref==0)
        {
            flag=1;
            ans.clear();
            break;
        }
        else
        {
            if(pref==1)
            {
                ans.pb('P');
            }
            else
            {
                ans.pb('S');
            }
        }

    }

    if(flag)
    {
        f(i,0,2*n-2)
        {
            string k=p[i];
            ll pref=1;
            f(i,0,k.length())
            {
                if(ans2[i]!=k[i])
                {
                    pref=0;
                    break;
                }
            }
            if(pref)
                ans.pb('P');
            else
                ans.pb('S');
        }
    }
    for(ll i=0;i<(2*n-2);i+=2)
    {
        if(ans[pair[i].second]=='P')
        {
            ans[pair[i+1].second] = 'S';  
        }
        else
        {
            ans[pair[i+1].second] = 'P';
        }
    }
    f(i,0,2*n-2)
    cout<<ans[i];
   




}