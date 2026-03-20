/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *tempA = headA;
        ListNode *tempB = headB;

        while (tempA && tempB)
        {
            if (tempA == tempB)
            {
                return tempA;
            }
            if (tempA->next == nullptr)
            {
                tempA = headB;
                tempB = tempB->next;
            }
            else if (tempB->next == nullptr)
            {
                tempB = headA;
                tempA = tempA->next;
            }
            else
            {
                tempA = tempA->next;
                tempB = tempB->next;
            }
        }
        return nullptr;
    }
};