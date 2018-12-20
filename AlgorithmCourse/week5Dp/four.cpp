#include<iostream>
#include<string>
 
using namespace std;
 
int longestCommonSubsequece(int str1[], int str2[], int len1, int len2)
{
    int i, j;
 
    //create a matrix of order (len1+1)*(len2+1) to tabulate values
    int LCS[len1+1][len2+1];
 
    //LCS[i][j]=Length of longest common subsequence of str1[0....(i-1)] and str2[0...(j-1)] 
 
    //initializing
    for(i=0;i<=len1;i++)
        LCS[i][0]=0;    //empty str2
 
    for(j=0;j<=len2;j++)
        LCS[0][j]=0;   //empty str1
 
    //now, start filling the matrix row wise
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            //if current character of both strings match
            if(str1[i-1]==str2[j-1])
            {
                LCS[i][j]=1+LCS[i-1][j-1];
            }
 
            //mismatch
            else
            {
                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }
 
    //now, return the final value 
    return LCS[len1][len2];
 
}
 
 
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int m;
    cin>>m;
    int b[m+1];
    for(int i=0;i<m;i++)
        cin>>b[i];
    cout<<longestCommonSubsequece(a,b,n,m);
 
    cout<<endl;
    return 0;
}
