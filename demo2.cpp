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

ll nC2(ll k){
    if(k==1 ){
        return 1;
    }
    return (k*(k-1));
}
int main()
{
    SPEEDUP
    ll n;
    cin >> n;
    ll a[n + 5];
    vecp(ll, ll) freq;
    f(i, 0, n)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n;)
    {
        ll k = a[i];
        ll count = 0;
        while (i < n && k == a[i])
        {
            count++;
            i++;
        }
        freq.pb(mp(k, count));
    }

    ll ans = 0;
    for (int i = 0; i < freq.size(); i++)
    {
        for (int j = i + 1; j < freq.size(); j++)
        {
            ll k = freq[j].first + 2 * freq[i].first;
            
            if (freq[i].second >= 2)
            {
                if (k % freq[i].first != 0 && k % freq[j].first == 0)
                {
                    ans += nC2(freq[i].second) * (freq[j].second) * 3;
                }
            }
            k = 2 * freq[j].first + freq[i].first;
            
            if (freq[j].second >= 2)
            {
                if (k % freq[j].first != 0 && k % freq[i].first == 0)
                {
                    // cout<<j<<" "<<nC2(freq[j].second);
                    ans += (freq[i].second) * nC2(freq[j].second) * 3;
                }
            }
        }
        for (int j = i + 1; j < freq.size(); j++)
        {
            for (int k = j + 1; k < freq.size(); k++)
            {
                ll p = freq[i].first + freq[j].first + freq[k].first;
                if (p % freq[i].first == 0 && p % freq[j].first != 0 && p % freq[k].first != 0)
                {
                    ans += (freq[i].second * freq[j].second * freq[k].second * 6);
                }
                else if (p % freq[i].first != 0 && p % freq[j].first == 0 && p % freq[k].first != 0)
                {
                    ans += (freq[i].second * freq[j].second * freq[k].second * 6);
                }
                else if (p % freq[i].first != 0 && p % freq[j].first != 0 && p % freq[k].first == 0)
                {
                    ans += (freq[i].second * freq[j].second * freq[k].second * 6);
                }
            }
        }
    }
    cout << ans<<"\n";
}