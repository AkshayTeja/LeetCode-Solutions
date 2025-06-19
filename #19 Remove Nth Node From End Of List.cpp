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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head->next && n == 1)
        {
            delete head;
            return nullptr;
        }

        ListNode *temp = head, *prev = head;
        int total = 1;
        while (temp->next)
        {
            temp = temp->next;
            total++;
        }
        temp = head;
        int count = 1;
        int pos = total - n + 1;
        if (n == total)
        {
            head = head->next;
            delete temp;
            return head;
        }
        while (count != pos)
        {
            prev = temp;
            temp = temp->next;
            count++;
        }
        prev->next = temp->next;
        delete temp;
        return head;
    }
};

// Another solution with lesser TC

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head->next && n == 1)
        {
            delete head;
            return nullptr;
        }

        ListNode *fast = head, *slow = head;
        ListNode *dummy = head;
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        if (fast == NULL) // Case when n equals size of list
        {
            head = head->next;
            delete dummy;
            return head;
        }
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *delNode;
        delNode = slow->next;
        slow->next = delNode->next;
        delete delNode;
        return head;
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int size = 0;
        ListNode *temp = head;
        while (temp)
        {
            temp = temp->next;
            size++;
        }
        temp = head;
        ListNode *prev;
        if (size == n)
            return head->next;
        for (int i = 0; i < size - n; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        return head;
    }
};