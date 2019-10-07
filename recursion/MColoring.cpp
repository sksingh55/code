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
#define endl cout << "\n"
#define SPEEDUP ios_base::sync_with_stdio(false);
using namespace std;
typedef long long int ll;

class SubsetSum
{
    vec(vec(int)) ans;

public:
    void solve(int n, int m, vector<int> graph[])
    {
        vec(int) color;
        color = initialize(color,n);
        cout<<(startVisit(1, m, n, color, graph));
        endl;
    }

private:
    vec(int) initialize(vec(int) visited, int n)
    {
        f(i, 0, n+2)
        {
            visited.pb(0);
        }
        return visited;
    }

private:
    void print(vec(int) ans)
    {
        f(i,0,ans.size())
        cout << ans[i];
        endl;
    }
private:
    bool isSafe(int node,int c,vec(int) color, vec(int)graph[]){
        for(int i=0;i<graph[node].size();i++){
            if(color[graph[node][i]] == c){
                return false;
            }
        }
        return true;
    }
private:
    bool startVisit(int node, int m, int n, vec(int) color, vec(int) graph[])
    {
        if(node>n+1){
            return false;
        }
        if (node == n+1)
        {
            return true;
        }
        for(int i=1;i<=m;i++){
            if(isSafe(node,i,color,graph)){
                color[node]=i;
                if(startVisit(node+1,m,n,color,graph)){
                    // print(color);
                    // cout<<node<<"\n";
                    return true;
                }
                color[node]=0;
            }
        }
        return false;
    }
};

int main()
{
    tc
    {
        int n, m, e, x, y;
        cin >> n >> m >> e;
        vector<int> graph[n+10];
        f(i, 0, e)
        {
            cin >> x >> y;
            graph[x].pb(y);
            graph[y].pb(x);
        }
        SubsetSum().solve(n, m, graph);
    }
    return 0;
}