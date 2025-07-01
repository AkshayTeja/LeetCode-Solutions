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
    bool helper(TreeNode *root, long leftLimit, long rightLimit)
    {
        if (root == NULL)
            return true;
        if (root->val <= leftLimit || root->val >= rightLimit)
            return false;
        return helper(root->left, leftLimit, root->val) && helper(root->right, root->val, rightLimit);
    }

    bool isValidBST(TreeNode *root)
    {
        return helper(root, LONG_MIN, LONG_MAX);
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
    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode *> st;
        long prevVal = LONG_MIN;
        TreeNode *current = root;
        while (current != NULL || !st.empty())
        {
            while (current)
            {
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            if (current->val <= prevVal)
                return false;
            prevVal = current->val;
            current = current->right;
        }
        return true;
    }
};