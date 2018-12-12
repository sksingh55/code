#include <bits/stdc++.h>
#define vec(a) vector<a>
#define vecp(a,b) vector < pair< a, b > > 
#define pb push_back
#define minpq priority_queue <long long int, vector<long long int>, greater<long long int> > pq;
#define f(i,a,b) for(long long int i=a;i<b;i++)
#define fr(i,a,b) for(long long int i=b;i>a;i--)
#define tc long long int t; cin>>t; while(t--)
#define mp make_pair
#define mapp(a,b) map<a, b>
#define umapp(a,b) unordered_map<a ,b> 
using namespace std;
typedef long long int ll;

string findlength(string s[],ll n)
{
    string temp=s[0];
    f(i,1,n)
    {
        ll j=0,k=0;
        while(j<temp.length() && k<s[i].length() )
        {
          if(temp[j]==s[i][k])
          {
            j++;
            k++;
          }
          else
          {
            k=0;
            j++;
          }   
        }
        f(l,k,s[i].length())
        temp+=s[i][l];
    }
    return temp;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {

        int n;
        cin>>n;
        string s[n+1];
        f(i,0,n)
        cin>>s[i];
        cout<<findlength(s,n);
        string ans=findlength(s,n);
        ll count=1;
        while(next_permutation(s,s+n))
        {
            string temp=findlength(s,n);
            count++;
            if(ans.length()>temp.length())
                ans=temp;
        }
        cout<<"Case "<<i<<": "<<ans.length()<<"\n";


    }
}

