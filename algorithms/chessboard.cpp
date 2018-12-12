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
ll s1[2000][2000],s0[2000][2000];
ll ans[100005];


int sumQuery0(int tli, int tlj, int rbi, int rbj) 
{ 
    int res = s0[rbi][rbj]; 
    if (tli > 1) 
    res = res - s0[tli-1][rbj]; 
    if (tlj > 1) 
    res = res - s0[rbi][tlj-1]; 
    if (tli > 1 && tlj > 1) 
    res = res + s0[tli-1][tlj-1]; 
    return res; 
} 

int sumQuery1(int tli, int tlj, int rbi, int rbj) 
{ 
    int res = s1[rbi][rbj]; 
    if (tli > 1) 
    res = res - s1[tli-1][rbj]; 
    if (tlj > 1) 
    res = res - s1[rbi][tlj-1]; 
    if (tli > 1 && tlj > 1) 
    res = res + s1[tli-1][tlj-1];
    return res; 
} 


void preprocess(ll n,ll m, ll size)
{
    f(i,1,n+2-size)
    {
        f(j,1,m+2-size)
        {
            ll tli=i,tlj=j,rbi=i-1+size,rbj=j-1+size;
            ll k=sumQuery0(tli,tlj,rbi,rbj);
            ans[k]=max(ans[k],size);
            k = sumQuery1(tli,tlj,rbi,rbj);
            ans[k]=max(ans[k],size);
        }
    }
}






int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    memset(s1,0,sizeof(s1));
    memset(s0,0,sizeof(s0));
    memset(ans,0,sizeof(ans));
    string s[n+1];
    f(i,0,n)
    cin>>s[i];

    f(i,1,n+1)
    {
        ll flag1,flag2;
        if(i%2==0)
        {
            flag1=1;
            flag2=0;
        }
        else
        {
            flag1=0;
            flag2=1;
        }


        f(j,1,m+1)
        {
            ll k=s[i-1][j-1]-'0';
            if(k!=flag1)
                s0[i][j]=1;
            if(k!=flag2)
                s1[i][j]=1;

            if(flag1==1)
                flag1=0;
            else
                flag1=1;

            if(flag2==1)
                flag2=0;
            else
                flag2=1;
        }
    }

    
    f(i,1,n+1)
    {
        f(j,1,m+1)
        {
            s0[i][j] += s0[i][j-1];
            s1[i][j] += s1[i][j-1];
        }
    }
    f(j,1,m+1)
    {
        f(i,1,n+1)
        {
            s0[i][j] += s0[i-1][j];
            s1[i][j] += s1[i-1][j];
        }
    }

    
    

    f(i,0,min(n,m)+1)
    {
        preprocess(n,m,i);
    }
    ll flag=ans[0];
    f(i,0,100000)
    {
        ans[i]=max(ans[i],flag);
        flag=ans[i];
    }

    long long int t;
    cin>>t;
    while(t--)
    {
        long long int k;
        cin>>k;
        if(k>99999)
            cout<<ans[99999]<<"\n";
        else
        cout<<ans[k]<<"\n";
    }
    

    

    
}

