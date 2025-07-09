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
    void helper(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
            return;
        helper(root->left, inorder);
        inorder.push_back(root->val);
        helper(root->right, inorder);
    }

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> inorder;
        helper(root, inorder);

        if (!root || (!root->left && !root->right))
        {
            return false;
        }

        int first = 0;
        int last = inorder.size() - 1;
        int flag = false;
        while (first < last)
        {
            if (inorder[first] + inorder[last] < k)
                first++;
            else if (inorder[first] + inorder[last] > k)
                last--;
            else
            {
                flag = true;
                break;
            }
        }
        return flag;
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
    void helper(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
            return;
        helper(root->left, inorder);
        inorder.push_back(root->val);
        helper(root->right, inorder);
    }
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> inorder;
        helper(root, inorder);
        if (!root || (!root->right && !root->left))
            return false;
        int left = 0, right = inorder.size() - 1;
        while (left < right)
        {
            if (inorder[left] + inorder[right] == k)
            {
                return true;
            }
            else if (inorder[left] + inorder[right] > k)
                right--;
            else
                left++;
        }
        return false;
    }
};