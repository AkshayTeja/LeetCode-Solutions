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
    void helper(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};

// Iterative

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
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> ans;
        TreeNode *node = root;

        while (true)
        {
            if (node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if (st.empty())
                    break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        TreeNode *current = root;
        vector<int> ans;
        while (current != NULL)
        {
            if (current->left == NULL)
            {
                ans.push_back(current->val);
                current = current->right;
            }
            else
            {
                TreeNode *predecessor = current->left;
                while (predecessor->right != NULL && predecessor->right != current)
                {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == NULL)
                {
                    predecessor->right = current;
                    current = current->left;
                }
                else
                {
                    predecessor->right = NULL;
                    ans.push_back(current->val);
                    current = current->right;
                }
            }
        }
        return ans;
    }
};