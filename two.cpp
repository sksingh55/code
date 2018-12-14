#include <bits/stdc++.h>
using namespace std;
int main()
{
	//Taking input
	int n , k;
	cin>>n>>k;
	int a[n+2];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	// forward array gonna store max value for each step
	int forward[n+2] = {0};
	int backward[n+2] = {0};
	forward[k]=0;
	if(k+1 < n)
		forward[k+1] = a[k+1];
	for(int i=k+2;i<=n;i++)
		forward[i] = a[i] + max(forward[i-1],forward[i-2]);
	//calculating for backward movement 
	backward[1]=a[1];
	if(n>=2)
		backward[2]=a[2]+backward[1];
	
	for(int i=3;i<=n;i++)
		backward[i] = a[i] + max(backward[i-2], backward[i-1]);
	
	int ans = INT_MIN;
	for(int i = k; i<=n ;i++)
		ans = max(ans , (forward[i]+backward[i]-a[i]));
	cout<<ans;


}
