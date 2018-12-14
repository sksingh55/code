#include <bits/stdc++.h>
#define tc int t; cin>>t; while(t--)
#define vec vector <long long int >
#define pb push_back
using namespace std;
typedef long long int ll;

int main()
{
ll t;
cin>>t;
for(int j=1;j<=t;j++)
{

ll m,n;
cin>>m>>n;
ll sum=0;
vec v;
for(int i=0;i<n;i++)
{
ll k;
cin>>k;
v.pb(k);
}
sort(v.begin(),v.end());
ll i,count=0;
for(i=n-1;i>=0;i--)
{
sum+=v[i];
count++;
if(sum>=m)
break;

}
cout<<"Scenario #"<<j<<":"<<"\n";
if(i==-1)
cout<<"impossible\n";
else
cout<<count<<"\n";
}
}
