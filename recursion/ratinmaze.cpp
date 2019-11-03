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

class RatInMaze
{
    vec(vec(int)) ans;

public:
    void solve(int n, vec(vec(int)) v)
    {
        initialize(n);
        startVisit(0, 0, n, v);
        print(n);
    }

private:
    void initialize(int n)
    {
        f(i, 0, n)
        {
            vec(int) temp;
            f(j, 0, n)
            {
                temp.pb(0);
            }
            ans.pb(temp);
        }
    }

private:
    void print(int n)
    {
        f(i, 0, n)
        {
            f(j, 0, n)
            {
                cout << ans[i][j] << " ";
            }
            endl;
        }
    }

private:
    bool isSafe(int i, int j, vec(vec(int)) v, int n)
    {
        if (i < 0 || i >= n || j < 0 || j >= n || v[i][j] == 0)
        {
            return false;
        }
        return true;
    }

private:
    bool startVisit(int i, int j, int n, vec(vec(int)) v)
    {

        if (i == n - 1 && j == n - 1)
        {
            ans[i][j] = 1;
            return true;
        }
        if (isSafe(i, j, v, n))
        {
            ans[i][j] = 1;
            if (startVisit(i + 1, j, n, v))
            {
                return true;
            }
            if (startVisit(i, j + 1, n, v))
            {
                return true;
            }
            ans[i][j] = 0;
        }

        return false;
    }
};

int main()
{
    vector<vec(int)> maze = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {0, 1, 0, 0},
                             {1, 1, 1, 1}};

    RatInMaze().solve(4, maze);
    return 0;
}