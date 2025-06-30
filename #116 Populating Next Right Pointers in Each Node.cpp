/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        if(root->left==NULL && root->right==NULL)
            return root;
        Node *top=root;
        queue<Node*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty())
        {
            int counter=q.size()-1;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                Node *temp=q.front();
                q.pop();
                if(counter>0)
                    temp->next=q.front();
                if(temp->left)
                    q.push({temp->left});
                if(temp->right)
                    q.push({temp->right});
                counter--;
            }
        }
        return top;
    }
};