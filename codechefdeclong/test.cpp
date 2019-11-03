#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define sz(x) ((int)x.size())
#define fast_io ios::sync_with_stdio(false); cin.tie(false)
#define fi first
#define se second
#define y1 polyn
#define stop system("pause")
#define INF 2147483647
#define LLINF 9223372036854775807
using namespace std;
typedef long long ll;

ll n, b[200000], _l, _r;

vector <ll> l;
vector <ll> r;

int main()
{
    cin >> n;

    for (int i = 0; i < n / 2; ++i) {
         cin >> b[i];
    }

    l.push_back(0);
    r.push_back(b[0]);

    for (int i = 1; i < n / 2; ++i) {
         _l = l[sz(l) - 1];
         _r = b[i] - l[sz(l) - 1];
//         while (true) {
//                if (_r <= r[sz(r) - 1])
//                    break;
//                ++_l;
//                --_r;
//         }
         if (_r > r[sz(r) - 1]) {
             _r = r[sz(r) - 1];
             _l += abs(b[i] - l[sz(l) - 1] - _r);
         }
         l.push_back (_l);
         r.push_back (_r);
    }

    reverse (all(r));

    for (int i = 0; i < sz(l); ++i) cout << l[i] << " ";

    for (int j = 0; j < sz(r); ++j) cout << r[j] << " ";



    return 0;
}