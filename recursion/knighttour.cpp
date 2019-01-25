#include <bits/stdc++.h>
#define vec(a) vector<a>
#define vecp(a,b) vector < pair< a, b > > 
#define pb push_back
#define minpq priority_queue <long long int, vector<long long int>, greater<long long int> > pq;
#define f(i,a,b) for(long long int i=a;i<b;i++)
#define fr(i,a,b) for(long long int i=a;i>=b;i--)
#define tc long long int t; cin>>t; while(t--)
#define mp make_pair
#define mapp(a,b) map<a, b>
#define umapp(a,b) unordered_map<a ,b> 
#define mem(d,val) memset(d,val,sizeof(d))
using namespace std;
#define mod 1000000007 
 

int a[8][8];
int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 }; 

bool issafe(int i,int j)
{
    if(a[i][j]==-1&&i>=0&&i<8&&j>=0&&j<8)
        return true;
    else
        return false;
}

bool solution(int i,int j,int c)
{
    if(c==64)
        return true;
    for(int k=7;k>=0;k--)
    {
        if(issafe(i+xMove[k],j+yMove[k]))
        {
            a[i+xMove[k]][j+yMove[k]]=c;
            if(solution(i+xMove[k],j+yMove[k],c+1))
                return true;
            else
                a[i+xMove[k]][j+yMove[k]]=-1;
        }    
    }
return false;

}



 int main()
 {
    mem(a,-1);
    solution(0,0,1);
    

    f(i,0,8)
    {
        f(j,0,8)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<'\n';
    }
 }