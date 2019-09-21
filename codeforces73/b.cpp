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
typedef long long int ll;

int main()
{
    int x,i,j;
    scanf("%d",&x);
    if(x==3){
        for(i=1;i<=x;i++){
            for(j=1;j<=x;j++){
                if(i==2)
                    printf("B");
                else if(j%2==1)
                    printf("W");
                else
                    printf("B");
            }
            printf("\n");
        }
    }
    else{
        for(i=1;i<=x;i++){
            for(j=1;j<=x;j++){
                if(i%2==1 && j%2==1)
                    printf("W");
                else if(i%2!=1 && j%2!=1)
                    printf("W");
                else
                    printf("B");
            }
            printf("\n");
        }
    }
    return 0;
}
