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
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return (max(maxDepth(root->left), maxDepth(root->right))) + 1;
    }
};

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
    int helper(TreeNode *root, int depth)
    {
        if (root->left == NULL && root->right == NULL)
            return depth;
        int left = (root->left) ? helper(root->left, depth + 1) : depth;
        int right = (root->right) ? helper(root->right, depth + 1) : depth;
        return max(left, right);
    }
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return helper(root, 1);
    }
};