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
void find(struct node * current , ll d)
{
    if(current == NULL)
        return;
    if(current->data == d)
        temp=current;

    find(current->left,d);
    find(current->right,d);
}
void insert(ll i,ll j,char c)
{
    temp=NULL;
    find(root,i);
    if(c == 'R' )
        temp->right = newnode(j);
    else
        temp->left = newnode(j);
}
ll mirror(struct node * one , struct node * two, ll k)
{
    if(one == NULL || two == NULL)
        return -1;
    if(one->data == k)
        return two->data;
    if(two->data == k)
        return one->data;
    ll ans = mirror(one->left,two->right,k);
    if(ans!=-1)
        return ans;
    return mirror(one->right,two->left,k);
}

void printtree(struct node * current)
{
    if(current == NULL)
        return;
    cout<<current->data<<" ";
    printtree(current->left);
    printtree(current->right);

}



int main()
{
    //ios_base::sync_with_stdio(0);
    ll n,m;
    cin>>n>>m;
    n--;
    root=(node * )malloc(sizeof(node));
    root = newnode(1);
    
    while(n--)
    {
        ll i,j;
        char c;
        cin>>i>>j>>c;
        
        insert(i,j,c);
        

    }
    while(m--)
    {
        ll k;
        cin>>k;
        cout<<mirror(root,root,k)<<"\n";
    }
    

}