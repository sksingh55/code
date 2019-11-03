#include<bits/stdc++.h> 
using namespace std; 
  
long long int X[105],Y[105],Z[105]; 
  
long long int dp[105][105][105]; 
  
int lcsOf3(  int m, int n, int o) 
{ 
    int L[m+1][n+1][o+1]; 
  
    for (int i=0; i<=m; i++) 
    { 
        for (int j=0; j<=n; j++) 
        { 
            for (int k=0; k<=o; k++) 
            { 
                if (i == 0 || j == 0||k==0) 
                    L[i][j][k] = 0; 
  
                else if (X[i-1] == Y[j-1] && X[i-1]==Z[k-1]) 
                    L[i][j][k] = L[i-1][j-1][k-1] + 1; 
  
                else
                    L[i][j][k] = max(max(L[i-1][j][k], 
                                         L[i][j-1][k]), 
                                     L[i][j][k-1]); 
            } 
        } 
    } 
  
    
    return L[m][n][o]; 
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
  
    cout << lcsOf3(m,n,o); 
// this code is contributed by Kushdeep Mittal 
} 