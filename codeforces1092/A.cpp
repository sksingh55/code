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
    tc
    {
        ll n,k;
        cin>>n>>k;
        ll d=n/k;
        ll r=n%k;
        string temp;
        for(ll i=0;i<k;i++)
        {
            temp += 'a'+i;
        }
        string s;
        f(i,0,d)
        {
            s+=temp;
        }
        f(i,0,r)
        {
            s+=('a'+i);
        }


        
        sort(s.begin(),s.end());
        cout<<s<<"\n";
    }
}