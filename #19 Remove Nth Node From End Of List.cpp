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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next && n==1)
        {
            delete head;
            return nullptr;
        }

        ListNode *temp=head,*prev=head;
        int total=1;
        while(temp->next)
        {
            temp=temp->next;
            total++;
        }
        temp=head;
        int count=1;
        int pos=total-n+1;
        if(n==total)
        {
            head=head->next;
            delete temp;
            return head;    
        }
        while(count!=pos)
        {
            prev=temp;
            temp=temp->next;
            count++;
        }
        prev->next=temp->next;
        delete temp;
        return head;
    }
};