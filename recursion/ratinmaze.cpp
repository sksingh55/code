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
int n=4;
int a[4][4];
int visited[4][4];
int ans=0;
//recursive approach
void solve(int n,int i,int j)
{
	cout<<i<<" "<<j<<"\n";
	if(i>=n||j>=n)
		return;
	if(i==n-1&&j==n-1)
		{
			ans++;
		}
		if(a[i][j]==0)
			return;
	visited[i][j]=1;
	solve(n,i+1,j);
	solve(n,i,j+1);
	
	return;
}
// DP approach
void solvedp()
{
	a[0][0]=1;
	f(i,0,n)
	{
		f(j,0,n)
		{
			if(a[i][j]==-1)
				{continue;}
			if(a[i+1][j]>=0&&i+1<n)
				a[i+1][j]+=a[i][j];
			if(a[i][j+1]>=0&&j+1<n)
				a[i][j+1]+=a[i][j];
			
			
		}
		

	
	}

	cout<<a[n-1][n-1];
}






int main()
{
	f(i,0,n)
	{
		f(j,0,n)
		{
			cin>>a[i][j];
		}
	}
	mem(visited,0);
	visited[0][0]=1;
	//solve(n,0,0);
	cout<<ans<<"\n";solvedp();



}