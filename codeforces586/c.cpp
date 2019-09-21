#include <bits/stdc++.h>
#define vec(a) vector<a>
#define vecp(a, b) vector<pair<a, b>>
#define pb push_back
#define minpq priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
#define f(i, a, b) for (long long int i = a; i < b; i++)
#define fr(i, a, b) for (long long int i = a; i >= b; i--)
#define tc           \
	long long int t; \
	cin >> t;        \
	while (t--)
#define mp make_pair
#define mapp(a, b) map<a, b>
#define umapp(a, b) unordered_map<a, b>
#define mem(d, val) memset(d, val, sizeof(d))
#define modd 1000000007
#define MAX 300005
using namespace std;
typedef  long int ll;

int main()
{
	string s;
    cin>>s;
    char minthan[s.length()+10];
    char minafter[s.length()+10];
    f(i,0,s.length()+10){
        minthan[i]='0';
        minafter[i]='0';
    }
    char minChar = s[0];
    f(i,1,s.length()){
        if(s[i]>minChar){
            minthan[i] = minChar;
        }
        minChar = min(s[i],minChar);
        // cout<<minthan[i]<<" ";
    }
    
    cout<<"Mike\n";
    f(i,1,s.length()){
        if(minthan[i]=='0'){
            cout<<"Mike\n";
        }else{
            cout<<"Ann\n";
        }
    }
}
