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
private:
    bool check(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
        {
            return true;
        }
        if (!left || !right)
        {
            return false;
        }
        if (left->val != right->val)
        {
            return false;
        }
        return check(left->left, right->right) && check(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        return check(root->left, root->right);
    }
};