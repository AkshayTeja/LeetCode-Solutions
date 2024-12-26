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
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int n = 0;
        ListNode *temp = head;
        while (temp)
        {
            n++;
            temp = temp->next;
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        int val = n / k;
        ListNode *prev = dummy;
        ListNode *curr = prev->next;
        while (val--)
        {
            for (int i = 0; i < k - 1; i++)
            {
                ListNode *nextNode = curr->next;
                curr->next = nextNode->next;
                nextNode->next = prev->next;
                prev->next = nextNode;
            }
            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};