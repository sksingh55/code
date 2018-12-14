//longest common subsequence 
#include <bits/stdc++.h>
#define vec vector< long long int>
#define vecp vector < pair<long long int ,long long int> > 
#define pb push_back
#define f(i,a,b) for(long long int i=a;i<b;i++)
#define tc long long int t; cin>>t; while(t--)
#define mp make_pair
using namespace std;
typedef  long long int ll;

ll max(ll a, ll b)
{
	if(a>b)
		return a;
	else
		return b;
}



int main()
{
	string a,b;
	cin>>a>>b;
	ll n=a.length();
	ll m=b.length();
	ll dp[n+2][m+2];
	memset(dp,0,sizeof(dp));
    f(i,1,n+1)
    {
    	f(j,1,m+1)
    	{
            if(a[i-1]==b[j-1])
            {
            	dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            	dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    	}
    }

    string ans;
    ll i,j;
    i=n;j=m;
 	 while(i!=0&&j!=0)
 	 {
 	 	if(max(dp[i][j-1],dp[i-1][j])==dp[i][j])
 	 	{
 	 		if(dp[i][j]==dp[i-1][j])
 	 			i--;
 	 		else
 	 			j--;
 	 	}
 	 	else
 	 	{
 	 		ans=a[i-1]+ans;
 	 		i--;j--;
 	 	}

 	 }
 	 cout<<ans;

}
    
 
