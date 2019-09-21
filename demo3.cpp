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

int counnt = 0;

    int n,m;
void path(string a[],int i,int j){

    if(a[i][j]=='#'){
        return;
    }
    if(counnt==1){
        return;
    }
    if(i<0 || j<0){
        return;
    }
    if(i==0 && j==0){
        counnt++;
        return;
    }

    if(j-1>=0 && counnt<1&&a[i][j-1]=='.'){
        path(a,i,j-1);
    }
    if(i-1>=0&& counnt<1&&a[i-1][j]=='.'){
        path(a,i-1,j);
    }
}

void path2(string a[],int i,int j){
    cout<<i<<j<<"\n";

    if(i==n-1 && j==m-1){
        counnt++;
        return;
    }
    if(a[i][j]=='#' || j >=n || i>=m){
        return;
    }
    if(counnt==1){
        return;
    }
    
    path2(a,i,j+1);
    path2(a,i+1,j);
}


int main(){
    cin>>n>>m;
    string a[n+5];
    f(i,0,n){
        cin>>a[i];
    }

    if((n-1)>=0 && (n-2)>=0 && (m-1)>=0 && (m-2)>=0 && a[n-1][m-2]=='#' && a[n-2][m-1]=='#'){
        cout<<0;
        return 0;
    }
    if(a[1][0]=='#' && a[0][1]=='#'){
        cout<<0;
        return 0;
    }
    int ans =0 ;
    counnt=0;
    path(a,n-2,m-1);
    if(counnt==1){
        ans++;
    }
    
    counnt=0;
    path(a,n-1,m-2);
    if(counnt==1){
        ans++;
    }
    if(ans==2){
        ans =0 ;
        counnt=0;
        path2(a,0,1);
        if(counnt==1){
            ans++;
        }
        
        counnt=0;
        path2(a,1,0);
        if(counnt==1){
            ans++;
        }
    }
    cout<<ans;

}