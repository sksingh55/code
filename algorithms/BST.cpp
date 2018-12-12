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
#define mem(d,val) memset(d,val,sizeof(d))
using namespace std;
#define mod 1000000007
typedef long long int ll;

struct node
{
    int data;
    struct node * left;
    struct node * right;
};




struct node * newnode(int d)
{
    struct node * temp = (node * ) malloc(sizeof(node));
    temp->data = d;
    temp->left = temp->right = NULL;
    return temp;
}
struct node * root;
struct node * temp ;
ll ans = 1;
void insert(struct node * current,struct node * parent,ll val, ll depth)
{
    if(current == NULL)
    { 
        if(val > parent->data )
            parent->right = newnode(val);
        else
            parent->left = newnode(val);

        ans = max(depth,ans);
        return;
    }
    if(val > current->data)
    {
        parent=current;
        current=current->right;
        insert(current,parent,val,depth+1);
    }
    else
    {
        parent=current;
        current=current->left;
        insert(current,parent,val,depth+1);
    }
}
int main()
{
    ll n;
    cin>>n;
    f(i,0,n)
    {
        ll k;
        cin>>k;
        if(i==0)
        {
            root=newnode(k);
        }
        else
            insert(root,NULL,k,1);
    }
    cout<<ans<<"\n";
    


}