//Strongly connected graph kosaraju's algorithm

#include <bits/stdc++.h>
#define vec vector< long long int>
#define vecp vector < pair<long long int ,long long int> > 
#define pb push_back
#define f(i,a,b) for(long long int i=a;i<b;i++)
#define tc long long int t; cin>>t; while(t--)
#define mp make_pair
using namespace std;
typedef  long long int ll;
stack <ll > s;
void dfs(vec graph[],bool visited[], ll node)
{
	visited[node]=true;
	f(i,0,graph[node].size())
	{
		if(visited[graph[node][i]]==false)
			dfs(graph,visited,graph[node][i]);
	}
	s.push(node);
}
void dfsrev(vec graph[],bool visited[], ll node)
{
	visited[node]=true;
	cout<<node<<"->";
	f(i,0,graph[node].size())
	{
		if(visited[graph[node][i]]==false)
			dfsrev(graph,visited,graph[node][i]);
	}
}


int main()
{
	int n,m;//number of vertices and edges
	cin>>n>>m;
	vec graph[n+1];
	vec rgraph[n+1];
	f(i,0,m)
	{
		ll x,y;
		cin>>x>>y;
		graph[x].pb(y);
		rgraph[y].pb(x);
	}

	bool visited[n+1];
	memset(visited,false, sizeof(visited));

    f(i,1,n+1)
    {
    	if(visited[i]==false)
    		{dfs(graph,visited,i);}
    }
    memset(visited,false, sizeof(visited));
    while(!s.empty())
    {
    	if(visited[s.top()]==false)
    	{dfsrev(rgraph,visited,s.top());s.pop();cout<<"\n";}
    	else
    		s.pop();
    }


    
    
}