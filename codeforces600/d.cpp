#include <bits/stdc++.h>
#define vec(a) vector<a>
#define vecp(a, b) vector<pair<a, b>>
#define pb push_back
#define minpq priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
#define f(i, a, b) for (long long int i = a; i < b; i++)
#define fr(i, a, b) for (long long int i = a; i >= b; i--)
#define tc             \
	long long int t;   \
	scanf("%lld", &t); \
	while (t--)
#define mp make_pair
#define mapp(a, b) map<a, b>
#define umapp(a, b) unordered_map<a, b>
#define mem(d, val) memset(d, val, sizeof(d))
#define modd 1000000007
#define MAX 300005
#define SPEEDUP ios_base::sync_with_stdio(false);
using namespace std;
typedef long long int ll;
int minn,maxx;
void dfs(int node,vec(int) graph[],vec(bool) &visited){
	minn = min(node,minn);
	maxx= max(node,maxx);
	visited[node] = true;
	for(auto i: graph[node]){
		if(!visited[i]){
			dfs(i,graph,visited);
		}
	}
}

int main()
{
	ll n,m;
	cin>>n>>m;
	vector<int> graph[n+1];
	vector<bool> visited(n+1,false);
	while(m--){
		int u,v;
		cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
		visited[u]=false;
		visited[v]=false;
	}
	int ans =0;
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			minn = INT_MAX;
			maxx = INT_MIN;
			dfs(i,graph,visited);
			for(int j = minn ; j<= maxx;j++){
				if(!visited[j]){
					ans++;
					dfs(j,graph,visited);
				}
			}
		}
	}
	cout<<ans;
}
