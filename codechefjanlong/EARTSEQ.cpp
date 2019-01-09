
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
#define mod 1000000000 
typedef long long int ll;

bool prime[1000000]; 
vector<ll> primes;
void SieveOfEratosthenes() 
{ 
    ll n=1000000;
    memset(prime, true, sizeof(prime)); 
  
    for (ll p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
           for (ll i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for(ll i=2;i<=1000000;i++)
        if(prime[i]==true)
            primes.pb(i);
} 

int main() {
    SieveOfEratosthenes();
    tc
    {
        ll n;
        cin>>n;
        vec(ll) ans;
        if(n==3)
        {
            cout<<"6 10 15\n";
            continue;
        }
        if(n==4)
        {
            cout<<"374 595 1365 858\n";
            continue;
        }
        
        ll flag=1;
        ll flag2=0;
        ll left=5;
        ll right=4;
        cout<<6<<" ";
        cout<<15<<" ";
        for(int i=0;i<n-3;i++)
        {
            if(flag==2)
            {
                flag=0;
                if(left==5)
                    left=7;
                else
                    left=5;
            }
            if(flag2==2)
            {
                flag2=0;
                right++;
            }
            flag++;
            flag2++;

            cout<<left*primes[right]<<" ";
        }
        if(flag==1)
            cout<<left*2<<"\n";
        else
            cout<<primes[right]*2<<"\n";
    
        
    }
    return 0;
}