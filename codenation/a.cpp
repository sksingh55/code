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

ll solve(string str, string pat)
{
    ll n1 = str.length();
    ll n2 = pat.length();
    if (n1 < n2)
    {
        return -1;
    }
    ll freq1[256] = {0};
    ll freq2[256] = {0};

    for (ll i = 0; i < n2; i++)
        freq1[pat[i]]++;

    ll start = 0, begin = -1, ans = INT_MAX;

    ll count = 0;
    for (ll j = 0; j < n1; j++)
    {
        freq2[str[j]]++;
        if (freq1[str[j]] != 0 && freq2[str[j]] <= freq1[str[j]])
            count++;
        if (count == n2)
        {
            while (freq2[str[start]] > freq1[str[start]] || freq1[str[start]] == 0)
            {
                if (freq2[str[start]] > freq1[str[start]])
                    freq2[str[start]]--;
                start++;
            }
            ll lw = j - start + 1;
            if (ans > lw)
            {
                ans = lw;
                begin = start;
            }
        }
    }
    if (begin == -1)
    {
        return -1;
    }
    return ans;
}
int main()
{
    ll n ;
    cin>>n;
    string s;
    cin>>s;
    ll count[256]={0};
    for(ll i =0;i<n;i++){
        count[s[i]]++;
    }
    string k;
    for(ll i='0';i<='9';i++){
        if(count[i]%2!=0){
            k+=i;
        }
    }
    if(k.length()==0){
        cout<<-1;
    }
    else{
        cout<<solve(s,k)-1;
    }
    return 0;
}


