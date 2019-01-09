#include<bits/stdc++.h> 
using namespace std; 
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int ans=a;
	for(int i=a;i>=1;i--)
	{
		if(i+1<=b&&i+2<=c)
		{
			ans=i;
			break;
		}
	}
	cout<<ans*3+3;
}