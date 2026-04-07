// Leetcode Question 19

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
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr && n == 1)
            return nullptr;
        int cnt = 0;
        ListNode *p = head;
        while (p)
        {
            cnt++;
            p = p->next;
        }
        int newN = cnt - n;
        if (newN == 0)
        {
            head = head->next;
            return head;
        }
        p = head;
        for (int i = 1; i < newN; i++)
        {
            p = p->next;
        }
        p->next = p->next->next;
        return head;
    }
};