// geeksforgreek lecture 2 fibonnaci series using memorization
#include <bits/stdc++.h>
#define vec vector<long long int> 
#define pb push_back
#define tc int t; cin>>t; while(t--)
#define mp make_pair
using namespace std;
typedef long long int ll;
ll lookup[100000];

void intialize()
{
	for(int i=0;i<100000;i++)
		lookup[i]=-1;
}



ll  fib(ll n)
{
	if(lookup[n] == -1)
	{
		if(n<=1)
			lookup[n]=n;
	
	else
		lookup[n]= fib(n-1) + fib(n-2);
}
	return lookup[n];

}

int main()
{


	intialize();

	ll n;
	cin>>n;
	cout<<fib(n);
}