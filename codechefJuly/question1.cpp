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
 tc{
 	int n;
 	cin>>n;
 	ll a[n+1];
 	double sum=0;
 	f(i,0,n){
 		cin>>a[i];
 		sum+=a[i];
 	}
 	double avr = sum/n;
 	ll ans=-1;
 	f(i,0,n){
 		if(a[i]==avr){
 			ans=i+1;
 			break;
 		}
 	}
 	if(ans==-1)
 		cout<<"Impossible\n";
 	else
 		cout<<ans<<"\n";

 }  
}