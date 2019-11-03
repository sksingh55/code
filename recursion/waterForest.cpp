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

class Solver
{
private:
    static ll pow(ll x, ll y, ll p)
    {
        ll res = 1;
        x = x % p;
        while (y > 0)
        {
            if (y & 1)
                res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res % p;
    }

ll c = 0 , n;
string a[1005];
public:
    void input()
    {
       cin>>n;
       f(i,0,n){
           cin>>a[i];
       }
       ll ans =0;
       f(i,0,n){
           f(j,0,n){
               if(a[i][j]=='T'){
                c = 0;
                solve(i,j);
                ans = max(ans , c);  
               }
           }
       }
       cout<<ans;

    }
private:
    void solve(int i,int j)
    {
        if(i<0 || j<0 || i>=n||j>=n) {
            return ;
        }  
        if(a[i][j]=='T'){
            c++;
            a[i][j]='W';
            solve(i-1,j);
            solve(i,j+1);
            solve(i,j-1);
            solve(i+1,j);
        }
    }
};

int main()
{
    SPEEDUP
    Solver().input();
}