#include<bits/stdc++.h> 
using namespace std; 
  
int X[105],Y[105],Z[105]; 
  
int dp[105][105][105]; 
  
/* Returns length of LCS for X[0..m-1], Y[0..n-1] 
and Z[0..o-1] */
int lcsOf3(int i, int j,int k) 
{ 
    if(i==-1||j==-1||k==-1) 
        return 0; 
    if(dp[i][j][k]!=-1) 
        return dp[i][j][k]; 
      
    if(X[i]==Y[j] && Y[j]==Z[k]) 
        return dp[i][j][k] = 1+lcsOf3(i-1,j-1,k-1); 
    else
        return dp[i][j][k] = max(max(lcsOf3(i-1,j,k), 
                            lcsOf3(i,j-1,k)),lcsOf3(i,j,k-1)); 
} 
  
// Driver code 
int main() 
{ 
    memset(dp, -1,sizeof(dp)); 
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>X[i];
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    cin>>Y[i];
    int o;
    cin>>o;
    for(int i=0;i<o;i++)
    cin>>Z[i];  
  
    cout << lcsOf3(m-1,n-1,o-1); 
// this code is contributed by Kushdeep Mittal 
} 