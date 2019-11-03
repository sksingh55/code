
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
#define mod 1000000000 
typedef long long int ll;

int main() {
  
    
    int n,m;
    cin>>n>>m;
    vecp(int,int) arr,brr;
    f(i,0,n)
    {
        int k;
        cin>>k;
        arr.pb(mp(k,i));
    }
    f(i,0,m)
    {
        int k;
        cin>>k;
        brr.pb(mp(k,i));
    }

    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());

    for(int i=0;i<n;i++){
        cout<<arr[i].second<<" "<<brr[0].second<<"\n";
    }

    for(int i=1;i<m;i++){
        cout<<arr[n-1].second<<" "<<brr[i].second<<"\n";
    }
}

