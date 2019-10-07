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

class KnightTour
{
    int ans[8][8] = {{0}};
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

public:
    void solve()
    {
        initialize();
        ans[0][0] = 0;
        startVisit(0, 0, 1);
        print();
    }

private:
    void initialize()
    {
        f(i, 0, 8)
        {
            f(j, 0, 8)
            {
                ans[i][j] = -1;
            }
        }
    }

private:
    void print()
    {
        f(i, 0, 8)
        {
            f(j, 0, 8)
            {
                cout << ans[i][j] << " ";
            }
            endl;
        }
        endl;
    }

private:
    bool isSafe(int i, int j)
    {
        if (i < 0 || i > 7 || j < 0 || j > 7 || ans[i][j] != -1)
        {
            return false;
        }
        return true;
    }

private:
    bool startVisit(int i, int j, int count)
    {

        if (count == 64)
        {
            return true;
        }
        f(k, 0, 8)
        {
            if (isSafe(i + xMove[k], j + yMove[k]))
            {
                ans[i + xMove[k]][j + yMove[k]] = count;
                if (startVisit(i + xMove[k], j + yMove[k], count + 1))
                {
                    return true;
                }
                else
                {
                    ans[i + xMove[k]][j + yMove[k]] = -1;
                }
            }
        }
        return false;
    }
};

int main()
{
    SPEEDUP
    KnightTour().solve();
}