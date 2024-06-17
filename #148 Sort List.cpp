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
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode *temp=head;
        while(temp)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        sort(v.begin(),v.end());
        temp=head;
        int i=0;
        for(auto it:v)
        {
            temp->val=it;
            temp=temp->next;
        }
        return head;
    }
};

//Optimal approach using merge sort

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
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *slow=head,*fast=head->next;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode *mergeLists(ListNode *list1,ListNode *list2)
    {
        ListNode *dummy=new ListNode(-1);
        ListNode *temp=dummy;
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
            else
            {
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
        if(list1)
        {
            temp->next=list1;
        }
        else
        {
            temp->next=list2;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *middle=findMiddle(head);
        ListNode *right=middle->next;
        middle->next=nullptr;
        ListNode *left=head;

        left=sortList(left);
        right=sortList(right);
        return mergeLists(left,right);
    }
};