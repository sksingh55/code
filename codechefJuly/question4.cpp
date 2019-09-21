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
#define pi pair<long long int,long long int> 
using namespace std;
#define mod 1000000007 
typedef long long int ll;
int main(){
	tc{
		int n;
		cin>>n;
		vec(ll) v;
		f(i,0,n){
			ll k;
			cin>>k;
			v.pb(k);
		}
		bool mark[n+1];
		mem(mark,false);
		ll penalty = 0;
		while(v.size()>1){
			priority_queue <pi, vector<pi>, greater<pi> > pq;
			f(i,0,v.size()){
				pq.push(mp(v[i]+v[(i+1)%v.size()] , i));
			}
			pi min = pq.top();
			pq.pop();
			penalty+= min.first;
			v[min.second] = min.first;
			v.erase(v.begin()+((min.second+1)%v.size()));
		}
		cout<<penalty<<"\n";
	}
}