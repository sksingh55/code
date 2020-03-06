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
using namespace std;
#define mod 1000000007
typedef long long int ll;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode*> store;
    TreeNode *curr = root;
    while(!store.empty() || curr != NULL){
        if(curr!=NULL){
            store.push(curr);
            curr = curr->left;
        }
        else{
            curr = store.top();
            store.pop();
            ans.pb(curr->val);
            curr = curr->right;
        }
    }
    return ans;
}

int main()
{
}
