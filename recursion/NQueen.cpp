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

class NQueens
{
    vec(vec(int)) ans;

public:
    void solve(int n)
    {
        initialize(n);
        if (startVisit(0, n))
            print(n);
        else
        {
            cout << "fail";
        }
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
    bool isSafe(int row, int col, int n)
    {
        int i, j;
        for (i = 0; i < col; i++)
        {
            if (ans[row][i])
            {
                return false;
            }
        }
        for (i = 0; i < row; i++)
        {
            if (ans[i][col])
            {
                return false;
            }
        }

        for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (ans[i][j])
            {
                return false;
            }
        }

        for (i = row, j = col; j < n && i >= 0; i--, j++)
        {
            if (ans[i][j])
            {
                return false;
            }
        }

        return true;
    }

private:
    bool startVisit(int row, int n)
    {

        if (row >= n)
        {
            return true;
        }
        for (int i = 0; i < n; i++)
        {
            if (isSafe(row, i, n))
            {
                ans[row][i] = 1;
                if (startVisit(row + 1, n))
                {
                    return true;
                }
                ans[row][i] = 0;
            }
        }
        return false;
    }
};

int main()
{
    tc
    {
        int n;
        cin >> n;
        NQueens().solve(n);
    }
    return 0;
}