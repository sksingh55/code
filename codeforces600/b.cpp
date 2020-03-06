#include <bits/stdc++.h>
#define vec(a) vector<a>
#define vecp(a, b) vector<pair<a, b>>
#define pb push_back
#define minpq priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
#define f(i, a, b) for (long long int i = a; i < b; i++)
#define fr(i, a, b) for (long long int i = a; i >= b; i--)
#define tc             \
	long long int t;   \
	scanf("%lld", &t); \
	while (t--)
#define mp make_pair
#define mapp(a, b) map<a, b>
#define umapp(a, b) unordered_map<a, b>
#define mem(d, val) memset(d, val, sizeof(d))
#define modd 1000000007
#define MAX 300005
#define SPEEDUP ios_base::sync_with_stdio(false);
using namespace std;
typedef long long int ll;

int main()
{
	int n;
	cin>>n;
	int a[n+1];
	f(i,0,n){
		cin>>a[i];
	}
    ll sum =0;
	int current = 0;
	vector<int> ans;
	map<int,int> count;
	for(int i=0;i<n;i++){
        sum += a[i];
		if(a[i]>0){
			if(count[a[i]]==1){
				if(current == 0){
					ans.pb(count.size()*2);
					count.clear();
					count[a[i]]++;
					current++;
				}
				else{
					cout<<-1;
					return 0;
				}
			}
			else{
				count[a[i]]++;
				current++;
			}
		}
		else{
			if(count[-a[i]]==1){
				current--;
			}
			else{
				cout<<-1;
				return 0;
			}
		}
		if(current==0 && sum == 0){
			ans.pb(count.size()*2);
			count.clear();
		}
	}
	if(current!=0 || sum!=0){
		cout<<-1;
		return 0;
	}

	cout<<ans.size()<<"\n";
	for(auto i: ans){
		cout<<i<<" ";
	}
}
