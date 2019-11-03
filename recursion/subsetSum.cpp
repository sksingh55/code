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
    void solve(int n, vector<int> v , int target)
    {
        vec(int) ans;
        startVisit(0, n, v,ans,0,target);
    }

private:
    void print(vec(int) ans)
    {
        f(i, 0, ans.size())
        {
           cout<<ans[i]<<" ";
        }
        endl;
    }

private:
    void startVisit(int i, int n,vec(int) v,vec(int) ans, int sum,int target)
    {
        if(sum == target){
            print(ans);
            return;
        }
        if(i>=n){
            return;
        }
        ans.pb(v[i]);
        startVisit(i+1,n,v,ans,(sum+v[i]),target);
        ans.pop_back();
        startVisit(i+1,n,v,ans,(sum),target);
        return;
    }
};

int main()
{
    tc
    {
        int n, x ,target;
        cin >> n >> target;
        vector<int> v;
        f(i, 0, n)
        {
            cin >> x;
            v.pb(x);
        }
        SubsetSum().solve(n, v, target);
    }
    return 0;
}