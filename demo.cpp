#include <bits/stdc++.h>
#define vec(a) vector<a>
#define vecp(a, b) vector<pair<a, b>>
#define pb push_back
#define minpq priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
#define f(i, a, b) for (long long int i = a; i < b; i++)
#define fr(i, a, b) for (long long int i = a; i >= b; i--)
#define tc           \
	long long int t; \
	scanf("%lld",&t);        \
	while (t--)
#define mp make_pair
#define mapp(a, b) map<a, b>
#define umapp(a, b) unordered_map<a, b>
#define mem(d, val) memset(d, val, sizeof(d))
#define modd 1000000007
#define MAX 300005
#define SPEEDUP ios_base::sync_with_stdio(false); 
using namespace std;
typedef  long long int ll;

int main()
{
	SPEEDUP
	tc{
		ll n;
		scanf("%lld",&n);
		double arr[n+5];
		f(i,1,n+1){
			scanf("%lf",&arr[i]);
		}
		double x;
		scanf("%lf",&x);
		ll A[n+5]={0};
		ll B[n+5]={0};
		f(i,1,n+1){
			A[i] = A[i-1]+ceil(arr[i]/x);
		}
		for(int i=n;i>0;i--){
			B[i] = B[i+1]+ceil(arr[i]);
		}
		int i;
		for(i=1;i<n-1;i++){
			if(A[i]<B[i+2]){
				continue;
			}
			else if(A[i]==B[i+2]){
				if(i<(n-i-1)){
					break;
				}
				else{
					i++;
					break;
				}
			}
			else{
				break;
			}
		}
		cout<<i<<" "<<n-i<<"\n";
	}
}
