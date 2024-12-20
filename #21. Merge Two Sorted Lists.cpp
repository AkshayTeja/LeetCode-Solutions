class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head, *p1 = list1, *p2 = list2;
        if (!p1)
            return p2;
        if (!p2)
            return p1;
        if (p1->val <= p2->val)
        {
            head = p1;
            p1 = p1->next;
        }
        else
        {
            head = p2;
            p2 = p2->next;
        }
        ListNode *current = head;
        while (p1 && p2)
        {
            if (p1->val <= p2->val)
            {
                current->next = p1;
                p1 = p1->next;
            }
            else
            {
                current->next = p2;
                p2 = p2->next;
            }
            current = current->next;
        }
        if (p1)
            current->next = p1;
        if (p2)
            current->next = p2;
        return head;
    }
};
