#include <bits/stdc++.h>
#define vec(a) vector<a>
#define vecp(a, b) vector<pair<a, b>>
#define pb push_back
#define minpq priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
#define f(i, a, b) for (long long int i = a; i < b; i++)
#define fr(i, a, b) for (long long int i = a; i >= b; i--)
#define tc           \
	long long int t; \
	cin >> t;        \
	while (t--)
#define mp make_pair
#define mapp(a, b) map<a, b>
#define umapp(a, b) unordered_map<a, b>
#define mem(d, val) memset(d, val, sizeof(d))
#define modd 1000000007
#define MAX 300005
using namespace std;
typedef  long int ll;

int main()
{
	ll n;
    cin>>n;
    string s;
    cin>>s;
    int feq[256]={0};
    f(i,0,s.length()){
        feq[s[i]]++;
    }
    int one = min(feq['o'],min(feq['n'],feq['e']));
    feq['o'] -= one;
    feq['n'] -= one;
    feq['e'] -= one;

    int zero = min(feq['z'],min(feq['e'],min(feq['r'],feq['o'])));
    feq['z'] -= zero;
    feq['e'] -= zero;
    feq['r'] -= zero;
    feq['o'] -= zero;

    f(i,0,one){
        cout<<"1 ";
    }
    f(i,0,zero){
        cout<<"0 ";
    }
    
}
