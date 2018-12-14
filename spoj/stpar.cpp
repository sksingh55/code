#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
while(n!=0)
{
	vector <int > v,ans;
	stack <int> s;
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		v.push_back(k);
	}
	s.push(v[0]);
  //      cout<<s.top();	
       for(int i=1;i<n;i++)
        {
		while(!s.empty()&&s.top()<v[i])
		{
			//cout<<s.top();
			ans.push_back(s.top());
			s.pop();
		}
		s.push(v[i]);
       }
       while(!s.empty())
       {
	       ans.push_back(s.top());
	       s.pop();
       }




int i;
//	for(i=0;i<n;i++)
//		cout<<ans[i];
       for( i=0;i<n-1;i++)
       {
	       if(ans[i]>ans[i+1])
		       break;
       }
       if(i==n-1)
	       cout<<"yes\n";
       else
	       cout<<"no\n";
cin>>n;
}
}
