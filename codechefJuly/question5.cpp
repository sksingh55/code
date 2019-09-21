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
 
bool prime[10000007]; 

void SieveOfEratosthenes() 
{ 
    int n =10000007;
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    {  
        if (prime[p] == true) 
        {  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 

} 



int main()
{
    SieveOfEratosthenes();
   tc{
    int rem;
    string response;
    cout<<"1 997\n";
    cin>>rem;
    vector<int> s;
    if(rem > 997*997)
    {
        for(int k=0;k<1000;k++)
        {
            int d = 997*997+rem;
            if(prime[d])  
            {
                s.pb(d);
            }

        }
    }
    else if(rem==0){
        cout<<"2 997\n";
        cin>>response;
    }
    else{
        for(int i=2;i<997*997;i++)
        {
            if(prime[i]){
                if(( 997*997 - rem )%i == 0){
                    s.pb(i);
                }
            }
        }
    }

    if(s.size()==1)
    {
        cout<<"2 "<<s[0]<<"\n";
        cin>>response;
    }
    else
    {
        cout<<"1 "<<s[0]<<"\n";
        cin>>rem;
        if(rem==0)
            cout<<"2 "<<s[0]<<"\n";
        else
            cout<<"2 "<<s[1]<<"\n";
        cin>>response;

        
    }
    if(response == "Yes")
    {
        continue;
    }
    else
        break;
   }
}