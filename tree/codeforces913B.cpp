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
   int n;
   cin>>n;
   vec(int) v[n+1];
   int mark[n+1]={0};
   for(int i=2;i<=n;i++){
   	int k;cin>>k;
   	v[k].pb(i);
   }
   for(int i=1;i<n;i++)
   {
   	if(v[i].size()==0){
   		mark[i]=3;
   		continue;
   	}
	f(j,0,v[i].size()){
		if(v[v[i][j]].size()==0){
			mark[i]++;
		}
	}   	
   }
   int ans=1;
   for(int i=1;i<n;i++){
   	if(mark[i]<3){
   		ans=0;
   		break;
   	}
   }
   if(ans){
   	cout<<"Yes";
   }
   else{
   	cout<<"No";
   }
}