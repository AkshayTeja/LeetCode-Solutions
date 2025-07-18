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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        ListNode *dummy = new ListNode(-1);
        ListNode *current = dummy;
        int carry = 0;
        while (t1 != NULL || t2 != NULL)
        {
            int sum = carry;
            if (t1)
            {
                sum += t1->val;
            }
            if (t2)
            {
                sum += t2->val;
            }
            ListNode *newNode = new ListNode(sum % 10);
            carry = sum / 10;
            current->next = newNode;
            current = newNode;
            if (t1)
                t1 = t1->next;
            if (t2)
                t2 = t2->next;
        }
        if (carry)
        {
            ListNode *newNode = new ListNode(carry);
            current->next = newNode;
            current = newNode;
        }
        return dummy->next;
    }
};

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *temp1 = l1, *temp2 = l2, *curr = dummy;
        int carry = 0;
        while (temp1 || temp2 || carry)
        {
            int val1 = temp1 ? temp1->val : 0;
            int val2 = temp2 ? temp2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            ListNode *newNode = new ListNode(sum % 10);
            curr->next = newNode;
            curr = newNode;
            if (temp1)
                temp1 = temp1->next;
            if (temp2)
                temp2 = temp2->next;
        }
        return dummy->next;
    }
};