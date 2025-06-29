/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<pair<TreeNode *, unsigned long long>> q;
        q.push({root, 0});
        int ans = 0;
        while (!q.empty())
        {
            int level = q.size();
            unsigned long long start = q.front().second;
            unsigned long long end = q.back().second;
            ans = max(ans, int(end - start + 1));
            for (int i = 0; i < level; i++)
            {
                TreeNode *node = q.front().first;
                unsigned long long index = q.front().second;
                index = index - start;
                q.pop();
                if (node->left)
                {
                    q.push({node->left, 2 * index});
                }
                if (node->right)
                {
                    q.push({node->right, 2 * index + 1});
                }
            }
        }
        return ans;
    }
};