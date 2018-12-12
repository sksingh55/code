#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n,m;
	cin>>n>>m;
    string s[n+1];
    for(int i=0;i<n;i++)
    	cin>>s[i];
    int ans=1;
    int row[n+1]={0};
    int col[m+1]={0};
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		if(s[i][j]=='#'&&ans==1)
    		{
    			col[j]=1;
    			for(int k=i;k<n;k++)
    			{
    				if(s[k][j]=='#'&&ans==1)
    				{
    					if(row[k]==0 &&ans==1 )
    						row[k]=1;
    					else
    						ans=0,break;
    				}

    			}
    		}
    	}
    }
    if(ans==0)
    	cout<<"No";
    else
    	cout<<"Yes";
 }
