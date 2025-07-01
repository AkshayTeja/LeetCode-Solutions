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
    TreeNode *helper(vector<int> &arr, int &i, int bound)
    {
        if (i == arr.size() || arr[i] > bound)
            return NULL;
        TreeNode *root = new TreeNode(arr[i++]);
        root->left = helper(arr, i, root->val);
        root->right = helper(arr, i, bound);
        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return helper(preorder, i, INT_MAX);
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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        stack<TreeNode *> st;
        TreeNode *root = new TreeNode(preorder[0]);
        st.push(root);
        for (int i = 1; i < preorder.size(); i++)
        {
            TreeNode *node = new TreeNode(preorder[i]);
            if (preorder[i] < st.top()->val)
            {
                st.top()->left = node;
            }
            else if (preorder[i] > st.top()->val)
            {
                TreeNode *temp;
                while (!st.empty() && preorder[i] > st.top()->val)
                {
                    temp = st.top();
                    st.pop();
                }
                temp->right = node;
            }
            st.push(node);
        }
        return root;
    }
};