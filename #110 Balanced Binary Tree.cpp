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
class Solution {
public:
    int helper(TreeNode *root,int &ans)
    {
        if(root==NULL)
            return 0;
        int left=helper(root->left,ans);
        int right=helper(root->right,ans);
        if(abs(left-right)>1)
            ans=0;
        return max(left,right)+1;

    }

    bool isBalanced(TreeNode* root) {
        int ans=1;
        helper(root,ans);
        if(ans==1)
            return true;
        return false;
    }
};

//Another solution

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
class Solution {
public:
    int helper(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        int left=helper(root->left);
        int right=helper(root->right);
        if(left==-1)
            return -1;
        if(right==-1)
            return -1;
        if(abs(left-right)>1)
            return -1;
        return max(left,right)+1;

    }

    bool isBalanced(TreeNode* root) {
        return helper(root)!=-1;
    }
};