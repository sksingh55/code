// Question 6 of week 3


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
int myCompare(string X, string Y) 
{ 
   string XY = X.append(Y); 
  
    string YX = Y.append(X); 
  
    return XY.compare(YX) > 0 ? 1: 0; 
} 
int main() {
    ll n;
    cin>>n;
    vec(string) v;
    f(i,0,n)
    {
        string k;
        cin>>k;
        v.pb(k);
    }
    sort(v.begin(),v.end(),myCompare);
    for(int i=0;i<n;i++)
    {
        cout<<v[i];
    }


}