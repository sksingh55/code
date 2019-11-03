#include<bits/stdc++.h> 
using namespace std; 
  
int main()
{ 
  int n;
  cin>>n;
  int a[2][n+1];
  a[0][1]=0;
  a[1][1]=1;
  a[0][2]=1;
  a[1][2]=1;
  a[1][3]=1;
  a[0][3]=1;
  for(int i=4;i<=n;i++)
  {
    a[0][i]=INT_MAX;
    a[1][i]=0;
     if(i%2==0)
     {
      if(a[0][i/2]+1<a[0][i])
     {   a[0][i]=a[0][i/2]+1;
             a[1][i]=i/2;}
     }
     if(i%3==0)
     {
      if(a[0][i/3]+1<a[0][i])
        {a[0][i]=a[0][i/3]+1;
                a[1][i]=i/3;}
     }
  
    if(a[0][i-1]+1<a[0][i])
      {
      a[0][i]=a[0][i-1]+1;a[1][i]=i-1;}
    // cout<<i<<" "<<a[0][i]<<" "<<a[1][i]<<"\n";
  }
  int ans=a[0][n];
  cout<<ans<<"\n";
  vector<int> v;
  int i=n;
  v.push_back(n);
  while(1)
  {
    if(i==1)
      break;
    v.push_back(a[1][i]);
    i = a[1][i];
    

  }
  for(int i=v.size()-1;i>=0;i--)
    cout<<v[i]<<" ";


  return 0; 
} 