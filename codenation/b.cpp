#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define ll long long int

using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        priority_queue<ll> maxval;
        priority_queue<int, vector<int>, greater<int>> minval;
        ll n, k;
        cin >> n >> k;
        vector<ll> v;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v.push_back(x);
            minval.push(x);
            maxval.push(x);
        }
        sort(v.begin(), v.end());
        vector<ll> min2;
        ll ans = INT_MAX;
        while (1)
        {
            ll p = minval.top();
            priority_queue<ll> temp=maxval;
            while (1)
            {
                ll z = temp.top();
                ans = min(ans,abs(z-p));
                if(z%k==0){
                    temp.pop();
                    temp.push(z/k);
                }
                else{
                    break;
                }
            }
            if(p*k<)
            
        }

        

        cout << ans << "\n";
    }
}
