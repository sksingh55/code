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
 
bool prime[10000005]; 

void SieveOfEratosthenes() 
{ 
	ll n = 10000005;
    memset(prime, true, sizeof(prime)); 
  
    for (ll p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (ll i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    }
} 



int main()
{
	SieveOfEratosthenes();
   tc{
    ll rem ;
    cout<<"1 997";
    cin>>rem;
    for(int i=2;i<10000;i++)
    {
    	double k= (997*997-rem)/i;
    	if(k-int(k)==0 && prime[int(k)]){
    		cout<<"2 "<<k<<"\n";
    		break;	
    	}
    }
   }
} 