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
    int data;
    int min;
    struct stacks *next;
};

struct stacks* newNode(int data){
    struct stacks *pt  = (struct stacks*)malloc(sizeof(struct stacks));
    if(!pt){
        cout<<"Heap Overflow\n";
        return NULL;
    }
    pt->data = data;
    pt->min = data;
    pt->next = NULL;
    return pt;
}

void push(struct stacks **pt,int x){
    struct stacks *point = newNode(x);
    if(*pt==NULL){
        *pt = point;
        return;
    }
    point->next = *pt;
    if((*pt)->min<point->min){
        point->min = (*pt)->min;
    }
    *pt = point;
}

void pop(struct stacks **pt){
    if(*pt == NULL){
        cout<<"Stack is empty\n";
        return;
    }
    struct stacks *node = *pt;
    *pt = (*pt)->next;
    free(node);
}

int peek(struct stacks *pt){
    if(pt == NULL){
        return -1;
    }
    return pt->data;
}
int getmin(struct stacks *pt){
    return pt->min;
}


int main()
{
    int n;
    cin>>n;
    struct stacks *pt = NULL;
    while(n--){
        int k;
        cin>>k;
        push(&pt,k);
    }
    while(peek(pt)!=-1){
        cout<<getmin(pt)<<"\n";
        pop(&pt);
    }
}

