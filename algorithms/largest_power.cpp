//largest power of number with is greater than n
#include <bits/stdc++.h>
#define vec vector< long long int>
#define vecp vector < pair< long long int ,long long int> > 
#define pb push_back
#define f(i,a,b) for(long long int i=a;i<b;i++)
#define tc long long int t; cin>>t; while(t--)
#define mp make_pair
using namespace std;
typedef long long int ll;
void SieveOfEratosthenes(int n,bool prime[])
{
    memset(prime, true, n);
    for (int p=2; p*p<=n; p++)
    {
       if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
 }

ll xorPairCount(ll arr[], ll n, ll x)//xor pair count with value x
{
    int result = 0; 
    unordered_map<ll, ll> m;
 
    for (ll i=0; i<n ; i++)
    {
        ll curr_xor =  x^arr[i];
        if (m.find(curr_xor) != m.end())
            result += m[curr_xor];
        m[arr[i]]++;
    }
    return result;
}
ll gcd(ll a, ll b)
{
    if(a==0)
        return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b)
{
    return (a*b)/gcd(a, b);
}

ll largest_power(ll n)
{
    n = n|(n>>1);
    n = n|(n>>2);
    n = n|(n>>4);
    n = n|(n>>8);
    return ((n+1)>>1);
}


int main()
{

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n;
    cin >>n;
    cout<<largest_power(n);
}
  
