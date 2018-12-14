#include<bits/stdc++.h>
using namespace std;
int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int a[n+5],b[m+5];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}

		for(int j=0;j<m;j++)
			cin>>b[j];


		sort(a,a+n);
		sort(b,b+m);
        
        if(a[n-1]>=b[m-1])
        cout<<"Godzilla\n";
    	else
    		cout<<"MechaGodzilla\n";


	}
}