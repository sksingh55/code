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



int main()
{
    
    tc
    {
      ll n,k;
      cin>>n>>k;
      ll a[n+1];
      f(i,0,n)
      cin>>a[i];
      sort(a,a+n);
      ll diff[n+1]={0};
      f(i,0,n-1)
      {
        if(a[i]>k)
        {
          a[i]=k-a[i];
        }
      }

      ll count=0;
      f(i,0,n-1)
      {
        f(j,i+1,n-1)
        {
          if(a[i]==1)
            break;

          if(a[j]==1)
            continue;
          else
          {
            ll red=a[j]-1;
            ll red2=a[i]-1;
            ll m=min(red,red2);
            a[i]=a[i]-m;
            a[j]=a[i]-m;
          }

        }
        if(a[i]==1)
          count++;
      }
      ll sum=0;
      f(i,0,n-1)
      {
        sum+=a[i];
      }
      if(sum%2==0)
      {
        cout<<()
      }

    }
    
}