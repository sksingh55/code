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
    int n,k;
    cin>>n>>k;

        int count[5025]={0};
        int arr[n];
        bool res = false;
        int maxx = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            count[arr[i]]++;
            if(count[arr[i]]>k)
                res = true;

            maxx = max( maxx, count[arr[i]]);
        }

        if(k>n){
            cout<<"NO";
            return 0;
        }

        for(int i=0;i<n;i++){
            arr[i] = count[arr[i]]--;
        }

        int ii=0;
        for(int j=maxx+1;j<=k;j++)
            arr[ii++] = j;

        if(res){
            cout<<"NO";
            return 0;
        }

        cout<<"YES\n";
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        
    }

