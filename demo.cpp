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

vector<vector<int>> a;

bool check(int i,int j,int n,int m){
	if(i>=0 && i<n && j>=0 && j<m && a[i][j]==1){
		return true;
	}
	return false;
}
void initialize(int n,int m){
	for(int i=0;i<n;i++){
		vector<int>temp;
		for(int j=0;j<m;j++){
			temp.push_back(1);
		}
		a.push_back(temp);
	}
}
void print(int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			// a[i][j]=1;
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}
void dfs(int n,int m,int i,int j){
	// print(n,m);
	if(i>=n||j>=m){
		return;
	}
	if(a[i][j]==0){
		return;
	}
	a[i][j]=0;
	if(check(i+1,j,n,m)){
		dfs(n,m,i+1,j);
	}
	if(check(i,j-1,n,m)){
		dfs(n,m,i,j-1);
	}
	if(check(i,j+1,n,m)){
		dfs(n,m,i,j+1);
	}
	if(check(i-1,j,n,m)){
		dfs(n,m,i-1,j);
	}
	
}
int main()
{
	int n,m;
	cin>>n>>m;
	initialize(n,m);
	string s[n+1];
	for(int i=0;i<n;i++){
		cin>>s[i];
		for(int j=0;j<s[i].length();j++){
			if(s[i][j]=='.'){
				a[i][j]=1;
			}
			else{
				a[i][j]=0;
			}
		}
	}

	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0||j==0||j==m-1||i==n-1){
				if(s[i][j]=='.'){
					dfs(n,m,i,j);
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ans += a[i][j];
		}
	}
	cout<<ans;
}




sdcscvds
csdcs
csdcds
csdcd
cdsdc
xsa
cdscds
csdc
csdcsd
xsax
