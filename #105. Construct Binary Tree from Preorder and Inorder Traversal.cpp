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
    unordered_map<int, int> mpp;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }
        return helper(preorder, 0, preorder.size() - 1, 0);
    }

private:
    TreeNode *helper(vector<int> &preorder, int preStart, int preEnd, int inStart)
    {
        if (preStart > preEnd)
            return NULL;
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRootIndex = mpp[root->val];
        int leftSubtreeSize = inRootIndex - inStart;
        root->left = helper(preorder, preStart + 1, preStart + leftSubtreeSize, inStart);
        root->right = helper(preorder, preStart + leftSubtreeSize + 1, preEnd, inRootIndex + 1);
        return root;
    }
};