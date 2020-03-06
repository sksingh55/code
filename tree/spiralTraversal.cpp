#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> solver(TreeNode *root)
{
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    int level = 0;
    q.push(root);
    while (!q.empty())
    {

        vector<int> temp;
        TreeNode *end = q.back();
        while(1){
            TreeNode *current = q.front();
            temp.push_back(current->val);
            q.pop();
            if(current->left){
                q.push(current->left);
            }
            if(current->right){
                q.push(current->right);
            }
            if(current->val == end->val){
                break;
            }
        }
        if(level%2!=0){
            reverse(temp.begin(),temp.end());
        }
        ans.push_back(temp);
        level++;
    }
    return ans;
}

int main()
{
}