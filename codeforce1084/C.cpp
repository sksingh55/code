#include <bits/stdc++.h>
#define vec(a) vector<a>
#define vecp(a,b) vector < pair< a, b > > 
#define pb push_back
#define minpq priority_queue <long long int, vector<long long int>, greater<long long int> > pq;
#define f(i,a,b) for(long long int i=a;i<b;i++)
#define fr(i,a,b) for(long long int i=a;i>=b;i--)
#define tc long long int t; cin>>t; while(t--)
#define mp make_pair
#define mapp(a,b) map<a, b>
#define umapp(a,b) unordered_map<a ,b> 
#define mem(d,val) memset(d,val,sizeof(d))
using namespace std;
#define mod 1000000007 
typedef long long int ll;

int main() {

  string s;
  cin >> s;
  int n = s.size();
  ll DP[n + 2]={0};
  DP[0] = 1;
  DP[1] = 1;
  int la = 1;
  for (int i = 2; i < n + 2; i++) {
    DP[i] = DP[i - 1];
    if (s[i - 2] == 'a') DP[i] += DP[la - 1];
    if (s[i - 2] == 'b') la = i;
    DP[i] %= mod;
  }
  cout << DP[n + 1] - 1;
  return 0;
}
      