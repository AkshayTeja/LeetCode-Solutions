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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        struct ListNode *current = head;
        struct ListNode *nextNode = current->next;
        struct ListNode *connector=nextNode;
        while(nextNode!=nullptr && nextNode->next!=nullptr)
        {
            current->next=nextNode->next;
            current=current->next;
            nextNode->next=current->next;
            nextNode=nextNode->next;
        }
        current->next=connector;
        return head;
    }
};