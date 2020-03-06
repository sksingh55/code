#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        queue<TreeNode *> q;
        q.push(root);
        int flag = 0;
        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();
            if (flag && (current->left || current->right))
            {
                return false;
            }
            if (!current->left && current->right)
            {
                return false;
            }
            if (current->left)
            {
                q.push(current->left);
            }
            else
            {
                flag = 1;
            }
            if (current->right)
            {
                q.push(current->right);
            }

            else
            {
                flag = 1;
            }
        }
        return true;
    }
};