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

int calcMod(string num, int a) 
{ 
    int res = 0; 
  
    for (int i = 0; i < num.length(); i++) 
         res = (res*10 + (int)num[i] - '0') %a; 
  
    return res; 
} 



int main(){
	tc{
		int n;
		string k;
		cin>>n;
		cin>>k;
		int rem = calcMod(k,n);
		if(rem > n-rem)
		{
			cout<<2*(n-rem);
		}
		else if(rem < n-rem){
			cout<<2*rem;
		}
		else
			cout<<2*rem-1;
		cout<<"\n";

	}
}