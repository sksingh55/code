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

struct stacks{
    int maxSize;
    int top;
    int *items;
};

struct stacks* newStack(int cap){
    struct stacks *pt  = (struct stacks*)malloc(sizeof(struct stacks));
    pt->maxSize = cap;
    pt->top = -1;
    pt->items = (int*)malloc(sizeof(int)*cap);
    return pt;
}

void push(struct stacks *pt,int x){
    if(pt->top == pt->maxSize-1){
        cout<<"Max Stack size achieved\n";
        return;
    }
    pt->top ++;
    pt->items[pt->top]=x;
}

void pop(struct stacks *pt){
    if(pt->top==-1){
        cout<<"Stack is empty\n";
        return;
    }
    pt->top--;
}

int peek(struct stacks *pt){
    if(pt->top == -1){
        return -1;
    }
    return pt->items[pt->top];
}
int solver(vector<string> s){
    struct stacks *pt = newStack(s.size());
    for(int i=0;i<s.size();i++){
        if(s[i] == "+"){
            int a = peek(pt);
            pop(pt);
            int b = peek(pt);
            pop(pt);
            push(pt,a+b);
        }
        else if(s[i] == "-"){
            int a = peek(pt);
            pop(pt);
            int b = peek(pt);
            pop(pt);
            push(pt,b-a);
        }
        else if(s[i] == "*"){
            int a = peek(pt);
            pop(pt);
            int b = peek(pt);
            pop(pt);
            push(pt,a*b);
        }
        else if(s[i] == "/"){
            int a = peek(pt);
            pop(pt);
            int b = peek(pt);
            pop(pt);
            push(pt,b/a);
        }
        else{
            push(pt,stoi(s[i]));
        }
    }
    return peek(pt);
}

int main()
{
    int n;
    cin>>n;
    vector<string> s;
    f(i,0,n){
        string k ;
        cin>>k;
        s.pb(k);
    }
    cout<<solver(s);
}

