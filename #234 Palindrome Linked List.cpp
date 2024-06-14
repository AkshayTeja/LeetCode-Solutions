/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return true;
        }
        int total=1,index=1;
        ListNode *temp=head;
        stack<int> st;
        while(temp)
        {
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp)
        {
            if(st.top()!=temp->val)
            {
                return false;
            }
            st.pop();
            temp=temp->next;
        }
        return true;
    }
};

//Another Solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=nullptr,*current=head,*nextNode;

        while(current)
        {
            nextNode=current->next;
            current->next=prev;
            prev=current;
            current=nextNode;
        }
        head=prev;
        return head;
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return true;
        }
        ListNode *slow=head,*fast=head;
        while(fast-> next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *newHead=reverseList(slow->next);
        ListNode *first=head;
        ListNode *second=newHead;
        while(second!=NULL)
        {
            if(first->val!=second->val)
            {
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverseList(newHead);
        return true;
    }
};