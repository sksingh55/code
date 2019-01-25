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

ll a,b,n;

ll gcd(ll a, ll b){
        if(a==0)
            return b;
        return gcd(b%a, a);
    }



void find(ll t, ll x, ll y, ll z){
        a=1; b=2*n+1;
        /*
            1 AAB
            2 ABA
            3 ABB
            4 BAB
        */
        if(t==1){ //AAB
            if(y==x-1 && z==x-2){
                a = 2*n+1-(y-1);
            }
            if(y==x-1 && z==x){
                a = (y+1);
            }
            if(y==x+1 && z==x){
                a = (y-1);
            }
            if(y==x+1 && z==x+2){
                a = 2*n+1-(y+1);
            }
        }

        if(t==2){ //ABA
            if(y==x-1 && z==x-2){
                a = 2*n+1 - 2*y;
            }
            if(y==x-1 && z==x){
                a=0; b=1;
            }
            if(y==x+1 && z==x){
                a=0; b=1;
            }
            if(y==x+1 && z==x+2){
                a = 2*n+1 - 2*y;
            }
        }

        if(t==3){ //ABB
            if(y==x-1 && z==x-2){
                a = 2*n+1-(y+1);
            }
            if(y==x-1 && z==x){
                a = (y+1);
            }
            if(y==x+1 && z==x){
                a = (y-1);
            }
            if(y==x+1 && z==x+2){
                a = 2*n+1-(y-1);
            }
        }


        if(t==4){ //BAB
            if(y==x-1 && z==x-2){
                a = 2*n+1 - 2*y;
            }
            if(y==x-1 && z==x){
                a=0; b=1;
            }
            if(y==x+1 && z==x){
                a=0; b=1;
            }
            if(y==x+1 && z==x+2){
                a = 2*n+1 - 2*y;
            }
        }

    }

int main()
{
    tc
    {
        ll t,x,y,z;
        cin>>n>>t>>x>>y>>z;
        b = 2*n+1;
        a = 0;  
        find(t, x, y, z);

        ll div = gcd(a, b);

        cout<<(a/div)<<" "<<(b/div)<<"\n";
    }

        
}

