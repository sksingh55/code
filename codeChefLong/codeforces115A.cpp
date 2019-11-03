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
vec(int) graph[20005]; 
bool visited[20005];
int ans=0;
void findMaxDepth(int i,int count){
   // cout<<i<<'\n';
   visited[i]=true;
   if(graph[i].size()==0){
      ans = max(ans,count);
   }
   for(int j=0;j<graph[i].size();j++){
      if(!visited[graph[i][j]]){
         findMaxDepth(graph[i][j],count+1);
      }
   }
}
int main()
{
   int n;
   cin>>n;
   int k[n+1];
   mem(visited,false);
   f(i,1,n+1){
      cin>>k[i];
      if(k[i]!=-1){
         graph[k[i]].pb(i);
      }
   }
   for(int i=1;i<=n;i++){
      if(k[i]==-1){
         findMaxDepth(i,1);
      }
   }
   cout<<ans;
}