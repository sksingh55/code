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
typedef long long int ll;

int main()
{
    tc
    {
        int n,m;
        cin>>n>>m;
        int ans[100][100];
        mem(ans,-1);
        if(n==1)
        {
            ll flag=0;
            ll x=1;
            for(int i=0;i<n;i++)
            {
                f(j,0,m)
                {
                    ans[i][j]=x;
                    flag++;
                    if(flag%2==0)
                    {
                        if(x==1)
                            x=2;
                        else
                            x=1;
                        flag=0;
                    }
                }
            }
        }
        else if(n==2)
        {
            ll x=0;
            f(i,0,m)
            {
                
                x++;
                ans[0][i]=x;
                ans[1][i]=x;
                
                x=x%3;
            }
        }
        else
        {
            if(m==1)
            {
                ll flag=0;
                ll x=1;
                for(int i=0;i<m;i++)
                {
                    f(j,0,n)
                    {
                        ans[j][i]=x;
                        flag++;
                        if(flag%2==0)
                        {
                            if(x==1)
                                x=2;
                            else
                                x=1;
                            flag=0;
                        }
                    }
                }
            }
            else if(m==2)
            {
                ll x=0;
                f(i,0,n)
                {
                    
                    x++;
                    ans[i][0]=x;
                    ans[i][1]=x;
                    
                    x=x%3;
                }

            }
            else
            {
                ll x=0;
                for(int i=0;i<n;i++)
                {
                    if(x==0)
                    {
                        ll flag=0;
                        ll x=1;
                        f(j,0,m)
                        {
                            ans[i][j]=x;
                            flag++;
                            if(flag%2==0)
                            {
                                if(x==1)
                                    x=2;
                                else
                                    x=1;
                                flag=0;
                            }
                        }
                    }
                    else if(x==1)
                    {
                        ll flag=0;
                        ll x=3;
                        f(j,0,m)
                        {
                            ans[i][j]=x;
                            flag++;
                            if(flag%2==0)
                            {
                                if(x==3)
                                    x=4;
                                else
                                    x=3;
                                flag=0;
                            }
                        }

                    }
                    else if(x==2)
                    {
                        ll flag=0;
                        ll x=2;
                        f(j,0,m)
                        {
                            ans[i][j]=x;
                            flag++;
                            if(flag%2==0)
                            {
                                if(x==2)
                                    x=1;
                                else
                                    x=2;
                                flag=0;
                            }
                        }

                    }
                    else if(x==3)
                    {
                        ll flag=0;
                        ll x=4;
                        f(j,0,m)
                        {
                            ans[i][j]=x;
                            flag++;
                            if(flag%2==0)
                            {
                                if(x==3)
                                    x=4;
                                else
                                    x=3;
                                flag=0;
                            }
                        }

                    }

                    x++;
                    x=x%4;

                }
            }
        }
        ll max=-1;
        f(i,0,n)
        {
            f(j,0,m)
            {
                if(ans[i][j]>max)
                    max=ans[i][j];
            }
        }
        cout<<max<<"\n";
        f(i,0,n)
        {
            f(j,0,m)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
        

    }
}
