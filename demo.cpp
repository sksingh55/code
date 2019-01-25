 
#include <bits/stdc++.h>
 
using namespace std; 
 
#define PI acos(-1)
#define mod 1000000007
#define ll long long
#define nitro std::ios_base::sync_with_stdio (false); cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define vi vector < int >
#define mod 1000000007
#define md 998244353
#define rep(i,a,b) for(int i=a;i<b;i++)
#define FF first
#define SS second
#define all(a) (a).begin(),(a).end()
 
ll power(ll x,ll y,ll p){
    ll res = 1;   
    x = x % p;    
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1; 
        x = (x*x) % p; 
    }
    return res;
}

ll gcd(ll A,ll b){if(b==0) return A; else return gcd(b,A%b);}

int main () {
    nitro;
 
    #ifdef DBG
        freopen("in","r",stdin);
    #endif
    int n; cin >> n;
    string s; cin >> s;
    
    int cnt0=0,cnt1=0,cnt2 = 0;
    rep(i,0,n){
        if(s[i] == '0') cnt0++;
        else if(s[i] == '1') cnt1++;
        else cnt2++; 
    }
    
    cnt0 = n/3 - cnt0;
    cnt1 = n/3 - cnt1;
    cnt2 = n/3 - cnt2;
    
    rep(i,0,n){
        if(s[i] == '1'){
            if(cnt1 < 0 and cnt0 > 0){
                cnt0--;
                cnt1++;
                s[i] = '0';
            }
        }
        else if(s[i] == '2'){
            if(cnt2 < 0 and cnt0 > 0){
                cnt0--;
                cnt2++;
                s[i] = '0';
            }
            else if(cnt2 < 0 and cnt1 > 0){
                cnt1--; cnt2++;
                s[i] = '1';
            }
        }
    }
    
    for(int i=n-1;i>=0;i--){
        if(s[i] == '0'){
            if(cnt0 < 0 and cnt2 > 0){
                cnt2--;
                cnt0++;
                s[i] = '2';
            }
            else if(cnt0 < 0 and cnt1 > 0){
                cnt1--;
                cnt0++;
                s[i] = '1';
            }
        }
        else if(s[i] == '1'){
            if(cnt1 < 0 and cnt2 > 0){
                cnt2--;
                cnt1++;
                s[i] = '2';
            }
        }
    }
    cout << s << endl;
    
    
    
    
    
   	return 0;
}  