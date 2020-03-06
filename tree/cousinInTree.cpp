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
    bool isCousins(TreeNode *root, int x, int y)
    {
        queue<pair<TreeNode *, int>> q;
        int level = 0, size = 0;
        bool flag = false;
        q.push({root, level});
        while (!q.empty())
        {
            size = q.size();
            while (size--)
            {
                pair<TreeNode *, int> temp = q.front();
                q.pop();
                if (temp.first->val == x)
                {
                    while (size--)
                    {
                        pair<TreeNode *, int> temp2 = q.front();
                        q.pop();
                        if (temp2.first->val == y && temp2.second != temp.second)
                        {
                            flag = true;
                            break;
                        }
                    }
                    return flag;
                }
                if (temp.first->val == y)
                {
                    while (size--)
                    {
                        pair<TreeNode *, int> temp2 = q.front();
                        q.pop();
                        if (temp2.first->val == x && temp2.second != temp.second)
                        {
                            flag = true;
                            break;
                        }
                    }
                    return flag;
                }
                if (temp.first->left)
                {
                    q.push({temp.first->left, temp.first->val});
                }
                if (temp.first->right)
                {
                    q.push({temp.first->right, temp.first->val});
                }
            }
        }
        return flag;
    }
};