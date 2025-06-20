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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head;
        ListNode *temp = head;
        int n = 1;
        while (temp->next)
        {
            temp = temp->next;
            n++;
        }
        temp->next = head;
        k = k % n;
        if (k == n)
            return head;
        ListNode *newTail = head;
        int tail = n - k - 1;
        for (int i = 0; i < tail; i++)
        {
            newTail = newTail->next;
        }
        ListNode *newHead = newTail->next;
        newTail->next = NULL;
        return newHead;
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *temp = head;
        int size = 1;
        if (!head)
            return NULL;
        while (temp->next)
        {
            temp = temp->next;
            size++;
        }
        temp->next = head;
        ListNode *newHead;
        k = k % size;
        temp = head;
        for (int i = 0; i < size - k - 1; i++)
        {
            temp = temp->next;
        }
        newHead = temp->next;
        temp->next = NULL;
        return newHead;
    }
};