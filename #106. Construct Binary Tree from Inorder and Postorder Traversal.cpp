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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }
        return helper(postorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    TreeNode *helper(vector<int> &postorder, int postStart, int postEnd, int inStart, int inEnd)
    {
        if (postStart > postEnd)
            return NULL;
        TreeNode *root = new TreeNode(postorder[postEnd]);
        int inRootIndex = mpp[root->val];
        int rightSubtreeSize = inEnd - inRootIndex;
        root->right = helper(postorder, postEnd - rightSubtreeSize, postEnd - 1, inRootIndex + 1, inEnd);
        root->left = helper(postorder, postStart, postEnd - rightSubtreeSize - 1, inStart, inRootIndex - 1);
        return root;
    }
};