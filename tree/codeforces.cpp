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
   int parent[n+1];
   vec(int) graph[n+1];
   int a[n+1];
   bool deleted[n+1]={false};
   for(int i=1;i<=n;i++){
   		int m;
   		cin>>m>>a[i];
   		parent[i] = m;
   		graph[m].pb(i);
   }
   vec(int) ans;
   for(int l=0;l<n;l++){
	   for(int i=1;i<=n;i++){
	   	if(a[i] && !deleted[i] && parent[i]!=-1){
	   		int count=0;
	   		for(int j=0;j<graph[i].size();j++){
	   			if(a[graph[i][j]]){
	   				count++;
	   			}
	   		}
	   		if(count==graph[i].size()){
	   			deleted[i]=true;
			   	ans.pb(i);
			   	for(int j=0;j<graph[i].size();j++){
			   		graph[parent[i]].pb(graph[i][j]);
			   		parent[graph[i][j]] = parent[i] ;
			   	}
	   		}
	   	}
	   }
	}
	if(ans.size()==0){
		cout<<-1;
		return 0;
	}
	f(i,0,ans.size()){
		cout<<ans[i]<<" ";
	}
	return 0;

}