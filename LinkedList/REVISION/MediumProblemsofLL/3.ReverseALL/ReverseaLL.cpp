// Leetcode Question 206.

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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *p = nullptr;
        ListNode *q = head;
        while (q)
        {
            ListNode *temp = q->next;
            q->next = p;
            p = q;
            q = temp;
        }
        return p;
    }
};