/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp=headA;
        map<ListNode*,int> mpp;
        while(temp)
        {
            mpp[temp]=1; //Insert entire node
            temp=temp->next;
        }
        temp=headB;
        while(temp)
        {
            if(mpp.find(temp)!=mpp.end())
                return temp;
            temp=temp->next;
        }
        return NULL;
    }
};

//Another approach

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp=headA;
        int lenA=1,lenB=1;
        while(temp)
        {
            lenA++;
            temp=temp->next;
        }
        temp=headB;
        while(temp)
        {
            lenB++;
            temp=temp->next;
        }

        ListNode *tempA=headA;
        ListNode *tempB=headB;
        if(lenA>lenB)
        {
            int diff=lenA-lenB;
            while(diff>0)
            {
                tempA=tempA->next;
                diff--;
            }
        }
        if(lenB>lenA)
        {
            int diff=lenB-lenA;
            while(diff>0)
            {
                tempB=tempB->next;
                diff--;
            }
        }

        while(tempA!=tempB)
        {
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempA;
    }
};

//Optimal Approach

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)
            return NULL;
        ListNode *tempA=headA;
        ListNode *tempB=headB;

        while(tempA!=tempB)
        {
            tempA=tempA->next;
            tempB=tempB->next;
            if(tempA==tempB)
                return tempA;
            if(tempA==NULL)
                tempA=headB;
            if(tempB==NULL)
                tempB=headA;
        }
        return tempA; //If both lists same     
    }
};