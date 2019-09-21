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
int main(){
	tc{
		vector<int> v;
		int q;
		cin>>q;
		bool mark[1000005];
		mem(mark,false);
		int odd=0,even=0;
		while(q--){
			int x;
			cin>>x;
			if(v.size()>100000 || mark[x]){
				cout<<even << " "<<odd<<"\n";
				continue;
			}
			int parity= __builtin_popcount (x);
			ll tempEven=0,tempOdd=0;
			if(parity % 2 == 0){
				tempEven = even;
				tempOdd = odd;
				even = even+tempEven+1;
				odd = odd+tempOdd;
			}
			else{
				tempOdd = even;
				tempEven = odd;
				even = even+tempEven;
				odd = odd+tempOdd+1;
			}


			v.pb(x);
			int k = v.size()-1;
			mark[x]=true;
			f(i,0,k){
				if(v[i]!=x && mark[v[i]^x]==false){
					v.pb(v[i]^x);
					mark[v[i]^x]=true;
				}
			}
			
			cout<<even<<" "<<odd<<"\n";

		}
	}
}