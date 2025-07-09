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
class BSTIterator
{
public:
    TreeNode *node;
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        node = root;
    }

    int next()
    {
        while (node)
        {
            st.push(node);
            node = node->left;
        }
        TreeNode *temp = st.top();
        st.pop();
        node = temp->right;
        return temp->val;
    }

    bool hasNext()
    {
        return !st.empty() || node;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */